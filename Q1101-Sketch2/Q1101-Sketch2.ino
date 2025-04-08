#define pinBuzzer 9

void setup() {
  pinMode(pinBuzzer, OUTPUT);
  randomSeed(analogRead(0));
}

void som1() {
  int freq = random(1000, 2000);

  for (int nL = 0; nL <= random(100, 2000); nL++) {
    tone(pinBuzzer, freq + (-nL * 2));
    delay(random(.9, 2));
  }

  for (int nL = 0; nL <= random(100, 1000); nL++) {
    tone(pinBuzzer, freq + (nL * 10));
    delay(random(.9, 2));
  }
}

void som2() {
  int freq = random(1000, 2000);

  for (int nL = 0; nL <= random(100, 2000); nL++) {
    tone(pinBuzzer, freq + (nL * 2));
    delay(random(.9, 2));
  }

  for (int nL = 0; nL <= random(100, 1000); nL++) {
    tone(pinBuzzer, freq + (-nL * 10));
    delay(random(.9, 2));
  }
}

void loop() {
  int freq = 2000;

  switch (random(1, 10)) {
    case 1:
      break;  
    case 2:
      break;      
    case 3: 
      som1(); 
      break;
    case 4: 
      som2(); 
      break;
    case 5:
      som1();
      som2();
      break;
    case 6:
      som1();
      som2();
      break;
    case 7:
      som1();
      som2();
      som1();
      break;
    case 8:
      som2();
      som1();
      som2();
      break;
    case 9:
      som1();
      som2();
      som1();
      som2();
      som1();
      break;
  }

  for (int nL = 0; nL <= random(3, 9); nL++) {
    tone(pinBuzzer, freq + random(-1700, 2000));
    delay(random(70, 170));

    noTone(pinBuzzer);
    delay(random(0, 30));
  }

  noTone(pinBuzzer);
  delay(random(2000, 4000));
}
