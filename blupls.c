/* blupls - A functional stub for developing an MCU project for the
 *          STM32F103 "Blue Pill" development board.
 *
 * Build using FreeRTOS and libopencm3. This code includes a
 * "heartbeat" RTOS task as a debugging element: if the PC13 LED is
 * flashing, then the MCU core is running.
 *
 * Written by Nathaniel Berners.
 *
 * No licence requirements, completely free and open to use for
 * whatever purpose is required.
 */

/*** FreeRTOS Includes ***********************************************
 *********************************************************************/
#include <FreeRTOS.h>
#include <task.h>

/*** libopencm3 Includes *********************************************
 *********************************************************************/
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

/*** Local Includes **************************************************
 *********************************************************************/

/*** Definitions *****************************************************
 *********************************************************************/
#define LEDhb   GPIO13

/*** Preprocessor Declarations ***************************************
 *********************************************************************/

/*** Function Prototypes *********************************************
 *********************************************************************/
static void init( void );
static void tHeartBeat( void* );
int main( void );

/*** Device System Initialisation ************************************
 *********************************************************************/
static void init() {
    // Clock Enable
    rcc_clock_setup_pll( &rcc_hse_configs[ RCC_CLOCK_HSE8_72MHZ] );

    // GPIOA Setup

    // GPIOB Setup

    // GPIOC Setup
    rcc_periph_clock_enable( RCC_GPIOC );
    gpio_set_mode( GPIOC, GPIO_MODE_OUTPUT_2_MHZ,
        GPIO_CNF_OUTPUT_PUSHPULL,
        LEDhb );
}

/*** FreeRTOS Tasks **************************************************
 *********************************************************************/

// tHeartBeat - A heartbeat task to show the MCU core is running
static void tHeartBeat( void *args __attribute__((unused)) ) {
    for(;;) {
        // Toggle PC13 off for 990ms
        gpio_toggle( GPIOC, LEDhb );
        vTaskDelay( pdMS_TO_TICKS( 990 ) );
        // Toggle PC13 on for 10ms
        gpio_toggle( GPIOC, LEDhb );
        vTaskDelay( pdMS_TO_TICKS( 10 ) );
    }
}

/*** Main Program Run ************************************************
 *********************************************************************/
int main() {
    // Run Device Initialisation
    init();

    // Create FreeRTOS Tasks
    xTaskCreate( tHeartBeat,
        "HeartBeat", 100, NULL, configMAX_PRIORITIES-1, NULL );

    // Start FreeRTOS Scheduler & INFINATE LOOP
    vTaskStartScheduler();
    for(;;);

    // Exit Here In Event Of Fire
    return 0;
}
