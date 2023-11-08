/*
    Javier Osvaldo Perez Bretado - 22760591
*/
/*
    Usando las funciones de pila realizar un programa que capture un texto y lo imprima
    al reves
*/

#include<iostream>
#include<stdlib.h>
#include<limits>

using namespace std;

// ------------------------------------------------------------------------------
// ----------------------- ESTRUCTURAS ------------------------------------------

struct node{
    int data;
    struct node* sig = nullptr;
};

// ------------------------------------------------------------------------------
// ----------------------- PROTOTIPOS -------------------------------------------

void agregarPila(struct node**, int);
int sacarPila(struct node**);
bool existePila(struct node*);
void imprimirPila(struct node*);
void pause();

// ------------------------------------------------------------------------------
// ----------------------- FUNCION PRINCIPAL ------------------------------------

int main(){

    struct node* pila = nullptr;

    agregarPila(&pila, 4);
    agregarPila(&pila, 3);
    agregarPila(&pila, 2);
    agregarPila(&pila, 1);

    while( existePila(pila) ){
        if( existePila(pila) ){
            cout << sacarPila(&pila) << endl;
        }
    }

    return 0;
}

// ------------------------------------------------------------------------------
// ----------------------- FUNCIONES --------------------------------------------

void agregarPila(struct node** pila, int dato){

    struct node* new_node = new node;

    new_node->data = dato;
    new_node->sig = *pila;
    *pila = new_node;

}

// ------------------------------------------------------------------------------

int sacarPila(struct node** pila){

    struct node* delete_node = *pila;
    int dato = delete_node->data;

    *pila = (*pila)->sig;

    delete delete_node;
    return dato;

}

// ------------------------------------------------------------------------------

bool existePila(struct node* pila){
    if( pila == nullptr )
        return false;

    return true;
}

// ------------------------------------------------------------------------------
// ----------------------- FUNCIONES AUXILIARES ---------------------------------

void pause(){
    cout << "Presione enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}
