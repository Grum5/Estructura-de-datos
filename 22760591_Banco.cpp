/*
    Realizar un programa para la asimulacion de atencion de cleintes de un banco
    Debe contener 4 filas, Cola UNICA, Cola A, Cola B, Cola C
    Cola UNICA: ACCCAABBACB
    Cola A: AAA
    Caja B: BBBBB
    Caja C: CC


    Javier Osvaldo Perez Bretado - 22760591
*/

#include <iostream>
#include <stdlib.h>
#include <limits>

using namespace std;

// -------------------------------------------------------------------
// ------------------------- PROTOTIPOS ------------------------------

char menu();
void agregarcliente(struct cola**, int*);
void desplazarCliente(struct cola**, struct cola**, struct cola**, struct cola**);

void atenderClientes(struct cola**, struct cola**, struct cola**, struct cola**, int*);

void reporteGeneral(struct cola*, struct cola*, struct cola*, struct cola*, int, int);

void agregar(struct cola**, char);
void eliminar(struct cola**);
bool existe(struct cola*);
void pause();

// -------------------------------------------------------------------
// ----------------------- ESTRUCTURAS -------------------------------

struct node{
    char data;
    struct node *sig = nullptr;
};

struct cola{
    struct node *front = nullptr;
    struct node *back = nullptr;
};

// -------------------------------------------------------------------
// -------------------------- MAIN -----------------------------------

int main(){

    // Declarar variables
    struct cola* colaUnica = nullptr;
    struct cola* colaA = nullptr;
    struct cola* colaB = nullptr;
    struct cola* colaC = nullptr;
    bool running = true;
    int total_clientes = 0;
    int clientes_atendidos = 0;

    // Menu
    while(running){

        system("clear");

        switch ( menu() ){

            case '1':
                // Agregar cliente a la cola
                agregarcliente(&colaUnica, &total_clientes);
                break;

            case '2':
                // Desplazar cliente de la cola
                desplazarCliente(&colaUnica, &colaA, &colaB, &colaC);
                break;

            case '3':
                // Atender si un cliente esta en la cola
                atenderClientes(&colaUnica, &colaA, &colaB, &colaC, &clientes_atendidos);
                break;

            case '4':
                // Reporte cola
                reporteGeneral(colaUnica, colaA, colaB, colaC, clientes_atendidos, total_clientes);
                break;

            case '5':
                // Salir si las colas estan vacias
                if( !existe(colaUnica) && !existe(colaA) && !existe(colaB) && !existe(colaC) )
                    running = false;
                else
                    cout << "No se puede salir, hay clientes en las colas" << endl;
                break;

            default:
                break;
        }

        pause();

    }

    delete colaUnica;
    delete colaA;
    delete colaB;
    delete colaC;

    return 0;
}

// -------------------------------------------------------------------
// -------------------------- FUNCIONES ------------------------------

char menu(){

    char opcion;

    cout << "1. AGREGAR cliente a la cola" << endl;
    cout << "2. DESPLAZAR cliente de la cola" << endl;
    cout << "3. ATENDER si un cliente esta en la cola" << endl;
    cout << "4. REPORTE cola" << endl;
    cout << "5. Salir" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    return opcion;
}

// -------------------------------------------------------------------

void agregarcliente(struct cola** colaUnica, int *total_clientes){

    char cliente;

    while( cliente != 'A' && cliente != 'B' && cliente != 'C' ){
        cout << "Ingrese el cliente (A, B, C): ";
        cin >> cliente;
    }

    agregar(colaUnica, cliente);

    *total_clientes += 1;

}

// -------------------------------------------------------------------

void desplazarCliente(struct cola** colaUnica, struct cola** colaA, struct cola** colaB, struct cola** colaC){

    if( existe(*colaUnica) ){

        if( (*colaUnica)->front->data == 'A'){
            agregar(colaA, (*colaUnica)->front->data);
        }

        else if( (*colaUnica)->front->data == 'B'){
            agregar(colaB, (*colaUnica)->front->data);
        }

        else if( (*colaUnica)->front->data == 'C'){
            agregar(colaC, (*colaUnica)->front->data);
        }

        eliminar(colaUnica);

    }
    else{
        cout << "No hay clientes en la cola unica" << endl;
    }

}

