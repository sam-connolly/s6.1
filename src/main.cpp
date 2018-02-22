#include <mbed.h>
#include <rtos.h>
#include <mbed_events.h>

Serial pc(USBTX, USBRX);
Thread worker;
EventQueue queue ;

DigitalOut red(LED_RED,1); /* initial state 1 led is off */
DigitalOut blue(LED_BLUE,1); /* initial state 1 led is off */
DigitalOut green(LED_GREEN,1); /* initial state 1 led is off */

void flash_red(void)
{
    red.write(0);
    wait(0.5);
    red.write(1);
}

void flash_blue(void)
{
    blue.write(0);
    wait(0.5);
    blue.write(1);
}

void flash_green(void)
{
    green.write(0);
    wait(0.5);
    green.write(1);
}

int main()
{

    // put your setup code here, to run once:
    worker.start( flash_red );

    while(1)
    {
        flash_red();
        wait(0.5);

        flash_blue();
        wait(0.5);

        flash_green();
        wait(0.5);
    }
}
