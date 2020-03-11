
void StartupScreen()   {

#define wait1 70 //  50
#define wait2 50

  /*  Horizontal, Vertical, Width, Height  */

  tft.drawRect(0, 0, 480, 320, DarkMAGENTA);
  tft.drawRect(20, 70, 440, 150, WHITE);
  delay(wait1);
  tft.fillRect(40, 90, 50, 100, DarkMAGENTA);
  delay(wait1);
  tft.fillRect(110, 90, 50, 100, DarkMAGENTA);
  delay(wait1);
  tft.fillRect(180, 90, 50, 100, DarkMAGENTA);
  delay(wait1);
  tft.fillRect(250, 90, 50, 100, DarkMAGENTA);    //
  delay(wait1);
  tft.fillRect(320, 90, 50, 100, DarkPINK);  //
  delay(wait1);
  tft.fillRect(390, 90, 50, 100, DarkPINK);  //

  delay(150);

  tft.setTextSize(5);
  tft.setTextColor(WHITE);

  /*  Horizontal, Vertical  */
  tft.setCursor(52, 120);
  tft.print("K");
  delay(wait2);
  tft.setCursor(122, 120);
  tft.print("I");
  delay(wait2);
  tft.setCursor(192, 120);
  tft.print("N");
  delay(wait2);
  tft.setCursor(262, 120);
  tft.print("Z");
  delay(wait2);
  tft.setCursor(332, 120);
  tft.print("Y");
  delay(wait2);
  tft.setCursor(402, 120);
  tft.print("!");
  delay(wait2);

  delay(700);

  tft.setTextSize(1);
  tft.setCursor(180, 230);
  tft.print("Kinzy Tech v1.0");
  tft.print("  -  2020");
  tft.setCursor(200, 260);
  tft.print("www.KinzyTech.com");
}
