#include <iostream>
#include "pico/stdlib.h"
#include "hardware/adc.h"

const float ADC_VREF = 3.3;
const float conversion_factor = ADC_VREF / (1 << 12); // ADC 12 bit

int main()
{
    stdio_init_all();

    adc_init();
    adc_set_temp_sensor_enabled(true);
    adc_select_input(4); // User ADC inputs are on 0-3 (GPIO 26-29), the temperature sensor is on input 4.

    while (true) {
        double adc_voltage = adc_read() * conversion_factor;
        // Formula from the Pico C/C++ SDK manual, page 70 (hardware_adc)
        double temperature = 27.0 - (adc_voltage - 0.706)/0.001721;
        std::cout << temperature << "\n";
        sleep_ms(5000);
    }
    
}