/*
    Colas

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
    struct node* sig = nullptr;
};

// ------------------------------------------------------------------------------
// ----------------------- PROTOTIPOS -------------------------------------------

void agregarCola(struct node**, int);
int sacarCola(struct node**);
bool existeCola(struct node*);
void pause();

// ------------------------------------------------------------------------------
// ----------------------- FUNCION PRINCIPAL ------------------------------------

int main(){

    return 0;
}

// ------------------------------------------------------------------------------
// ----------------------- FUNCIONES --------------------------------------------

void agregarCola(struct node** cola, int dato){

    if( existeCola(*cola) ){
        // Si existe la cola, se agrega el nodo al final

        struct node* final = *cola;
        struct node* new_node = new node;

        new_node->data = dato;

        while(final->sig != nullptr){
            final = final->sig;
        }

        final->sig = new_node;
    }
    else{
        // Si no existe la cola, se crea el primer nodo

        *cola = new node;
        (*cola)->data = dato;
    }

}

// ------------------------------------------------------------------------------

int sacarCola(struct node** cola){

    struct node* temp = *cola;
    int dato = temp->data;

    *cola = (*cola)->sig;

    delete temp;

    return dato;
}

// ------------------------------------------------------------------------------

bool existeCola(struct node* cola){
    if( cola == nullptr )
        return false;

    return true;
}

// ------------------------------------------------------------------------------
// ----------------------- FUNCIONES ADICIONALES --------------------------------

void pause(){
    cout << "Presione enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}