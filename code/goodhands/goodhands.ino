#include <CapacitiveSensor.h>

/*
 * GoodHands Main Control Program v0.1
 * https://github.com/sbyrnes/goodhands
 * Author: Sean Byrnes, Fogstack Software
 * 
 * Requires the CapacitiveSensor library from Paul Badger and Paul Stoffregen.
 * https://github.com/PaulStoffregen/CapacitiveSensor
 *
 * The CapacitiveSensor Library works by creating changes in the voltage between two pins and measuring the
 * delay between when the voltage is changed on the send pin and received on the sensor pin. With no capacitance
 * the delay is minimal, but adding capacitance (such as your finger) will dampen the oscillation and delay the change. 
 *
 * In GoodHands v0.1 we use three sensor pins, one for each finger, and one send pin shared by all four. 
 * 
 * For debugging, each sensor pin has an output pin that is activated if that sensor is active so that we can
 * show LEDs for visual feedback.
 */

/** SET UP THE CAPACTIVE LIBRARY ENTITIES **/
// Pin 2 is the send pin for all signals
CapacitiveSensor   pinkySensor   = CapacitiveSensor(2,4);     // Sensing between pins 2 & 4, pin 4 is sensor pin
CapacitiveSensor   ringSensor    = CapacitiveSensor(2,6);     // Sensing between pins 2 & 6, pin 6 is sensor pin
CapacitiveSensor   middleSensor  = CapacitiveSensor(2,8);     // Sensing between pins 2 & 8, pin 8 is sensor pin
CapacitiveSensor   pointerSensor = CapacitiveSensor(2,10);  // Sensing between pins 2 & 10, pin 10 is sensor pin

// Output pins
int pinkyOutput   = 5; 
int ringOutput    = 7; 
int middleOutput  = 9; 
int pointerOutput = 11; 

/** Arduino Setup **/
void setup()                    
{
  // Configure output pins
  pinMode(pinkyOutput, OUTPUT);
  pinMode(ringOutput, OUTPUT);
  pinMode(middleOutput, OUTPUT);
  pinMode(pointerOutput, OUTPUT);
  
  // configure sensors by disabling autocalibrate, probably should turn this on at some point
   pinkySensor.set_CS_AutocaL_Millis(0xFFFFFFFF);     
   ringSensor.set_CS_AutocaL_Millis(0xFFFFFFFF);   
   middleSensor.set_CS_AutocaL_Millis(0xFFFFFFFF);     
   pointerSensor.set_CS_AutocaL_Millis(0xFFFFFFFF);       
   
  // Enable serial communication for debugging 
  Serial.begin(9600);
}

long kMinimumThreshold = 50;

/** Main Arduino Loop **/
void loop()                    
{
    long pinkyValue   =  pinkySensor.capacitiveSensor(30);
    long ringValue    =  ringSensor.capacitiveSensor(30);
    long middleValue  =  middleSensor.capacitiveSensor(30);
    long pointerValue =  pointerSensor.capacitiveSensor(30);
    
    Serial.print(pinkyValue);                
    Serial.print("\t");
    Serial.print(ringValue);                 
    Serial.print("\t");
    Serial.print(middleValue);              
    Serial.print("\t");
    Serial.print(pointerValue);              
    Serial.println("");

    detectTouch(pinkyValue, pinkyOutput);
    detectTouch(ringValue, ringOutput);
    detectTouch(middleValue, middleOutput);
    detectTouch(pointerValue, pointerOutput);

    delay(100);  // Sensor loop delay
}

void detectTouch(long sensorValue, int outputPin){
    if(sensorValue > kMinimumThreshold)
    {
      digitalWrite(outputPin, HIGH);
    } else {
      digitalWrite(outputPin, LOW);
    }
}

