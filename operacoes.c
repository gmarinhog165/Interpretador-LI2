#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>
#include <math.h>
#include "operacoes.h"

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "+".
 * @returns O resultado da soma de dois elementos.
 */
void add (STACK *s){
    DATA X = pop (s);
    DATA Y = pop(s);
    DATA r;
    //printf("%d\n", X.type );
    if (X.type == 1 && Y.type == 1){
        r.INT = X.INT + Y.INT;
        r.type = 1;
    }
    else if (X.type == 2 && Y.type == 2){
        r.DOUBLE = X.DOUBLE + Y.DOUBLE;
        r.type = 2;
    }
    push(s, r);
}

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "-".
 * @returns A função sub vai subtrair os 2 elementos da stack.
 */
void sub (STACK *s){
    DATA X = pop(s);
    DATA Y = pop(s);
    DATA r;
    if (X.type == 1 && Y.type ==1){
        r.INT = Y.INT - X.INT;
        r.type = 1;
    }
    else if (X.type == 2 && Y.type == 2){
        r.DOUBLE = Y.DOUBLE - X.DOUBLE;
        r.type = 2;
    }
    push (s, r);
}

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "/".
 * @returns A função divd vai dividir os 2 elementos da stack.
*/
void divd (STACK *s){
    DATA X = pop(s);
    DATA Y = pop(s);
    DATA r,e1;
    if (X.type==1 && Y.type ==1) {
        r.INT = Y.INT / X.INT;
        r.type = 1;
    }
    else if (X.type == 2 && Y.type == 2){
        r.DOUBLE = Y.DOUBLE / X.DOUBLE;
        r.type = 2;
    }
    else if (X.type == 2 && Y.type == 1){
        e1.DOUBLE = Y.INT;
        r.DOUBLE = e1.DOUBLE / X.DOUBLE;
        r.type = 2;
    }
    else if (X.type == 1 && Y.type == 2){
        e1.DOUBLE = X.INT;
        r.DOUBLE = Y.DOUBLE / e1.DOUBLE;
        r.type = 2;
    }
    push(s, r);
}

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "*".
 * @returns A função mult vai multiplicar os 2 elementos da stack.
*/
void mult (STACK*s){
    DATA X = pop(s);
    DATA Y = pop(s);
    DATA r;
    if (X.type==1 && Y.type ==1) {
        r.INT = Y.INT * X.INT;
        r.type = 1;
    }
    else if (X.type == 2 && Y.type == 2){
        r.DOUBLE = Y.DOUBLE * X.DOUBLE;
        r.type = 2;
    }
    else if (X.type == 2 && Y.type == 1){
        r.DOUBLE = Y.INT * X.DOUBLE;
        r.type = 2;
    }
    else if (X.type == 1 && Y.type == 2){
        r.DOUBLE = Y.DOUBLE * X.INT;
        r.type = 2;
    }
    push(s, r);
}

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "#".
 * @returns A função expo vai colocar um elemento da stack como potência do outro.
 */
void expo (STACK *s){
    DATA Y = pop(s);
    DATA X = pop(s);
    DATA r;
    if (Y.type == 1 && X.type == 1) {
        r.INT = pow(X.INT,Y.INT);
        r.type = 1;
        push(s,r);
    }
    else if (Y.type == 2 && X.type == 1) {
        r.DOUBLE = pow(X.INT,Y.DOUBLE);
        r.type = 2;
        push(s,r);
    }
    else if (Y.type == 1 && X.type == 2) {
        r.DOUBLE = pow(X.DOUBLE,Y.INT);
        r.type = 2;
        push(s,r);
    }
    else {
        r.DOUBLE= pow(X.DOUBLE,Y.DOUBLE);
        r.type = 2;
        push (s,r);
    }

}

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "&".
 * @returns A função and vai utilizar 2 elementos da stack e fazer a operação pre-definida &.
*/
void and (STACK *s){
    DATA X = pop(s);
    DATA Y = pop(s);
    DATA r;
    int e1,e2;
    if (X.type == 1 && Y.type ==1){
        r.INT = Y.INT & X.INT;
        r.type = 1;
    }
    else if (X.type == 2 && Y.type == 2){
        e1 = Y.DOUBLE;
        e2 = X.DOUBLE;

        r.DOUBLE = e1 & e2;
        r.type = 2;
    }
    push(s, r);
}

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "|".
 * @returns A função ou vai utilizar 2 elementos da stack e fazer a operação pre-definida |. Transforma os dois elementos em binário e compara os seus bites. Devolve o bit 1, exceto quando ambos os bites em comparação forem 0, neste caso devolve o bit 0.
