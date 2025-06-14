// ====== CONFIGURATION ======
#define HEATER_PWM_PIN 3        // PWM output pin

// ====== TEMPERATURE CONTROL ======
double setpoint = 55.0;         // Target temperature in °C
double currentTemp = 30.0;      // Simulated temperature
double pwmOutput = 0.0;

// ====== PID PARAMETERS ======
double Kp = 5.0;
double Ki = 0.8;
double Kd = 2.5;

// ====== PID STATE VARIABLES ======
double prevError = 0.0;
double integral = 0.0;
unsigned long lastTime = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("PWM Output Test - Simulated Temp Input with PID");

  pinMode(HEATER_PWM_PIN, OUTPUT);
  lastTime = millis();
}

void loop() {
  // Simulate a temperature reading (you can modify this to test)
  // Example: simulate temperature rising slowly
  currentTemp += 0.5;
  if (currentTemp > 70) currentTemp = 30;

  // PID calculations
  double error = setpoint - currentTemp;
  unsigned long now = millis();
  double deltaTime = (now - lastTime) / 1000.0; // convert ms to seconds

  if (deltaTime >= 0.5) { // update every 0.5 seconds
    integral += error * deltaTime;

    // Prevent integral windup
    integral = constrain(integral, -255.0 / Ki, 255.0 / Ki);

    double derivative = (error - prevError) / deltaTime;

    pwmOutput = Kp * error + Ki * integral + Kd * derivative;
    pwmOutput = constrain(pwmOutput, 0, 255);

    prevError = error;
    lastTime = now;
  }

  // Apply PWM to heater
  analogWrite(HEATER_PWM_PIN, (int)pwmOutput);

  // Debug output
  Serial.print("Setpoint: ");
  Serial.print(setpoint);
  Serial.print(" °C | Simulated Temp: ");
  Serial.print(currentTemp);
  Serial.print(" °C | PWM: ");
  Serial.println((int)pwmOutput);

  delay(1000); // 1-second delay for oscilloscope visibility
}
