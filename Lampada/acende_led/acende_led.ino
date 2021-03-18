    //acender lampada com app
    #define lampada_porta  8      

    int comando; 
    boolean lampada = false;  

    void setup() {  
        pinMode(lampada_porta, OUTPUT);
        Serial.begin(9600); 
      } 
      
    void loop(){
      if (Serial.available() > 0) {
        comando = Serial.read();
      
      if (lampada) {
      digitalWrite(lampada_porta, HIGH);
      }
      else {
        digitalWrite(lampada_porta, LOW);
        }
       switch (comando) {
         case 'L':lampada = true;break;
         case 'l':lampada = false;break;
         }
       }
    }
