#include "mcc_generated_files/mcc.h"
#include "stdint.h"

#define NO_MODE_SELECTED (0)
#define FREQ_ADJUST_MODE (1)
#define DUTY_ADJUST_MODE (2)

void read_adc(uint16_t* convertedValue)
{
//  ADCC_StartConversion(TRIMPOT);
//  while (!ADCC_IsConversionDone())
//    ;

  *convertedValue = (uint16_t) ADCC_GetConversionResult();
}

void set_parameter(uint8_t parm, uint16_t new_value, uint16_t* tau, uint8_t* T)
{
  switch (parm) {

  case FREQ_ADJUST_MODE:
    new_value = 0xffff - new_value; // CW turn = higher frequency (lower period)
    *T = new_value >> 8;
    TMR6_Stop();
    TMR7_Stop();
    TMR6_LoadPeriodRegister(*T);
    TMR7_LoadPeriodRegister(*T);
    TMR6_Start();
    TMR7_Start();
    break;
    
  case DUTY_ADJUST_MODE: // 8+16-14=10-bit right justified: uint8_t*uint16_t>>14
    *tau = ((*T) * new_value) >> 14; // CW turn = higher duty cycle (higher tau)
    PWM6_LoadDutyValue(*tau);
    PWM7_LoadDutyValue(*tau);
    break;

  case NO_MODE_SELECTED:
  default:
    return;
  }

  LED5_LAT = (new_value & 0x8000) ? 1 : 0;
  LED4_LAT = (new_value & 0x4000) ? 1 : 0;
  LED3_LAT = (new_value & 0x2000) ? 1 : 0;
  LED2_LAT = (new_value & 0x1000) ? 1 : 0;
  return;
}

void main(void)
{
    uint8_t tmr_period; // 8-bit counter shared by positive PWM6, negative PWM7
    uint16_t tmr_toggle; // left-aligned 10-bit timestamp within 4*tmr_period+4

    uint8_t mode = NO_MODE_SELECTED; // turning knob won't set freq or duty yet

    // initialize the device
    SYSTEM_Initialize();

    // Disable the Global Interrupts
    INTERRUPT_GlobalInterruptDisable();

    set_parameter(FREQ_ADJUST_MODE, 0x8000, (void*)0, &tmr_period); // mid-range
    set_parameter(DUTY_ADJUST_MODE, 0x8000, &tmr_toggle, &tmr_period); // 50%

    while (1) {
      uint16_t knob_pos;

      if (!S1PRESS_N_PORT) // S1 pressed
	mode = FREQ_ADJUST_MODE;

      else if (!S2PRESS_N_PORT) // S2 pressed
	mode = DUTY_ADJUST_MODE;
	  
      read_adc(&knob_pos);
      set_parameter(mode, knob_pos, &tmr_toggle, &tmr_period);
    }
}
