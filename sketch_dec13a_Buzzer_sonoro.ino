//Declaramos os pinos que vamos a usar
int digPin = 6;   //Pino Digital 6 para o sensor de presença
int pinBuzzerA = 7;    //Digital 7 para o buzzer

//Declara uma variável para armazenar o valor que o sensor devolve
int valor = 0; 

void setup()
{
  Serial.begin(9600);   //Inicia o console serial
  pinMode(digPin, INPUT);  //Configuramos o pino digital 6 como entrada
}

void loop()
{
  
  valor = digitalRead(digPin);    //Lê o valor do sensor e atribui a variável valor
  Serial.println(valor);          //Imprime no console o valor do sensor
  if(valor)                   //Se o valor é verdadeiro ou seja igual a 1, faça
  {
   
    Serial.println("DETECTADO");    //Imprime a mensagem DETECTADO no console
    sonoro();           //chama a função sonoro() do buzzer ligado
    
  }
  else                            //Se não faça
  {
    Serial.println("NADA DETECTADO");       //Imprime no console a mensagem NADA DETECTADO
    //noTone(pinBuzzerA);                     //Desliga o Buzzer
  }
  
    
  
}


//Função que liga/desliga o Buzzer como um alarme

void sonoro(){
  int duracao = 1000;
  
  tone(pinBuzzerA, 250, duracao);
  delay(60);
  noTone(pinBuzzerA);
  delay(60);
}
