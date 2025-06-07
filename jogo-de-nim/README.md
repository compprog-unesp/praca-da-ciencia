# Jogo de Nim

## Explicação do Problema:

O Jogo de Nim é um jogo matemático de estratégia para duas pessoas. Ele funciona assim:

- Existem várias pilhas, e cada pilha contém uma certa quantidade de pedras.

- Os jogadores se revezam, e a cada turno um jogador pode retirar quantas pedras quiser de apenas uma pilha.

- Ganha o jogador que pegar a última pedra do jogo.

Embora pareça um jogo simples, existe uma estratégia matemática que permite ao jogador prever se está em uma posição vencedora ou perdedora. Essa estratégia envolve o uso do XOR binário (ou "Nim-sum") entre as pilhas.

## O que este código faz:

Este projeto contém um programa em C++ que ajuda você a jogar o Jogo de Nim contra outra pessoa, fornecendo dicas estratégicas durante a partida.

Como funciona:

1. Você informa quantas pilhas existem e quantas pedras há em cada uma.

2. O programa analisa a situação e diz quantas pedras tirar e de qual pilha para te deixar em uma posição vencedora.

3. Depois, você informa a jogada que o seu amigo (adversário) fez.

4. O programa repete esse processo até que o jogo termine — ele avisa quando você vencer ou perder.

Este programa foi feito para duas pessoas reais jogarem, sendo que uma delas tem a ajuda do programa. Assim, você pode se divertir com seu amigo e ao mesmo tempo aprender a lógica por trás do jogo.