*/
void ou (STACK *s){
    DATA X = pop(s);
    DATA Y = pop(s);
    DATA r;
    int e1,e2;
    if (X.type == 1 && Y.type ==1){
        r.INT = Y.INT | X.INT;
        r.type = 1;
    }
    else if (X.type == 2 && Y.type == 2){
        e1 = Y.DOUBLE;
        e2 = X.DOUBLE;

        r.DOUBLE = e1 | e2;
        r.type = 2;
    }
    push(s, r);
}

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "^".
 * @returns A função xor vai utilizar 2 elementos da stack e fazer a operação pre-definida ^. Transforma os dois elementos em binário e compara os seus bites. Se os bites em comparação forem diferentes, devolve o bit 1. No caso, dos bites serem iguais devolve o bit 0.
 */
void xor (STACK *s){
    DATA X = pop(s);
    DATA Y = pop(s);
    DATA r;
    int e1,e2;
    if (X.type == 1 && Y.type ==1){
        r.INT = Y.INT ^ X.INT;
        r.type = 1;
    }
    else if (X.type == 2 && Y.type == 2){
        e1 = Y.DOUBLE;
        e2 = X.DOUBLE;

        r.DOUBLE = e1 ^ e2;
        r.type = 2;
    }
    push(s, r);
}

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "~".
 * @returns A função not vai utilizar 2 elementos da stack e fazer a operação pre-definida ~.
*/
void not (STACK *s){
    DATA X = pop(s);
    DATA r;
    r.INT = ~ X.INT;
    r.type = 1;
    push(s, r);
}

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér ")".
 * @returns A função decr vai utilizar 1 elemento da stack e decrementar em 1 valor.
*/
void decr (STACK *s){
    DATA X = pop(s);
    DATA r;
    if (X.type == 1){
        r.INT = X.INT - 1;
        r.type = 1;
    }
    else if (X.type == 2){
        r.DOUBLE = X.DOUBLE - 1;
        r.type = 2;
    }
    else if (X.type == 4){
        r.CHAR = X.CHAR - 1;
        r.type = 4;
    }
    push(s, r);
}

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "(".
 * @returns A função incr vai utilizar 1 elemento da stack e incrementar em 1 valor.
*/
void incr (STACK *s){
    DATA X = pop(s);
    DATA r;
    if (X.type == 1){
        r.INT = X.INT + 1;
        r.type = 1;
    }
    else if (X.type == 2){
        r.DOUBLE = X.DOUBLE + 1;
        r.type = 2;
    }
    else if (X.type == 4){
        r.CHAR = X.CHAR + 1;
        r.type = 4;
    }
    push(s, r);
}

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "%".
 * @returns A função res vai utilizar 2 elemento da stack e gerar o resto da sua divisão.
*/
void res (STACK *s){
    DATA X = pop(s);
    DATA Y = pop(s);
    DATA r;
    int e1,e2;
    if (X.type == 1 && Y.type ==1){
        r.INT = Y.INT % X.INT;
        r.type = 1;
    }
    else if (X.type == 2 && Y.type == 2){
        e1 = Y.DOUBLE;
        e2 = X.DOUBLE;

        r.DOUBLE = e1 % e2;
        r.type = 2;
    }
    push(s, r);
}

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "@".
 * @returns Rodar os 3 primeiros elementos no topo da stack.
 */
void ordem (STACK *s){
    DATA X = pop(s);
    DATA Y = pop(s);
    DATA Z = pop(s);
    push (s,Y);
    push (s,X);
    push (s,Z);
}

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "_".
 * @returns Retornar dois "push's" da stack.
 */
void duplicar (STACK *s){
    DATA X = pop(s);
    push (s,X);
    push (s,X);
}

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér ";".
 * @returns Devolve o primeiro elemento da stack.
 */
void pop2 (STACK *s){
    pop(s);
}

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "\\".
 * @returns Trocar os dois primeiros elementos do topo da stack.
 */
void top2 (STACK *s){
    DATA X = pop (s);
    DATA Y = pop(s);
    push (s,X);
    push (s,Y);
}

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "$".
 * @returns Copia o n-ésimo elemento para o topo da stack.
 */
