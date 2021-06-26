#include <IRremote.h>	// Biblioteca de funcionamento do controle remoto

//Constantes simbólicas do sensor ultrassônico

#define TRIGGER 10
#define ECHO 9

// Constantes simbólicas para desligar o motor

#define DIST_SEGURA 30  // Distancia segura de 30cm quando estiver em ré para não bater
#define COD_RE -26521   // Código recebido no loop depois de apertar o botão da ré e antes de receber outro valor  

//Variáveis do acionador do motor

int ativador_A = 3;		// Ativa canal 3 e 4
int entrada_1 = 7;		// Entrada 1 da Ponte H (Canal 3 e 4)
int entrada_2 = 8;		// Entrada 2 da Ponte H (Canal 3 e 4)
int entrada_3 = 2;		// Entrada 1 da Ponte H (Canal 1 e 2)
int entrada_4 = 4;		// Entrada 2 da Ponte H (Canal 1 e 2)
int ativador_B = 5;		// Ativa canal 1 e 2

// Variáveis do sensor infravermelho

int pinoRecepitorIR = 6;// Pino onde está ligado o sensor
int valorRecebido;		// Variável para receber valores do controle
int right = 0xFF6897;	// Valor botão 6 = ir para direita
int left = 0xFF28D7;	// Valor botão 4 = ir para esquerda
int foward = 0xFF8877;	// Valor botão 2 = ir pra frente
int back = 0xFF9867;	// Valor botão 8 = ir para trás (ré)
int stop = 0xFF;		// Valor botão power = parar

double duracao; //Variável para armazenar a duração do pulso do sensor ultrassônico
double dist;    //Variável para armazenar a distância convertida em cm

// Habilita o pino para receber informações do controle remoto
IRrecv irrecv(pinoRecepitorIR);
decode_results results; // Armazena as informações do controle remoto

//Função para calcular a distância do pulso
double calculoD() {

  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite (TRIGGER, LOW);

  duracao = pulseIn(ECHO, HIGH);

  return 2 * (duracao / 58);
}

//Função para ir para frente
void frente() {

  /*Ligando uma entrada, e desativando outra controla
    o sentido da corrente */
  //Sentido para frente//
  digitalWrite(entrada_1, HIGH);
  digitalWrite(entrada_2, LOW);

  digitalWrite(entrada_3, HIGH);
  digitalWrite(entrada_4, LOW);
}

// Função para ir de ré
void re() {

  // Inverso da função anterior, sentido reverso
  digitalWrite(entrada_1, LOW);
  digitalWrite(entrada_2, HIGH);

  digitalWrite(entrada_3, LOW);
  digitalWrite(entrada_4, HIGH);

}

//Função para virar à esquerda
void esquerda() {

  // Um motor para frente e outro para trás para o carro virar
  digitalWrite(entrada_1, LOW);
  digitalWrite(entrada_2, HIGH);

  digitalWrite(entrada_3, HIGH);
  digitalWrite(entrada_4, LOW);
}

//Função para virar à direita
void direita() {

  // Um motor para frente e outro para trás para o carro virar
  // Agora no sentido inverso ao anterior

  digitalWrite(entrada_1, HIGH);
  digitalWrite(entrada_2, LOW);

  digitalWrite(entrada_3, LOW);
  digitalWrite(entrada_4, HIGH);
}

//Função para parar
void parar() {

  // Todos motores param
  digitalWrite(entrada_1, LOW);
  digitalWrite(entrada_2, LOW);

  digitalWrite(entrada_3, LOW);
  digitalWrite(entrada_4, LOW);
}

void setup() {

  // Incializa o monitor serial
  Serial.begin(9600);

  // Inicializa o acionador de motor
  pinMode(ativador_A, OUTPUT);
  pinMode(entrada_1, OUTPUT);
  pinMode(entrada_2, OUTPUT);
  pinMode(ativador_B, OUTPUT);
  pinMode(entrada_3, OUTPUT);
  pinMode(entrada_4, OUTPUT);

  irrecv.enableIRIn(); // Inicializa o receptor IR

  digitalWrite(ativador_A, HIGH); // Liga o ativador da Ponte H (Canal 3 e 4)
  digitalWrite(ativador_B, HIGH); // Liga o ativador da Ponte H (Canal 1 e 2)

}

void loop() {

  // Atribui o resultado da função de calcular distância para a variável dist
  dist = calculoD();
  // Exibe no monitor serial a distância e o valor recebido enquanto nada é pressionado no controle remoto
  Serial.println(dist);
  Serial.println(valorRecebido);

  // Caso a distância seja menor que a distância segura definida e o código seja o código usado na Ré o motor para
  if (dist < DIST_SEGURA && valorRecebido == COD_RE) {
    parar();
  }

  // Recebe os valores do controle remoto
  if (irrecv.decode(&results)) {

    //Exibe no monitor serial os valores Hexadecimais lidos do controle
    Serial.print("Valor lido : ");
    Serial.println(results.value, HEX);
    valorRecebido = (results.value);
    //Atribui esses valores para a variável "ValorRecebido"

    // Caso seja igual ao botão definido para ir para frente
    if (valorRecebido == foward) {
      frente(); // Executa a função de ir para frente
    }
    
    // Caso seja igual ao botão definido para virar para direita
    if (valorRecebido == right) {
      direita(); // Executa a função de virar para direita
    }
    
    // Caso seja igual ao botão definido para virar para esquerda
    if (valorRecebido == left) {
      esquerda(); //Executa a função de virar para esquerda
    }
    
    // Caso seja igual ao botão definido para ir para trás
    if (valorRecebido == back) {
      dist = calculoD(); 
      Serial.println(dist);
      re(); // Executa a função de ir para trás
    }
    
    // Caso seja igual ao botão definido para desligar os motores
    if (valorRecebido == stop) {
      parar(); // Executa a função que desliga os motores
    }
    irrecv.resume(); /*Caso nenhum botão seja pressionado,
    sabendo por experimentação que os códigos quando nenhum botão é pressionado não são iguais aos hexadecimais,
    essa função espera um novo botão ser apertado.*/
    dist = calculoD();
  }
}