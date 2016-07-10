#include <Adafruit_CircuitPlayground.h>

void setup() {
  while (!Serial); // Espera a que se inicie la consola serial en el IDE
  Serial.begin(115200);
  Serial.println("Circuit Playground sensor test");
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(255);

  CircuitPlayground.setPixelColor(1, 0, 255, 0);
}

void loop() {
  Serial.println(CircuitPlayground.lightSensor());
  delay(20);
}
