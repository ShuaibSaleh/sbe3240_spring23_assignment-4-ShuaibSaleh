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
    GPIO_ConfigPin(GPIO_B, i, GPIO_OUTPUT, GPIO_PUSH_PULL);
  }
  GPIO_ConfigPin(GPIO_B, 3, GPIO_INPUT,GPIO_PULL_UP);

  int counter = 0;
  uint8 flag = 0;
  uint8 red = 5;
  uint8 green = 6;
  uint8 blue = 7;

  
  while (1) {

	/* check the input button then apply delay
	   then check again for the denouncing feature*/
     if (GPIO_ReadPin(GPIO_B, 3)){
//     if (GPIOB_IDR&(1<<3)){
        flag=0;



     }
     for (int i = 0; i < 16000; i++)
                 	     {

				 }
		 if (GPIO_ReadPin(GPIO_B, 3)){
		//     if (GPIOB_IDR&(1<<3)){
				flag=0;

			 }

     else{


        if (counter < 7 && flag == 0){
        counter++;
        flag = 1;
        }

        if (counter >= 7 && flag == 0){
                counter=-1;
                }

     }

	switch (counter)
	{
	case 0:
		GPIO_WritePin(GPIO_B, red, LOW);
		GPIO_WritePin(GPIO_B, green, LOW);
		GPIO_WritePin(GPIO_B, blue, LOW);
		break;
	
	case 1:
		GPIO_WritePin(GPIO_B, red, HIGH);
		GPIO_WritePin(GPIO_B, green, LOW);
		GPIO_WritePin(GPIO_B, blue, LOW);
		break;

	
	case 2:
		GPIO_WritePin(GPIO_B, red, LOW);
		GPIO_WritePin(GPIO_B, green, HIGH);
		GPIO_WritePin(GPIO_B, blue, LOW);
		break;



	 case 3:
		GPIO_WritePin(GPIO_B, red, LOW);
		GPIO_WritePin(GPIO_B, green, LOW);
		GPIO_WritePin(GPIO_B, blue, HIGH);
		break;


	 case 4:
		GPIO_WritePin(GPIO_B, red, HIGH);
		GPIO_WritePin(GPIO_B, green, HIGH);
		GPIO_WritePin(GPIO_B, blue, LOW);
		break;


	 case 5:
		GPIO_WritePin(GPIO_B, red, HIGH);
		GPIO_WritePin(GPIO_B, green, LOW);
		GPIO_WritePin(GPIO_B, blue, HIGH);
		break;



	 case 6:
		GPIO_WritePin(GPIO_B, red, LOW);
		GPIO_WritePin(GPIO_B, green, HIGH);
		GPIO_WritePin(GPIO_B, blue, HIGH);
		break;


	 case 7:
		GPIO_WritePin(GPIO_B, red, HIGH);
		GPIO_WritePin(GPIO_B, green, HIGH);
		GPIO_WritePin(GPIO_B, blue, HIGH);
		break;


//	 case 8:
//		GPIO_WritePin(GPIO_B, red, LOW);
//		GPIO_WritePin(GPIO_B, green, LOW);
//		GPIO_WritePin(GPIO_B, blue, LOW);
//		break;


	

	default:
//		counter = 0;
//		flag = 0;
		break;
	}





  }


  return 0;
}
