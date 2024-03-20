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

#include "stdint.h"
// APIs required

// create and initialise GPIO -input

void GPIO_Init(GPIO_Handle_t *handle);
// create and initialise HW timer

void HW_Timer_init(HW_Timer_t *timer, int32_t period, timer_mode_t mode);
// set up interrupts

void GPIO_SetUpInterrupt(GPIO_Handle_t *handle, gpio_interrupt_mode_t mode, uint16_t priority);
void HW_TimerSetUpInterrupt(HW_Timer_t *handle);
// enable and disable interrupts

void HW_TimerEnable(HW_Timer_t *handle);
void HW_TimerDisable(HW_Timer_t *handle);

void GPIO_InterruptDisable(GPIO_Handle_t *handle);
void GPIO_InterruptEnable(GPIO_Handle_t *handle);

#define GPIO_PULL_UP 1
#define GPIO_PULL_DOWN 0
#define GPIOx 0xAF2398
#define DEFAULT_STATE
#define TIM1 0x3ADDFEDD
#define BAUDRATE 9600
#define STOP_BIT_CNT 1
#define ODD_PARITY_CHECK 0
#define EVEN_PARITY_CHECK 0
#define PARITY_NONE 1
#define FIFO_DEPTH 8

// states and defines
typedef enum timer_mode
{
    oneshot,
    periodic
} timer_mode_t;

typedef enum io_mode
{
    input,
    output,
    inout,
} timer_mode_t;

typedef enum gpio_interrupt_mode
{
    rising,
    falling
} gpio_interrupt_mode_t;

// handles for GPIO and Timer
typedef struct GPIO_Handle
{
    uint32_t base_address;
    uint16_t io_mode;
    uint8_t default_state;
    uint8_t pull;
    void (*callback)(void *ctx);
} GPIO_Handle_t;

typedef struct HW_Timer
{
    uint32_t base_address;
    uint16_t period;
    timer_mode_t mode;
    void (*callback)(void *ctx);
} HW_Timer_t;

// global variables
uint8_t byte = 0; // received byte
uint8_t readbuffer[FIFO_DEPTH];
uint8_t complete_read = 0;
uint8_t start = 0;
uint8_t stop=STOP_BIT_CNT;
uint8_t bit_count = 0;
// callbacks and prototypes
uint8_t GPIO_ReadPin(GPIO_Handle_t *handle);

void GPIOx_Interrupt_handler(GPIO_Handle_t *handle);
void HW_Timer_Handler(HW_Timer_t *handle);

uint8_t count_bits(uint8_t num){
    uint8_t cnt=0;
    while(num){
        cnt++;
        num = num & (num-1);
    }
    return cnt;
}
// handles
GPIO_Handle_t UART1 = {.io_mode = input, .base_address = GPIOx, .callback = GPIOx_Interrupt_handler, .pull = GPIO_PULL_UP};
HW_Timer_t timer = {
    .base_address = TIM1,
    .callback = HW_Timer_Handler,
    .mode = oneshot,
    .period = 1 / BAUDRATE * 1000 // ms
};

void GPIOx_Interrupt_handler(GPIO_Handle_t *handle)
{
    // first interrupt is the start bit
    HW_TimerEnable(&timer);
    GPIO_InterruptDisable(UART1);
}

void GPIOx_Interrupt_handler_Rising(GPIO_Handle_t *handle){
    static uint8_t i;
    i++;
    if(i> FIFO_DEPTH){
        i=0;
        return;
    }
    readbuffer[i] = byte;
    UART_Receive(byte);

}

void UART_Receive(uint8_t byte){
    printf("%s", byte);
}

void HW_Timer_Handler(HW_Timer_t *handle)
{
    if (start == 0)
    {
        // start bit ignore
        start = 1;
        HW_TimerEnable(&timer);
        return;
    }
    // bit 1-8 data bits
    if(bit_count<8)
    {
        byte |= GPIO_ReadPin(&UART1) << bit_count;
        bit_count++;
    }else{
        byte = 0;
        start = 0;
    }

    // Parity checks
    if(!count_bits(byte)%2){
        // parity check failed. handle
        byte=0; // discard the data
    }

    if(bit_count >= 8 && --stop ==0){
        bit_count =0;
        stop = STOP_BIT_CNT;
        HW_TimerDisable(&timer);
        GPIO_InterruptEnable(&UART1);
        return; 
    }
    HW_TimerEnable(&timer);
}

typedef void (*gpio_interrupt_cb)(void*ctx);
typedef void (*hw_timer_cb)(void *ctx);

void UARTx_Init(HW_Timer_t *timer, GPIO_Handle_t *gpio_handle, gpio_interrupt_cb gpio_cb, hw_timer_cb timer_cb){
    
}



// task // main thread

static void uart_task(void *arg)
{

    // setup interrupts
    GPIO_SetUpInterrupt(UART1, falling, 5);
    HW_TimerSetUpInterrupt(timer);

    // start timers
    GPIO_InterruptEnable(&UART1);
    HW_TimerDisable(&timer);

    while (1)
    {
    }
}
