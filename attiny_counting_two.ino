#include <TinyWireM.h>
#include <Tiny4kOLED.h>

// Variables for the counter
unsigned long integerPart = 1;   // Integer part of the counter
unsigned long fractionalPart = 301342540; // 301342540 Fractional part of the counter

// Fonts
const DCfont *defaultFont = FONT6X8;

#include "font8x16atari.h"
const DCfont *primaryFont = FONT8X16ATARI;

#include "font11x16.h"
const DCfont *secondaryFont = FONT11X16;

uint8_t currentCharacter;

void setup() {
  // Initialize the I2C communication
  TinyWireM.begin();

  // Initialize the OLED display
  oled.begin();
  oled.clear();
  oled.on();
  //oled.setFont(currentFont);
}

void loop() {
  // Convert the counter values to strings
  char integerStr[11]; // Enough to hold "4294967295"
  char fractionalStr[10]; // Enough to hold "999999999"
  itoa(integerPart, integerStr, 10);
  sprintf(fractionalStr, "%09lu", fractionalPart); // Ensure 9 digits with leading zeros

  // Display the counter value
  oled.clear();
  oled.setFont(defaultFont);
  oled.setCursor(0, 1);
  oled.print("Global Warming Index");
  oled.setFont(primaryFont);
  oled.setCursor(5, 11);
  oled.print("+");
  oled.print(integerStr);
  oled.print(".");
  oled.print(fractionalStr);
  oled.setCursor(102, 10);
  oled.print("o");
  oled.setCursor(110, 11);
  oled.print("C");/* 
  oled.setFont(defaultFont);
  oled.setCursor(50, 30);
  oled.print("2024"); */

  // Increment the counter
  fractionalPart++;
  if (fractionalPart == 1000000000) { // 1.000000000
    fractionalPart = 0;
    integerPart++;
  }

  // Delay for one second
  delay(1000);
}
