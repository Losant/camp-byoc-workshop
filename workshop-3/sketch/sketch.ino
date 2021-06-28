#include <WiFiNINA.h> // this is a library that helps us connect to the internet!

// WiFi credentials.
const char* WIFI_SSID = "ssid";
const char* WIFI_PASS = "pass";

WiFiSSLClient client;

// information for HTTP Request
int    HTTP_PORT   = 443;
String HTTP_METHOD = "POST";
char   HOST_NAME[] = "virtual-lights.onlosant.com";

// edit this
String message = "{ \"name\": \"Heath\", \"message\": \"Hello, World!\" }";

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
 * this is a new function we're adding called connect
 * this function conncts to the wifi that we put as the SSID
 * and uses the password that we gave it!
 * */
void connect() {

  // Connect to Wifi.
  Serial.print("Connecting to ");
  Serial.println(WIFI_SSID);

  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }


  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

}

void makeHTTPRequest() {
  if(client.connect(HOST_NAME, HTTP_PORT)) {
    // if connected:
    Serial.println("Connected to server");
    // make a HTTP request:
    // send HTTP header
    client.println(HTTP_METHOD + " HTTP/1.1");
    client.println("Host: " + String(HOST_NAME));
    client.println("Connection: close");
    client.println(); // end HTTP header

    // send HTTP body
    client.println(message);

    while(client.connected()) {
      if(client.available()){
        // read an incoming byte from the server and print it to serial monitor:
        char c = client.read();
        Serial.print(c);
      }
    }

    // the server's disconnected, stop the client:
    client.stop();
    Serial.println();
    Serial.println("disconnected");
  } else {// if not connected:
    Serial.println("connection failed");
  }
}

/**
 * setup() is called once when the board is
 * initially powered on or reset.
 */
void setup() {
  Serial.begin(115200);

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

   // in setup, we want to connect to the internet
  connect();

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

        makeHTTPRequest();
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
