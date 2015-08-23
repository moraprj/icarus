// Variables
int geiger_input = 2;
long count = 0;
long countPerMinute = 0;
long timePreviousMeassure = 0;

void setup(){
  pinMode(geiger_input, INPUT);
  digitalWrite(geiger_input,HIGH);
  
  Serial.begin(9600);

  attachInterrupt(0,countPulse,FALLING);
}

void loop(){
  if (millis()-timePreviousMeassure > 10000){
    countPerMinute = 6*count;
    timePreviousMeassure = millis();
    
    //La variable "countPerMinute" tendrá que ser leída por las Rasberry y almacenada
    //en un archivo de texto junto con la fecha y hora de la medida
    //El formato correcto será de la forma "dd/mm/yyyy hh:mm:ss;countPerMinute"
    //Ejemplo:
    //  24/07/2015 14:35:14;24
    //  24/07/2015 14:35:24;24
    //  24/07/2015 14:35:34;12
    //  24/07/2015 14:35:44;0
    //  24/07/2015 14:35:54;12
    
    //Esta parte se ha usado para la calibración del instrumento en CaLMa
    //Será borrada cuando se compile en el sensor
    //Begin -> GobetWino
    char buffer[20];
    //Serial.print("#S|LOGTEST|[");
    Serial.println(itoa((countPerMinute), buffer, 10));
    //Serial.println("]#");
    //End -> GobetWino
   
    count = 0;
  }
}

void countPulse(){
  detachInterrupt(0);
  count++;
  while(digitalRead(2)==0){
  }
  attachInterrupt(0,countPulse,FALLING);
}
