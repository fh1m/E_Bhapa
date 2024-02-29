
# E-Bhapa - Your E-companion

**Intro**
I am thrilled to present to you *E-Bhapa*


*context: So we had a team and all of my team members bailed on me so I had to make something at the last minute so here what 6 hours, no sleep and 4 cup of coffee makes when there is no components available, the last servo burnt, so with all I had left I had to show some creativity in the code and I liked the code in the end so thought to share it.*


*What can it do actually?*
**lets see**

**Feature 1: Follow Object**
E-Bhapa's first remarkable feature is its ability to intelligently follow objects detected by its sonar sensor. Using cutting-edge algorithms, E-Bhapa dynamically adjusts its speed to maintain a safe distance from the detected object, showcasing precise and responsive movement.

**Feature 2: Dynamic Obstacle Avoidance**
In the face of unexpected obstacles, E-Bhapa seamlessly navigates its surroundings with dynamic obstacle avoidance. When confronted with an obstacle, E-Bhapa strategically pauses before executing a randomized turn, ensuring smooth and efficient traversal through challenging environments.

**Feature 3: Enhanced Exploration**
Equipped with a diverse range of exploration tactics, E-Bhapa demonstrates unparalleled adaptability in unknown terrains. Through randomized actions including forward movement, backward movement, turns, and pauses, E-Bhapa explores its environment with a blend of curiosity and intelligence, uncovering new paths and opportunities.

**Feature 4: Proportional Speed Control**
E-Bhapa's proportional speed control ensures optimal performance in various environmental conditions. By adjusting its speed based on the complexity of its surroundings, E-Bhapa maximizes efficiency and safety, demonstrating unparalleled versatility in exploration tasks.

**Feature 5: Adaptive Speed Control**
E-Bhapa further elevates its capabilities with adaptive speed control, a groundbreaking feature that enables real-time adjustments to its velocity based on environmental complexity. By dynamically modulating its speed, E-Bhapa optimizes its performance, showcasing unmatched agility and intelligence in the field.

## Code Summary
### see what shit does

1. **setup() Function:**
   - This function is executed once at the beginning of the program.
   - It initializes serial communication for debugging and sets the pinMode for the ultrasonic sensor's TRIG_PIN and ECHO_PIN.

2. **loop() Function:**
   - The loop function runs continuously after the setup.
   - It retrieves the current distance from the ultrasonic sensor and prints it to the serial monitor for debugging.
   - Based on the distance measured, it determines the appropriate action for E-Bhapa to take: following an object, dynamically avoiding obstacles, or exploring the environment.

3. **measureDistance() Function:**
   - This function calculates the distance to an object detected by the ultrasonic sensor.
   - It sends a brief pulse to the sensor's TRIG_PIN to initiate a measurement and then measures the time it takes for the pulse to bounce back (echo) from the object.
   - The duration of the echo pulse is converted into distance using the formula: distance = (duration * speed of sound) / 2.

4. **adjustMotorSpeed() Function:**
   - This function adjusts the speed of E-Bhapa's motors to achieve the desired movement.
   - It takes two parameters: leftSpeed and rightSpeed, representing the speed of the left and right motors, respectively.
   - The function sets the speed of each motor using the setSpeed() method from the AFMotor library and then activates the motors to run in the FORWARD direction using the run() method.

5. **stopMotors() Function:**
   - This function stops all of E-Bhapa's motors.
   - It sets the speed of each motor to zero using the setSpeed() method and then releases the motors using the run() method with the RELEASE parameter.

6. **followObject() Function:**
   - This function enables E-Bhapa to track and follow objects within a specified distance range.
   - It adjusts the speed of the motors based on the distance to the detected object, ensuring E-Bhapa maintains a safe following distance while tracking the object's movement.

7. **dynamicObstacleAvoidance() Function:**
   - This function implements dynamic obstacle avoidance behavior for E-Bhapa.
   - It pauses E-Bhapa's movement, executes a randomized turn in a left or right direction to navigate around the obstacle, and then resumes exploration.

8. **enhancedExploration() Function:**
   - This function enhances E-Bhapa's exploration capabilities by executing a randomized sequence of actions, including moving forward, moving backward, turning left, turning right, and pausing.
   - It allows E-Bhapa to explore its environment comprehensively, uncovering new paths and opportunities for further exploration.

These functions work together seamlessly to provide E-Bhapa with intelligent and adaptive behavior, allowing it to navigate and explore its surroundings effectively in various scenarios.

## Finally, lets see our Bhapa(s)

Bhapa                      |  E-Bhapa
:-------------------------:|:-------------------------:
<img src="https://github.com/fh1m/E_Bhapa/assets/132839265/91687e66-9a50-4cab-a14e-3a07d4fe1148" width="500">   |  <img src="https://github.com/fh1m/E_Bhapa/assets/132839265/4c5dfb16-a4f3-441b-a47e-7087035e5113" width="500"> 

## looks identical, wow