void copiaelem(STACK *s){
    int x = pop(s).INT;
    STACK arr = *s;
    for (int i = 0; i < x; i++) {
        pop(&arr);
    }
    DATA A = pop(&arr);
    push(s,A);
}

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "l".
 * @returns Apenas lê a linha indicada.
 */
void lerlinha(DATA *h, STACK *s);

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "c".
 * @returns Converter o topo da stack para caractér.
 */
void convchar(STACK *s){
    DATA X = pop(s);
    DATA r;
    if (X.type==1){
        r.CHAR = X.INT;
        r.type = 4;
        push(s,r);
    }
    else push(s,X);
}

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "f".
 * @returns Converter o topo da stack num double.
 */
void convdouble(STACK *s){
    DATA X = pop(s);
    DATA r;
    if (X.type ==1){
        r.DOUBLE = X.INT;
        r.type = 2;
        push (s,r);
    }
    else if (X.type == 2){
        push (s,X);
    }
    else {
        char *arr;
        r.DOUBLE = strtod (X.STRING,&arr);
        r.type = 2;
        push(s,r);
    }
}

/**
 * @param s - Stack
 * \brief   Aqui verificamos para quando a string tiver o caractér "i".
 * @returns Converter o topo da stack num inteiro.
 */
void convint (STACK *s){
    DATA X = pop(s);
    DATA r;
    if (X.type == 2){
        r.INT =  X.DOUBLE;
        r.type = 1;
        push(s,r);
    }
    else if (X.type == 1){
        push(s,X);
    }
    else if (X.type == 4){
        r.INT = X.CHAR;
        r.type = 1;
        push(s,r);
    }
    else{
        char *arr;
        r.INT = strtol (X.STRING,&arr,10);
        r.type = 1;
        push(s,r);
    }
}

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o símbolo "=".
 * @returns Conetivo lógico de igual.
 */
void igual (STACK *s){
    DATA X = pop(s);
    DATA Y = pop(s);
    double r,z;
    DATA resultado;
    if (X.type == 1) r = X.INT;
    else r = X.DOUBLE;
    if (Y.type == 1)z = Y.INT;
    else z = Y.DOUBLE;
    if (r == z){
        resultado.INT = 1;
        resultado.type = 1;
        push (s,resultado);
    }
    else {
        resultado.INT = 0;
        resultado.type = 1;
        push (s,resultado);
    }
}

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o símbolo "<".
 * @returns Conetivo lógico de menor.
 */
void menor (STACK *s){
    DATA X = pop(s);
    DATA Y = pop(s);
    double r,z;
    DATA resultado;
    if (X.type == 1) r = X.INT;
    else  r = X.DOUBLE;
    if (Y.type == 1)z = Y.INT;
    else  z = Y.DOUBLE;
    if (z < r){
        resultado.INT = 1;
        resultado.type = 1;
        push (s,resultado);
    }
    else {
        resultado.INT = 0;
        resultado.type = 1;
        push (s,resultado);
    }
}

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o símbolo ">".
 * @returns Conetivo lógico de maior.
 */
void maior (STACK *s){
    DATA X = pop(s);
    DATA Y = pop(s);
    double r,z;
    DATA resultado;
    if (X.type == 1) r = X.INT;
    else  r = X.DOUBLE;
    if (Y.type == 1)z = Y.INT;
    else  z = Y.DOUBLE;
    if (z > r){
        resultado.INT = 1;
        resultado.type = 1;
        push (s,resultado);
    }
    else {
        resultado.INT = 0;
        resultado.type = 1;
        push (s,resultado);
    }
}

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o símbolo "!".
 * @returns Conetivo lógico de negação.
 */
void exclmark(STACK *s){
    DATA X = pop(s);
    DATA r;
    double z;
    if (X.type == 1){
        if (X.INT != 0){
            r.INT = 0;
            r.type = 1;
            push(s,r);
        }
        else{
            r.INT = 1;
            r.type = 1;
            push(s,r);
        }
    }
    else if (X.type == 2){
        if (X.DOUBLE != 0){
            r.INT = 0;
            r.type = 1;
            push(s,r);
        }
        else{
            r.INT = 1;
            r.type = 1;
            push(s,r);
        }
    }
    else if (X.type == 4){
        z = X.CHAR;
        if (z != 0){
            r.INT = 0;
            r.type = 1;
            push(s,r);
        }
        else {
            r.INT = 1;
            r.type = 1;
            push(s,r);
        }
    }
}

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o símbolo "e%".
 * @returns Conetivo lógico de E (Conjunção).
 */
