# LCD and LED Color Cycling

This code controls an LCD display and three LEDs (red, yellow, and green) using an Arduino board. The LEDs cycle through different colors, and the corresponding color is displayed on the LCD.

## Hardware Requirements

- Arduino board
- LCD display
- Three LEDs (red, yellow, and green)
- Resistors (if required) for connecting the LEDs

## Circuit Setup

1. Connect the LCD display to the Arduino board using the following pin connections:

   - LCD RS pin to Arduino pin 12
   - LCD EN pin to Arduino pin 11
   - LCD D4 pin to Arduino pin 5
   - LCD D5 pin to Arduino pin 4
   - LCD D6 pin to Arduino pin 3
   - LCD D7 pin to Arduino pin 2

2. Connect the red LED to Arduino pin 8.
3. Connect the yellow LED to Arduino pin 9.
4. Connect the green LED to Arduino pin 10.
5. Add resistors in series with the LEDs if required.

## Code Explanation

1. The code starts by importing the necessary library for controlling the LCD display.
2. The pin assignments for the LCD and LEDs are declared as constants and variables.
3. The `setup()` function is called once at the beginning to configure the pin modes and initialize the LCD.
4. The `loop()` function is called repeatedly in an infinite loop.
5. Inside the `loop()` function, the LCD cursor is positioned and the corresponding LED is turned on for 2 seconds.
6. The LED colors and text are updated on the LCD for each cycle.

## Usage

1. Upload the code to your Arduino board.
2. Make sure the circuit connections are properly set up.
3. Power on the Arduino board.
4. Observe the LED color cycling on the corresponding pins.
5. The LCD will display the current LED color.

Note: Adjust the delays in the `loop()` function if you want to change the duration of each LED color display.
