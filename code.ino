#include <AFMotor.h>

#define TRIG_PIN 13
#define ECHO_PIN 12

#define SONAR_FOLLOW_DISTANCE 25 // Distance at which the robot follows an object
#define MAX_SPEED 255            // Maximum motor speed
#define ACCELERATION_STEP 15     // Motor speed adjustment step for smoother acceleration
#define MIN_SPEED 100            // Minimum motor speed for proportional control
#define TURN_SPEED 200           // Speed for turning
#define TURN_DURATION_MIN 200    // Minimum duration for turning (in milliseconds)
#define TURN_DURATION_MAX 500    // Maximum duration for turning (in milliseconds)
#define PAUSE_DURATION_MIN 300   // Minimum pause duration before turning (in milliseconds)
#define PAUSE_DURATION_MAX 800   // Maximum pause duration before turning (in milliseconds)
#define OPEN_SPACE_SPEED 255     // Speed in open spaces
#define CLUTTERED_SPACE_SPEED 150 // Speed in cluttered areas

AF_DCMotor motor1(1); // Left-front motor
AF_DCMotor motor2(2); // Right-front motor
AF_DCMotor motor3(3); // Left-rear motor
AF_DCMotor motor4(4); // Right-rear motor

void setup() {
  Serial.begin(9600);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
}

void loop() {
  long distance = measureDistance();
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance > 0 && distance < SONAR_FOLLOW_DISTANCE) {
    followObject(distance);
  } else if (distance >= SONAR_FOLLOW_DISTANCE && distance < 30) {
    dynamicObstacleAvoidance();
  } else {
    enhancedExploration();
  }

  delay(100); // Short delay to stabilize sensor readings
}

long measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(20);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2; // Calculate distance in cm
}

void adjustMotorSpeed(int leftSpeed, int rightSpeed) {
  motor1.setSpeed(leftSpeed);
  motor2.setSpeed(leftSpeed);
  motor3.setSpeed(rightSpeed);
  motor4.setSpeed(rightSpeed);

  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void stopMotors() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void followObject(long distance) {
  int adjustedSpeed = map(distance, 0, SONAR_FOLLOW_DISTANCE, MIN_SPEED, MAX_SPEED);
  adjustMotorSpeed(adjustedSpeed, adjustedSpeed);
}

void dynamicObstacleAvoidance() {
  stopMotors();
  delay(random(PAUSE_DURATION_MIN, PAUSE_DURATION_MAX)); // Randomized pause before turning
  bool turnLeft = random(2) == 0;
  adjustMotorSpeed(turnLeft ? 0 : TURN_SPEED, turnLeft ? TURN_SPEED : 0); // Turn
  delay(random(TURN_DURATION_MIN, TURN_DURATION_MAX)); // Randomized turning duration
  stopMotors(); // Stop after turning
}

void enhancedExploration() {
  int action = random(0, 10); // More diverse actions

  long currentDistance = measureDistance(); // Get current distance for speed adjustment

  switch(action) {
    case 0: // Move forward
      adjustMotorSpeed(determineSpeed(currentDistance), determineSpeed(currentDistance));
      break;
    case 1: // Move backward
      adjustMotorSpeed(-determineSpeed(currentDistance), -determineSpeed(currentDistance));
      break;
    case 2: // Turn left
      adjustMotorSpeed(-TURN_SPEED, TURN_SPEED);
      delay(random(TURN_DURATION_MIN, TURN_DURATION_MAX)); // Randomized turning duration
      stopMotors();
      break;
    case 3: // Turn right
      adjustMotorSpeed(TURN_SPEED, -TURN_SPEED);
      delay(random(TURN_DURATION_MIN, TURN_DURATION_MAX)); // Randomized turning duration
      stopMotors();
      break;
    case 4: // Random pause
      stopMotors();
      delay(random(PAUSE_DURATION_MIN, PAUSE_DURATION_MAX));
      break;
  }
}

// Function to determine speed based on environment complexity
int determineSpeed(long distance) {
  if (distance > SONAR_FOLLOW_DISTANCE) {
    return OPEN_SPACE_SPEED; // Higher speed in open spaces
  } else {
    return CLUTTERED_SPACE_SPEED; // Lower speed in cluttered areas
  }
}

