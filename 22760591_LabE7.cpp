/*
    Crear una lista circular simple con numeros enteros, e imprimir la lista


    Javier Osvaldo Perez Bretado - 22760591
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct node{
    int data;
    struct node *sig = NULL;
};

void agregar(struct node**, int);
void imprimir(struct node*);

int main(){

    struct node *lista = NULL;

    agregar(&lista, 1);
    agregar(&lista, 2);
    agregar(&lista, 3);

    imprimir(lista);

    return 0;
}


void agregar(struct node** lista, int dato){

    if(*lista == NULL){
        *lista = (struct node*) malloc(sizeof(struct node));
        (*lista)->data = dato;
        (*lista)->sig = *lista;
    }
    else{
        struct node* nuevo_nodo = (struct node*) malloc(sizeof(struct node));
        nuevo_nodo->data = dato;
        //nuevo_nodo->sig = nuevo_nodo;
        struct node* ptr_temp = *lista;

        while(ptr_temp->sig != *lista){
            ptr_temp = ptr_temp->sig;
        }

        ptr_temp->sig = nuevo_nodo;
        nuevo_nodo->sig = *lista;
    }
}

void imprimir(struct node* lista_temp){

    struct node* ptr_temp = lista_temp;

    while( ptr_temp->sig != lista_temp){
        cout << ptr_temp->data << endl;
        ptr_temp = ptr_temp->sig;
    }
    cout << ptr_temp->data << endl;
}
