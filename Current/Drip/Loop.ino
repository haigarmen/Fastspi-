
//---------------------------------------------------------------//
// LOOP

void loop() {
  
  // Test Sensor
  if(checkTimer()) {
    Serial.println("Let's Read Our Sensor...");
    readSensor();
  }
  
  // Loop Through The Strands
  loopStrands();
  
  // Light Them LEDs !!!
  FastSPI_LED.show();

} /* END OF LOOP */

