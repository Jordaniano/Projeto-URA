<h1 align="left">
    <a href="https://github.com/Jordaniano/Projeto-URA">Labirinto Quiz</a>
</h1>

> O Labirinto-Quiz é um desafio proposto pelo projeto de extensão Um Robô Por Aluno (URA) realizado na Universidade Federal do Rio Grande do Norte (UFRN), com o intuito de propagar o conhecimento sobre robótica, e assuntos relacionados à base nacional curricular comum para os discentes Secundaristas. 
> O labirinto chega com conhecimentos sobre programação em C++ no Arduino UNO e utiliza os seguintes componentes: LED, LED RGB, Potenciômetro, buzzer, placa de ensaio, e claro, o proprío Arduino.


  <h2 align="left">
    Como jogar:</a>
</h2>

>O jogador tera que responder algumas perguntas baseados na base comum curricular para poder avançar no labirinto. O objetivo é atravessa-lo ligando os Leds que correspondem o caminho até o final do labirinto


<h2 align="left">
    Sobre os componentes:</a>

</h2>

- LEDs:
  > Indicam o caminho que o jogador pecorreu até o final do labirinto
- LED RGB:
  > Indica se o jogador esta seguindo o caminho correto de ou não. Ele varia entre vermelho, amarelo e verde indicando, respectivamente, que o jogador está mais distante a mais perto do final do labirinto
- POTENCIOMETROS:
  > Os potenciomentros controlam os leds dipostos no decorrer do labirinto. O potenciomentro 01 pode ligar os Leds 01 e 02 e o potenciomentro 02  pode ligar os Leds 03 e 04


  
<h2 align="left">
    Sobre o Código: </a>
</h2>

- Definição de pinos:
  > Para começar a realizar um circuito com cada componente, os pinos conectados para os Leds são digitais, com o potênciometro são analógicas, e com o Led RGB, é usado um pino 3.3V e uma digital, para finalizar o circuito dos Leds e os potenciômetros é o usado o GND.
- Declaração de variáveis:
  > Variáveis são criadas para definir quais entradas cada componente irá realizar, sendo elas digitais  ou analógicas.
- Função de configuração (setup):
  > Define o modo dos pinos dos Leds como saída
  > Define o modo dos pinos dos potenciômetros como entrada
- Função “executor”:
  > Responsável por controlar o estado das entradas red, green e blue do Led RGB.
  > Define o tempo de delay na qual as entradas do Led RBG devem ficar ligada.
- Função "action_capture":
  > Define os estados ligados e desligados das entradas do Led RGB.
  > Define o tempo padrão para que os Leds permanecerem ligados
  > Chama a função  “executor” para ligar as entradas necessárias para o Led RGB reproduzir as cores desejadas sendo elas: vermelho, verde e amarelo.
- Função "loop":
  > O circuito começa com o Led_entrada e o Led RGB no vermelho.
  
  > O início do código é dedicado a pegar os valores padrões dos potenciometros (de 0 a 1023) e mapea-los para valores de 0 a 10 afim de tornar a leitura desses valores mais precisas.
  
  > Utilizando a estrutura condicionale If else o valor do Potenciômetro 1 é verificado e se caso a pessoa acerte liga o Led 1 e liga a cor amarelo do Led  RGB caso o valor do potenciometro esteja entre 1 e 5, usando a função “action  capture”/ caso erre o Led 2 irá ligar e o Led RGB continuará no vermelho caso o valor do potenciometro esteja entre 6 a 10.
  
  > Utilizando a estrutura condicionale If else o valor do Potenciômetro 2 e se caso a pessoa acerte liga o Led 3 e liga a cor amarelo do Led  RGB caso o valor do potenciometro esteja entre 1 e 5, usando a função “action  capture”/ caso erre o Led 4 irá ligar e o Led RGB continuará no amarelo caso o valor do potenciometro esteja entre 6 a 10.
  
  > Essas estruturas condicionais definem a leitura de valor 0 dos potenciometros como um indicativo para desligar os Leds ligados pelo labirinto.
  > Caso o Led 1 e 3 estiverem acesos, o Led de saída Ligará e o Led RGB ficará ligado no verde, indicando a vitória do desafio.
<h2 align="left">
    Artigo: </a>
</h2>

<h2 align="left">
     <a href="https://docs.google.com/document/u/1/d/e/2PACX-1vQ1gxdzNtT72nHXmk283pnN9YDIfpJn--Yb9_wYfMGEOX4IdRJCAhf3w3B4JRYZQA/pub">Artigo <--- </a>
</h2>

- [Maria Clara](https://github.com/Clara-Parpinelli)
- [Jordan Ian](https://github.com/Jordaniano)


