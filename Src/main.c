/*******************************************************************************
  * @file    Src/main.c 
  * @author  Luong Hoan Tien
  * @version V1.0
  * @date    May-2016
  * @brief   Main program body
  ******************************************************************************/
  
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#define SIZE 10

extern UART_HandleTypeDef UartHandle;

/* Buffer used for reception */
char aRxBuffer[SIZE];
char *buf = aRxBuffer;

int main(void)
{
	int i=0;
  HAL_Init();  
  /* Configure the System clock to 84 MHz */
  SystemClock_Config();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	gpio_init();
	UART_init();
	printf("\rttttttt\n");
  while (1)
  {
			HAL_UART_Receive_IT(&UartHandle,(uint8_t*) buf, SIZE);
			i=strlen(buf);

			printf("\r%s\n",buf);
			printf("\r%d\n", i);
			HAL_Delay(500); //500ms

  }
}
/***************************** END OF FILE *************************************/
