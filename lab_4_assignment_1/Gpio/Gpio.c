/*
 *  	Name: Shuaib Abdulsalam Ahmed Aklan Saleh
 *      Sec: 1
 *      B.N.: 48
 */

#include "Gpio.h"

#include "Gpio_Private.h"
#include "Utils.h"

void Gpio_ConfigPin(uint8 PortName, uint8 PinNum, uint8 PinMode,
                    uint8 DefaultState) {
  switch (PortName) {
    case GPIO_A:
      GPIOA_MODER &= ~(0x03 << (PinNum * 2));
      GPIOA_MODER |= (PinMode << (PinNum * 2));

      switch(PinMode){

      case GPIO_OUTPUT:
    	  GPIOA_OTYPER &= ~(0x01 << PinNum);
    	  GPIOA_OTYPER |= (DefaultState << PinNum);
    	  break;

      case GPIO_INPUT:
//    	  GPIOA_PUPDR &= ~(0x03 << (PinNum * 2)) ;
    	  GPIOA_PUPDR |= (DefaultState << (PinNum * 2)) ;
    	  break;

      default:
    	  break;
      }
      break;

    case GPIO_B:
      GPIOB_MODER &= ~(0x03 << (PinNum * 2));
      GPIOB_MODER |= (PinMode << (PinNum * 2));

      switch(PinMode){

            case GPIO_OUTPUT:
          	  GPIOB_OTYPER &= ~(0x01 << PinNum);
          	  GPIOB_OTYPER |= (DefaultState << PinNum);
          	  break;

            case GPIO_INPUT:
//          	  GPIOB_PUPDR &= ~(0x03 << (PinNum * 2)) ;
          	  GPIOB_PUPDR |= (DefaultState << (PinNum * 2)) ;
          	  break;

            default:
          	  break;
            }
            break;

    case GPIO_C:
      // TODO:
      GPIOC_MODER &= ~(0x03 << (PinNum * 2));
      GPIOC_MODER |= (PinMode << (PinNum * 2));

      switch(PinMode){

            case GPIO_OUTPUT:
          	  GPIOC_OTYPER &= ~(0x01 << PinNum);
          	  GPIOC_OTYPER |= (DefaultState << PinNum);
          	  break;

            case GPIO_INPUT:
//          	  GPIOC_PUPDR &= ~(0x03 << (PinNum * 2)) ;
          	  GPIOC_PUPDR |= (DefaultState << (PinNum * 2)) ;
          	  break;

            default:
          	  break;
            }
            break;

    case GPIO_D:
      // TODO:
      GPIOD_MODER &= ~(0x03 << (PinNum * 2));
      GPIOD_MODER |= (PinMode << (PinNum * 2));

      switch(PinMode){

            case GPIO_OUTPUT:
          	  GPIOD_OTYPER &= ~(0x01 << PinNum);
          	  GPIOD_OTYPER |= (DefaultState << PinNum);
          	  break;

            case GPIO_INPUT:
//          	  GPIOD_PUPDR &= ~(0x03 << (PinNum * 2)) ;
          	  GPIOD_PUPDR |= (DefaultState << (PinNum * 2)) ;
          	  break;

            default:
          	  break;
            }
            break;
    default:
      break;
  }
}

void Gpio_WritePin(uint8 PortName, uint8 PinNum, uint8 Data) {

 //TODO: check if the pin is output

if( (GPIOA_MODER&(1<<PinNum*2)) || (GPIOB_MODER&(1<<PinNum*2))
	|| (GPIOC_MODER&(1<<PinNum*2)) || (GPIOD_MODER&(1<<PinNum*2)) ){

   
  switch (PortName) {
    case GPIO_A:
      GPIOA_ODR &= ~(0x1 << PinNum);
      GPIOA_ODR |= (Data << PinNum);
      break;
    case GPIO_B:
      GPIOB_ODR &= ~(0x1 << PinNum);
      GPIOB_ODR |= (Data << PinNum);
      break;
    case GPIO_C:
      // TODO:
      GPIOC_ODR &= ~(0x1 << PinNum);
      GPIOC_ODR |= (Data << PinNum);
      // DONE
      break;
    case GPIO_D:
      // TODO:
      GPIOD_ODR &= ~(0x1 << PinNum);
      GPIOD_ODR |= (Data << PinNum);
      // DONE
      break;
    default:
      break;
  }

  }
 // DONE
}

/*ReadPin function*/
uint8 Gpio_ReadPin(uint8 PortName, uint8 PinNum){

	uint8 x = 0;


			 switch(PortName){

			 case GPIO_A:

				 x =((GPIOA_IDR&(1<<PinNum))>> PinNum);

				 break;

			 case GPIO_B:

				 x=((GPIOB_IDR&(1<<PinNum))>> PinNum);

				 break;

			 case GPIO_C:

				 x=((GPIOC_IDR&(1<<PinNum))>> PinNum);

				 break;

			 case GPIO_D:

				 x=((GPIOD_IDR&(1<<PinNum))>> PinNum);

				 break;

			 default:
				 x = 0;
			   break;
		 }


	return x;
}

//DONE
