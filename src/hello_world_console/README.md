# hello_world_console

## UART

By default Pi Pico use UART0 as target console.

Using a USBtoSerial PL2303 cable:

* pin0/TX with the white wire
* pin1/RX with the green wire

Then:

```
minicom -b 115200 -D /dev/ttyUSB0
```

## USB

Redirect console to USB using ```ENABLE_USB_CONSOLE``` cmake option.

```
cmake .. -DENABLE_USB_CONSOLE=ON
```

Then:

```
minicom -b 115200 -D /dev/ttyACM0
```
