/*
    Realizar un programa el cual utilice una función para crear una lista enlazada con nombres de personas.
    La función debe recibir la dirección de la lista y el nombre de la persona.
    La función debe crear la lista alfabéticamente

    Javier Osvaldo Perez Bretado - 22760591
*/

#include <iostream>
#include <stdlib.h>
#include <limits>
#include <cstring>

using namespace std;

// --------------------------------------------------------------------
// ------------------------ ESTRUCTURAS -------------------------------

struct node
{
    char *name = NULL;
    int contador = 1;
    struct node *sig = NULL;
};

// --------------------------------------------------------------------
// -------------------- PROTOTIPOS  -----------------------------------

void agregar(struct node **, char *);
void imprimir(struct node *);
bool existeEnLista(struct node *, char *);
bool existeLista(struct node*);
void pause();

// --------------------------------------------------------------------
// ------------------------ FUNCION PRINCIPAL -------------------------

int main()
{

    struct node *lista = NULL;                     // Se declara un puntero a un nodo y se inicializa en NULL
    char opcion;                                   // Variable para guardar la opcion del menu
    bool running = true;                           // Variable para controlar el ciclo del menu

    char* nombre = new char[100];

    do
    {
        // Se limpia la pantalla y se muestra el menu
        system("clear");
        cout << "1. Agregar un nodo (Ordenados alfabeticamente)" << endl;
        cout << "2. Imprimir la lista" << endl;
        cout << "3. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion)
        {

        case '1': // Opcion para agregar un nodo
            cout << "Agregar nombre: " << endl;
            cin.ignore();
            cin >> nombre;
            agregar(&lista, nombre);
            break;

        case '2':            // Opcion para imprimir la lista
            imprimir(lista); // Se manda el puntero a la funcion imprimir
            break;

        case '3': // Opcion para salir
            cout << "Saliendo..." << endl;
            running = false;
            break;

        default: // Opcion invalida
            cout << "Opcion invalida" << endl;
            break;
        }

        pause(); // Se hace una pausa para que el usuario pueda leer la informacion

    } while (running);

    // Liberar memoria
    delete[] nombre;
    delete[] lista;


    return 0;
}

// --------------------------------------------------------------------
// ------------------------ FUNCIONES ---------------------------------

void agregar(struct node **lista, char *nombre)
{

    if (*lista == NULL)
    {
        (*lista) = new node;
        (*lista)->name = new char[100];
        strcpy((*lista)->name, nombre);
    }

    else
    {
        if (!existeEnLista(*lista, nombre)){ // Si el nombre no existe en la lista, se agrega un nuevo nodo con el nombre

            struct node* lista_temp = *lista;
            struct node* nuevo_nodo = new node;
            int longitud = strlen(nombre);
            nuevo_nodo->name = new char[longitud + 1];
            strcpy(nuevo_nodo->name, nombre);
            nuevo_nodo->name[longitud] = '\0';

            // CASO 1: El nombre es menor al primer nodo de la lista
            if (strcmp(nombre, lista_temp->name) < 0)
            {
                nuevo_nodo->sig = (*lista);
                (*lista) = nuevo_nodo;
            }
            // CASO 2: El nombre es mayor al primer nodo de la lista
            else
            {
                while (lista_temp->sig != NULL && strcmp(nombre, lista_temp->sig->name) > 0)
                {
                    lista_temp = lista_temp->sig;
                }
                nuevo_nodo->sig = lista_temp->sig;
                lista_temp->sig = nuevo_nodo;
            }
        }
    }

}

// --------------------------------------------------------------------

bool existeEnLista(struct node *lista_temp, char *nombre){
    /* Funcion que evalua si un nombre ya existe en la lista */

    bool existe = false;

    while (lista_temp != NULL){ // Ciclo para recorrer la lista

        if (strcmp(lista_temp->name, nombre) == 0){ // Si el nombre ya existe en la lista, se incrementa el contador
            lista_temp->contador += 1;
            existe = true;
            break;
        }

        else{ // Si el nombre no existe en la lista, se evalua el siguiente nodo
            lista_temp = lista_temp->sig;
        }
    }
    return existe; // Si el nombre no existe en la lista, se retorna false
}

// --------------------------------------------------------------------

void imprimir(struct node *lista_temp){
    /* Funcion para imprimir la lista */

    if (lista_temp == NULL){ // Si la lista esta vacia, se muestra un mensaje
        cout << "La lista esta vacia" << endl;
    }

    else{ // Si la lista no esta vacia, se recorre la lista y se muestra el nombre y el contador
        while (lista_temp != NULL){
            cout << "Nombre: "<< lista_temp->name << " - Cantidad: " << lista_temp->contador << endl;
            lista_temp = lista_temp->sig;
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


// --------------------------------------------------------------------
// --------------------------------------------------------------------

void pause(){
    /*Funcion para hacer un pause en ubuntu*/

    // Limpiar el búfer de entrada
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Presiona Enter para continuar...";
    cin.get();
}