#include "pico/stdlib.h"

static constexpr uint LED_PIN = 25; // built-in LED on pin 25

int main()
{
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) {
        gpio_put(LED_PIN, 1);
        sleep_ms(400);
        gpio_put(led, 0);
        sleep_ms(400);      
    }
}
