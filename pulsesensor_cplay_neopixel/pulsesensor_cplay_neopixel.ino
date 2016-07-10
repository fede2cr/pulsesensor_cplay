#include <Adafruit_CircuitPlayground.h>

// Pulse sensor with Arduino IDE Serial Plotter
// Code demo by Lady Ada from Adafruit
// https://www.youtube.com/watch?v=Rfko5UnqDI4

const uint8_t min = 80;
const uint8_t max = 190;

void setup() {
//  while (!Serial); // Espera a que se inicie la consola serial en el IDE
  Serial.begin(115200);
  Serial.println("Circuit Playground sensor test");
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(255);
  CircuitPlayground.setPixelColor(1, 0, 255, 0);
}

void loop() {
  uint8_t red = CircuitPlayground.lightSensor();  
  Serial.println(red);
  
  // Solo muestra pulso con dedo presente
  if (( red > min ) && ( red < max )) {
   uint8_t pulse = map(red, min, max, 0, 255);
    for (int i=5; i<10; ++i) {
      CircuitPlayground.strip.setPixelColor(i, pulse, 0, 0);
    }
  } else {
    // Como el brillo es 255, no queremos la luz verde siempre activa
    for (int i=5; i<10; ++i) {
      CircuitPlayground.strip.setPixelColor(i, 0, 0, 0);
    }
    CircuitPlayground.setPixelColor(1, 0, 0, 0);

    delay(2000);
    CircuitPlayground.setPixelColor(1, 0, 255, 0);
  }
  CircuitPlayground.strip.show();
  
  delay(20);
}
