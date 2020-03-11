
void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  Serial1.begin(9600); // opens serial port, sets data rate to 9600 bps
  uint16_t id = tft.readID();

  tft.reset();
  tft.begin(id);
  tft.setRotation(1);
  tft.fillScreen(BLACK);
  StartupScreen();                            //  Display Startup Screen
  delay(2500);



  tft.begin(id);
  tft.setRotation(0);     //Portrait
  tft.fillScreen(BLACK);
  tft.setTextColor(RED, BLACK);
  tft.setTextSize(2);     // System font is 8 pixels.  ht = 8*2=16
  tft.setCursor(100, 0);
  tft.print("ID = 0x");
  tft.println(id, HEX);
  delay(500);



  ClearPage();

  tft.setCursor(100, 0);
  tft.setTextColor(MAGENTA, BLACK);
  tft.print(" Kinzy Tech ");
  if (id == 0x9320 || id == 0x9325 || id == 0xB509) { //0x9486
    top = 0;                      // these controllers scroll full screen
    lines = tft.height() / ht;    // we are in portrait mode
  }
  if (id == 0x7783) {
    tft.println("can NOT scroll");
    while (1);                    // die.
  }
  tft.setCursor(10, 0);

}
