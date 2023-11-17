/*
    Realizar un programa que permita:
        * Agregar en un árbol binario nombres de personas. Si el nombre ya existe en el árbol binario, incrementar un contador en el nodo de ese nombre.
        * Imprimir un reporte de los antecesores de un nombre ingresado en el árbol binario.
    NOTA: Imprimir los antecesores, desde el antecesor mas cercano hasta la raíz.
    Enviar el archivo fuente.

        * Agregar impresion en inorden
        * Agregar impresion en preorden
    Javier Osvaldo Perez Bretado - 22760591
*/

#include <iostream>
#include <stdlib.h>
#include <limits>

using namespace std;

// -------------------------------------------------------------------
// ------------------------- ESTUCTURAS ------------------------------

struct node_pila{

    struct node_arbol *node = nullptr;
    struct node_pila *sig = nullptr;

};

struct node_arbol{

    string nombre;
    int contador = 1;

    struct node_arbol *izq = nullptr;
    struct node_arbol *der = nullptr;

};

// -------------------------------------------------------------------
// --------------- PROTOTIPOS PARA ARBOLES ---------------------------

void agregarNodoArbol(struct node_arbol**, string);
void reporteInorden(struct node_arbol*);
void reportePreorden(struct node_arbol*);
bool existeNombre(struct node_arbol*, string);
bool existeArbol(struct node_arbol*);
string reporteAntecesores(struct node_arbol*, string);

// ------------ PROTOTIPOS PARA RECORRIDOS DE IMPRESION --------------

void printInorden(struct node_arbol*);
void printPreorden(struct node_arbol*);
void printPostorden(struct node_arbol*);

// ---------------- PROTOTIPOS PARA PILAS ----------------------------

void agregarPila(struct node_pila**, struct node_arbol *);
void sacarPila(struct node_pila**);
bool existePila(struct node_pila*);

// --------------- PROTOTIPOS DE FUNCIONES EXTRAS --------------------

char menu();
void pause();

// -------------------------------------------------------------------
// -------------------------- MAIN -----------------------------------

int main(){

    // Declarar variables
    struct node_arbol *arbol = nullptr;
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
                cin.ignore();
                getline(cin, nombre);
                agregarNodoArbol(&arbol, nombre);
                break;

            case '2':
                // Imprimir reporte
                cout << "Nombre: ";
                cin.ignore();
                getline(cin, nombre);
                cout << endl;

                // Si el arbol existe y existe el nombre en el arbol realizar el reporte
                if( existeArbol(arbol) && existeNombre(arbol, nombre)){
                    reporteAntecesores(arbol, nombre);
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

            case '4':
                // Reporte Inorden
                cin.ignore();
                printInorden(arbol);
                break;

            case '5':
                // Reporte Preorden
                cin.ignore();
                printPreorden(arbol);
                break;

            default:
                // Opcion no valida
                cout << "Opcion invalida" << endl;
                break;
        }

        // Pausar el programa hasta que se oprima Enter
        pause();
    }

    cout << endl;
    return 0;
}

// -------------------------------------------------------------------
// -------------------- FUNCIONES DE ARBOL ---------------------------


