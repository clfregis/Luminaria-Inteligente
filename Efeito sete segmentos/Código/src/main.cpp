/**
* Código criado por Cláudio Regis responsável por mostrar um exemplo de
* hora no display OLED
* Conexões Físicas
* Display  ->  ESP8266 12E
* D3       ->  SDA
* D5       ->  SCL
*
*
 */
#define size_seg 19

#include <Arduino.h>
// For a connection via I2C using Wire include
#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h"
#include "OLEDDisplayUi.h"  // Include the UI lib (Para fazer multiplas telas)
#include "images.h"         // Include custom images (para printar imagens)

// Inicializa o display OLED usando a biblioteca Wire
SSD1306Wire  display(0x3c, D3, D5);
// Inicializa o UI (user interface, quando tem multiplas telas)
// OLEDDisplayUi ui ( &display );

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

void Data_atual(){
  display.setFont(Roboto_Mono_12);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(1,0, "Tue");
  display.drawVerticalLine(33, 0, 15);
  display.drawVerticalLine(34, 0, 15);
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.drawString(63,0, "29 May");
  display.setTextAlignment(TEXT_ALIGN_RIGHT);
  display.drawVerticalLine(92, 0, 15);
  display.drawVerticalLine(93, 0, 15);
  display.drawString(127,0, "27ºC");
  display.drawHorizontalLine(0, 14, 127);
  display.drawHorizontalLine(0, 15, 127);
}
void Dois_pontos(){
  // Dois pontos
  display.fillRect(62, 30, 4, 4);
  display.fillRect(62, 45, 4, 4);
}
// Função que imita o segmento "a" de um display de 7-segmentos no display OLED.
// Recebe como parametro o digito (um dos quatro disponiveis) em que o segmento será ligado.
void a(int digito){
  // Segmento a
  int valor;
  if(digito==0){valor=0;}
  else if(digito==1){valor=31;}
  else if(digito==2){valor=68;}
  else if(digito==3){valor=99;}
  else{valor=-1000;}
  display.drawHorizontalLine(7+valor, 18, size_seg-4);
  display.drawHorizontalLine(6+valor, 19, size_seg-2);
  display.drawHorizontalLine(5+valor, 20, size_seg);
  display.drawHorizontalLine(6+valor, 21, size_seg-2);
  display.drawHorizontalLine(7+valor, 22, size_seg-4);
}
// Função que imita o segmento "b" de um display de 7-segmentos no display OLED.
// Recebe como parametro o digito (um dos quatro disponiveis) em que o segmento será ligado.
void b(int digito){
  // Segmento b
  int valor;
  if(digito==0){valor=0;}
  else if(digito==1){valor=31;}
  else if(digito==2){valor=68;}
  else if(digito==3){valor=99;}
  else{valor=-1000;}
  display.drawVerticalLine(24+valor, 23, size_seg-4);
  display.drawVerticalLine(25+valor, 22, size_seg-2);
  display.drawVerticalLine(26+valor, 21, size_seg);
  display.drawVerticalLine(27+valor, 22, size_seg-2);
  display.drawVerticalLine(28+valor, 23, size_seg-4);
}
// Função que imita o segmento "c" de um display de 7-segmentos no display OLED.
// Recebe como parametro o digito (um dos quatro disponiveis) em que o segmento será ligado.
void c(int digito){
  // Segmento c
  int valor;
  if(digito==0){valor=0;}
  else if(digito==1){valor=31;}
  else if(digito==2){valor=68;}
  else if(digito==3){valor=99;}
  else{valor=-1000;}
  display.drawVerticalLine(24+valor, 43, size_seg-4);
  display.drawVerticalLine(25+valor, 42, size_seg-2);
  display.drawVerticalLine(26+valor, 41, size_seg);
  display.drawVerticalLine(27+valor, 42, size_seg-2);
  display.drawVerticalLine(28+valor, 43, size_seg-4);
}
// Função que imita o segmento "d" de um display de 7-segmentos no display OLED.
// Recebe como parametro o digito (um dos quatro disponiveis) em que o segmento será ligado.
void d(int digito){
  // Segmento d
  int valor;
  if(digito==0){valor=0;}
  else if(digito==1){valor=31;}
  else if(digito==2){valor=68;}
  else if(digito==3){valor=99;}
  else{valor=-1000;}
  display.drawHorizontalLine(7+valor, 58, size_seg-4);
  display.drawHorizontalLine(6+valor, 59, size_seg-2);
  display.drawHorizontalLine(5+valor, 60, size_seg);
  display.drawHorizontalLine(6+valor, 61, size_seg-2);
  display.drawHorizontalLine(7+valor, 62, size_seg-4);
}
// Função que imita o segmento "e" de um display de 7-segmentos no display OLED.
// Recebe como parametro o digito (um dos quatro disponiveis) em que o segmento será ligado.
void e(int digito){
  // Segmento e
  int valor;
  if(digito==0){valor=0;}
  else if(digito==1){valor=31;}
  else if(digito==2){valor=68;}
  else if(digito==3){valor=99;}
  else{valor=-1000;}
  display.drawVerticalLine(0+valor, 43, size_seg-4);
  display.drawVerticalLine(1+valor, 42, size_seg-2);
  display.drawVerticalLine(2+valor, 41, size_seg);
  display.drawVerticalLine(3+valor, 42, size_seg-2);
  display.drawVerticalLine(4+valor, 43, size_seg-4);
}
// Função que imita o segmento "f" de um display de 7-segmentos no display OLED.
// Recebe como parametro o digito (um dos quatro disponiveis) em que o segmento será ligado.
void f(int digito){
  // Segmento f
  int valor;
  if(digito==0){valor=0;}
  else if(digito==1){valor=31;}
  else if(digito==2){valor=68;}
  else if(digito==3){valor=99;}
  else{valor=-1000;}
  display.drawVerticalLine(0+valor, 23, size_seg-4);
  display.drawVerticalLine(1+valor, 22, size_seg-2);
  display.drawVerticalLine(2+valor, 21, size_seg);
  display.drawVerticalLine(3+valor, 22, size_seg-2);
  display.drawVerticalLine(4+valor, 23, size_seg-4);
}
// Função que imita o segmento "g" de um display de 7-segmentos no display OLED.
// Recebe como parametro o digito (um dos quatro disponiveis) em que o segmento será ligado.
void g(int digito){
  // Segmento g
  int valor;
  if(digito==0){valor=0;}
  else if(digito==1){valor=31;}
  else if(digito==2){valor=68;}
  else if(digito==3){valor=99;}
  else{valor=-1000;}
  display.drawHorizontalLine(7+valor, 38, size_seg-4);
  display.drawHorizontalLine(6+valor, 39, size_seg-2);
  display.drawHorizontalLine(5+valor, 40, size_seg);
  display.drawHorizontalLine(6+valor, 41, size_seg-2);
  display.drawHorizontalLine(7+valor, 42, size_seg-4);
}

