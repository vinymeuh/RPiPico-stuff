# Raspberry Pi Pico stuffs

Access to USB console:

```
minicom -b 115200 -D /dev/ttyACM0
```

## RESET button

Wire one button pin to GND (Pico pin 38 for example) and the other to RUN (Pico pin 30).

![RPi Pico reset button](images/rpipico-reset-button.png)

## Miscalleneaous

* [KiCad RPi Pico Library](https://github.com/ncarandini/KiCad-RP-Pico)
