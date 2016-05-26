/*******************************************************************************
  * @file    Src/main.c 
  * @author  Luong Hoan Tien
  * @version V1.0
  * @date    May-2016
  * @brief   Main program body
  ******************************************************************************/
  
/* Includes ------------------------------------------------------------------*/
#include "main.h"

extern UART_HandleTypeDef UartHandle;
__IO ITStatus UartReady = RESET;

/* Buffer used for transmission */
uint8_t aTxBuffer[] = " ****UART_TwoBoards_ComIT****  ****UART_TwoBoards_ComIT****  ****UART_TwoBoards_ComIT**** ";

/* Buffer used for reception */
uint8_t aRxBuffer[RXBUFFERSIZE];

int main(void)
{
  HAL_Init();  
  /* Configure the System clock to 84 MHz */
  SystemClock_Config();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	gpio_init();
	UART_init();
	printf("\rttttttt\n");
  while (1)
  {   
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
    HAL_Delay(500); //100ms
  }
}
/***************************** END OF FILE *************************************/
