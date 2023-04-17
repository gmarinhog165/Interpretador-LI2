/**
 @file  operacoes.h
 @brief Ficheiro com as funções relativas as operacoes.c
*/
/**
 * Projeto realizado por Gonçalo Marinho, Luís Caetano e Mariana Morais, alunas do 1º ano do LEI na Universidade
 * do Minho, no âmbito da cadeira de Laboratórios de Informática II.
 */

//!
/*!
Parte do código relativa aos Guiões 1 e 2.
*/

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "+".
 * @returns O resultado da soma de dois elementos.
 */
void add (STACK *s);

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "-".
 * @returns A função sub vai subtrair os 2 elementos da stack.
 */
void sub (STACK *s);

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "/".
 * @returns A função divd vai dividir os 2 elementos da stack.
*/
void divd (STACK *s);
/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "*".
 * @returns A função mult vai multiplicar os 2 elementos da stack.
*/
void mult (STACK*s);

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "#".
 * @returns A função expo vai colocar um elemento da stack como potência do outro.
 */
void expo (STACK *s);

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "&".
 * @returns A função and vai utilizar 2 elementos da stack e fazer a operação pre-definida &.
*/
void and (STACK *s);

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "|".
 * @returns A função ou vai utilizar 2 elementos da stack e fazer a operação pre-definida |. Transforma os dois elementos em binário e compara os seus bites. Devolve o bit 1, exceto quando ambos os bites em comparação forem 0, neste caso devolve o bit 0.
*/
void ou (STACK *s);

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "^".
 * @returns A função xor vai utilizar 2 elementos da stack e fazer a operação pre-definida ^. Transforma os dois elementos em binário e compara os seus bites. Se os bites em comparação forem diferentes, devolve o bit 1. No caso, dos bites serem iguais devolve o bit 0.
 */
void xor (STACK *s);

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "~".
 * @returns A função not vai utilizar 2 elementos da stack e fazer a operação pre-definida ~.
*/
void not (STACK *s);

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér ")".
 * @returns A função decr vai utilizar 1 elemento da stack e decrementar em 1 valor.
*/
void decr (STACK *s);

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "(".
 * @returns A função incr vai utilizar 1 elemento da stack e incrementar em 1 valor.
*/
void incr (STACK *s);

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "%".
 * @returns A função res vai utilizar 2 elemento da stack e gerar o resto da sua divisão.
*/
void res (STACK *s);

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "@".
 * @returns Rodar os 3 primeiros elementos no topo da stack.
 */
void ordem (STACK *s);

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "_".
 * @returns Retornar dois "push's" da stack.
 */
void duplicar (STACK *s);

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér ";".
 * @returns Devolve o primeiro elemento da stack.
 */
void pop2 (STACK *s);

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "\\".
 * @returns Trocar os dois primeiros elementos do topo da stack.
 */
void top2 (STACK *s);

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "$".
 * @returns Copia o n-ésimo elemento para o topo da stack.
 */
void copiaelem(STACK *s);

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
void convchar(STACK *s);

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o caractér "f".
 * @returns Converter o topo da stack num double.
 */
void convdouble(STACK *s);

/**
 * @param s - Stack
 * \brief   Aqui verificamos para quando a string tiver o caractér "i".
 * @returns Converter o topo da stack num inteiro.
 */
void convint (STACK *s);


//!
/*!
Parte do código relativa ao Guião 3.
*/

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o símbolo "=".
 * @returns Conetivo lógico de igual.
 */
void igual (STACK *s);

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o símbolo "<".
 * @returns Conetivo lógico de menor.
 */
void menor (STACK *s);

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o símbolo ">".
 * @returns Conetivo lógico de maior.
 */
void maior (STACK *s);

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o símbolo "!".
 * @returns Conetivo lógico de negação.
 */
void exclmark(STACK *s);

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o símbolo "e%".
 * @returns Conetivo lógico de E (Conjunção).
 */
void esc (STACK *s);

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o símbolo "e|".
 * @returns Conetivo lógico de OU (U ou Dijunção).
 */
void ousc (STACK *s);

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o símbolo "e<".
 * @returns Para coloca o menor dos 2 valores na stack.
 */
void menordosdois(STACK *s);

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o símbolo "e>".
 * @returns Para coloca o maior dos 2 valores na stack.
 */
void maiordosdois(STACK *s);

/**
 * @param s - Stack
 * \brief   Para quando a string tiver o símbolo "?".
 * @returns If-then-else.
 */
void ifthelse (STACK *s);

void handle(DATA *h, STACK *s, char *token);

void comando (DATA *h, STACK *s, char *token);

int appear (char *token);