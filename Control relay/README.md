# Relay Control with Arduino and LCD

This program controls a relay using an Arduino board and displays the relay status on an LCD.

## Hardware Requirements

- Arduino board
- Relay module
- LCD display
- Jumper wires

## Circuit Setup

1. Connect the Arduino pins to the corresponding LCD pins:
   - Arduino pin 12 (rs) to LCD pin rs
   - Arduino pin 11 (en) to LCD pin en
   - Arduino pin 5 (d4) to LCD pin d4
   - Arduino pin 4 (d5) to LCD pin d5
   - Arduino pin 3 (d6) to LCD pin d6
   - Arduino pin 2 (d7) to LCD pin d7
2. Connect the relay module control pin to Arduino pin 6.

## Code Explanation

The code uses the LiquidCrystal library to control the LCD display. It defines the Arduino pins connected to the LCD and creates an object of type LiquidCrystal. The `setup()` function initializes the program by configuring the relay pin as an output, initializing the LCD display, and opening the serial console. The `controlRelay()` function controls the relay state and displays the status on the LCD and serial console. Finally, the `loop()` function repeatedly turns the relay on and off with a delay of 5 seconds between each state change.

## Usage

1. Connect the Arduino board to your computer.
2. Upload the code to the Arduino board using the Arduino IDE or any other compatible software.
3. Open the serial console to view the relay status.
4. The relay will turn on for 5 seconds and then turn off for 5 seconds repeatedly.
