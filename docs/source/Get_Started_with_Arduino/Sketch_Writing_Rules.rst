Arduino IDE Sketch Writing Rules
=============================================

Arduino is an easy-to-use open-source hardware platform, suitable for beginners to develop electronic projects. Following some basic rules and best practices when writing Arduino code (called "sketch") can help improve code readability, maintainability, and efficiency. This article will introduce these rules and best practices and provide detailed explanations.

1. Structured Code
------------------

A typical Arduino sketch consists of two main parts: the ``setup()`` function and the ``loop()`` function.

- The ``setup()`` function: used for initialization settings, such as setting pin modes, starting serial communication, etc. This function is executed once at the start of the program.

  .. code-block:: arduino
  
     void setup() {
       // Initialization settings
     }

- The ``loop()`` function: contains the main program logic, which is executed repeatedly.

  .. code-block:: arduino
  
     void loop() {
       // Main program logic
     }

2. Meaningful Naming
--------------------

Use meaningful variable names, function names, and constant names to make the code easy to understand and maintain.

- Variable names should describe their purpose, such as ``int sensorValue;``.
- Function names should describe their function, such as ``void readSensor();``.
- Constant names are usually in uppercase letters and underscores, such as ``const int LED_PIN = 13;``.

3. Comments
-----------

Adding comments to the code can help yourself and others understand the code logic. Comments should be concise and clear.

- Use single-line comments to explain the function of variables, functions, or code blocks.

  .. code-block:: arduino
  
     int sensorValue; // Sensor reading

- Use block comments to explain complex logic or algorithms.

  .. code-block:: arduino
  
     /*
      * Read sensor data and calculate the average
      */
     void readSensor() {
       // Code implementation
     }

4. Use Constants
----------------

For values that do not change, use the ``const`` keyword to define constants, which can improve code readability and security.

.. code-block:: arduino

   const int LED_PIN = 13; // LED connected to digital pin 13

5. Avoid Magic Numbers
----------------------

"Magic numbers" refer to numerical constants used directly in the code. Use meaningful named constants instead to improve code readability.

.. code-block:: arduino

   const int MAX_SPEED = 255;
   analogWrite(motorPin, MAX_SPEED);

6. Handle Errors
----------------

When writing code, consider possible error conditions and handle them appropriately. For example, check function return values to ensure device connections are normal.

.. code-block:: arduino

   if (WiFi.status() != WL_CONNECTED) {
     // Handle WiFi not connected case
   }

7. Format Code
--------------

Good code formatting helps improve readability. Maintain consistent indentation style, appropriate spacing, and alignment.

- Each code block should be indented by two or four spaces.
- Leave a blank line between functions.
- Leave spaces on both sides of operators.

8. Decompose Tasks
------------------

Decompose complex tasks into multiple small functions, each performing a distinct function. This makes the code simpler, easier to debug, and maintain.

.. code-block:: arduino

   void setup() {
     initializePins();
     initializeSerial();
   }
   
   void initializePins() {
     pinMode(LED_PIN, OUTPUT);
   }

   void initializeSerial() {
     Serial.begin(9600);
   }

Conclusion
----------

Following the above rules and best practices can help you write high-quality Arduino code. Good programming habits not only improve code readability and maintainability but also reduce errors and enhance development efficiency. Hopefully, these rules will help you achieve better results in Arduino development.
