# LICASER
O LICASER, sigla para Little Car Service, foi desenvolvido com a finalidade de ser um hardware capaz de ser usado em aparelhos para transporte de carga de pequeno porte, como: cadeiras de rodas e carros para transportes de cargas em armazéns. O intuito principal do projeto é simplificar processos que são feitos de formas braçais, melhorando a condição de vida ou de trabalho dos usuários.

<div align="center">
<img src = "https://raw.githubusercontent.com/MateusFreitas-C/LICASER/main/Fotos/logo.jpeg">
</div>

Este projeto, desenvolvido em grupo, objetiva a obtenção da última nota na disciplina de Introdução à Engenharia da Computação, da Universidade Federal da Paraíba (UFPB).  
A imagem abaixo trata-se de um exemplo de modelagem em 3D das principais aplicações do LICASER, sendo elas um Carro para Transporte de Cargas e uma Cadeira de Rodas.

<div align="center">
<img src = "https://github.com/MateusFreitas-C/LICASER/blob/main/Fotos/Design_projeto.jpeg">
</div>

# Materiais Utilizados e Orçamento:
   | Item | Preço |
   |---|---|
   | 1 Arduino UNO R3 | R$ 45,90 | 
   | 1 Acionador de Motor Ponte H | R$ 25,00 |
   | 2 Motores DC | R$ 26,00 |
   | 1 Bateria V | R$ 9,00 |
   | 1 Sensor Infravermelho | R$ 4,00 |
   | 1 Sensor Ultrassônico HC-SR04 | R$ 14,00 |
   | 1 Controle Remoto | R$ 6,56 |
   | 1 Protoboard 830 furos | R$ 15,00 |
   | 27 Jumpers | R$ 9,90 |
   | Total | R$ 155,36 |
   
   # Etapas do Desenvolvimento e Funcionamento
   
   Abaixo será descrita as etapas da realização do circuito e código do projeto.
   O circuito foi feito utilizando o simulador de Arduino Tinkercad.
   
   ## 1º Passo:
   As primeiras conexões realizadas foram a do Arduino com a protoboard, e em seguida foram ligados os motores na Ponte H.
   
   ## 2º Passo:
   Foram feitos os códigos para acionamento dos motores, que inicialmente era ligados por Monitor Serial.
   
   ## 3º Passo:
   Após certificar que as funções estavam funcionando corretamente, foi colocado o Sensor Infravermelho e o Controle Remoto, e ajustado o código para receber os valores do controle.  
   Botão 2 o motor gira para frente;    
   Botão 4 o motor gira alternadamente fazendo com que vire para a esquerda;  
   Botão 6 o motor gira alternadamente fazendo com que vire para a direita;  
   Botao 8 o motor gira para trás;  
   Botão Power o motor para;  

  ## 4º Passo:
  Por fim foi ligado o Sensor Ultrassônico, e atribuido uma função para calcular a distância do LICASER até um obstáculo. Esse sensor fica na parte de trás do LICASER e funciona quando está na função de dar ré. Quando a distância for menor que 30cm, por segurança, o motor desliga.
  
  
  A imagem abaixo mostra a esquematização do circuito feito no Tinkercad.
<div align="center">
<img src = "https://raw.githubusercontent.com/MateusFreitas-C/LICASER/main/Fotos/Esquematizacao_hardware.png">
</div>
  
# Colaboradores

[Marcos Oliveira](https://github.com/MarcosOliver16)  
[Mateus Freitas](https://github.com/MateusFreitas-C)  
[Vinicius Fernandes](https://github.com/Vinifernandess)  
