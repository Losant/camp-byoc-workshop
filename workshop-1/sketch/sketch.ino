/**
 * setup() is called once when the board is 
 * initially powered on or reset.
 */
void setup() {

  // Configure GPIO 1 as a digital output.
  // https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/
  pinMode(1, OUTPUT);
//  pinMode(LED_BUILTIN, OUTPUT);

}

/**
 * loop() is called over and over again for as
 * long as the board is powered on.
 */
void loop() {

  // Set GPIO 1 to HIGH (turn on), wait one second (1000 milliseconds)
  // and then set GPIO 1 to LOW (turn off), then wait another second.
  // This will result in the LED turning on and off every one second.
  // https://www.arduino.cc/reference/en/language/functions/digital-io/digitalwrite/

  digitalWrite(1, HIGH);
//  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(1, LOW);
//  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);

}
