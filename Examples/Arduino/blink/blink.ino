// 
// Ejemplo Blink para la tarjeta Bast Pro mini M0 de Electroniccats
// 
// Led integrado en la tarjeta - Pin digital 24
// 


int led_pin = 24;  

int t_delay = 100;


void setup() {
  // put your setup code here, to run once:

pinMode(led_pin,OUTPUT);

Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print(led_pin);
digitalWrite(led_pin,HIGH);
delay(t_delay);
digitalWrite(led_pin,LOW);
delay(t_delay);

}
