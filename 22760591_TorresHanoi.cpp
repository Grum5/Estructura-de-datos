/*
    Javier Osvaldo Perez Bretado - 22760591
*/

#include<iostream>
#include<stdlib.h>
#include<limits>

using namespace std;

// ------------------------------------------------------------------------------
// ----------------------- ESTRUCTURAS ------------------------------------------

struct node{
    int data;
    node* sig = nullptr;
};

// ------------------------------------------------------------------------------
// ----------------------- PROTOTIPOS -------------------------------------------

void meterPila(struct node**, int);
int sacarPila(struct node**);
void existePila(struct node*);
void imprimirPila(struct node*);
void pause();

// ------------------------------------------------------------------------------
// ----------------------- FUNCION PRINCIPAL ------------------------------------

int main(){

    struct node* pila_A = nullptr;
    struct node* pila_B = nullptr;
    struct node* pila_C = nullptr;

    meterPila(&pila_A, 4);
    meterPila(&pila_A, 3);
    meterPila(&pila_A, 2);
    meterPila(&pila_A, 1);

    return 0;
}