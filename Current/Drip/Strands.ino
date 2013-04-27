
//---------------------------------------------------------------//
// STRANDS

void startRain() {

  if(timesLooped < timesToLoop) {
    // Start the Playing
    currentlyPlaying = true;
    // Loop 
    loopStrands(); 
  }
  else {
    // Stop The Playing
    currentlyPlaying = false;
    // Reser Our Counter
    timesLooped = 0;
  }
  
  
}

// Loop Through Our Strands
void loopStrands() {

    for(int i = 0; i < numStrands; i++) {
      // Set Random Speed
      speed[i] = random(blinkSpeed[miN],blinkSpeed[maX]);

      // Reset Current Millisecond
      currentMillis[i] = millis();
      
      for(int k = 0; k < strandLength; k++) {   
        // Check & Reset LED Strand
        lightStrand(k, i);
      }
    }
    
    // Increase Our Counter
    timesLooped++;
    
}

// Reset + Light Our Strands
void lightStrand(int k, int i) {

    // If We Reach The End Of The Strand, Reset
    if (k >= endLED[i]){       
      timer[i] = speed[i];
    } 
    
    // Is Our Timer Ready To Switch ?? 
    if(currentMillis[i] - stepTime[i] >= timer[i]) {
      
      // Turn The LEDs Black
      leds[LEDsections[i]].r = 0;
      leds[LEDsections[i]].g = 0;
      leds[LEDsections[i]].b = 0;
  
      // Increment
      LEDsections[i]++;
  
      // Go Back To The Beginning
      if(LEDsections[i] == endLED[i]) {
        LEDsections[i] = startLED[i];
        timer[i] = speed[i];
      }
  
      // Turn The LEDs White
      leds[LEDsections[i]].r = 255;
      leds[LEDsections[i]].g = 255;
      leds[LEDsections[i]].b = 255;
  
      // Reset Our Timer
      stepTime[i] = currentMillis[i];
    }
  
}
