# Switch LCD text and LED Color by button click

## Hardware Requirements

- Arduino board
- LCD display
- Push button
- LEDs (red, yellow, and green)
- Resistors and wires for circuit connections

## Circuit Setup

1. Connect the LCD display to the Arduino board:

   - LCD RS pin to Arduino pin 12
   - LCD Enable pin to Arduino pin 11
   - LCD D4, D5, D6, and D7 pins to Arduino pins 5, 4, 3, and 2 respectively

2. Connect the LEDs to the Arduino board:

   - Red LED pin to Arduino pin 8
   - Yellow LED pin to Arduino pin 9
   - Green LED pin to Arduino pin 10

3. Connect the push button to the Arduino board:
   - One pin of the button to Arduino pin 6
   - The other pin of the button to GND (Ground)

## Code Explanation

The provided code controls the LEDs based on button presses and displays the current LED color on the LCD display. Here's an overview of the code's functionality:

- The LiquidCrystal library is imported to control the LCD display.
- The pin assignments for the LCD display, LEDs, and the push button are defined.
- The LiquidCrystal object is created using the pin assignments.
- The setup() function initializes the pins and LCD display.
- The loop() function continuously checks the button state and updates the LED color and LCD display accordingly.
- The button state is read using the digitalRead() function.
- The buttonPushCounter variable keeps track of the number of button presses.
- Depending on the value of buttonPushCounter, the code determines the LED color to be displayed and updates the LEDs and LCD display accordingly.

## Usage

1. Set up the hardware components as described in the "Circuit Setup" section.
2. Upload the code to your Arduino board.
3. Open the serial monitor to view the output (if needed).
4. Press the push button to cycle through different LED colors.
5. Observe the changes in the LEDs and the LCD display to see the current LED color.

Note: Make sure to install the required LiquidCrystal library in your Arduino IDE before uploading the code.
