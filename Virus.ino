const int a=13;
const int b=12;
const int c=11;
const int d=10;
const int e=9;
const int f=8;
const int g=7;
const int STOP=5;
const int reseteacion = 3;
int aux = 0;
int pos = 0;
int posN = 0;
int cont = 0;



int nulO(){
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}
int cero(){
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);
  posN = 0;
}
int uno(){
digitalWrite(a,LOW);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,LOW);
digitalWrite(e,LOW);
digitalWrite(f,LOW);
digitalWrite(g,LOW);
posN = 1;
}
int dos(){
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,LOW);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,LOW);
digitalWrite(g,HIGH);
posN = 2;
}
int tres(){
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,LOW);
digitalWrite(f,LOW);
digitalWrite(g,HIGH);  
posN = 3;
}
int cuatro(){
digitalWrite(a,LOW);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,LOW);
digitalWrite(e,LOW);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);  
posN = 4;
}
int cinco(){
digitalWrite(a,HIGH);
digitalWrite(b,LOW);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,LOW);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
posN = 5;
}
int seis(){
digitalWrite(a,HIGH);
digitalWrite(b,LOW);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
posN = 6;
}
int siete(){
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,LOW);
digitalWrite(e,LOW);
digitalWrite(f,LOW);
digitalWrite(g,LOW);
posN = 7;
}
int ocho(){
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
posN = 8;
}
int nueve(){
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,LOW);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
posN = 9;
}

 

void Ascendente(){
  cero();
  detener();
  delay(500);
  uno();
  detener();
  delay(500);
  dos();
  detener();
  delay(500);
  tres();
  detener();
  delay(500);
  cuatro();
  detener(); 
  delay(500);
  cinco();
  detener();
  delay(500);
  seis();
  detener();
  delay(500);
  siete();
  detener();
  delay(500);
  ocho();
  detener();
  delay(500);
  nueve();
  detener();
  delay(500);
}

 

void Descendente(){
  nueve();
  detener();
  delay(500);
  ocho();
  detener();
  delay(500);
  siete();
  detener();
  delay(500);
  seis();
  detener();
  delay(500);
  cinco();
  detener();
  delay(500);
  cuatro();
  detener();
  delay(500);
  tres();
  detener();
  delay(500);
  dos();
  detener();
  delay(500);
  uno();
  detener();
  delay(500);
  cero();
  detener();
  delay(500);
}

void leer(){
    aux = digitalRead (STOP);
    delay(500);
    Serial.println(aux);
 }

void detener(){
  pos = posN;
  cont = 0;
  aux = 0;
  for(int i=0; i<3; i++){
    aux = digitalRead(STOP);
    cont = cont + aux;
    delay (500);
  }
  
  if (cont >=2){
    Serial.println(pos, "Numero Capturado");
    Serial.println("Marque Posicion en 2, 1 YAAAA");
    delay(1500);
    if (digitalRead(STOP) == LOW){
      
      if(pos < 0){
        cero();
      delay(500);
      }
      if(pos < 1){
        uno();
      }
      delay(500);
      if(pos < 2){
        dos();
      }
      delay(500);
      if(pos < 3){
        tres();
      }
      delay(500);
      if(pos < 4){
        cuatro();
      }
      delay(500);
      if(pos < 5){
        cinco();
      }
      delay(500);
      if(pos < 6){
        seis();
      }
      delay(500);
      if(pos < 7){
        siete();
      }
      delay(500);
      if(pos < 8){
        ocho();
      }
      delay(500);
      if(pos < 9){
        nueve();
      }
      delay(500);
      loop();
      
      digitalWrite(reseteacion,HIGH);

    }
    
    if(digitalRead(STOP) == HIGH){
      if(pos > 9){
        nueve();
      }
      delay(500);
      if(pos > 8){
        ocho();
      }
      delay(500);
      if(pos > 7){
        siete();
      }
      delay(500);
      if(pos > 6){
        seis();
      }
      delay(500);
      if(pos > 5){
        cinco();
      }
      delay(500);
      if(pos > 4){
        cuatro();
      }
      delay(500);
      if(pos > 3){
        tres();
      }
      delay(500);
      if(pos > 2){
        dos();
      }
      delay(500);
      if(pos > 1){
        uno();
      }
      delay(500);
      if(pos > 0){
        cero();
      }
      delay(500);
      loop();

      digitalWrite(reseteacion,HIGH);
    }
  }
}


void setup()
{
  Serial.begin(9600);
pinMode(a,OUTPUT);
pinMode(b,OUTPUT);
pinMode(c,OUTPUT);
pinMode(d,OUTPUT);
pinMode(e,OUTPUT);
pinMode(f,OUTPUT);
pinMode(g,OUTPUT);
pinMode(reseteacion,OUTPUT);
pinMode(STOP,INPUT);

}
void loop()
{
  Serial.println("Presione el pulsador: ");
  leer();
  if (aux == 0){
    Ascendente();
  }else{
    nulO();
  }
  if (aux == 1){
    Descendente();
  }else{
    nulO();
  }

}
