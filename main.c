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
    *T = (0xffff - new_value) >> 8; // CW turn = higher freq. (lower T)
    TMR6_Stop();
    TMR7_Stop();
    TMR6_LoadPeriodRegister(*T);
    TMR7_LoadPeriodRegister(*T);
    TMR6_Start();
    TMR7_Start();
    break;
    
  case DUTY_ADJUST_MODE:
    *tau = ((uint32_t)(*T) * (uint32_t)new_value) >> 8; // CW turn = higher tau
    PWM6_LoadDutyValue(*tau);
    PWM7_LoadDutyValue(*tau);
    break;

  case NO_MODE_SELECTED:
  default:
    break;
  }
  return;
}

/*
                         Main application
 */
void main(void)
{
    uint8_t tmr_period; // 8-bit timer counter
    uint16_t tmr_toggle; // left-aligned 10-bit timestamp within 4*tmr_period+4

    // initialize the device
    SYSTEM_Initialize();

    // Disable the Global Interrupts
    INTERRUPT_GlobalInterruptDisable();

    set_parameter(FREQ_ADJUST_MODE, 0x8000, (void*)0, &tmr_period); // mid-range
    set_parameter(DUTY_ADJUST_MODE, 0x8000, &tmr_toggle, &tmr_period); // 50%

    uint8_t mode = NO_MODE_SELECTED; // turning knob won't set freq or duty yet

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
