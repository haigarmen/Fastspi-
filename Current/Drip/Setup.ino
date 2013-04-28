
//---------------------------------------------------------------//
// SETUP

void setup() {
  
  // FastSPI Setup
  FastSPI_LED.setLeds(NUM_LEDS);
  FastSPI_LED.setChipset(CFastSPI_LED::SPI_TM1809);
  FastSPI_LED.setPin(outputPin);
  
  // FastSPI Init & Start
  FastSPI_LED.init();
  FastSPI_LED.start();

  // RGB
  leds = (struct CRGB*)FastSPI_LED.getRGBData(); 

  // Serial Begin
  Serial.begin(9600);
  
  // Sensor
  pinMode(configPin, OUTPUT);
  pinMode(ledDebugPin, OUTPUT);
  pinMode(pwPin, INPUT);
  
  // Interrupt
  attachInterrupt(pwPin, readSensor, CHANGE);
  
  // Let's Catch Our Breath
  delay(500);

} /* END OF SETUP */