void esc (STACK *s){
    DATA X = pop(s);
    DATA Y = pop(s);
    double r,z;
    DATA resultado;
    if (X.type == 1) r = X.INT;
    else  r = X.DOUBLE;
    if (Y.type == 1) z = Y.INT;
    else  z = Y.DOUBLE;
    if (r != 0 && z != 0){
        if (Y.type == 1){
            resultado.INT = r;
            resultado.type = 1;
            push(s,resultado);
        }
        else if (Y.type == 2){
            resultado.DOUBLE = r;
            resultado.type = 2;
            push(s,resultado);
        }
    }
    else{
        resultado.INT = 0;
        resultado.type = 1;
        push(s,resultado);
    }
}

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o símbolo "e|".
 * @returns Conetivo lógico de OU (U ou Dijunção).
 */
void ousc (STACK *s){
    DATA X = pop(s);
    DATA Y = pop(s);
    double r,z;
    if (X.type == 1) r = X.INT;
    else  r = X.DOUBLE;
    if (Y.type == 1) z = Y.INT;
    else  z = Y.DOUBLE;
    if (r == 0 && z == 0){
        push (s,X);
    }
    else if (z == 0){
        push(s,X);
    }
    else push (s,Y);
}

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o símbolo "e<".
 * @returns Para coloca o menor dos 2 valores na stack.
 */
void menordosdois(STACK *s){
    DATA X = pop(s);
    DATA Y = pop(s);
    double r,z;
    if (X.type == 1) r = X.INT;
    else  r = X.DOUBLE;
    if (Y.type == 1) z = Y.INT;
    else  z = Y.DOUBLE;
    if (z < r) push(s,Y);
    else if (z > r) push (s,X);
    else if (z == r) push (s,Y);
}

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o símbolo "e>".
 * @returns Para coloca o maior dos 2 valores na stack.
 */
void maiordosdois(STACK *s){
    DATA X = pop(s);
    DATA Y = pop(s);
    double r,z;
    if (X.type == 1) r = X.INT;
    else r = X.DOUBLE;
    if (Y.type == 1) z = Y.INT;
    else z = Y.DOUBLE;
    if (z > r) push(s,Y);
    else if (z < r) push (s,X);
    else if (z == r) push (s,Y);
}

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o símbolo "?".
 * @returns If-then-else.
 */
void ifthelse (STACK *s){
    DATA X = pop(s);
    DATA Y = pop(s);
    DATA Z = pop(s);
    double r;
    if (Z.type == 1) r = Z.INT;
    else r = Z.DOUBLE;
    if (r != 0) push (s,Y);
    else push (s,X);
}

/**
 * A função appear identifica se aparece o input da string no stdin.
 */
