/*
    Javier Osvaldo Perez Bretado - 22760591
*/

/*
    Programar una funcion para separar la lista doble en 2 listas
    la lista 1 debe contener los pares y la lista 2 los impares
    al final de la lista inicial debe quedar vacia
*/

#include <iostream>
#include <stdlib.h>
#include <limits>

using namespace std;

// ------------------------------------------------------------------------------
// ----------------------- ESTRUCTURAS ------------------------------------------

struct node{
    int data;
    struct node* sig = nullptr;
    struct node* ant = nullptr;
};

// ------------------------------------------------------------------------------
// ----------------------- PROTOTIPOS -------------------------------------------

void agregarNodoDoble(struct node**, int);
void imprimir(struct node*);
void function(struct node**, struct node**, struct node**);
bool existeLista(struct node*);
void dividir( struct node**, struct node**, struct node** );


// ------------------------------------------------------------------------------
// ----------------------- FUNCION PRINCIPAL ------------------------------------

int main(){

    struct node* lista = nullptr;
    struct node* listaPar = nullptr;
    struct node* listaImp = nullptr;
    int dato;


    agregarNodoDoble(&lista, 1);
    agregarNodoDoble(&lista, 2);
    agregarNodoDoble(&lista, 1);
    cout << "LISTA ORIGINAL" << endl;
    imprimir(lista);

    // function(&lista, &listaPar, &listaImpar);

    dividir(&lista, &listaImp, &listaPar);

    cout << "LISTA PAR" << endl;
    imprimir(listaPar);
    cout << "LISTA IMPAR" << endl;
    imprimir(listaImp);
    cout << "LISTA ORIGINAL"<< endl;
    imprimir(lista);
}

// ------------------------------------------------------------------------------
// ----------------------- FUNCIONES --------------------------------------------

void function(struct node** lista, struct node** lista1, struct node** lista2){

    struct node* ptr_temp = *lista;
    struct node* delete_node = nullptr;

    while(ptr_temp->sig != nullptr){
        if(ptr_temp->data % 2 == 0){
            agregarNodoDoble(lista1, ptr_temp->data);
        }
        else{
            agregarNodoDoble(lista2, ptr_temp->data);
        }
        delete_node = ptr_temp;
        ptr_temp = ptr_temp->sig;
        delete delete_node;
    }
    if(ptr_temp->data % 2 == 0){
        agregarNodoDoble(lista1, ptr_temp->data);
    }
    else{
        agregarNodoDoble(lista2, ptr_temp->data);
    }
    delete_node = ptr_temp;
    *lista = nullptr;
    delete delete_node;
}

// ------------------------------------------------------------------------------

void dividir( struct node** lista, struct node** listaImp, struct node** listaPar ){

    struct node* ptr_temp = *lista;
    struct node* last_nodePar = nullptr;
    struct node* last_nodeImp = nullptr;

    int i = 1;

    while( ptr_temp->sig != nullptr ){
        if( ptr_temp->data % 2 != 0 ){ // Si es impar
           if( *listaImp == nullptr ){
                *listaImp = ptr_temp;
                last_nodeImp = ptr_temp;
                ptr_temp = ptr_temp->sig;
                (*listaImp)->sig = nullptr;
                (*listaImp)->ant = nullptr;
           }
           else{
                ptr_temp->ant = last_nodeImp;
                last_nodeImp->sig = ptr_temp;
                last_nodeImp = last_nodeImp->sig;
                ptr_temp = ptr_temp->sig;
                last_nodeImp->sig = nullptr;
           }

        }
        else{ // Si es par
            if( *listaPar == nullptr ){
                *listaPar = ptr_temp;
                last_nodePar = ptr_temp;
                ptr_temp = ptr_temp->sig;
                (*listaPar)->sig = nullptr;
                (*listaPar)->ant = nullptr;
            }
            else{
                ptr_temp->ant = last_nodePar;
                last_nodePar->sig = ptr_temp;
                last_nodePar = last_nodePar->sig;
                ptr_temp = ptr_temp->sig;
                last_nodePar->sig = nullptr;
            }
        }

    }

    if( ptr_temp->data % 2 != 0 ){
        if( *listaImp != nullptr){
            ptr_temp->ant = last_nodeImp;
            last_nodeImp->sig = ptr_temp;
        }
        else{
            *listaImp = ptr_temp;
            (*listaImp)->ant = nullptr;
        }
    }
    else{
        if( *listaPar != nullptr){
            ptr_temp->ant = last_nodePar;
            last_nodePar->sig = ptr_temp;
        }
        else{
            *listaPar = ptr_temp;
            (*listaPar)->ant = nullptr;
        }
    }

    *lista = nullptr;
}

// ------------------------------------------------------------------------------

void agregarNodoDoble(struct node** lista, int dato){

    struct node* new_node;
    struct node* ptr_temp;

    new_node = new node;

    new_node->data = dato;

    if(*lista == nullptr){
        *lista = new_node;
    }
    else{
        ptr_temp = *lista;
        while( ptr_temp->sig != nullptr ){
            ptr_temp = ptr_temp->sig;
        }
        ptr_temp->sig = new_node;
        new_node->ant = ptr_temp;
    }
}

// ------------------------------------------------------------------------------

void imprimir(struct node* lista){

    if( existeLista(lista) ){

        struct node* ptr_aux = lista;

        while(ptr_aux->sig != nullptr){
            cout << ptr_aux->data << endl;
            ptr_aux = ptr_aux->sig;
        }
        cout << ptr_aux->data << endl;

    }
    else{
        cout << "No existe la lista" << endl;
    }
}

// ------------------------------------------------------------------------------

bool existeLista(struct node* lista){
    /* Comprueba que la lista existe */

    if(lista == nullptr){
        return false;
    }
    return true;

}