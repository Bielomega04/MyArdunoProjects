#include <Arduino.h>
#define LED 13
void setup()
{
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

void loop()
{
  digitalWrite(LED, HIGH);
  delay(250);
  digitalWrite(LED, LOW);
  delay(250);
}
