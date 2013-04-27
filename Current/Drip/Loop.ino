
//---------------------------------------------------------------//
// LOOP

void loop() {
  
  // Check Our Timer
  if(checkTimer() && !currentlyPlaying) {
    
    if(debug) Serial.println("Let's Read Our Sensor...");
    
    // Test Sensor
    readSensor();
  }
  
  // Loop Through The Strands
  if(inRange && !currentlyPlaying) {
    
    if(debug) Serial.println("Let's Light Those LEDs...");
    
    // Start Our Animation
    startRain();
  }
  
  // Light Them LEDs !!!
  FastSPI_LED.show();

} /* END OF LOOP */