void agregarNodoArbol(struct node_arbol** arbol, string nombre){

    // Variable temporal para recorrer el arbol
    bool running = true;

    if( *arbol == nullptr){
        // Si el arbol esta vacio, agregar el nodo
        *arbol = new node_arbol;
        (*arbol)->nombre = nombre;
    }
    else{
        // Si el arbol no esta vacio, tiene al menos un nodo

        // Crear un nuevo nodo
        struct node_arbol* nuevo_nodo = new node_arbol;
        nuevo_nodo->nombre = nombre;

        // Crear un nodo temporal para recorrer el arbol
        struct node_arbol* ptr_temp = *arbol;

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

string reporteAntecesores(struct node_arbol* arbol, string nombre){

    // Si el nombre es menor al nombre de la raiz, imprimir el return de la funcion reporte y el contador del nodo hijo contador
    if( nombre < arbol->nombre )
        cout << reporteAntecesores(arbol->izq, nombre) << "\t" << arbol->izq->contador << endl;

    // Si el nombre es mayor al nombre de la raiz, imprimir el return de la funcion reporte y el contador del nodo hijo contador
    if( nombre > arbol->nombre )
        cout << reporteAntecesores(arbol->der, nombre) << "\t" << arbol->der->contador << endl;

    // Si no se cumple ninguna condicion, retornar el nombre del nodo actual (raiz)
    return arbol->nombre;

}

// -------------------------------------------------------------------

bool existeNombre(struct node_arbol* arbol, string nombre){

    // Declaracion de variables temporales
    bool existencia = false;
    bool running = true;

    // Ciclo para recorrer el arbol
    while( running ){

        // Si el nombre es igual al nombre de la raiz se comprueba la existencia y se abandona el ciclo
        if( nombre == arbol->nombre ){
            existencia = true;
            running = false;
        }

        // Si el nombre es menor al de la raiz y el nodo izquierdo es diferente de nullptr se mueve arbol al nodo izquierdo
        else if( nombre < arbol->nombre && arbol->izq != nullptr )
            arbol = arbol->izq;

        // Si el nombre es menor al de la raiz y el nodo izquierdo es diferente de nullptr se acaba el ciclo
        else if( nombre < arbol->nombre && arbol->izq == nullptr )
            running = false;

        // Si el nombre es menor al de la raiz y el nodo derecho es diferente de nullptr se mueve arbol al nodo derecho
        else if( nombre > arbol->nombre && arbol->der != nullptr )
            arbol = arbol->der;

        // Si el nombre es menor al de la raiz y el nodo derecho es diferente de nullptr se acaba el ciclo
        else if( nombre > arbol->nombre && arbol->der == nullptr )
            running = false;

    }

    // Se retorna el booleano existencia
    return existencia;
}

// -------------------------------------------------------------------

bool existeArbol(struct node_arbol* arbol){

    // Se comprueba si arbol no apunta a nullptr y se retorna true
    if( arbol != nullptr )
        return true;

    return false;

}

// -------------------------------------------------------------------
// ----------------- FUNCIONES DE RECORRIDOS -------------------------

void printInorden(struct node_arbol *arbol){

    if ( !existeArbol(arbol) ){

        cout << "No existe el arbol" << endl;
        return;

    }

    struct node_pila *pila = nullptr;
    struct node_arbol *ptr_temp = arbol;

    while( existeArbol(ptr_temp) || existePila(pila)){

        while( ptr_temp != nullptr ){

            // Se agrega a la pila un nodo que contenga el dato de la estructura de arbol
            agregarPila( &pila, ptr_temp);

            // Se mueve ptr_temp al nodo izquierdo
            ptr_temp = ptr_temp->izq;

        }

        // Ya que ptr_temp apunta a nulo, se reapunta a la direccion de memoria anterior
        ptr_temp = pila->node;

        // Se saca de un nodo de la pila
        sacarPila( &pila );

        // Se imprime el valor del nombre del nodo actual en pantalla
        cout << ptr_temp->nombre << endl;

        // Se cambia el apuntador al nodo derecho
        ptr_temp = ptr_temp->der;

    }

}

// -------------------------------------------------------------------

void printPreorden(struct node_arbol *arbol){

    struct node_arbol *ptr_temp = nullptr;
    struct node_pila *pila = nullptr;

    agregarPila( &pila, arbol);

    while ( existePila( pila ) ){

        ptr_temp = pila->node;

        sacarPila( &pila );

        cout << ptr_temp->nombre << endl;

        if( ptr_temp->der != nullptr )
            agregarPila( &pila , ptr_temp->der );

        if( ptr_temp->izq != nullptr )
            agregarPila( &pila, ptr_temp->izq );

    }

}

// -------------------------------------------------------------------

void printPostorden(struct node_arbol *arbol){

}

// -------------------------------------------------------------------
// ----------------- FUNCIONES DE PILA -------------------------------

void agregarPila(struct node_pila** pila, struct node_arbol *arbol){

    // Declaracion de el nodo de la pila
    struct node_pila* new_node = new node_pila;

    // Se le asigna la direccion de memoria del nodo a la estructura
    new_node->node = arbol;

    // Se enlaza el apuntador sig del nodo nuevo a la pila
    new_node->sig = *pila;

    // Se enlaza la pila al nuevo nodo
    *pila = new_node;

}

// -------------------------------------------------------------------

bool existePila(struct node_pila* pila){

    // Se comprueba si pila no apunta a nullptr y se retorna true
    if( pila != nullptr )
        return true;

    return false;

}

// -------------------------------------------------------------------

void sacarPila(struct node_pila** pila){

    struct node_pila* delete_node = *pila;

    *pila = (*pila)->sig;

    delete delete_node;

}

// -------------------------------------------------------------------
// --------------------- FUNCIONES AUXILIARES ------------------------

char menu(){

    // Declarar variable temporal
    char opcion;

    // Imprimir el menu
    cout << "Menu" << endl;
    cout << "1) Agregar nombre" << endl;
    cout << "2) Imprimir reporte" << endl;
    cout << "3) Salir" << endl;
    cout << "4) Reporte INORDEN" << endl;
    cout << "5) Reporte PREORDEN" << endl;
    cout << "Opcion: ";

    // Registrar la opcion
    cin >> opcion;

    // Retornar la opcion
    return opcion;
}

// -------------------------------------------------------------------

void pause(){
    /*Funcion de pausa*/

    cout << "Presione ENTER para continuar...";
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}