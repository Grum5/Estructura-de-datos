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
    struct node* sig = nullptr;
};

// ------------------------------------------------------------------------------
// ----------------------- PROTOTIPOS -------------------------------------------

void agregar(struct node**);
void imprimir(struct node*);
void concat(struct node**, struct node**);
void eliminar(struct node**);
bool existeLista(struct node*);
void pause();

// ------------------------------------------------------------------------------
// ----------------------- FUNCION PRINCIPAL ------------------------------------

int main(){

    // Declarar las listas
    struct node* lista1 = nullptr;
    struct node* lista2 = nullptr;

    // Declarar variables para el menu
    char opcion;
    bool running = true;

    do{

        system("clear");

        cout << "1) AGREGAR lista1" << endl;
        cout << "2) AGREGAR lista2" << endl;
        cout << "3) IMPRIMIR lista1" << endl;
        cout << "4) IMPRIMIR lista2" << endl;
        cout << "5) CONCATENAR (lista1 + lista2)" << endl;
        cout << "6) ELIMINAR dato de lista1" << endl;
        cout << "7) ELIMINAR dato de lista2" << endl;
        cout << "8) SALIR" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion){

            case '1':
                agregar(&lista1);
                break;

            case '2':
                agregar(&lista2);
                break;

            case '3':
                imprimir(lista1);
                break;

            case '4':
                imprimir(lista2);
                break;

            case '5':
                concat(&lista1, &lista2);
                break;

            case '6':
                eliminar(&lista1);
                break;

            case '7':
                eliminar(&lista2);
                break;

            case '8':
                cout << "Saliendo..." << endl;
                running = false;
                break;

            default:
                cout << "Opcion invalida" << endl;
                break;
        }
        pause();
    }while(running);

    return 0;
}

// ------------------------------------------------------------------------------
// ----------------------- FUNCIONES -------------------------------------------

void agregar(struct node** lista){

    int dato;

    cout << "Ingresa el dato a ingresar: " << endl;
    cin >> dato;

    if( !existeLista(*lista) ){

        *lista = new node;
        (*lista)->data = dato;
        (*lista)->sig = *lista;

    }
    else{

        struct node* ptr_temp = *lista;
        struct node* new_node = new node;

        new_node->data = dato;
        new_node->sig = *lista;

        while( ptr_temp->sig != *lista ){
            ptr_temp = ptr_temp->sig;
        }

        ptr_temp->sig = new_node;

    }

}

// ------------------------------------------------------------------------------

void imprimir(struct node* lista){

    if( existeLista(lista) ){

        struct node* ptr_aux = lista;

        while(ptr_aux->sig != lista){
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

void concat(struct node** lista1, struct node** lista2){

    if( !existeLista(*lista1) && !existeLista(*lista2) ){
        cout << "No existe la lista1 y lista2" << endl;
    }

    else if( existeLista(*lista1) && !existeLista(*lista2) ){
        cout << "No existe lista2" << endl;
    }

    else if( !existeLista(*lista1) && existeLista(*lista2) ){

        *lista1 = *lista2;
        *lista2 = nullptr;

    }
    else{

        struct node* ptr_temp = *lista1;

        while( ptr_temp->sig != *lista1 ){
            ptr_temp = ptr_temp->sig;
        }

        ptr_temp->sig = *lista2;
        ptr_temp = ptr_temp->sig;

        while( ptr_temp->sig != *lista2 ){
            ptr_temp = ptr_temp->sig;
        }

        ptr_temp->sig = *lista1;
        *lista2 = nullptr;

    }

}

// ------------------------------------------------------------------------------

void eliminar(struct node** lista){
    /* Funcion que elimina los nodos que tengan el valor que se ingreso en su estructura */

    if( existeLista(*lista) ){

    int dato;
    cout << "Ingrese el dato a eliminar: " << endl;
    cin >> dato;

        struct node* ptr_temp = *lista;

        while( ptr_temp->sig != *lista ){
            if( ptr_temp->sig->data == dato ){
                struct node* delete_node = ptr_temp->sig;
                ptr_temp->sig = ptr_temp->sig->sig;
                delete delete_node;
            }
            else{
                ptr_temp =  ptr_temp->sig;
            }
        }

        if( (*lista)->data == dato && (*lista)->sig != *lista ){  // Evaluar el primer nodo de la lista y verificar no sea el ultimo nodo
            struct node* delete_node = ptr_temp->sig;
            *lista = (*lista)->sig;
            ptr_temp->sig = *lista;
            delete delete_node;
        }

        else if( (*lista)->data == dato && (*lista)->sig == *lista ){    // Si es el ultimo nodo y se debe eliminar
            *lista = nullptr;
            delete ptr_temp;
        }

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
