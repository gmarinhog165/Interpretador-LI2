#define MAX_STACK 1000


/**
* struct da stack com o array que guarda os push's dados e sp que guarda o tamanho da stack
*/
typedef enum {INT = 1, DOUBLE = 2, CHAR = 4, STRING = 8} TYPE;
typedef enum {A = 10} VALUE;


typedef struct data {
    TYPE type;
    VALUE valor;
    long INT;
    double DOUBLE;
    char CHAR;
    char *STRING;
} DATA;



typedef struct {
        DATA stack [MAX_STACK];
        int sp;
} STACK;

STACK *new_stack();

/*
* Função push definida em stack.c
*/
void push(STACK *s, DATA elem);

/*
* Função pop definida em stack.c
*/
DATA pop(STACK *s);

/*
* Função top definida em stack.c
*/
DATA top (STACK *s);

int atribui(char *token);

