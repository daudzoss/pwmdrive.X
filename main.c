#include "mcc_generated_files/mcc.h"
#include "stdint.h"

#define NO_MODE_SELECTED (0)
#define FREQ_ADJUST_MODE (1)
#define DUTY_ADJUST_MODE (2)

void set_current_limit(uint8_t pwm_chan, uint8_t dac_value)
{
  if (pwm_chan == 6) { // low channel (PWM6 uses RA1, labeled "1")
    CLIK1CS_N_LAT = 0;
    CLIK2CS_N_LAT = 1;
  } else if (pwm_chan == 7) { // even channel (PWM7 uses RA2, labeled "2")
    CLIK1CS_N_LAT = 1;
    CLIK2CS_N_LAT = 0;
  }

  SPI1_WriteByte(dac_value);
    
  // de-assert both channels
  CLIK1CS_N_LAT = 1;
  CLIK2CS_N_LAT = 1;
}

uint16_t read_adc(uint8_t chan)
{
  // correct for the fact that knob fully left reads full scale, fully right 0:
  return 0xffc0 - (uint16_t) ADCC_GetSingleConversion(chan);
}

void set_parameter(uint8_t parm, uint16_t new_value, uint16_t* tau, uint16_t* T)
{
  switch (parm) {

  case FREQ_ADJUST_MODE: // knob is frequency but parameter is time; reverse so

    new_value = 0xffff - new_value;
    if (T)
      *T = new_value; // CW turn = higher frequency (lower period)

    break;
    
  case DUTY_ADJUST_MODE: // uint8_t*uint16_t>>14: 8+16-14=10-bit right justified

    if (tau)
      *tau = new_value; // CW turn = higher duty cycle (tau)

    break;

  case NO_MODE_SELECTED: // adjust the current limit downward first if no button
  default:
/*
    set_current_limit(6, new_value >> 8);
    set_current_limit(7, new_value >> 8);
*/
    return;
  }

  // duty cycle has to be recalculated every time period changes
  if (T && tau) {
    uint16_t new_duty = ((*T) * (*tau)) >> 14;

    TMR6_LoadPeriodRegister(*T >> 8);
    PWM6_LoadDutyValue(new_duty);
    PWM7_LoadDutyValue(new_duty);
  }

  // display binary representation of upper nybble on LED array
  LED5_LAT = (new_value & 0x8000) ? 1 : 0;
  LED4_LAT = (new_value & 0x4000) ? 1 : 0;
  LED3_LAT = (new_value & 0x2000) ? 1 : 0;
  LED2_LAT = (new_value & 0x1000) ? 1 : 0;
}

void main(void)
{
    uint8_t tmr_period; // 8-bit TMR6 shared by positive PWM6 and negative PWM7
    uint16_t tmr_toggle; // right-aligned 10-bit high time within 4*tmr_period+4

    uint8_t mode = NO_MODE_SELECTED; // turning knob won't set freq or duty yet

    // initialize the device
    SYSTEM_Initialize();

    set_current_limit(6, 0xff);
    set_current_limit(7, 0xff);

    set_parameter(FREQ_ADJUST_MODE, 0x8000, (void*)0, &tmr_period); // mid-range
    set_parameter(DUTY_ADJUST_MODE, 0x8000, &tmr_toggle, &tmr_period); // 50%

    while (1) {
      uint16_t knob_pos;

      if (!S1PRESS_N_PORT) // S1 pressed
	mode = FREQ_ADJUST_MODE;

      else if (!S2PRESS_N_PORT) // S2 pressed
	mode = DUTY_ADJUST_MODE;
	  
      knob_pos = read_adc(TRIMPOT);
      set_parameter(mode, knob_pos, &tmr_toggle, &tmr_period);
    }
}
