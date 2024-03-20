/**
 * @file soft_uart.cpp
 * @author Stanley Ezeh (ezeh.stanley.es@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <cstdint>
// APIs required

// create and initialise GPIO -input

void GPIO_Init(GPIO_Handle_t *handle);
// create and initialise HW timer

void HW_Timer_init(HW_Timer_t *timer, int32_t period, timer_mode_t mode);
// set up interrupts

void GPIO_SetUpInterrupt(GPIO_Handle_t *handle, gpio_interrupt_mode_t mode, uint16_t priority);
// enable and disable interrupts

void HW_TimerEnable(HW_Timer_t *handle);
void HW_TimerDisable(HW_Timer_t *handle);

void GPIO_InterruptDisable(GPIO_Handle_t *handle);
void GPIO_InterruptEnable(GPIO_Handle_t *handle);


// states and defines
typedef enum timer_mode{

}timer_mode_t;

typedef enum gpio_interrupt_mode{

}gpio_interrupt_mode_t;

// handles for GPIO and Timer
typedef struct GPIO_Handle{

}GPIO_Handle_t;

typedef struct HW_Timer{

}HW_Timer_t;

// global variables
uint8_t byte=0;  // received byte
uint8_t complete_read=0;

// handles
GPIO_Handle_t UART1 ={};
UART1.




