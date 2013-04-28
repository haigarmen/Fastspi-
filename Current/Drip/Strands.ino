
//---------------------------------------------------------------//
// STRANDS

// Loop Through Our Strands
void loopStrands() {
  
  // Loop
  for(int i = 0; i < numStrands; i++) {
    // Print
    if(debug) {
      Serial.print("Loop #");
      Serial.println(i);
    }
 
    // If We Still Have A Loop Left...
    if(timesLooped[i] < timesToLoop) {
      // Set Random Speed
      speed[i] = random(minSpeed, maxSpeed);
      // Reset Current Millisecond
      currentMillis[i] = millis();
      // Turn This Strand On
      strandPlaying[i] = true;
      // Loop Through Our Strand Length
      for(int k = 0; k < strandLength; k++) {  
        // Check & Reset LED Strand
        lightStrand(k, i);
      }
    
    }
    // If We've Run Our Course
    else {
      // Print
      if(debug) {
        Serial.print(" Times Up.. Strand #");
        Serial.print(i);
        Serial.print(" Has Looped ");
        Serial.print(timesLooped[i]);
        Serial.println(" Times");
      }
      // Turn This Strand Off
      strandPlaying[i] = false;
      // Turn The LEDs Black
      leds[LEDsections[i]].r = 0;
      leds[LEDsections[i]].g = 0;
      leds[LEDsections[i]].b = 0;
    } 
    
  }
  
  // Test To See If Any Of Our Other Strands Are Still Playing ?
  if( isAnyPlaying() == false) {
    if(debug) Serial.println(" Resetting Strands");
    // Reset
    resetStrands();
  }
  
}

// Time + Light Our Strands
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
      
      // Turn The LEDs White
      leds[LEDsections[i]].r = 255;
      leds[LEDsections[i]].g = 255;
      leds[LEDsections[i]].b = 255;
      
      // Go Back To The Beginning
      if(LEDsections[i] == endLED[i]) {
        /*
          Turn them black here b/c otherwise 
          the LEDs flash white quickly when they reset...
        */
        leds[LEDsections[i]].r = 0;
        leds[LEDsections[i]].g = 0;
        leds[LEDsections[i]].b = 0;
        LEDsections[i] = startLED[i];
        
        timer[i] = speed[i];
        timesLooped[i]++;
      }
      


      // Reset Our Timer
      stepTime[i] = currentMillis[i];

    }
  
}

void resetStrands() {
  // Loop 
  for(int i = 0; i < numStrands; i++) {
    // Say That We're Not Playing
    strandPlaying[i] = false;
    // Reset Our Loop Count
    timesLooped[i] = 0;
  }
  // Broadcast That We're Not Playing Anymore
  currentlyPlaying = false; 
  // Turn Our Boolean False So That Our Sensor Will Read Again
  inRange = false;
}

// Function To Test If We Are Still Playing
boolean isAnyPlaying() {
  // Local Variable, Set To False
  boolean isStillPlaying = false;
  // Loop Through All Of Our Strands
  for(int i = 0; i < numStrands; i++) {
    // If Any Of The Are Still Playing...
    if(strandPlaying[i] == true) {
      // Set Our Local Boolean To TRUE
      isStillPlaying = true; 
    }
    // Else, Our Local Boolean Stays False
  }
  
  // Return Our Local Boolean Value
  return isStillPlaying; 
}
