
//---------------------------------------------------------------//
// LOOP

void loop() {
  
  // Test Sensor
  if(millis() % 500 == 0) {
    Serial.println("Let's Read Our Sensor...");
    //readSensor();
  }
  
  // Loop Through The Strands
  //if(inRange) {
    loopStrands();
  //}
  
  // Light Them LEDs !!!
  FastSPI_LED.show();

} /* END OF LOOP */