int appear (char *token){
    int r=0;
    if (strcmp(token, "A") == 0) r=1;
    else if (strcmp(token, ":A") == 0) r=1;
    else if (strcmp(token, "B") == 0) r=1;
    else if (strcmp(token, ":B") == 0) r=1;
    else if (strcmp(token, "C") == 0) r=1;
    else if (strcmp(token, ":C") == 0) r=1;
    else if (strcmp(token, "D") == 0) r=1;
    else if (strcmp(token, ":D") == 0) r=1;
    else if (strcmp(token, "E") == 0) r=1;
    else if (strcmp(token, ":E") == 0) r=1;
    else if (strcmp(token, "F") == 0) r=1;
    else if (strcmp(token, ":F") == 0) r=1;
    else if (strcmp(token, "G") == 0) r=1;
    else if (strcmp(token, ":G") == 0) r=1;
    else if (strcmp(token, "H") == 0) r=1;
    else if (strcmp(token, ":H") == 0) r=1;
    else if (strcmp(token, "I") == 0) r=1;
    else if (strcmp(token, ":I") == 0) r=1;
    else if (strcmp(token, "J") == 0) r=1;
    else if (strcmp(token, ":J") == 0) r=1;
    else if (strcmp(token, "K") == 0) r=1;
    else if (strcmp(token, ":K") == 0) r=1;
    else if (strcmp(token, "L") == 0) r=1;
    else if (strcmp(token, ":L") == 0) r=1;
    else if (strcmp(token, "M") == 0) r=1;
    else if (strcmp(token, ":M") == 0) r=1;
    else if (strcmp(token, "N") == 0) r=1;
    else if (strcmp(token, ":N") == 0) r=1;
    else if (strcmp(token, "O") == 0) r=1;
    else if (strcmp(token, ":O") == 0) r=1;
    else if (strcmp(token, "P") == 0) r=1;
    else if (strcmp(token, ":P") == 0) r=1;
    else if (strcmp(token, "Q") == 0) r=1;
    else if (strcmp(token, ":Q") == 0) r=1;
    else if (strcmp(token, "R") == 0) r=1;
    else if (strcmp(token, ":R") == 0) r=1;
    else if (strcmp(token, "S") == 0) r=1;
    else if (strcmp(token, ":S") == 0) r=1;
    else if (strcmp(token, "T") == 0) r=1;
    else if (strcmp(token, ":T") == 0) r=1;
    else if (strcmp(token, "U") == 0) r=1;
    else if (strcmp(token, ":U") == 0) r=1;
    else if (strcmp(token, "V") == 0) r=1;
    else if (strcmp(token, ":V") == 0) r=1;
    else if (strcmp(token, "W") == 0) r=1;
    else if (strcmp(token, ":W") == 0) r=1;
    else if (strcmp(token, "X") == 0) r=1;
    else if (strcmp(token, ":X") == 0) r=1;
    else if (strcmp(token, "Y") == 0) r=1;
    else if (strcmp(token, ":Y") == 0) r=1;
    else if (strcmp(token, "Z") == 0) r=1;
    else if (strcmp(token, ":Z") == 0) r=1;
    return r;
}

/**
* A função comando altera os valores do array default.
*/
void comando (DATA *h, STACK *s, char *token){
    if (strcmp(token, ":A") == 0) h[0] = top(s);
    else if (strcmp(token, ":B") == 0) h[1] = top(s);
    else if (strcmp(token, ":C") == 0) h[2] = top(s);
    else if (strcmp(token, ":D") == 0) h[3] = top(s);
    else if (strcmp(token, ":E") == 0) h[4] = top(s);
    else if (strcmp(token, ":F") == 0) h[5] = top(s);
    else if (strcmp(token, ":N") == 0) h[6] = top(s);
    else if (strcmp(token, ":S") == 0) h[7] = top(s);
    else if (strcmp(token, ":X") == 0) h[8] = top(s);
    else if (strcmp(token, ":Y") == 0) h[9] = top(s);
    else if (strcmp(token, ":Z") == 0) h[10] = top(s);
    else if (strcmp(token, ":G") == 0) h[11] = top(s);
    else if (strcmp(token, ":H") == 0) h[12] = top(s);
    else if (strcmp(token, ":I") == 0) h[13] = top(s);
    else if (strcmp(token, ":J") == 0) h[14] = top(s);
    else if (strcmp(token, ":K") == 0) h[15] = top(s);
    else if (strcmp(token, ":L") == 0) h[16] = top(s);
    else if (strcmp(token, ":M") == 0) h[17] = top(s);
    else if (strcmp(token, ":N") == 0) h[18] = top(s);
    else if (strcmp(token, ":O") == 0) h[19] = top(s);
    else if (strcmp(token, ":P") == 0) h[20] = top(s);
    else if (strcmp(token, ":Q") == 0) h[21] = top(s);
    else if (strcmp(token, ":R") == 0) h[22] = top(s);
    else if (strcmp(token, ":T") == 0) h[23] = top(s);
    else if (strcmp(token, ":U") == 0) h[24] = top(s);
    else if (strcmp(token, ":V") == 0) h[25] = top(s);

    else if (strcmp(token, "A") == 0) push(s,h[0]);
    else if (strcmp(token, "B") == 0) push(s,h[1]);
    else if (strcmp(token, "C") == 0) push(s,h[2]);
    else if (strcmp(token, "D") == 0) push(s,h[3]);
    else if (strcmp(token, "E") == 0) push(s,h[4]);
    else if (strcmp(token, "F") == 0) push(s,h[5]);
    else if (strcmp(token, "N") == 0) push(s,h[6]);
    else if (strcmp(token, "S") == 0) push(s,h[7]);
    else if (strcmp(token, "X") == 0) push(s,h[8]);
    else if (strcmp(token, "Y") == 0) push(s,h[9]);
    else if (strcmp(token, "Z") == 0) push(s,h[10]);
    else if (strcmp(token, "G") == 0) push(s,h[11]);
    else if (strcmp(token, "H") == 0) push(s,h[12]);
    else if (strcmp(token, "I") == 0) push(s,h[13]);
    else if (strcmp(token, "J") == 0) push(s,h[14]);
    else if (strcmp(token, "K") == 0) push(s,h[15]);
    else if (strcmp(token, "L") == 0) push(s,h[16]);
    else if (strcmp(token, "M") == 0) push(s,h[17]);
    else if (strcmp(token, "N") == 0) push(s,h[18]);
    else if (strcmp(token, "O") == 0) push(s,h[19]);
    else if (strcmp(token, "P") == 0) push(s,h[20]);
    else if (strcmp(token, "Q") == 0) push(s,h[21]);
    else if (strcmp(token, "R") == 0) push(s,h[22]);
    else if (strcmp(token, "T") == 0) push(s,h[23]);
    else if (strcmp(token, "U") == 0) push(s,h[24]);
    else if (strcmp(token, "V") == 0) push(s,h[25]);
}

