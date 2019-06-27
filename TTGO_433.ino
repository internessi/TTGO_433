#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();

void setup() {
   delay(500);
  Serial.begin(115200);

  pinMode       (5, OUTPUT);  
  digitalWrite  (5, HIGH);

  Serial.println("booting");
  mySwitch.enableReceive(digitalPinToInterrupt(19));
}

void loop() {
  if (mySwitch.available()) {
    Serial.print("Received ");
    Serial.print( mySwitch.getReceivedValue() );
    Serial.print(" / ");
    Serial.print( mySwitch.getReceivedBitlength() );
    Serial.print("bit ");
    Serial.print("Protocol: ");
    Serial.println( mySwitch.getReceivedProtocol() );
    mySwitch.resetAvailable();
  }
}
