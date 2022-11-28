#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_sorted(int *a, int n) {
    while ( --n >= 1 ) {                   //A condicao so e verdadeira se houver mais de um elemento.
        if ( a[n] < a[n-1] ) return false; //Condicao que verifica se o total de elementos do vetor for menor que o total - 1,
    }                                      // se a condicao for falsa, significa que os elementos estao em ordem, retorna true,
    return true;                           // senao retorna false e sera embaralhada ate que esteja em ordem.
}

void shuffle(int *a, int n) { //Esta funcao embaralha os valores da variavel "numeros" da funcao main.
    int i, t, r;              //Como utiliza passagem de parametros por referencia, substitui os valores na main.
                              //Toda vez que o loop for executado, trocara dois valores de posicao.
    for(i = 0; i < n; i++) {  //Entao o loop pega um valor da posicao a[x] = w e troca com a[y] = z
        t = a[i];             // logo a[x] = z e a[y] = w, ate coloca-los em ordem crescente.
        r = rand() % n;       //Quanto maior o vetor mais vezes o loop sera utilizado.
        a[i] = a[r];          //Na linha 17 e utilizado uma funcao que fornece valores random de 0 a n = 6.
        a[r] = t;
    }
}

void bogosort(int *a, int n) {
    while( !is_sorted(a, n)) { //Chamada da funcao "is_sorted" e enquanto NAO for verdadeira
        shuffle(a, n);         // chama a funcao "shuffle" se o valor da funcao "is_sorted" for FALSE.
    }
}

int main() {
    int numeros[] = { 2, 7, 5, 13, 3, 11, 2 };
    int i;

    bogosort(numeros, 7); //Chamada da funcao com passagem de parametros por valor.

    for(i = 0; i < 7; i++) {
        printf("%d ", numeros[i]); //Loop para exibir os numeros.
    }

    return 0;
}