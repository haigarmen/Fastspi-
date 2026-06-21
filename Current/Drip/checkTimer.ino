
//---------------------------------------------------------------//
// TIMER

boolean checkTimer() {
  if( millis() >= sonarMillis + sonarInterval ) {
    sonarMillis = millis();
    return true;
  }
  else {
    return false;
  }

}
