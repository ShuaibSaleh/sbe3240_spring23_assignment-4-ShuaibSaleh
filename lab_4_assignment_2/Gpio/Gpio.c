/*
 *  	Name: Shuaib Abdulsalam Ahmed Aklan Saleh
 *      Sec: 1
 *      B.N.: 48
 */

#include "Gpio.h"
#include "Std_Types.h"
#include "Gpio_Private.h"


void GPIO_ConfigPin(uint8 PortName, uint8 PinNum, uint8 PinMode,uint8 DefaultState) {

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
				  GPIOA_PUPDR &= ~(0x03 << (PinNum * 2)) ;
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
					  GPIOB_PUPDR &= ~(0x03 << (PinNum * 2)) ;
					  GPIOB_PUPDR |= (DefaultState << (PinNum * 2)) ;
					  break;

					default:
					  break;
					}
         break;



    case GPIO_C:
      GPIOC_MODER &= ~(0x03 << (PinNum * 2));
      GPIOC_MODER |= (PinMode << (PinNum * 2));

			  switch(PinMode){

					case GPIO_OUTPUT:
					  GPIOC_OTYPER &= ~(0x01 << PinNum);
					  GPIOC_OTYPER |= (DefaultState << PinNum);
					  break;

					case GPIO_INPUT:
					  GPIOC_PUPDR &= ~(0x03 << (PinNum * 2)) ;
					  GPIOC_PUPDR |= (DefaultState << (PinNum * 2)) ;
					  break;

					default:
					  break;
					}
        break;

    case GPIO_D:

      GPIOD_MODER &= ~(0x03 << (PinNum * 2));
      GPIOD_MODER |= (PinMode << (PinNum * 2));

			  switch(PinMode){

					case GPIO_OUTPUT:
					  GPIOD_OTYPER &= ~(0x01 << PinNum);
					  GPIOD_OTYPER |= (DefaultState << PinNum);
					  break;

					case GPIO_INPUT:
					  GPIOD_PUPDR &= ~(0x03 << (PinNum * 2)) ;
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









void GPIO_WritePin( uint8 PortName, uint8 PinNum , uint8 Data)

{


//        switch (portName)
//        {
//        case GPIO_A:
//        	if (((GPIOA_MODER&(0x03<<(pinNumber*2)))>>(pinNumber*2))==GPIO_OUTPUT){
//
//                GPIOA_ODR &=~(1<<pinNumber);
//                GPIOA_ODR |=Data<<pinNumber;
//
////                return OK ;
//
//        	}
//        	else{
////        		return NOK ;
//        	}
//                break;
//
//        case GPIO_B:
//        	if (((GPIOB_MODER&(0x03<<(pinNumber*2)))>>(pinNumber*2))==GPIO_OUTPUT){
//                GPIOB_ODR &=~(1<<pinNumber);
//                GPIOB_ODR |=Data<<pinNumber;
////                return OK ;
//        	}
//        	else{
////        		return NOK ;
//        	}
//                break;
//
//
//        case GPIO_C:
//        	if (((GPIOC_MODER&(0x03<<(pinNumber*2)))>>(pinNumber*2))==GPIO_OUTPUT){
//                GPIOC_ODR &=~(1<<pinNumber);
//                GPIOC_ODR |=Data<<pinNumber;
////                return OK ;
//        	}
//        	else{
////        		return NOK ;
//        	}
//                break;
//        case GPIO_D:
//        	if (((GPIOD_MODER&(0x03<<(pinNumber*2)))>>(pinNumber*2))==GPIO_OUTPUT){
//                GPIOD_ODR &=~(1<<pinNumber);
//                GPIOD_ODR |=Data<<pinNumber;
////                return OK ;
//        	}
//        	else{
////        		return NOK ;
//        	}
//
//                break;
//
//        default:
////        	return NOK ;
//                break;
//        }


        if( (GPIOA_MODER&(1<<PinNum*2)) || (GPIOB_MODER&(1<<PinNum*2))
        	 ){


          switch (PortName) {
            case GPIO_A:
              GPIOA_ODR &= ~(0x1 << PinNum);
              GPIOA_ODR |= (Data << PinNum);
              break;
            case GPIO_B:
//            	GPIOB_ODR &=~(1<<PinNum);
//            	                GPIOB_ODR |=Data<<PinNum;
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


}



uint8 GPIO_ReadPin( uint8 portName  , uint8 pinNumber) {


	switch (portName) {
		case GPIO_A:
			if(((GPIOA_IDR &(1<<pinNumber))>>pinNumber)==1){
				return 1;

			}
			else {
				return 0 ;
			}
			break ;
		case GPIO_B:
			if(((GPIOB_IDR &(1<<pinNumber))>>pinNumber)==1){
				return 1;

			}
			else {
				return 0 ;
			}
			break ;
		case GPIO_C:
			if(((GPIOC_IDR &(1<<pinNumber))>>pinNumber)==1){
				return 1;

			}
			else {
				return 0 ;
			}

			break ;

		case GPIO_D:
			if(((GPIOD_IDR &(1<<pinNumber))>>pinNumber)==1){
				return 1;

			}
			else {
				return 0 ;
			}

			break;


		default:
			return 0;
			break;
	}

}





