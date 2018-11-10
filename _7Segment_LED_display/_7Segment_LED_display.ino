
/*
 *    -A--
 *   F    B
 *   |    |
 *    -G--
 *   E    C
 *   |    |
 *    -D--
 * 
 * Digits  ABCDEFGH
 * ---------------------
 * 0       11111100
 * 1       00001100
 * 2       11011010
 * 3       11110010
 * 4       01100110
 * 5       10110110
 * 6       10111110
 * 7       11100000
 * 8       11111110
 * 9       11110110
 * A       11101110
 * B       11111110
 * C       10011100
 * D       11111100
 * E       10011110
 * F       10001110
 */
 




const char segmentPins[7] = {7,6,5,4,3,2,8};
const char segment1 = 9;

const int digits[10] = {
0xFC, // 0
0x0C, // 1
0xDA, // 2
0xF2, // 3
0x66, // 4
0xB6, // 5
0xBE, // 6
0xE0, // 7
0xFE, // 8
0xF6, // 9
};

void setupLEDPins(){
  for(int i=0; i < 7; i++ ){
    pinMode(segmentPins[i], OUTPUT);
  }
  pinMode(segment1, OUTPUT);
}



char isBitSet(int value, int bitPosition){

  return ((value >> bitPosition) & (char)1 );
}


void setLEDOutput(int value, int digit){
digitalWrite(digit, HIGH);
for(int i=0; i < 7; i ++){

  if(isBitSet((value >> 1), i) == 0x01){
    digitalWrite(segmentPins[6-i], HIGH);
    
  }else{
    digitalWrite(segmentPins[6-i],LOW);
  }
  delay(50);
}
  
}

void countToNine(){
  
setLEDOutput(digits[0], segment1);
delay(500);
setLEDOutput(digits[1], segment1);
delay(500);
setLEDOutput(digits[2], segment1);
delay(500);
setLEDOutput(digits[3], segment1);
delay(500);
setLEDOutput(digits[4], segment1);
delay(500);
setLEDOutput(digits[5], segment1);
delay(500);
setLEDOutput(digits[6], segment1);
delay(500);
setLEDOutput(digits[7], segment1);
delay(2000);
setLEDOutput(digits[8], segment1);
delay(500);
setLEDOutput(digits[9], segment1);
}

void setup() {
 
setupLEDPins();

/*
digitalWrite(segment1, HIGH);
digitalWrite(segmentPins[0], HIGH);
digitalWrite(segmentPins[1], HIGH);
digitalWrite(segmentPins[2], LOW);
digitalWrite(segmentPins[3], HIGH);
digitalWrite(segmentPins[4], HIGH);
digitalWrite(segmentPins[5], LOW);
digitalWrite(segmentPins[6], HIGH);
digitalWrite(segmentPins[7], LOW);
*/


}

void loop() {
  // put your main code here, to run repeatedly:

  countToNine();
  delay(1000);

}
