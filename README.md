blupls is a simple, functional C stub for beginning to build an MCU
project with the "Blue Pill" development board running an ARM
Cortex-M3 MCU by ST Microelectronics; specifically, the STM32F103C8T6.

This has been developed for use with GCC and Makefiles, and depends on
the FreeRTOS and libopencm3 projects.

On its own, blupls runs the user LED of the Blue Pill (GPIO13, or PC13,
on port GPIOC), flashing it for 10ms on/990ms off as a "heartbeat" to
indicate the running of the MCU core. This is useful for showing simply
that your new Blue Pill is working, or as a simple debugging step:
If the heartbeat is running, the core is running.
If the heartbeat has stopped, the core has crashed.

Use blupls as the basis for your next project, and no longer worry
about writing the basics...again.
