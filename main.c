#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "operacoes.h"
#include <string.h>
#include <math.h>
#include "operacoes.h"

/**
 * Os default values auxiliam na criação do array, com o valor de cada letra.
 * Caso não fosse alterado, esse valor era default.
 */
void defaultvalues (DATA *h){
    h[0].INT = 10;
    h[0].type = 1;
    h[1].INT = 11;
    h[1].type = 1;
    h[2].INT = 12;
    h[2].type = 1;
    h[3].INT = 13;
    h[3].type = 1;
    h[4].INT = 14;
    h[4].type = 1;
    h[5].INT = 15;
    h[5].type = 1;
    h[6].CHAR = '\n';
    h[6].type = 4;
    h[7].CHAR = ' ';
    h[7].type = 4;
    h[8].INT = 0;
    h[8].type = 1;
    h[9].INT = 1;
    h[9].type = 1;
    h[10].INT = 2;
    h[10].type = 1;
    }


/**
* A função main vai receber um input do stdin, coloca-lo no array line. Depois vai ler a string até encontrar um '\n'
* e fazer o que a função handle lhe mandar. Depois disso vai imprimir o conteúdo da stack.
*/
int main(){
    STACK *s = new_stack();
    DATA h[26];
    defaultvalues(h);

    char line[BUFSIZ];
    char token[BUFSIZ];

    if (fgets(line, BUFSIZ, stdin) != NULL){
        while (sscanf(line, "%s%[^\n]", token, line) == 2) {
            handle(h,s, token);
        }
        handle (h,s, token);
        for (int i = 0; i < s->sp; i++){
            DATA e = s->stack[i];
            TYPE tipo = e.type;
            if (tipo == INT) printf ("%ld", e.INT);
            else if (tipo == CHAR) printf("%c", e.CHAR);
            else if (tipo == DOUBLE) printf ("%g", e.DOUBLE);
            else if (tipo == STRING) printf("%s", e.STRING);
        }
        printf ("\n");

    }


    return 0;
}