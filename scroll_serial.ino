#include <Adafruit_GFX.h> // Hardware-specific library
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;



#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define PINK    0xF9FF

int currLinePrint = 29;
// work in line numbers.  Font height in ht
int16_t ht = 16, top = 1, line, lines = 29, scroll;
int incomingByte = 0; // for incoming serial data
int incomingByte1 = 0; // for incoming serial data
int colorInterval = 0;

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  Serial1.begin(9600); // opens serial port, sets data rate to 9600 bps

  tft.reset();
  uint16_t id = tft.readID();
  tft.begin(id);
  tft.setRotation(0);     //Portrait
  tft.fillScreen(BLACK);
  tft.setTextColor(RED, BLACK);
  tft.setTextSize(2);     // System font is 8 pixels.  ht = 8*2=16
  tft.setCursor(100, 0);
  tft.print("ID = 0x");
  tft.println(id, HEX);
  delay(500);
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

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    
    if (currLinePrint > 18) {
      tft.setCursor(0, (scroll + top) * ht);
      if (++scroll >= lines) scroll = 0;
      tft.setTextColor(YELLOW, BLACK);
      tft.vertScroll(top * ht, lines * ht, (scroll) * ht);
      tft.print(">");
      line++;
      currLinePrint = 0;
    }

    tft.setTextColor(RED, BLACK);

    tft.print(char(incomingByte));
    currLinePrint++;
  }

  if (Serial1.available() > 0) {
    // read the incoming byte:
    incomingByte1 = Serial1.read();

    if (currLinePrint > 18) {
      tft.setCursor(0, (scroll + top) * ht);
      if (++scroll >= lines) scroll = 0;
      tft.setTextColor(CYAN, BLACK);
      tft.vertScroll(top * ht, lines * ht, (scroll) * ht);
      tft.print(">");
      line++;
      currLinePrint = 0;
    }

    tft.setTextColor(GREEN, BLACK);

    tft.print(char(incomingByte1));
    currLinePrint++;
  }
}
