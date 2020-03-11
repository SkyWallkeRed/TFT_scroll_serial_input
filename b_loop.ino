
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
      line++;
      if (++scroll >= lines) scroll = 0;
      tft.setCursor(0, (scroll + top) * ht);
      tft.setTextColor(CYAN, BLACK);
      tft.vertScroll(top * ht, lines * ht, (scroll) * ht);
      tft.print(">");

      currLinePrint = 0;
    }
    
    tft.setTextColor(GREEN, BLACK);
    
    tft.print(char(incomingByte1));
    currLinePrint++;
  }
}
