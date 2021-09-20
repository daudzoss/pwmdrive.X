#include "mcc_generated_files/mcc.h"
#include "stdint.h"

#define NO_MODE_SELECTED 0
#define FREQ_ADJUST_MODE 1
#define DUTY_ADJUST_MODE 2

void read_adc(int8_t* lbyte, uint8_t* hbyte)
{
  adc_result_t convertedValue;

//  ADCC_StartConversion(TRIMPOT);
//  while (!ADCC_IsConversionDone())
//    ;

  convertedValue = ADCC_GetConversionResult();
  *lbyte = convertedValue & 0xff;
  *hbyte = convertedValue >> 8;
}

void set_parameter(uint8_t parm, uint8_t lbyte, uint8_t hbyte)
{
  switch (parm) {
  case FREQ_ADJUST_MODE:

    break;
    
  case DUTY_ADJUST_MODE:

    break;

  case NO_MODE_SELECTED:
  default:
    return;
  }
}

/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    uint8_t mode = NO_MODE_SELECTED;
    uint8_t adc_lbyte, adc_hbyte;

    while (1) {
      if (S1PORT & S1MASK == 0) // S1 pressed
	mode = FREQ_ADJUST_MODE;

      else if (S2_PORT & S2MASK == 0) // S2 pressed
	mode = DUTY_ADJUST_MODE;
	  
      read_adc(&adc_lbyte, &adc_hbyte);
      set_parameter(mode, adc_lbyte, adc_hbyte);
    }
}
