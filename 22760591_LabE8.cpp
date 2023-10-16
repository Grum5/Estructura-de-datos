/*
    Programar una funcion para concatenar 2 listas enlazadas circulares
    La lista 2 debe unirse al final de la lista 1

    Javier Osvaldo Perez Bretado - 22760591
*/

#include<iostream>
#include<stdlib.h>
#include<limits>

using namespace std;

// ------------------------------------------------------------------------------
// ------------------------------------------------------------------------------

struct node{
    int data;
    struct node* sig = NULL;
};

// ------------------------------------------------------------------------------
// ------------------------------------------------------------------------------

void concat(struct node**, struct node**);
void agregar(struct node**, int);
void imprimir(struct node* );
bool existeLista(struct node*);
void pause();
void printMenu();

// ------------------------------------------------------------------------------
// ------------------------------------------------------------------------------

int main(){
    /* Funcion main de testeo */

    // Declarar las listas
    struct node* lista1 = NULL;
    struct node* lista2 = NULL;
    bool running = true;
    char opcion;
    int dato;

    do{
        printMenu();
        cin >> opcion;
        switch(opcion){

            case '1':
                cout << "Valor a ingresar:  " << endl;
                cin >> dato;
                agregar(&lista1, dato);
                break;

            case '2':
                cout << "Valor a ingresar:  " << endl;
                cin >> dato;
                agregar(&lista2, dato);
                break;

            case '3':
                if( existeLista(lista1) ){
                    imprimir(lista1);
                }
                else{
                    cout << "No existe lista 1" << endl;
                }
                break;

            case '4':
                if( existeLista(lista2) ){
                    imprimir(lista2);
                }
                else{
                    cout << "No existe lista 2" << endl;
                }
                break;

            case '5':
                if ( !existeLista(lista1) && !existeLista(lista2) ){
                    cout << "No existe la lista 1 y lista 2" << endl;
                }
                else if( !existeLista(lista1) && existeLista(lista2) ){
                    lista1 = lista2;
                    lista2 = NULL;
                    free(lista2);
                }
                else if( existeLista(lista1) && !existeLista(lista2) ){
                    cout << "lista 2 no existe" << endl;
                }
                else if( existeLista(lista1) && existeLista(lista2) ) {
                    concat(&lista1, &lista2);
                }

                break;

            case '6':
                running = false;
                cout << "Saliendo..." << endl;
                break;

            default:
                cout << "NO VALIDO" << endl;
                break;
        }

        pause();

    }while(running);

    return 0;
}

// ------------------------------------------------------------------------------
// ------------------------------------------------------------------------------

void concat(struct node** lista1, struct node** lista2){

    struct node* ptr_temp1 = *lista1;
    struct node* ptr_temp2 = *lista2;

    // Mover puntero temporal de lista 2
    while(ptr_temp2->sig != *lista2){
        ptr_temp2 = ptr_temp2->sig;
    }

    // Mover puntero temporal de lista 1
    while(ptr_temp1->sig != *lista1){
        ptr_temp1 = ptr_temp1->sig;
    }

    ptr_temp1->sig = *lista2;
    ptr_temp2->sig = *lista1;

    // Dejar a lista2 apuntando a NULL
    *lista2 = NULL;
    // Liberar memoria de Lista2
    free(*lista2);

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

// --------------------------------------------------------------------

void printMenu(){
    system("clear");
        cout << "1. Agregar Lista 1" << endl;
        cout << "2. Agregar Lista 2" << endl;
        cout << "3. Imprimir Lista 1" << endl;
        cout << "4. Imprimir Lista 2" << endl;
        cout << "5. Concatenar" << endl;
        cout << "6. Salir" << endl;
        cout << "Opcion: ";
}
// --------------------------------------------------------------------

bool existeLista(struct node* lista_temp){
    /* Comprueba que la lista existe */

    if(lista_temp == NULL){
        return false;
    }
    return true;
}

// --------------------------------------------------------------------
// --------------------------------------------------------------------

void pause(){
    /*Funcion para hacer un pause en ubuntu*/

    // Limpiar el búfer de entrada
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Presiona Enter para continuar...";
    cin.get();
}