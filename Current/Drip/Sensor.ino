 
//---------------------------------------------------------------//
// SENSOR FUNCTIONS


// Time + Test Our Sensor
void readSensor() {
  
  sonarMillis = millis();
  digitalWrite(configPin, HIGH);
  Serial.println("Turning Sensor On"); 
  //delay(120); //start of calibration ring

  pinMode(pwPin, INPUT);
  
  for(int i = 0; i < arraysize; i++) {								    
    pulse = pulseIn(pwPin, HIGH);
    rangevalue[i] = pulse/58;
    delay(10);
  }
  
  Serial.print("Unsorted: ");
  printArray(rangevalue, arraysize);
  iSort(rangevalue, arraysize);
  
  Serial.print("Sorted: ");
  printArray(rangevalue, arraysize);
  
  Serial.print("The mode/median is: ");
  mode = getMode(rangevalue, arraysize);
  Serial.print(mode);
  Serial.println();
  
  // If We Are Within Range
  if (mode <= targetMax && mode >= targetMin) {    
    Serial.println("We See You... ");    
    inRange = true;
  }
  else{
    Serial.println("Nothing To See Here... ");
    inRange = false;
  }

  digitalWrite(configPin, LOW); 
  Serial.println("Turning Sensor Off"); 
  Serial.println("-------------\n"); 
  
}

// Print Our Values
void printArray(int *a, int n) {
  
  for (int i = 0; i < n; i++) {
    Serial.print(a[i], DEC);
    Serial.print(' ');
  }
  Serial.println();
  
}

//Sort Our Values
void iSort(int *a, int n){

  for (int i = 1; i < n; ++i) {
    int j = a[i];
    int k;
    for (k = i - 1; (k >= 0) && (j < a[k]); k--) {
      a[k + 1] = a[k];
    }
    a[k + 1] = j;
  }
  
}

//Mode function, returning the mode or median.
int getMode(int *x, int n) {
  
  int i = 0;
  int count = 0;
  int maxCount = 0;
  int mode = 0;
  int bimodal;
  int prevCount = 0;
  
  while(i < (n - 1)) {
    prevCount = count;
    count = 0;
    
    while(x[i] == x[i+1]) {
      count++;
      i++;
    }
    
    if(count > prevCount & count > maxCount) {
      mode = x[i];
      maxCount = count;
      bimodal = 0;
    }
    
    if(count == 0) {
      i++;
    }
    
    if(count == maxCount) { //If the dataset has 2 or more modes.
      bimodal = 1;
    }
    
    if(mode == 0 || bimodal == 1) { //Return the median if there is no mode.
      mode = x[(n/2)];
    }
    
    return mode;
  }
  
}