// Ponteiro de funções, utilizado para chamar a função correspondente ao segmento
// necessário passando como parâmetro a casa, ou melhor, o dígito correspondente.
void (*numero[7])(int casa) = {a,b,c,d,e,f,g};


void mostrar_hora(int hora, int minuto){
  if(hora>23){/*Condicao de erro*/}
  if(minuto>59){/*Condicao de erro*/}
  const int number[10][7]={
    {0,1,1,0,0,0,0},    // 1
    {1,1,0,1,1,0,1},    // 2
    {1,1,1,1,0,0,1},    // 3
    {0,1,1,0,0,1,1},    // 4
    {1,0,1,1,0,1,1},    // 5
    {1,0,1,1,1,1,1},    // 6
    {1,1,1,0,0,0,0},    // 7
    {1,1,1,1,1,1,1},    // 8
    {1,1,1,1,0,1,1},    // 9
    {1,1,1,1,1,1,0}     // 0
  };

  // Mostra 2 para teste
  for(int i=0;i<7;i++){
    if(number[1][i]==1){
      (*numero[i])(0); // 0 pois vai ligar o primeiro digito(hora_dezena)
    }
  }
// Mostra 0 para teste
for(int i=0;i<7;i++){
  if(number[9][i]==1){
    (*numero[i])(1); // 1 pois vai ligar o segundo digito(hora_unidade)
  }
}
// Mostra 4 para teste
for(int i=0;i<7;i++){
  if(number[3][i]==1){
    (*numero[i])(2); // 2 pois vai ligar o primeiro digito(hora_dezena)
  }
}
// Mostra 9 para teste
for(int i=0;i<7;i++){
  if(number[8][i]==1){
    (*numero[i])(3); // 3 pois vai ligar o primeiro digito(hora_dezena)
  }
}
}

void setup() {
	// The ESP is capable of rendering 60fps in 80Mhz mode
	// but that won't give you much time for anything else
	// run it in 160Mhz mode or just set it to 30 fps
  // ui.setTargetFPS(30);
  // // Initialising the UI will init the display too.
  // ui.init();
  display.init();
  display.flipScreenVertically();
  display.setBrightness(50); // O brilho normal é 100

}


void loop(){
  display.clear();
  Data_atual();
  Dois_pontos();
  // // Mostra 88:88 para teste
  // for (int dig=0;dig<4;dig++){
  //   for (int seg=0;seg<7;seg++){
  //     (*numero[seg])(dig);
  //   }
  // }
  mostrar_hora(10,0);
  display.display();
  delay(5000);
  display.displayOff();
  delay(2000);
  display.displayOn();
}
