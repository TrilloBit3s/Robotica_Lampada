//Michael moraes sabino
//trillobit3s@gmail.com   -   estuartyy@gmail.com
//10/11/2023
//Lampada APP Numero 2 

#include <SoftwareSerial.h> //Biblioteca para conectar com o bluetooth (já vem instalado), não precisa baixar

SoftwareSerial BT(8,9); // Portas para o serial do bluetooth (RX, TX)

#define led1 4 // Pinos digitais dos leds
#define led2 7

int Valor_BT; // Variável que vai ler o valor enviado pelo bluetooth 

void setup(){ 
  BT.begin(9600); //Início da serial do bluetooth

  pinMode(led1, OUTPUT); //Ligando a saída dos leds
  pinMode(led2, OUTPUT);
  digitalWrite(led1,LOW); //Garantir que os LEDs estejam desligados antes do comando
  digitalWrite(led2,LOW);
}

void loop() 
{
  if (BT.available()){ //Se o bluetooth estiver funcionando, vai ler o "valor", para reproduzir o comando
    Valor_BT = BT.read();
  }
  if (Valor_BT=='A'){ //Leitura dos valores para saber se deve acender ou não o LED
    digitalWrite (led1,HIGH);
  }
  if (Valor_BT=='a'){
    digitalWrite (led1,LOW);
  }
  if (Valor_BT=='B'){
    digitalWrite (led2,HIGH);
  }
  if (Valor_BT=='b'){
    digitalWrite (led2,LOW);
  }
  if (Valor_BT=='D'){
    digitalWrite (led1,HIGH);
    digitalWrite (led2,HIGH);
    delay(350);
    digitalWrite (led1,LOW);
    digitalWrite (led2,LOW);
    delay(350);
  }
  if (Valor_BT=='d'){
    digitalWrite (led1,LOW);
    digitalWrite (led2,LOW);
  }
}