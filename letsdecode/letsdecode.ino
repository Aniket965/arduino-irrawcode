/**
 * lets hack the ir remote 
*/
#include <IRremote.h>

int RECV_PIN = 11;
unsigned int rawCodes[70];
int codeLen;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}

void loop() {
  if (irrecv.decode(&results))
  { 
      extractRaw(&results);
      Serial.println("enedd");
          // Displays the raw codes
    for (int i = 0; i < codeLen; i ++)
    {
      Serial.print(rawCodes[i]);
      Serial.print(", ");
    }
    Serial.println(); 

    irrecv.resume(); // Receive the next value
      irrecv.resume(); // Receive the next value
  }
  delay(100);
}
// Extracts the raw data
void extractRaw (decode_results *results) {
  codeLen = results->rawlen - 1;
  Serial.println(codeLen);
  for (int i = 1; i <= codeLen; i++) {
  
    if (i % 2) {
      // Mark
      rawCodes[i - 1] = results->rawbuf[i]*USECPERTICK - MARK_EXCESS;

      
 
   }
    else{
      // Space
      rawCodes[i - 1] = results->rawbuf[i]*USECPERTICK + MARK_EXCESS; 
      }
     
      }
}


