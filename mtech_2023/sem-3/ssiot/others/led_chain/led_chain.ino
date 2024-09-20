void setup() {
  int i;
  for ( i = 2; i <= 7; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  int i, loop;

  // for ( i = 2; i <= 7; i++) {
  //   digitalWrite(i, HIGH);
  //   delay(500);                    
  //   digitalWrite(i, LOW); 
  //   delay(500);  
  // }
  // for ( i = 7; i >= 2; i--) {
  //   digitalWrite(i, HIGH);
  //   delay(500);                    
  //   digitalWrite(i, LOW); 
  //   delay(500);  
  // }
  for (loop = 0; loop < 4; loop++) {
    for ( i = 2; i <= 7; i++) {
      digitalWrite(i, HIGH);
      delay(50);                    
      digitalWrite(i, LOW); 
      delay(50);  
    }
    for ( i = 7; i >= 2; i--) {
      digitalWrite(i, HIGH);
      delay(50);                    
      digitalWrite(i, LOW); 
      delay(50);  
    }
  }
  for (loop = 0; loop < 6; loop++) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    delay(50);                    
    digitalWrite(2, LOW); 
    digitalWrite(3, LOW); 
    digitalWrite(4, LOW); 
    digitalWrite(5, LOW); 
    digitalWrite(6, LOW); 
    digitalWrite(7, LOW); 
    delay(50);  
  }
}
