#include <stdlib.h>
#include "stack.h"
#include <math.h>
#include <stdio.h>
#include <string.h>


/*
* Forma uma nova stack
*/
STACK *new_stack(){
    return (STACK *) malloc (sizeof(STACK));
}

/*
* Função push que coloca no topo da stack um novo elemento
*/
void push (STACK *s, DATA elem){
    s->stack[s->sp] = elem;
    s->sp++; 
}


/*
* Função pop que retira do topo da stack o elemento correspondente
*/
DATA pop(STACK *s){
    s->sp--;
    return s->stack[s->sp];
}


/*
* Função top que devolve o elemento que está no topo da stack
*/
DATA top(STACK*s){
    return s->stack[s->sp-1];
}


int atribui (char *token){
    //int n;
    double temp;
    //double val = 1e-12;
    char str[100];
    int r=0;
    if (sscanf(token, "%lf", &temp) == 1) 
    {
        //n = (int)temp; // typecast to int.
        if (strchr(token, '.')) 
            r = 2;        
        else 
            r = 1;       
    }
  
    else if (sscanf(token, "%s", str) == 1)     
        r = 8;

    else if (sscanf(token, "%c", str) == 1)
        r = 4;

    return r;
}