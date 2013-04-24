
//---------------------------------------------------------------//
// LOOP

void loop() {
  
  // Test Sensor
  readSensor();
  
  // Loop Through The Strands
  loopStrands();

  // Light Them LEDs !!!
  FastSPI_LED.show();

} /* END OF LOOP */

