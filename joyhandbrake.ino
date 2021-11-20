#include "Joystick.h"

// This program uses a momentary pushbutton connected between GND and pin 2
// as USB HIB joystick button 1
int BUTTON_PIN = 2;

int JOYSTICK_BUTTON = 1;

void setup()
{
  Joystick.begin();

  pinMode(BUTTON_PIN, INPUT);
  digitalWrite(BUTTON_PIN, HIGH); // pull button pin high
}

int getHandbrakeStatus()
{
  return !digitalRead(BUTTON_PIN);
}

void loop()
{
  if (getHandbrakeStatus()) {
    Joystick.setButton(JOYSTICK_BUTTON, 1);
    while (getHandbrakeStatus()) {
      delay(1);
    }
    Joystick.setButton(JOYSTICK_BUTTON, 0);
  }
}
