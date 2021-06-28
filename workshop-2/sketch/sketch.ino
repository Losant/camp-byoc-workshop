/*
 * const means that these values never change.
 * Since the LED pin and button pin will always be the same,
 * we can set them as const.
 */
const int LED_PIN = 1; // GPIO 1
const int BUTTON_PIN = 2; // GPIO 2

/*
 * These are called "variables" which means they are values
 * that will change while the program runs.
 */
int ledState = LOW;
int previousButtonState = LOW;
int currentButtonState;

unsigned long lastDebounceTime = 0;

/**
 * setup() is called once when the board is
 * initially powered on or reset.
 */
void setup() {

  /* Configure LED_PIN (GPIO 1) as a digital output. */
  pinMode(LED_PIN, OUTPUT);

  /* Configure BUTTON_PIN (GPIO 2) as a digital input. */
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  /*
   * Read the state of the button and set the above variable
   * to use that value.
   */
  currentButtonState = digitalRead(BUTTON_PIN);

  /*
   * If the last program the board ran left the LED on,
   * turn it off to start.
   */
  digitalWrite(LED_PIN, ledState);
}

/**
 * loop() is called over and over again for as
 * long as the board is powered on.
 */
void loop() {
  /* This variable will reset every time the loop starts over. */
  int buttonStateInThisLoop = digitalRead(BUTTON_PIN);

  /*
   * Here the button is "debounced," which means you can't press
   * the button too quickly. This is to ensure the program doesn't
   * get confused by having too much input at once.
   */
  if (buttonStateInThisLoop != previousButtonState) {
    lastDebounceTime = millis();
  }

  /*
   * This checks that it has been long enough to allow
   * a button press to happen.
   */
  if ((millis() - lastDebounceTime) > 50) {

    /*
     * If the button state in this loop is not the same as what
     * our current button state is set to, update it.
     */
    if (buttonStateInThisLoop != currentButtonState) {
      currentButtonState = buttonStateInThisLoop;

      /* If the button state is HIGH... */
      if (currentButtonState == HIGH) {
        /*
         * ...then toggle the LED state. Using a ! tells the program
         * that it wants to set the variable to the opposite of whatever
         * it was set to before.
         */
        ledState = !ledState;
      }
    }
  }

  /* Write the determined LED state to the pin. */
  digitalWrite(LED_PIN, ledState);
  previousButtonState = buttonStateInThisLoop;
}
