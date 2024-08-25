//Script para ligar dispositivos no arduino
//Dev: Michael M.Sabino

#define lampada2_porta 7  
#define lampada_porta  8   		
#define ventilador_porta  12       

int comando;
boolean lampada = false;
boolean lampada2 = false;
boolean ventilador = false;

void setup(){  
	pinMode(lampada_porta, OUTPUT);
	pinMode(lampada2_porta, OUTPUT);
	pinMode(ventilador_porta, OUTPUT);
	Serial.begin(9600); 
} 
  
void loop(){
  if(Serial.available() > 0){
		comando = Serial.read();

	if(lampada){
		digitalWrite(lampada_porta, HIGH);
	}else{
		digitalWrite(lampada_porta, LOW);
	}
		switch (comando){
			case 'l':lampada = true;break;
			case 'L':lampada = false;break;
		}
	}
    
	if(ventilador){
		digitalWrite(ventilador_porta, HIGH);
	}else{
		digitalWrite(ventilador_porta, LOW);
	}
		switch (comando){
			case 'v':ventilador = true;break;
			case 'V':ventilador = false;break;
		} 

	if(lampada2){
		digitalWrite(lampada2_porta, HIGH);
	}else{
		digitalWrite(lampada2_porta, LOW);
	}
		switch (comando){
			case 'm':lampada2 = true;break;
			case 'M':lampada2 = false;break;
		}      
}