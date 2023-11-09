/*
    Realizar un programa que permita:
        * agregar en un árbol binario nombres de personas. Si el nombre ya existe en el árbol binario, incrementar un contador en el nodo de ese nombre.
        * Imprimir un reporte de los antecesores de un nombre ingresado en el árbol binario.
    NOTA: Imprimir los antecesores, desde el antecesor mas cercano hasta la raíz.
    Enviar el archivo fuente.

    Javier Osvaldo Perez Bretado - 22760591
*/

#include <iostream>
#include <stdlib.h>
#include <limits>

using namespace std;

// -------------------------------------------------------------------
// ------------------------- ESTUCTURAS ------------------------------

struct node{
    string nombre;
    int contador = 1;
    struct node *izq = nullptr;
    struct node *der = nullptr;
};

// -------------------------------------------------------------------
// ------------------------- PROTOTIPOS ------------------------------

char menu();
void agregarNodo(struct node**, string);
string reporte(struct node*, string);
bool existeNombre(struct node*, string);
bool existeArbol(struct node*);
void pause();

// -------------------------------------------------------------------
// -------------------------- MAIN -----------------------------------

int main(){

    // Declarar variables
    struct node *arbol = nullptr;
    bool running = true;
    string nombre;


    while(running){

        // Realizar un clear de la screen
        system("clear");

        // Ejecutar un switch que pide de opcion el retorno de la funcion menu
        switch( menu() ){

            case '1':
                // Agregar nombre al arbol
                cout << "Nombre: ";
                cin >> nombre;
                agregarNodo(&arbol, nombre);
                break;

            case '2':
                // Imprimir reporte
                cout << "Nombre: ";
                cin >> nombre;
                cout << endl;

                // Si el arbol existe y existe el nombre en el arbol realizar el reporte
                if( existeArbol(arbol) && existeNombre(arbol, nombre)){
                    reporte(arbol, nombre);
                    cout << arbol->nombre << "\t" << arbol->contador << endl;;

                }

                // En caso contrario imprimir que no existe
                else
                    cout << "No existe el nombre en el arbol" << endl;

                break;

            case '3':
                // Salir del programa
                running = false;
                break;

            default:
                // Opcion no valida
                cout << "Opcion invalida" << endl;
                break;
        }

        // Pausar el programa hasta que se oprima Enter
        pause();
    }

    return 0;
}

// -------------------------------------------------------------------
// ------------------------- FUNCIONES -------------------------------

char menu(){

    // Declarar variable temporal
    char opcion;

    // Imprimir el menu
    cout << "Menu" << endl;
    cout << "1) Agregar nombre" << endl;
    cout << "2) Imprimir reporte" << endl;
    cout << "3) Salir" << endl;
    cout << "Opcion: ";

    // Registrar la opcion
    cin >> opcion;

    // Retornar la opcion
    return opcion;
}

// -------------------------------------------------------------------

void agregarNodo(struct node** arbol, string nombre){

    // Variable temporal para recorrer el arbol
    bool running = true;

    if( *arbol == nullptr){
        // Si el arbol esta vacio, agregar el nodo
        *arbol = new node;
        (*arbol)->nombre = nombre;
    }
    else{
        // Si el arbol no esta vacio, tiene al menos un nodo

        // Crear un nuevo nodo
        struct node* nuevo_nodo = new node;
        nuevo_nodo->nombre = nombre;

        // Crear un nodo temporal para recorrer el arbol
        struct node* ptr_temp = *arbol;

        // Recorrer el arbol
        while(running){

            // Si el nombre es menor que la raiz
            if( nombre < ptr_temp->nombre ){

                // Si el puntero izquierdo NO es nulo, se desplaza ptr_temp
                if( ptr_temp->izq != nullptr ){
                    ptr_temp = ptr_temp->izq;
                }

                // Si el puntero izquierdo es nulo, se inserta nuevo_nodo
                else{
                    ptr_temp->izq = nuevo_nodo;

                    // Se cambia la condicion de running
                    running = false;

                }

            }

            // Si el nombre es mayor que la raiz
            else if( nombre > ptr_temp->nombre ){

                // Si el puntero derecho NO es nulo, se desplaza ptr_temp
                if( ptr_temp->der != nullptr){
                    ptr_temp = ptr_temp->der;
                }

                // Si el puntero derecho es nulo, se inserta nuevo_nodo
                else{
                    ptr_temp->der = nuevo_nodo;

                    // Se cambia la condicion de running
                    running = false;

                }
            }

            // Si el nombre es igual que al de la raiz
            else if( nombre == ptr_temp->nombre ){

                // Se incrementa el contador del nodo raiz
                ptr_temp->contador++;

                // Se elimina la memoria usada para nuevo_nodo
                delete nuevo_nodo;

                // Se cambia la condicion de running
                running = false;

            }
        }
    }

}

// -------------------------------------------------------------------

string reporte(struct node* arbol, string nombre){

    // Si el nombre es menor al nombre de la raiz, imprimir el return de la funcion reporte y el contador del nodo hijo contador
    if( nombre < arbol->nombre )
        cout << reporte(arbol->izq, nombre) << "\t" << arbol->izq->contador << endl;

    // Si el nombre es mayor al nombre de la raiz, imprimir el return de la funcion reporte y el contador del nodo hijo contador
    if( nombre > arbol->nombre )
        cout << reporte(arbol->der, nombre) << "\t" << arbol->der->contador << endl;

    // Si no se cumple ninguna condicion, retornar el nombre del nodo actual (raiz)
    return arbol->nombre;

}

// -------------------------------------------------------------------

bool existeNombre(struct node* arbol, string nombre){

    // Si nombre es menor al nombre de la raiz y el nodo hijo izquierdo no es nulo, ejecutar de nuevo la funcion
    if( nombre < arbol->nombre && arbol->izq != nullptr )
        existeNombre(arbol->izq, nombre);

    // Si nombre es menor al nombre de la raiz y el nodo hijo izquierdo es nulo, retornar false
    else if(nombre < arbol->nombre && arbol->izq == nullptr)
        return false;

    // Si nombre es mayor al nombre de la raiz y el nodo hijo derecho no es nulo, ejecutar de nuevo la funcion
    if( nombre > arbol->nombre && arbol->der != nullptr)
        existeNombre(arbol->der, nombre);

    // Si nombre es mayor al nombre de la raiz y el nodo hijo derecho es nulo, retornar false
    else if(nombre < arbol->nombre && arbol->izq == nullptr)
        return false;

    // Si no se cumple ninguna condicion, retornar true (el nodo con el nombre existe)
    return true;

}

// -------------------------------------------------------------------

bool existeArbol(struct node* arbol){

    //Declarar una variable temporal
    bool existe;

    // Utilizar un operador ternario para saber si existe el arbol
    arbol != nullptr ? existe = true :  existe = false;

    // Retornar la existencia del arbol
    return existe;

}
// -------------------------------------------------------------------
// --------------------- FUNCIONES AUXILIARES ------------------------

void pause(){
    /*Funcion de pausa*/

    cout << "Presione ENTER para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}
