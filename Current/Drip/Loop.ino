
//---------------------------------------------------------------//
// LOOP

void loop() {
  
  // Test Sensor
  if(millis() % 500 == 0) {
    Serial.print("Time...  \n");
    readSensor();
  }
  
  // Loop Through The Strands
  if(inRange) {
    Serial.print("We're In Range...  \n");
    loopStrands();
    Serial.println("-------------\n"); 
  }
  
  // Light Them LEDs !!!
  FastSPI_LED.show();

} /* END OF LOOP */