// -------------------------------------------------------------------

void atenderClientes(struct cola** colaUnica, struct cola** colaA, struct cola** colaB, struct cola** colaC ,int* clientes_atendidos){

    char caja;

    cout << "Caja que se va a atender (A, B, C): ";
    cin >> caja;

    if ( caja == 'A' ){
        if ( existe(*colaA) ){
            eliminar(colaA);
            *clientes_atendidos += 1;
        }
        else
            cout << "No hay clientes en la cola A" << endl;
    }

    else if ( caja == 'B' ){
        if ( existe(*colaB) ){
            eliminar(colaB);
            *clientes_atendidos += 1;
        }
        else
            cout << "No hay clientes en la cola B" << endl;
    }

    else if ( caja == 'C' ){
        if ( existe(*colaC) ){
            eliminar(colaC);
            *clientes_atendidos += 1;
        }
        else
            cout << "No hay clientes en la cola C" << endl;
    }

    else{
        cout << "Caja no valida" << endl;
    }

}

// -------------------------------------------------------------------

void reporteGeneral(struct cola* colaUnica, struct cola* colaA, struct cola* colaB, struct cola* colaC, int clientes_atendidos, int total_clientes){

    float porcentaje = 0;

    if(clientes_atendidos != 0 && total_clientes != 0)
        porcentaje = (clientes_atendidos* 100) / total_clientes;

    if( existe(colaUnica) ){

        struct node* temp1 = colaUnica->front;

        cout << "Cola Unica: ";
        while( temp1 != nullptr ){
            cout << temp1->data << " ";
            temp1 = temp1->sig;
        }
    }
    else
        cout << "Cola Unica: VACIA";

    if( existe(colaA) ){

        struct node* temp2 = colaA->front;

        cout << endl << "Cola A: ";
        while( temp2 != nullptr ){
            cout << temp2->data << " ";
            temp2 = temp2->sig;
        }
    }
    else
        cout << endl << "Cola A: VACIA";

    if( existe(colaB) ){

        struct node *temp3 = colaB->front;

        cout << endl << "Cola B: ";
        while( temp3 != nullptr ){
            cout << temp3->data << " ";
            temp3 = temp3->sig;
        }
    }
    else
        cout << endl << "Cola B: VACIA";

    if( existe(colaC) ){

        struct node *temp4 = colaC->front;

        cout << endl << "Cola C: ";
        while( temp4 != nullptr ){
            cout << temp4->data << " ";
            temp4 = temp4->sig;
        }
    }
    else
        cout << endl << "Cola C: VACIA";

    cout << endl << "Total de clientes que se han formado: " << total_clientes << endl;
    cout << "Porcentaje de clientes atendidos: " << porcentaje << "%" << endl;
}

// -------------------------------------------------------------------
// -------------------------------------------------------------------

void agregar(struct cola** Cola, char dato){

    if ( existe(*Cola) ){

        struct node* temp = new node;
        temp->data = dato;

        (*Cola)->back->sig = temp;
        (*Cola)->back = temp;

    }

    else{

        *Cola = new cola;
        (*Cola)->front = new node;
        (*Cola)->front->data = dato;
        (*Cola)->back = (*Cola)->front;

    }

}

// -------------------------------------------------------------------

void eliminar(struct cola** Cola){

    if( (*Cola)->front != nullptr && (*Cola)->back != nullptr){     // Si la cola no esta vacia

        struct node* temp = (*Cola)->front;

        if( (*Cola)->front == (*Cola)->back ){
            (*Cola)->front = nullptr;
            (*Cola)->back = nullptr;
        }

        else{
            (*Cola)->front = (*Cola)->front->sig;
        }

        delete temp;

    }

    if( (*Cola)->front == nullptr && (*Cola)->back == nullptr ){    // Si la cola esta vacia
        delete *Cola;
        *Cola = nullptr;
    }

}

// -------------------------------------------------------------------

bool existe(struct cola* Cola){

    if( Cola == nullptr ){
        return false;
    }
    else
        return true;

}

// -------------------------------------------------------------------
// -------------------------- PAUSE ----------------------------------

void pause(){
    cout << "Presione ENTER para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}