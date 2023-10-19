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
bool existeLista(struct node*);
void dividir( struct node**, struct node**, struct node** );
void pause();

// ------------------------------------------------------------------------------
// ----------------------- FUNCION PRINCIPAL ------------------------------------

int main(){

    struct node* lista = nullptr;
    struct node* listaPar = nullptr;
    struct node* listaImp = nullptr;
    int dato;

    // MENU
    char opcion;
    bool running = true;

    do{
        system("clear");
        cout << "MENU" << endl;
        cout << "1. Agregar nodo" << endl;
        cout << "2. Imprimir lista" << endl;
        cout << "3. Dividir lista" << endl;
        cout << "4. Imprimir listas" << endl;
        cout << "5. Salir" << endl;
        cin >> opcion;
        switch(opcion){
            case '1':
                cout << "Ingrese un numero: ";
                cin >> dato;
                agregarNodoDoble(&lista, dato);
                break;
            case '2':
                imprimir(lista);
                break;
            case '3':
                dividir(&lista, &listaImp, &listaPar);
                break;
            case '4':
                cout << "LISTA PAR" << endl;
                imprimir(listaPar);
                cout << "LISTA IMPAR" << endl;
                imprimir(listaImp);
                cout << "LISTA ORIGINAL"<< endl;
                imprimir(lista);
                break;
            case '5':
                running = false;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
        pause();
    }while(running);

    return 0;
}

// ------------------------------------------------------------------------------
// ----------------------- FUNCIONES --------------------------------------------

void dividir( struct node** lista, struct node** listaImp, struct node** listaPar ){
    /* Funcion que redirige a donde apunta cada nodo de la lista original, dejando la lista original apuntando a null */

    if( existeLista(*lista) ){ // Si existe la lista (no es null

        struct node* ptr_temp = *lista;
        struct node* last_nodePar = nullptr;
        struct node* last_nodeImp = nullptr;

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

// ------------------------------------------------------------------------------
// ------------------------------------------------------------------------------

void pause(){
    /*Funcion para hacer un pause en ubuntu*/

    // Limpiar el búfer de entrada
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Presiona Enter para continuar..." << endl;
    cin.get();
}