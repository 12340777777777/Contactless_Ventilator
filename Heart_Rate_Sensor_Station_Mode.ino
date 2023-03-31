
//===================================================================================NodeMCU Heart Rate_Sensor Serial Plotter
//----------------------------------------Variable Declaration
const int PulseSensorHRWire = A0; //--> PulseSensor connected to ANALOG PIN 0 (A0 / ADC 0).
const int LED_D1 = D1; //--> LED to detect when the heart is beating. The LED is connected to PIN D1 (GPIO5) on the NodeMCU ESP12E.
int Threshold = 600; //--> Determine which Signal to "count as a beat" and which to ignore.
int Signal; //--> holds the incoming raw data.
//----------------------------------------

//--------------------------------------------------------------------------------void setup
void setup() {
  Serial.begin(115200); //--> Set's up Serial Communication at certain speed.
  pinMode(LED_D1,OUTPUT); //--> Set LED_3 PIN as Output.
}
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------void loop
void loop() {
  Signal = analogRead(PulseSensorHRWire); //--> Read the PulseSensor's value. Assign this value to the "Signal" variable.

  Serial.println(Signal); //--> Send the Signal value to Serial Plotter.

  if(Signal > Threshold){ //--> If the signal is above "600"(Threshold), then "turn-on" Arduino's on-Board LED.
    digitalWrite(LED_D1,HIGH);
  } else {
    digitalWrite(LED_D1,LOW); //--> Else, the sigal must be below "600", so "turn-off" this LED.
  }

  delay(10);
}
//--------------------------------------------------------------------------------
//===================================================================================
