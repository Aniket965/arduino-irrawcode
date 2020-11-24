/**
 * lets hack the ir remote 
*/
#include <IRremote.h>

int RECV_PIN = 11;
unsigned int rawCodes[70];
int codeLen;
IRrecv IrReceiver(11);

void setup()
{
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  Serial.println("Enabled IRin");
    IrReceiver.enableIRIn();  // Start the receiver
    IrReceiver.blink13(true); // Enable feedback LED

    Serial.print(F("Ready to receive IR signals at pin "));
 
}




void loop() {
      if (IrReceiver.decode()) {  // Grab an IR code
    
        Serial.println();                               // blank line between entries
        IrReceiver.printIRResultAsCArray(&Serial);      // Output the results as source code array
       
        IrReceiver.resume();                            // Prepare for the next value
    }
}
