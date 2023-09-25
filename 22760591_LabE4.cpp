/*
    Realizar un programa que capture un texto
    Extraer cada palabra y guardar las palabras en una arreglo de cadenas
    Guardar el numero de caracteres que tiene cada palabra en un arreglo numerico
    Imprimir las palabras del arreglo de cadenas y numero de letras de cada palabra

    Javier Osvaldo Perez Bretado - 22760591
*/

#include <iostream>

using namespace std;

//--------------------------------------------------------------------
//-----------------------Prototipo de funciones-----------------------

int separarPalabras(char*);
int contarPalabras(char*);
char** llenarMatriz(char*, char**, int*);
int* llenarLetras(char*, int*);

//--------------------------------------------------------------------
//--------------------------Función Principal-------------------------

int main() {

    // Declarar puntero de caracteres
    char texto[20] = "Hola mundo test";
    char* punteroTexto = texto;


    /*
    cout << "Introduce el texto" << endl;
    cin.getline(texto, 100);
    */

    // Declarar matriz con memoria dinamica
    char** palabras = new char*[contarPalabras(texto)];
    int* letras = new int[contarPalabras(texto)];

    letras = llenarLetras(punteroTexto, letras);
    palabras = llenarMatriz(punteroTexto, palabras, letras);

    return 0;
}

//--------------------------------------------------------------------
//-------------------------Funciones auxiliares-----------------------

int* llenarLetras(char* texto, int* letras){
    
    

    return letras;
}

char** llenarMatriz(char* texto, char** matriz){

    while(*texto){

    }

    return matriz;
}

char* resetPuntero(char* texto){
    int size = 0;
    while(*texto){
        size++;
        texto++;
    }
    
    return (texto - size);

}

int* contarLetras(int palabrasTotales, char* texto){
    int *letras = new int[palabrasTotales];
    int i = 0;

    while(*texto){
        if(*texto == ' '){
            i++;
        }
        else{
            letras[i]++;
        }
    }
    
    return letras;
}

int contarPalabras(char* texto){

    // Obtener el numero de palabras
    int palabrasTotales = 0;
    bool esPalabra = false;
    
    while(*texto){
        if(*texto == ' '){
            esPalabra = false;
        }
        else if(!esPalabra){
            esPalabra = true;
            palabrasTotales++;
        }
        texto++;
    }

    return palabrasTotales;    
}

