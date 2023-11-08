/*
    Usando las funciones de pila realizar un programa que capture un texto y lo imprima
    al reves

    Javier Osvaldo Perez Bretado - 22760591
*/

#include<iostream>
#include<stdlib.h>
#include<limits>

using namespace std;

struct node{
    char data;
    struct node* sig = nullptr;
};

void inverso(struct node** ,char*);
void agregarPila(struct node**, int);
char sacarPila(struct node**);
bool existePila(struct node*);
void pause();

int main(){

    struct node* pila = nullptr;
    char* texto = new char[100];

    cout << "Texto: ";
    cin.getline(texto, 100);

    inverso(&pila, texto);
    while(existePila(pila)){
        if(existePila){
            cout << sacarPila(&pila);
        }
    }
    cout << endl;
    return 0;
}

// ------------------------------------------------------------------------------
// ----------------------- FUNCIONES --------------------------------------------

void inverso(struct node** pila, char texto[]){

    while(*texto != '\0'){
        agregarPila(pila, *texto);
        *texto++;
    }
}

void agregarPila(struct node** pila, int dato){

    struct node* new_node = new node;

    new_node->data = dato;
    new_node->sig = *pila;
    *pila = new_node;

}

// ------------------------------------------------------------------------------

// ------------------------------------------------------------------------------

bool existePila(struct node* pila){
    if( pila == nullptr )
        return false;

    return true;
}

// ------------------------------------------------------------------------------

char sacarPila(struct node** pila){

    struct node* delete_node = *pila;
    char dato = delete_node->data;

    *pila = (*pila)->sig;

    delete delete_node;
    return dato;

}

// ------------------------------------------------------------------------------
// ----------------------- FUNCIONES AUXILIARES ---------------------------------

void pause(){
    cout << "Presione enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}
