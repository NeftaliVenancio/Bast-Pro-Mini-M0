//
// Ejemplo deescritura analogica PWM para las Bast Pro Mini M0 de electroniccats
// 
// Pines habilitados para PWM - Pin digital 1, 13. 
//                            - Pin analogico A1
//
//|12
// Pin control de voltaje mediante DAC - Pin analogico A0


// Enciende un led por PWM de o a 255 con un delay de 100ms entre cada aumento de uno en uno, al llegar a 255, espera 500ms e inicia el decremento a 0.

int pwm_led = A1;

int pwm = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(pwm_led,OUTPUT);

Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

analogWrite(pwm_led,pwm);
delay(100);

if(pwm >= 255)
{

  pwm = 0;

  delay(500);

  for(int i = 255; i>0; i--)
  {
    analogWrite(pwm_led,i);
    delay(100);
  }

}
else
{

pwm++;

}

}
