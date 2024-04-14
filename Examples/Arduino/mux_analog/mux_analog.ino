
int n_sensores = 16;

int s[] = {A0,A1,A2,A3}; //pines de selecciòn para el multiplexor

int sen[] = {A4, A5}; // pines de lectura analogica para los dos multiplexores


//Variables de lectura 
int lec[16][2];  //almacenamiento del multiplexor 1


int comb[16][4] = { //Matrix de 16x4

                {0,0,0,0}, //0
                {0,0,0,1}, //1
                {0,0,1,0}, //2
                {0,0,1,1}, //3
                {0,1,0,0}, //4
                {0,1,0,1}, //5
                {0,1,1,0}, //6
                {0,1,1,1}, //7
                {1,0,0,0}, //8
                {1,0,0,1}, //9
                {1,0,1,0}, //10
                {1,0,1,1}, //11
                {1,1,0,0}, //12
                {1,1,0,1}, //13
                {1,1,1,0}, //14
                {1,1,1,1}, //15

                };


void setup() {
  // put your setup code here, to run once:

  for (int i = 0; i<= 3; i++)
  {
    pinMode(s[i],OUTPUT);
  }

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(" ");

  for (int j = 0; j<= n_sensores-1 ; j++)
  {
    digitalWrite(s[0],comb[j][0]);
    digitalWrite(s[1],comb[j][1]);
    digitalWrite(s[2],comb[j][2]);
    digitalWrite(s[3],comb[j][3]);

    lec[j][0] = analogRead(sen[0]);
    lec[j][1] = analogRead(sen[1]);

    Serial.print("  s");
    Serial.print(j);
    Serial.print(" = ");
    Serial.print(lec[j][0]);

    delay(100);
  }


}
