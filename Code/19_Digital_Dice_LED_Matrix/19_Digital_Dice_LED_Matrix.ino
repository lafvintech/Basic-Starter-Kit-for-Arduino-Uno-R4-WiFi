#include <Arduino_LED_Matrix.h>

ArduinoLEDMatrix matrix;
const int tiltPin = 2;    // The pin where the tilt switch is connected
volatile bool rolling = false;
unsigned long lastShakeTime = 0;
// Pre-defined 2D array
byte frame[8][12] = {
     { 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0 },
     { 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
     { 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
     { 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
     { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

byte one[8][12] = {
     { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

byte two[8][12] = {
     { 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

byte three[8][12] = {
     { 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

byte four[8][12] = {
     { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};


byte five[8][12] = {
     { 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

byte six[8][12] = {
     { 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

const uint32_t hi[] = {
  0xcdfcdfcc,
  0x4fc4fc4c,
  0xc4cdfcdf,
  66
};

void display_number(byte number)
{
if(number==1){matrix.renderBitmap(one, 8, 12);}
else if(number==2){matrix.renderBitmap(two, 8, 12);}
else if(number==3){matrix.renderBitmap(three, 8, 12);}
else if(number==4){matrix.renderBitmap(four, 8, 12);}
else if(number==5){matrix.renderBitmap(five, 8, 12);}
else if(number==6){matrix.renderBitmap(six, 8, 12);}
else {matrix.renderBitmap(frame, 8, 12);}
}


void setup() {
  // Initialize LED matrix
  matrix.begin();
  pinMode(tiltPin, INPUT_PULLUP);  // Enable internal pull-up resistor
  attachInterrupt(digitalPinToInterrupt(tiltPin), rollDice, CHANGE);
  matrix.loadFrame(hi);
}


void loop() {
  // Check if it's rolling
  if (rolling) {
    byte number = random(1, 7);  // Generate a random number between 1 and 6
    display_number(number);
    delay(80);  // Delay to make the rolling effect visible

    // Stop rolling after 1 second
    if ((millis() - lastShakeTime) > 1000) {
      rolling = false;
    }
  }
}

// Interrupt handler for shake detection
void rollDice() {
  if (digitalRead(tiltPin) == LOW) {
    lastShakeTime = millis();  // Record the time of shake
    rolling = true;            // Start rolling
  }
}