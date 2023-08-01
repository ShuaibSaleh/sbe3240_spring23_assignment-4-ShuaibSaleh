/*
 *  	Name: Shuaib Abdulsalam Ahmed Aklan Saleh
 *      Sec: 1
 *      B.N.: 58
 */

#include "Gpio.h"
#include "Rcc.h"
#include "Std_Types.h"

int main() {
  Rcc_Init();
  Rcc_Enable(RCC_GPIOB);

  uint32 i ;
  for (i = 5; i < 8; i++) {
    Gpio_ConfigPin(GPIO_B, i, GPIO_OUTPUT, GPIO_PUSH_PULL);
  }
  Gpio_ConfigPin(GPIO_B, 3, GPIO_INPUT,GPIO_PULL_UP);

  uint8 counter = 0;
  uint8 flag = 0;
  uint8 red = 5;
  uint8 green = 6;
  uint8 blue = 7;


  while (1) {

	/* check the input button then apply delay
	   then check again for the denouncing feature*/
//     if (Gpio_ReadPin(GPIO_B, 3)&1){
//        flag=0;
//
//     }
//
//     for (int j = 0; j < 1000000; j++)
//     {
//
//     }

     if (Gpio_ReadPin(GPIO_B,3)&1){
        flag=0;

     }

     else{
        if (counter >= 8 && flag == 0){
        counter=0;
        }

        if (counter < 8 && flag == 0){
        counter++;
        flag = 1;
        }

     }


     switch (counter){

	case 0:
		Gpio_WritePin(GPIO_B, red, LOW);
		Gpio_WritePin(GPIO_B, green, LOW);
		Gpio_WritePin(GPIO_B, blue, LOW);

		break;
	
	case 1:
		Gpio_WritePin(GPIO_B, red, HIGH);
		Gpio_WritePin(GPIO_B, green, LOW);
		Gpio_WritePin(GPIO_B, blue, LOW);
		break;


	case 2:
		Gpio_WritePin(GPIO_B, red, LOW);
		Gpio_WritePin(GPIO_B, green, HIGH);
		Gpio_WritePin(GPIO_B, blue, LOW);
		break;



	 case 3:
		Gpio_WritePin(GPIO_B, red, LOW);
		Gpio_WritePin(GPIO_B, green, LOW);
		Gpio_WritePin(GPIO_B, blue, HIGH);
		break;


	 case 4:
		Gpio_WritePin(GPIO_B, red, HIGH);
		Gpio_WritePin(GPIO_B, green, HIGH);
		Gpio_WritePin(GPIO_B, blue, LOW);
		break;


	 case 5:
		Gpio_WritePin(GPIO_B, red, HIGH);
		Gpio_WritePin(GPIO_B, green, LOW);
		Gpio_WritePin(GPIO_B, blue, HIGH);
		break;



	 case 6:
		Gpio_WritePin(GPIO_B, red, LOW);
		Gpio_WritePin(GPIO_B, green, HIGH);
		Gpio_WritePin(GPIO_B, blue, HIGH);
		break;


	 case 7:
		Gpio_WritePin(GPIO_B, red, HIGH);
		Gpio_WritePin(GPIO_B, green, HIGH);
		Gpio_WritePin(GPIO_B, blue, HIGH);
		break;


	 case 8:
		Gpio_WritePin(GPIO_B, red, LOW);
		Gpio_WritePin(GPIO_B, green, LOW);
		Gpio_WritePin(GPIO_B, blue, LOW);
		break;




	default:
		counter = 0;
		flag = 0;
		break;
	}




  }


  return 0;
}
