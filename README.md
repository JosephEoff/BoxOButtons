# BoxOButtons

A simple Arduino program to read up to 10 buttons and send the state to a PC over the USB port.

This program reads the digital IO pins 2 to 12 and sends any changed state to the PC using a very simple protocol.

Each message consists of the pin number, a colon, and the state of the pin.

Digital IO pin 2 low:
2:0

Digital IO pin 10 changed to high:
10:1

The inputs are all debounced using a hardcoded timeout.  The timeout can be easily changed in code.  The timeout is the same for all pins.

It only does digital IO pins 2 to 12 because 0 and 1 are used for the serial connection to the USB adapter.  Digital IO pin 13 is normally used for the power on LED on the Arduino, so I skipped it too.
