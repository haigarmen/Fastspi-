
boolean checkTimer() {
  if( millis() >= sonarMillis + sonarInterval ) {
    return true;
    sonarMillis = millis();
  }
  else {
    return false;
  }
  
}
