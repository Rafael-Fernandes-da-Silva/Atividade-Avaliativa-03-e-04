#include <stdio.h>
#include <stdlib.h>
#define TAM 10
#define true 1
#define false 0

void mostrar(int *vetor) { //Realiza um loop que exibe o vetor.
    int i = 0;

    for(i = 0; i < TAM; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int calcularGap(int gap) {
    gap = gap / 1.3; //Se a divisão resultar em float, será convertido para inteiro
    if(gap < 1) {    //Caso o resultado da divisão seja menor que um,
        return 1;    // então o "gap" será 1(distancia de um elemento).
    }
    return gap;
}

void trocarLugares(int *primeiro, int *segundo) { //Foi utilizado passagem de parametros por referencia.
    int auxiliar = *primeiro;                     //Atribui o valor do "primeiro" na variável "auxiliar".
    *primeiro = *segundo;                         //Atribui o valor do "segundo" para o "primeiro".
    *segundo = auxiliar;                          //Atribui o valor do "auxiliar" ao "segundo".
}

void combSort(int *vetor, int tamanho) {
    int i = 0;
    int gap = tamanho;       //O "gap" e o elemento entre dois outros elementos,
    int houveTrocaDeLugares; // entre 1 2 3, o gap = 2.

    do {
        gap = calcularGap(gap);      //Calcula o valor do "gap" a cada looping.
        houveTrocaDeLugares = false; //Verifica se elementos trocaram de lugar.

        for(i = 0; i < tamanho - gap; i++) {               //Anda pelo vetor a partir do "gap".
            if( vetor[i] > vetor[i + gap]) {               //Compara cada elemento com "gap".
                trocarLugares(&vetor[i], &vetor[i + gap]); //Caso seja maior, ha troca de elementos.
                houveTrocaDeLugares = true;                //Muda o valor da variavel "houveTrocaDeLugares".
            }
        }
    }
    while(gap != 1 || houveTrocaDeLugares == true); //Enquanto "gap" for diferente de 1 ou "houveTrocaDeLugares",
}                                                   // igual a true, repetira o loop.

int main() {
    int vetor[TAM] = {3, 2, 1, 5, 4, 9, 7, 8, 6, 0};

    combSort(vetor, TAM);
    printf("\n Vetor organizado: \n");
    mostrar(vetor);

    return 0;
}