# Distance Sensor with LCD and LEDs

This project demonstrates how to use a distance sensor with an LCD display and LEDs to measure and display the distance of an object.

## Hardware Requirements

- Arduino board
- Distance sensor (e.g., ultrasonic sensor)
- LCD display
- Three LEDs (e.g., green, yellow, red)
- Jumper wires
- Breadboard (optional, for circuit setup)

## Circuit Setup

1. Connect the Arduino pins to the corresponding LCD pins as follows:

   - `rs` pin -> Arduino pin 12
   - `en` pin -> Arduino pin 11
   - `d4` pin -> Arduino pin 5
   - `d5` pin -> Arduino pin 4
   - `d6` pin -> Arduino pin 3
   - `d7` pin -> Arduino pin 2

2. Connect the distance sensor signal pin to Arduino pin 6.

3. Connect the green LED to Arduino pin 8, the yellow LED to Arduino pin 9, and the red LED to Arduino pin 10.

4. Make sure to connect the power (VCC) and ground (GND) of all components properly.

(Optional: Use a breadboard to organize the connections.)

## Code Explanation

The code uses the LiquidCrystal library to control the LCD display. It defines integer constants to assign Arduino pins for LCD and LED connections. The `setup()` function configures the pins, initializes the LCD, and opens the serial console. The `loop()` function continuously reads the distance from the sensor, compares it with predefined values, and displays the distance on the LCD and LEDs based on the object's proximity. The `microsecondsToCentimeters()` function converts the duration in microseconds to centimeters.

## Usage

1. Connect the Arduino board to your computer.

2. Open the Arduino IDE or any other compatible software.

3. Copy the provided code into a new sketch.

4. Upload the sketch to the Arduino board.

5. Open the serial console to view the distance readings.

6. Observe the LCD display and the corresponding LED lighting up based on the object's distance.

7. Experiment with different object distances to observe the changes in LCD and LED output.

Note: Ensure that the necessary libraries are installed before uploading the code to the Arduino board.
