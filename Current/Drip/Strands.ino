
//---------------------------------------------------------------//
// STRANDS

void startRain() {

  // Start the Playing
  currentlyPlaying = true;

  // Loop 
  loopStrands(); 
 
}

// Loop Through Our Strands
void loopStrands() {

  for(int i = 0; i < numStrands; i++) {
    if(debug) Serial.print("Loop #");
    if(debug) Serial.println(i);
    
    if(timesLooped[i] < timesToLoop) {
    
      // Set Random Speed
      speed[i] = random(blinkSpeed[miN],blinkSpeed[maX]);
      // Reset Current Millisecond
      currentMillis[i] = millis();
      // Loop Through Our Strand Length
      for(int k = 0; k < strandLength; k++) {  
        // Check & Reset LED Strand
        lightStrand(k, i);
      }
    
    }
    else {
      if(debug) Serial.print(" Times Up.. Strand #");
      if(debug) Serial.print(i);
      if(debug) Serial.print(" Has Looped ");
      if(debug) Serial.print(timesLooped[i]);
      if(debug) Serial.println(" Times");
    }
    
  }
  
}

// Time + Light Our Strands
void lightStrand(int k, int i) {

    // If We Reach The End Of The Strand, Reset
    if (k >= endLED[i]){    
      if(debug) Serial.println("K == END...");   
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
      //if(debug) Serial.print("LED #");
      //if(debug) Serial.print(i);
      //if(debug) Serial.print(" = ");
      //if(debug) Serial.println(LEDsections[i]);
  
      // Go Back To The Beginning
      if(LEDsections[i] == endLED[i]) {
        if(debug) Serial.println("LED == END...");
        LEDsections[i] = startLED[i];
        timer[i] = speed[i];
        timesLooped[i]++;
      }
  
      // Turn The LEDs White
      leds[LEDsections[i]].r = 255;
      leds[LEDsections[i]].g = 255;
      leds[LEDsections[i]].b = 255;
  
      // Reset Our Timer
      stepTime[i] = currentMillis[i];
    }
  
}

// Function To Test If We Are Still Playing
boolean isPlaying() {
  // Local Variable, Set To False
  boolean isStillPlaying = false;
  // Loop Through All Of Our Strands
  for(int i = 0; i < numStrands; i++) {
    // If Any Of The Are Still Playing...
    if(strandPlaying[i] = true) {
      // Set Our Local Boolean To TRUE
      isStillPlaying = true; 
    }
    // Else, Our Local Boolean Stays False
  }
  
  // Return Our Local Boolean Value
  return isStillPlaying; 
}
