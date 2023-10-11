/*
    Programar una funcion para concatenar 2 listas enlazadas circulares
    La lista 2 debe unirse al final de la lista 1

    Javier Osvaldo Perez Bretado - 22760591
*/

#include<iostream>
#include<stdlib.h>

using namespace std;

// ------------------------------------------------------------------------------
// ------------------------------------------------------------------------------

struct node{
    int data;
    struct node* sig = NULL;
};

// ------------------------------------------------------------------------------
// ------------------------------------------------------------------------------

void concat(struct node**, struct node*);
void agregar(struct node**, int);
void imprimir(struct node* );

// ------------------------------------------------------------------------------
// ------------------------------------------------------------------------------

int main(){
    /* Funcion main de testeo */

    // Declarar las listas
    struct node* lista1 = NULL;
    struct node* lista2 = NULL;

    // Se agregan nodos a la lista 1
    for(int i = 1; i <= 4; i++){
        agregar(&lista1, i);
    }

    // Se agregan nodos a la lista 2
    for(int i = 5; i <= 7; i++){
        agregar(&lista2, i);
    }
    // Se imprime la lista 1 para ver su contenido
    imprimir(lista1);
    cout << endl;

    // Se imprime la lista 2 para ver su contenido
    imprimir(lista2);
    cout << endl;

    // Se concatenan las dos listas
    concat(&lista1, lista2);

    // Se imprimen los resultados
    imprimir(lista1);

    return 0;
}

// ------------------------------------------------------------------------------
// ------------------------------------------------------------------------------

void concat(struct node** lista1, struct node* lista2){

    if(*lista1 == NULL && lista2 == NULL){ // Si no existe ninguna lista
        cout << "No existen listas" << endl;

    }
    else if(lista2 != NULL && *lista1 == NULL){ // Si lista 2 existe y lista 1 NO EXISTE
        *lista1 = lista2;

    }

    else if(*lista1 != NULL && lista2 != NULL){ // Si ambas listas existen
        struct node* ptr_temp1 = *lista1;
        struct node* ptr_temp2 = lista2;

        // Mover puntero temporal de lista 2
        while(ptr_temp2->sig != lista2){
            ptr_temp2 = ptr_temp2->sig;
        }

        // Mover puntero temporal de lista 1
        while(ptr_temp1->sig != *lista1){
            ptr_temp1 = ptr_temp1->sig;
        }

        ptr_temp1->sig = lista2;
        ptr_temp2->sig = *lista1;

    }
}

// ------------------------------------------------------------------------------

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

// ------------------------------------------------------------------------------

void imprimir(struct node* lista_temp){

    if(lista_temp != NULL){
        struct node* ptr_temp = lista_temp;

        while( ptr_temp->sig != lista_temp){
            cout << ptr_temp->data << endl;
            ptr_temp = ptr_temp->sig;
        }
        cout << ptr_temp->data << endl;
    }
}