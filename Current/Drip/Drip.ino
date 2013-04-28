/* 
 
 by Robert Werner | Jesse Scott | Haig Armen
 
 Emily Carr University of Art + Design
 
 21 Umbrellas
 
 */

//---------------------------------------------------------------//
// VARIABLES

// Debug
boolean debug = false;

// INCLUDES  
#include <FastSPI_LED.h>

// DEFINES
#define NUM_LEDS 300

// SERIAL
int outputPin = 4;
int ledDebugPin = 13;

// SONAR
const int pwPin = 5;
int configPin = 3;

long targetMin = 30;
long targetMax = 130;

int arraysize = 3;
int rangevalue[] = {0, 0, 0};
long pulse;
int mode;

boolean inRange = false;

boolean currentlyPlaying = false;
int timesToLoop = 4;
int timesLooped[8] = {0,0,0,0,0,0,0,0};
boolean strandPlaying[8] = {true, false, false, false, false, false, false, false};

long sonarMillis = 0;
long sonarInterval = 1000;

// LEDS
struct CRGB { 
  unsigned char r; 
  unsigned char g; 
  unsigned char b; 
};
struct CRGB *leds;

// Number Of Strands
int numStrands = 8;

// Length Of Strands
unsigned long strandLength = 18;

// TIMING ETC

// Individual Timer For Each Strand
unsigned long currentMillis[8] = {0,0,0,0,0,0,0,0}; 

// Step time clock restarts strands
unsigned long stepTime[8] = {0,0,0,0,0,0,0,0}; 

// Individual Timer For Each Strand
int timer[8] = {0,0,0,0,0,0,0,0}; 

// Individual Speed For Each Strand
int speed[8] = {0,0,0,0,0,0,0,0};

// Blink Min/Max
int maxSpeed = 55;          
int minSpeed = 5;


// LED POSITIONS

// Starting Position of Initial LED For Each Strand
int startLED[8] = { 
  strandLength * 0,  // 0 
  strandLength * 1,  // 18
  strandLength * 2,  // 36
  strandLength * 3,  // 54
  strandLength * 4,  // 72
  strandLength * 5,  // 90
  strandLength * 6,  // 108
  strandLength * 7   // 126
}; 

// Temporary Position/Length Of Each LED for Each Strand
int LEDsections[8] = {
  startLED[0],
  startLED[1], 
  startLED[2], 
  startLED[3], 
  startLED[4], 
  startLED[5],
  startLED[6],
  startLED[7] 
};

// Final Position of Last LED For Each Strand
int endLED[8] = {
  startLED[0] + strandLength, 
  startLED[1] + strandLength, 
  startLED[2] + strandLength,
  startLED[3] + strandLength, 
  startLED[4] + strandLength, 
  startLED[5] + strandLength,
  startLED[6] + strandLength, 
  startLED[7] + strandLength 
}; 

// Reset All LEDs
int reset = 0; 












