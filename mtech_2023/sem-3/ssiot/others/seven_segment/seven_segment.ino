/* Seven segment
Segments:            Pins:
          a a a              8 8 8
        f      b          3      7
        f      b          3      7
        f      b          3      7
          g g g              2 2 2
        e      c          4      6
        e      c          4      6
        e      c          4      6
          d d d              5 5 5
*/


//                  a  b  c  d  e  f  g
const byte pins[] = {8, 7, 6, 5, 4, 3, 2};
// For common cathode
const byte digits[] = {
  //gfedcba
  0b0111111,  // 0
  0b0000110,  // 1
  0b1011011,  // 2
  0b1001111,  // 3
  0b1100110,  // 4
  0b1101101,  // 5
  0b1111101,  // 6
  0b0100111,  // 7
  0b1111111,  // 8
  0b1101111  // 9
};
//For common anode
/*const byte digits[] = {
  //gfedcba
  0b1000000,  // 0
  0b1111001,  // 1
  0b0100100,  // 2
  0b0110000,  // 3
  0b0011001,  // 4
  0b0010010,  // 5
  0b0000010,  // 6
  0b1011000,  // 7
  0b0000000,  // 8
  0b0010000  // 9
};*/

void displayNumber(byte number) {
  number = number % 10;  // hold the number within array bounds
  byte d = digits[number];
  for (byte i = 0; i < sizeof(pins); i++) {
    digitalWrite(pins[i], bitRead(d, i));  // turn segments on or off
  }
}

void setup() {
  for (byte j = 0; j < sizeof(pins); j++) {
    pinMode(pins[j], OUTPUT);
  }
}

void loop() {
  // test: display 0 ... 9
  for (byte k = 0; k < 10; k++) {
    displayNumber(k);
    delay(1000);
  }
}