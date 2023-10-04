/*
    Realizar un programa en el cual se capturen numeros enteros
    y guardarlos en una lista enlazada. Verificar que los numeros
    que se guarden en la lista no se repitan

        - Se han agregado las funciones de incrementar y eliminar ultimo nodo

    Javier Osvaldo Perez Breatdo - 22760591
*/

#include<iostream>
#include<stdlib.h>
#include<limits>

using namespace std;

// --------------------------------------------------------------------
// ------------------------ ESTRUCTURAS -------------------------------

struct node{
    int data;
    struct node *sig = NULL;
};

// --------------------------------------------------------------------
// -------------------- DEFINICIONES ----------------------------------

// Por el momento se comento esto ya que me causa problemas para visualizar bien el codigo
// typedef struct node nodo;
// typedef nodo *tipoLista;

// --------------------------------------------------------------------
// ------------------------ PROTOTIPOS --------------------------------

void menuRun(struct node* *);   // Se manda un puntero a un puntero para poder modificar la lista
void agregar(struct node* *);   // Se manda un puntero a un puntero para poder modificar la lista
void imprimir(struct node*);
bool existeEnLista(struct node*, int);
void pause();
void incrementar(struct node*);
bool existeLista(struct node*);
int eliminarUltimoNodo(struct node* *);

// --------------------------------------------------------------------
// ------------------------ FUNCION PRINCIPAL -------------------------

int main(){

    struct node *lista = NULL; // Se declara un puntero a un nodo y se inicializa en NULL

    menuRun(&lista); // Se manda la direccion de memoria del puntero a la funcion menuRun

    return 0;
}

// --------------------------------------------------------------------
// ------------------------ FUNCIONES ---------------------------------

void menuRun(struct node* *lista){
    /* Funcion que genera y gestiona el menu */

    char opcion;

    do{
        system("clear");
        cout << "1. Agregar un nodo" << endl;
        cout << "2. Imprimir la lista" << endl;
        cout << "3. Salir" << endl;
        cout << "4. Incrementar" << endl;
        cout << "5. Eliminar ultimo nodo" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion){
            case '1':
                agregar(lista); // Se manda la direccion de memoria del puntero a la funcion agregar
                break;
            case '2':
                imprimir(*lista); // Se manda el puntero a la funcion imprimir
                break;
            case '3':
                cout << "Saliendo..." << endl;
                break;
            case '4':
                incrementar(*lista);
                break;
            case  '5':
                existeLista(*lista) ? cout << "Valor eliminado: "<< eliminarUltimoNodo(lista) : cout << "La lista esta vacia";
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }

        pause();

    }while(opcion!='3');

}

// --------------------------------------------------------------------

int eliminarUltimoNodo(struct node* *lista){
    /* Funcion que elimina el ultimo nodo de la lista */

    struct node* last_node = *lista;                // Nodo temporal para recorrer la lista

    int valor;                                      // Variable para guardar el valor del ultimo nodo

    if( last_node->sig == NULL){                    // Si el nodo siguiente es NULL, significa que solo hay un nodo en la lista

        valor = last_node->data;                    // Se guarda el valor del nodo
        free(last_node);                            // Se libera la memoria del nodo
        *lista = NULL;                              // Se asigna NULL al puntero de la lista

        return valor;                               // Se retorna el valor del nodo
    }
    else{

        struct node* prev_node = NULL;              // Nodo temporal para guardar el nodo anterior

        while(last_node->sig != NULL){              // Se recorre la lista hasta que el nodo siguiente sea NULL
            prev_node = last_node;
            last_node = last_node->sig;
        }

        valor = last_node->data;                    // Se guarda el valor del ultimo nodo
        free(last_node);                            // Se libera la memoria del ultimo nodo
        prev_node->sig = NULL;                      // Se asigna NULL al nodo anterior
        return valor;                               // Se retorna el valor del ultimo nodo
    }
}


// --------------------------------------------------------------------

void incrementar(struct node* lista_temp){
    /* Funcion que suma el valor del nodo n por el nodo n+1 */

    struct node* p =lista_temp;
    if(p->sig != NULL && p != NULL){
        p = p->sig;
        while (p != NULL){
            lista_temp -> data = (lista_temp -> data) + (p -> data);
            lista_temp = lista_temp->sig;
            p = p->sig;
        }
    }
}

// --------------------------------------------------------------------

bool existeLista(struct node* lista_temp){
    /* Comprueba que la lista existe */

    if(lista_temp == NULL){
        return false;
    }
    return true;
}

bool existeEnLista(struct node* lista_temp, int dato){
    /* Comprueba el valor de un dato en la lista */

    // Se recorre la lista hasta que el puntero temporal sea NULL
    while(lista_temp != NULL){
        if (lista_temp->data == dato){
            return true; // Si el dato existe en la lista se retorna un true
        }
        lista_temp = lista_temp->sig; // Se avanza al siguiente nodo
    }

    return false; // Si el dato no existe en la lista se retorna un false
}

void agregar(struct node* *lista){
    /* Funcion que agrega un nuevo nodo al inicio de la lista */

    int dato;

    // Pedir el dato que se ingresara
    cout << "Ingresa el numero deseado: ";
    cin >> dato;

    if( !existeEnLista(*lista, dato) ){

        if(lista == NULL){ // Verificar si la lista es NULL

            *lista = (struct node*) malloc(sizeof(struct node)); // Se asigna memoria para el nodo
            (*lista)->data = dato; // Se asigna el dato al nodo

        }

        else{ // Si la lista no es NULL, tiene un nodo por lo tanto se crea un nodo nuevo que se conecta

        struct node* nodo_nuevo; // Se declara un nodo nuevo

        nodo_nuevo = (struct node*) malloc(sizeof(struct node)); // Se asigna memoria para el nodo nuevo

        nodo_nuevo->data = dato; // Se asigna el dato al nodo nuevo
        nodo_nuevo->sig = *lista; // Se conecta el nodo nuevo con la lista
        *lista = nodo_nuevo; // Se asigna el nodo nuevo como el primer nodo de la lista

        }
    }
    else{
        cout << "Este valor ya existe en la lista" << endl;
    }

}

void imprimir(struct node* lista_temp){
    /* Funcion que imprime los datos de cada nodo */

    while( lista_temp != NULL){
        cout << lista_temp->data << endl;
        lista_temp = lista_temp->sig;
    }
}


//-------------------------------------------------------
//-------------------------------------------------------

void pause(){
  /*Funcion para hacer un pause en ubuntu*/

  // Limpiar el búfer de entrada
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Presiona Enter para continuar...";
  cin.get();

}