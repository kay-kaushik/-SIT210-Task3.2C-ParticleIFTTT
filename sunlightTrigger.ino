int compval = 200; // compare value 
int lightval; // intitailising int which store analog read value
int sensorPin = A5; // pin which takes  analog input 
void setup() {
    pinMode(sensorPin,INPUT);
    pinMode(D7,OUTPUT);
}

void loop() {
    
    digitalWrite(D7,LOW); 
    lightval = analogRead(sensorPin); // reading data
    
    if (lightval > compval){ //if high then publish sunny 
        digitalWrite(D7,HIGH);
        Particle.publish("light_stat","sunny");
        delay(10000);
    }
    else{
        Particle.publish("light_stat","shady"); // else publish shady
        delay(10000);
    }
    
}
