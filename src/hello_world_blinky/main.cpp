#include "pico/stdlib.h"

static constexpr uint led = 25; // built-in LED on pin 25

int main(int argc, char *argv[])
{
    gpio_init(led);
    gpio_set_dir(led, GPIO_OUT);

    while (true) {
        gpio_put(led, 1);
        sleep_ms(400);
        gpio_put(led, 0);
        sleep_ms(400);      
    }
    return 0;
}
