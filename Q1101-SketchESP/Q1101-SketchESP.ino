// Definindo o pino do buzzer
int pinBuzzer = 4;

char comando;

void toneESP(int pin, int freq, int duty = 127, int resolution = 8) {
  ledcDetach(pin);
  ledcAttach(pin, freq, resolution);
  ledcWrite(pin, duty);
}

void noToneESP(int pin) {
  ledcWrite(pin, 0);
}

// Função para reproduzir um alerta com várias frequências
void alerta(int *frequencias, int tamanho, int tempo, int repete) {
  for (int nL = 0; nL < repete; nL++) {
    for (int i = 0; i < tamanho; i++) {
      toneESP(pinBuzzer, frequencias[i]);  // Reproduz o som na frequência definida
      delay(tempo);                     // Duração de cada tom
    }
  }
  noToneESP(pinBuzzer);
}

void setup() {
  pinMode(pinBuzzer, OUTPUT);
  Serial.begin(9600);

  int alerta1[] = { 1000, 1500, 1000 };  // Frequências do alerta 1
  alerta(alerta1, 3, 50, 2);             // Chama a função para tocar o alerta 1
}

void loop() {

  if (Serial.available()) {
    comando = Serial.read();
    Serial.print(comando);

    switch (comando) {
      case '1': {
        int alerta1[] = { 1000, 1500, 1000 };  // Frequências do alerta 1
        alerta(alerta1, 3, 50, 2);             // Chama a função para tocar o alerta 1
        break;
      }

      case '2': {
        // Alerta 2: Alerta longo com várias frequências
        int alerta2[] = { 500, 600, 700, 600, 500 };  // Frequências do alerta 2
        alerta(alerta2, 5, 50, 3);                    // Chama a função para tocar o alerta 2
        break;
      }

      case '3': {
        // Alerta 3: Alerta curto com várias frequências
        int alerta3[] = { 1000, 1200, 1400, 1200, 1000 };  // Frequências do alerta 3
        alerta(alerta3, 5, 100, 1);                        // Chama a função para tocar o alerta 3
        break;
      }

      case '4': {
        for (int i = 0; i < 5; i++) {  // Repetir a sequência 5 vezes
          // Frequências altas e baixas para simular uma sirene
          for (int j = 1000; j < 2000; j += 100) {  // Subindo de 1000 Hz para 2000 Hz
            toneESP(pinBuzzer, j);
            delay(20);  // Duração de cada tom
          }
          for (int j = 2000; j > 1000; j -= 100) {  // Descendo de 2000 Hz para 1000 Hz
            toneESP(pinBuzzer, j);
            delay(20);  // Duração de cada tom
          }
        }
        noToneESP(pinBuzzer);
        break;
      }

      case '5': {
        toneESP(pinBuzzer, 1000, 60);  // bip agudo, como se fosse um sensor
        delay(100);

        // repetição rápida
        for (int i = 0; i < 3; i++) {
          toneESP(pinBuzzer, 700, 50);
          delay(70);
        }

        noToneESP(pinBuzzer);  // Para o som
        break;
      }
    }
  }
}