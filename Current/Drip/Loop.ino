
//---------------------------------------------------------------//
// LOOP

void loop() {
  
  // Blink Min/Max
  int maX = 35;          
  int miN = 1;

  // Loop Through The Strands
  for(int i = 0; i < numStrands; i++) {
      
      // Set Random Speed
      speed[i] = random(blinkSpeed[miN],blinkSpeed[maX]);

      // Reset Current Millisecond
      currentMillis[i] = millis();
      
      for(int k = 0; k < strandLength; k++) {   
        // Check & Reset LED Strand
        resetStrand(k, i);
      }
  } 

  // Light Them LEDs !!!
  FastSPI_LED.show();

} /* END OF LOOP */

