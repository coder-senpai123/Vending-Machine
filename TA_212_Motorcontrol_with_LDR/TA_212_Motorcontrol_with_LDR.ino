int PWM = 5;           // connect PWM of Motor Driver to Pin 5 of Arduino UNO Board
int INB = 6;           // connect INB of Motor Driver to Pin 6 of Arduino UNO Board
int INA = 7;           // connect INA of Motor Driver to Pin 7 of Arduino UNO Board

int SENSOR = A5;       // Used to take analog input. In this case, sense the resistance change of the Light Dependent Resistor

int SPEED = 200;       // PWM (Pulse Width Modulation) value used to control the speed of the motor.
                       // The value can be varied from 0 (Lowest) to 255 (Highest)
                       // Note: Motor doesn't start until a significant voltage/PWM is applied due to internal losses and static friction.
                       // If PWM is set to 0, the motor is idle.

int THRESHOLD = 600;   // Arduino will receive values from 0 (dark) to 1023 (bright). 
                       // This value is to set a cutoff. Change this to tune it to your ambient illumination.

/* The code has two functions: void setup() and void loop()
   void setup() runs only once at the beginning and after pressing reset.
   void loop() runs in a never-ending loop once void setup() is completed.
*/

void setup() {
    // pinMode(PIN_NUMBER, MODE) is used to predefine the character of the pin

    pinMode(PWM, OUTPUT);   // PWM (Pulse Width Modulation) pin is used to control the speed of the motor,
                            // the value can be varied from 0 (Lowest) to 255 (Highest)

    pinMode(INA, OUTPUT);   // INA and INB control the direction of rotation of the motor
    pinMode(INB, OUTPUT);   // 

    pinMode(SENSOR, INPUT); // LDR will be used as a potentiometer, and the varying voltage will be measured through this pin.

    analogWrite(PWM, 0);    // Turn the motor OFF by default
}
void loop() {
    digitalWrite(INA, LOW);   // Reversed direction of rotation
    digitalWrite(INB, HIGH);  // Interchanged INA and INB

    if (analogRead(SENSOR) <= THRESHOLD) {
        analogWrite(PWM, SPEED);  // When the sensor output goes below the set threshold value, the motor turns ON.
    }
    else {
        analogWrite(PWM, 0);
    }

    delay(100);  // Add delay to wait before the loop runs again. Delay is entered in milliseconds.
}


