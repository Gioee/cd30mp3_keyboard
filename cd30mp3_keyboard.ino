
/*    
      BOARD: ARDUINO PRO MICRO

      -=IF R>100Ohm []=KOHM
      +=IF R=0Ohm
      NC = NOT CONNECTED

      USE PULLUP RESISTOR OR INPUT_PULLUP ON THESE PINS
        PIN 14 = nBLU(+AS, +REG, +>, +<, +9, +4, +3)
        PIN 13 = GRIGIO(+TP, +RDS, +SOUND, +SETTINGS, +8, +6, +2)
        PIN 11 = VIOLA(+FM/AM, +BC, +OK, +CD, +1, +5, +7)

      PIN 16 = nVIOLA = +5V (CONNECT TO VCC) (-AS, -REG, -TP, -RDS, -<[18], ->[14], +EJECT, -FAM[4], -CD[18], -SOUND[14], -SETTINGS[18], -BC[9], -OK[14], -1[21], -5[22], -7[20], -2[21], -6[22], -8[21], -3[21], -4[22], -9[21])
      PIN 5 = nGIALLO = GROUND CHAIN (-TP, -RDS, -<[20], ->[22], -EJECT[19], -FAM[21], -CD[20], -SOUND[22], -SETTINGS[20], -BC[22], -OK[22], -1[17], -5[12], -7[4], -2[4], -6[12], -8[17], -3[4], -4[12], -9[17])
      
      PIN 6 = nROSSO(-EJECT[JUST 100Ohm])
      
      ROTARY ENCODER = C (INVERTED FROM PHOTO)
        PIN 16 = C1 +nVIOLA, -nGIALLO[19]
        PIN 9 = C2 +BLU ROTARY ENCODER B
        PIN 16 = C3 +nVIOLA, -nGIALLO[19]
        PIN 10 = C4 +GIALLO ROTARY ENCODER A
        PIN 7 = C5 -nVERDE[1] ROTARY ENCODER PRESS

      PIN 15 = GROUND
      PIN 8 & PIN 12 = NC
      PIN 1, 2, 4 = ARDUINO PIN 3 = LED TRANSISTOR PWM
      PIN 3 = 12V FOR LED
 */

#include <Keyboard.h>

#define C1A 949
#define C1B 954

#define C2A 876
#define C2B 881

#define C3A 792
#define C3B 796

#define C4A 699
#define C4B 706

#define C5A 586
#define C5B 592

#define C6A 441
#define C6B 448

#define C7A 203
#define C7B 209

#define CMAX 1023


int nVERDE, nBLU, GRIGIO, VIOLA, nROSSO, nGIALLO, GIALLO, BLU, lastStateGIALLO = 0;
unsigned long currentTime, encTime, btnTime;
int luminosita;

void setup() {

  currentTime = millis();
  btnTime = currentTime;
  encTime = currentTime;

  pinMode(3, OUTPUT);
  pinMode(A3, INPUT_PULLUP);
  pinMode(A10, INPUT_PULLUP);
  pinMode(A8, INPUT_PULLUP);

  Keyboard.begin();

  Serial.begin(115200);
}

void loop() {

  currentTime = millis();

  if (currentTime >= (encTime + 5)) {  //check every 5ms

    GIALLO = analogRead(A1);  //ENC A
    BLU = analogRead(A2);     // ENC B

    if (((GIALLO - lastStateGIALLO) > 7) && GIALLO == CMAX) {
      if (BLU == 0) {
        Keyboard.write('p');
      } else {
        Keyboard.write('m');
      }

      /*
      Serial.print("LGIALLO:");
      Serial.print(lastStateGIALLO);
      Serial.print(",GIALLO:");
      Serial.print(GIALLO);
      Serial.print(",BLU:");
      Serial.println(BLU);
      */
    }

    lastStateGIALLO = GIALLO;

    encTime = currentTime;
  }

  if (currentTime >= (btnTime + 150)) {  //check every 150ms

    nBLU = analogRead(A3);
    GRIGIO = analogRead(A10);
    VIOLA = analogRead(A8);

    nROSSO = analogRead(A9);

    nVERDE = analogRead(A0);

    switch (nBLU) {
      case C1A ... C1B:
        Keyboard.write('A');
        break;
      case C2A ... C2B:
        Keyboard.write('R');
        break;
      case C3A ... C3B:
        Keyboard.press(KEY_RIGHT_ARROW);
        Keyboard.release(KEY_RIGHT_ARROW);
        break;
      case C4A ... C4B:
        Keyboard.press(KEY_LEFT_ARROW);
        Keyboard.release(KEY_LEFT_ARROW);
        break;
      case C5A ... C5B:
        Keyboard.write('9');
        break;
      case C6A ... C6B:
        Keyboard.write('4');
        break;
      case C7A ... C7B:
        Keyboard.write('3');
        break;
    }

    switch (GRIGIO) {
      case C1A ... C1B:
        Keyboard.write('T');
        break;
      case C2A ... C2B:
        Keyboard.write('D');
        break;
      case C3A ... C3B:
        Keyboard.write('S');
        break;
      case C4A ... C4B:
        Keyboard.write('G');
        break;
      case C5A ... C5B:
        Keyboard.write('8');
        break;
      case C6A ... C6B:
        Keyboard.write('6');
        break;
      case C7A ... C7B:
        Keyboard.write('2');
        break;
    }

    switch (VIOLA) {
      case C1A ... C1B:
        Keyboard.press(KEY_UP_ARROW);
        Keyboard.release(KEY_UP_ARROW);
        break;
      case C2A ... C2B:
        Keyboard.write('B');
        break;
      case C3A ... C3B:
        Keyboard.write('O');
        break;
      case C4A ... C4B:
        Keyboard.press(KEY_DOWN_ARROW);
        Keyboard.release(KEY_DOWN_ARROW);
        break;
      case C5A ... C5B:
        Keyboard.write('1');
        break;
      case C6A ... C6B:
        Keyboard.write('5');
        break;
      case C7A ... C7B:
        Keyboard.write('7');
        break;
    }

    if (nROSSO == CMAX) {
      Keyboard.write('E');
    }

    if (nVERDE == CMAX) {
      Keyboard.press(KEY_TAB);
      Keyboard.release(KEY_TAB);
    }

    btnTime = currentTime;

    /*
    Serial.print("E:");
    Serial.print(nROSSO);
    Serial.print(", V:");
    Serial.print(nVERDE);
    Serial.print("VIOLA:");
    Serial.print(VIOLA);
    Serial.print("GRIGIO:");
    Serial.print(GRIGIO);
    Serial.print("nBLU:");
    Serial.println(nBLU);
    */
  }

  if (Serial.available() > 0) {
    int grab = Serial.parseInt();

    if ((grab > -1) && (grab < 256)) {
      luminosita = grab;
      analogWrite(3, luminosita);
      Serial.println(luminosita);
    }
  }
}
