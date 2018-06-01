/**
* Código criado por Cláudio Regis responsável por mostrar um exemplo de
* hora no display OLED
*
*
 */
#include <Arduino.h>
// For a connection via I2C using Wire include
#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"`
// or #include "SH1106Wire.h", legacy include: `#include "SH1106.h"`
// For a connection via I2C using brzo_i2c (must be installed) include
// #include <brzo_i2c.h> // Only needed for Arduino 1.6.5 and earlier
// #include "SSD1306Brzo.h"
// #include "SH1106Brzo.h"
// For a connection via SPI include
// #include <SPI.h> // Only needed for Arduino 1.6.5 and earlier
// #include "SSD1306Spi.h"
// #include "SH1106SPi.h"

// Include the UI lib (Para fazer multiplas telas)
#include "OLEDDisplayUi.h"
// Include custom images (para printar imagens)
#include "images.h"

// Use the corresponding display class:

// Conexões
// Display  ->  ESP8266 12E
// D3       ->  SDA
// D5       ->  SCL

// Inicializa o display OLED usando a biblioteca Wire
SSD1306Wire  display(0x3c, D3, D5);
// Inicializa o UI (user interface, quando tem multiplas telas)
OLEDDisplayUi ui ( &display );

// Função util para relogio digital: Printa 0 a esquerda
// String twoDigits(int digits){
//   if(digits < 10) {
//     String i = '0'+String(digits);
//     return i;
//   }
//   else {
//     return String(digits);
//   }
// }

// void claudioOverlay(OLEDDisplay *display, OLEDDisplayUiState* state) {
//   display->setTextAlignment(TEXT_ALIGN_RIGHT);
//   display->setFont(ArialMT_Plain_10);
//   display->drawString(128, 50, String("Claudio"));
// }

void frameOverlay(OLEDDisplay *display, OLEDDisplayUiState* state) {
  display->drawHorizontalLine(0, 0, 128);   // Linha na horizontal em cima
  display->drawHorizontalLine(0, 7, 128);   // Linha na horizontal em cima
  display->drawHorizontalLine(0, 63, 128);  // Linha na horizontal em baixo
  display->drawVerticalLine(0, 0, 64);      // Linha na vertical na esquerda
  display->drawVerticalLine(127, 0, 64);    // Linha na vertical na direita

}

void drawFrame1(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  // Use http://resizeimage.net/ para redimensionar o icone e salve em BMP
  // Use https://www.online-utility.org/image/convert/to/XBM para converter para XBM
  // Abra o arquivo com o Atom e salve com um nome apropriado no image.h
  display->drawXbm(34, 14, Icon_width, Icon_height, Calendario_icon);

}
void drawFrame2(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  // Use http://resizeimage.net/ para redimensionar o icone e salve em BMP
  // Use https://www.online-utility.org/image/convert/to/XBM para converter para XBM
  // Abra o arquivo com o Atom e salve com um nome apropriado no image.h
  display->drawXbm(34, 14, Icon_width, Icon_height, Nuvem_icon);

}
void drawFrame3(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  // Use http://resizeimage.net/ para redimensionar o icone e salve em BMP
  // Use https://www.online-utility.org/image/convert/to/XBM para converter para XBM
  // Abra o arquivo com o Atom e salve com um nome apropriado no image.h
  display->drawXbm(34, 14, Icon_width, Icon_height, NuvemSol_icon);

}
void drawFrame4(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  // Use http://javl.github.io/image2cpp/
  // Para criar o arquivo XBM
  display->drawXbm(34, 14, Icon_width, Icon_height, Relogio_icon);

}
void drawFrame5(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  // Use http://resizeimage.net/ para redimensionar o icone e salve em BMP
  // Use https://www.online-utility.org/image/convert/to/XBM para converter para XBM
  // Abra o arquivo com o Atom e salve com um nome apropriado no image.h
  display->drawXbm(34, 14, Icon_width, Icon_height, Temperatura_icon);

}

// This array keeps function pointers to all frames
// frames are the single views that slide in
FrameCallback frames[] = { drawFrame1, drawFrame2, drawFrame3, drawFrame4, drawFrame5 };

// how many frames are there?
int frameCount = 5;


// // Overlays are statically drawn on top of a frame eg. a clock
 OverlayCallback overlays[] = { frameOverlay };
 int overlaysCount = 1;

void setup() {
	// The ESP is capable of rendering 60fps in 80Mhz mode
	// but that won't give you much time for anything else
	// run it in 160Mhz mode or just set it to 30 fps
  ui.setTargetFPS(60);

	// Customize the active and inactive symbol
  ui.setActiveSymbol(activeSymbol);
  ui.setInactiveSymbol(inactiveSymbol);

  // You can change this to
  // TOP, LEFT, BOTTOM, RIGHT
  ui.setIndicatorPosition(TOP);

  // Defines where the first frame is located in the bar.
  ui.setIndicatorDirection(LEFT_RIGHT);

  // You can change the transition that is used
  // SLIDE_LEFT, SLIDE_RIGHT, SLIDE_UP, SLIDE_DOWN
  ui.setFrameAnimation(SLIDE_LEFT);

  // Add frames
  ui.setFrames(frames, frameCount);

  // Add overlays
  ui.setOverlays(overlays, overlaysCount);

  // Initialising the UI will init the display too.
  ui.init();

  display.flipScreenVertically();

}


void loop() {
  int remainingTimeBudget = ui.update();

  if (remainingTimeBudget > 0) {
    // You can do some work here
    // Don't do stuff if you are below your
    // time budget.
    delay(remainingTimeBudget);

  }


}
