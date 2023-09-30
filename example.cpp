#include<iostream>

using namespace std;

void funcionEdita(int, int**);

int main(){

    int x = 5;
    int *p = &x;

    cout << "x: " << x << endl;
    cout << "&x: " << &x << endl;
    cout << "p: " << p << endl;
    cout << "*p: " << *p << endl;
    cout << "&p: " << &p << endl << endl;

    funcionEdita(x, &p); // Se manda la variable x y la direccion de memoria del puntero p

    cout << x << endl;

    return 0;
}

void funcionEdita(int x, int **pointer){ // Se manda un puntero a un puntero para poder modificar la variable

    // Se modifica la variable x

    cout << "x: " << x << endl;
    cout << "&x: " << &x << endl;

    // Se modifica el puntero que apunta a la variable x

    (**pointer) = 10;

    // Se imprime la variable x para verificar que se modifico con el puntero
    cout << "x: " << x << endl;
    cout << "&x: " << &x << endl;

    // Se imprime el puntero que apunta a la variable x

    cout << "pointer: " << *pointer << endl;
    cout << "*pointer: " << *pointer << endl;
    cout << "&pointer: " << &pointer << endl;

}