/**
* A função handle vai navegar por todas as operações possiveis até encontrar a correspondente.
* O val vai juntar os numeros na ausencia de operadores.
*/

void handle(DATA *h, STACK *s, char *token){

    if (atribui(token) == 8){
        if (strcmp(token, "+") == 0) add(s);
        else if (strcmp (token, "-") == 0) sub(s);
        else if (strcmp (token, "/") == 0) divd(s);
        else if (strcmp (token, "*") == 0) mult(s);
        else if (strcmp (token, "#") == 0) expo(s);
        else if (strcmp (token, "&") == 0) and(s);
        else if (strcmp (token, "|") == 0) ou(s);
        else if (strcmp (token, "^") == 0) xor(s);
        else if (strcmp (token, "~") == 0) not(s);
        else if (strcmp (token, "(") == 0) decr(s);
        else if (strcmp (token, ")") == 0) incr(s);
        else if (strcmp (token, "%") == 0) res(s);
        else if (strcmp (token, "@") == 0) ordem(s);
        else if (strcmp (token, "_") == 0) duplicar(s);
        else if (strcmp (token, ";") == 0) pop2(s);
        else if (strcmp (token, "\\") == 0) top2(s);
        else if (strcmp (token, "$") == 0) copiaelem(s);
        else if (strcmp (token, "c") == 0) convchar(s);
        else if (strcmp (token, "l") == 0) lerlinha(h,s);
        else if (strcmp (token, "f") == 0) convdouble(s);
        else if (strcmp (token, "i") == 0) convint(s);
        else if (strcmp (token, "=") == 0) igual(s);
        else if (strcmp (token, ">") == 0) maior(s);
        else if (strcmp (token, "<") == 0) menor(s);
        else if (strcmp (token, "!") == 0) exclmark(s);
        else if (strcmp (token, "e&") == 0) esc(s);
        else if (strcmp (token, "e|") == 0) ousc(s);
        else if (strcmp (token, "e<") == 0) menordosdois(s);
        else if (strcmp (token, "e>") == 0) maiordosdois(s);
        else if (strcmp (token, ("?")) == 0) ifthelse(s);
        else if (appear(token) == 1) comando(h,s, token);
        else if (strlen (token) == 1){
            DATA val;
            sscanf (token, "%c", &val.CHAR);
            val.type = 4;
            push(s,val);

        }
    }
    else if (atribui(token) == 1){
        DATA val;
        sscanf(token, "%ld", &val.INT);
        val.type = 1;
        push (s,val);
    }
    else if (atribui(token) == 2) {
        DATA val;
        sscanf(token, "%lg", &val.DOUBLE);
        val.type = 2;
        push(s,val);
    }

}

void lerlinha(DATA *h,STACK *s){
    char arr[BUFSIZ];
    char arr2[BUFSIZ];
    if (fgets(arr, BUFSIZ, stdin) != NULL){
        while (sscanf(arr, "%s%[^\n]", arr2, arr) == 2) {
            handle(h,s, arr);
        }
    }
    handle (h,s,arr);
}