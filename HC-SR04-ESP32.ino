const int trigger = 26; // Pino 26 conectado ao TRIG do HC-SR04
const int echo = 27; // Pino 27 conectado ao ECHO do HC-SR04
const int led = 13;  // Pino 13 conectado ao LED

void setup() {
  Serial.begin(115200); // Inicializa a comunicação serial
  pinMode(trigger, OUTPUT); // Configura o pino TRIG como saída
  pinMode(echo, INPUT);  // Configura o pino ECHO como entrada
  pinMode(led, OUTPUT);  // Configura o pino LED como saída
}

void loop() {
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  
  long duracao = pulseIn(echo, HIGH); // Mede o tempo de resposta do ECHO
  float distancia = (duracao * 0.0343) / 2;// Calcula a distância usando a velocidade do som (aproximadamente 343 m/s)
  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println(" cm");
  
  if (distancia <= 10) // quando estiver menor ou igual a 10 cm enviará um alerta. ** Valor editável para a distância preferir.
  {
    digitalWrite(led, HIGH); // Acende o LED se a distância for menor ou igual a 10 cm
  } else {
    digitalWrite(led, LOW);  // Desliga o LED caso contrário
  }
  
  delay(500); // Aguarda antes de fazer a próxima leitura
}