const float Echo=6;
const float Trig=7;
const float Motor=11;

//configuracao inicial
void setup() {                
  Serial.begin (9600);       // inicializa a porta serie 
  pinMode(Echo, INPUT);     // define o pin 6 como entrada (echo)
  pinMode(Trig, OUTPUT);    // define o pin 7 como saida  (triger)
  pinMode(13, 1);            // Define o pin 13 como saida
  pinMode(12, 1);            // Define o pin 13 como saida
  }

void trigger(){
  // gera o trigger 
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);   // gera a onda de trigger a cada 10ms
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  }

long distancia_total(){
  long duracao, distancia;
  duracao = pulseIn(Echo, HIGH);
  distancia = duracao*0.034/2;            // calcula a distancia en centimetros
  return distancia;
  }

void motor(long distancia){
  //Controlo do motor atraves do ultrassonico
  
  analogWrite(Motor,distancia);
  
  }

void loop() {
  long distancia;   
  trigger();
  distancia=distancia_total();
  motor(distancia);

  if (distancia <= 500 || distancia > 10){
    Serial.print(distancia);           // envia o valor da distancia para a porta serial
    Serial.println("cm");              // coloca a distancia em centimetros "cm"
    digitalWrite(13, 0);               // desliga o led 13
    digitalWrite(12, 1);               // liga o led 12
  }
  
   if (distancia <= 10 && distancia >= 1){
    digitalWrite(13, 1);                     // Liga o pin13
    Serial.println("Alarme.......");         // envia a palavra alarme para a porta serial
    digitalWrite(12, 0);               // desliga o led 12
  }
  delay(50);                                // Tempo de espera de 50ms

}
