/*
    Realizar un programa que utilice funcion recursiva
    que indique si un texto es un palindromo o No lo es que indique si un texto es un palindromo o No lo es

    22760591 - Javier Osvaldo Perez Bretado
*/

#include<iostream>
#include<string.h>

using namespace std;

//--------------------------------------------//

int size(char* text){
    int longitud = 0;

    while(*text){
        longitud++;
        text++;    
    }
    
    return longitud;
}

//--------------------------------------------//

int sizeNoS(const char* text){
    
    int espacios = 0;

    while(*text){
        if(*text != ' '){
            espacios++;
        }
        text++;
    }

    return espacios;
}

//--------------------------------------------//

bool palindromo(char* pLeft, char* pRight){
    if(*pLeft == *pRight && pLeft <= pRight){
        pLeft++;
        pRight--;
        return palindromo(pLeft, pRight);
    }
    else if(*pLeft != *pRight && pLeft <= pRight){
        return false;
    }
    return true;
}

//--------------------------------------------//

int main(){
    
    // Crear un arreglo de char con espacios para testeo
    // char t[50] = "ana lava lana";
    
    char t[50];

    cout << "Ingrese texto" << endl;
    cin.getline(t, 50);

    // Declarar un arreglo con memoria dinamica sin espacios
    char* noSpaceText = new char[sizeNoS(t) + 1];
    
    // --------- Rellenar el arreglo sin espacios --------- //
    // ---------------------------------------------------- //

    int j = 0;

    for(int i = 0; i < size(t); i++){
        if (t[i] != ' '){
            noSpaceText[j] = t[i];
            j++;
        }
    }
    
    noSpaceText[j] = '\0';
 
    // ---------------------------------------------------- //
    // ---------------------------------------------------- //
    
    // Declarar punteros auxiliares
    char* pLeft = noSpaceText;
    char* pRight = noSpaceText + sizeNoS(noSpaceText) - 1;
    
    bool isPalindromo = palindromo(pLeft, pRight);

    if(isPalindromo){
        cout << "El texto es palindromo" << endl;
    }
    else{
        cout << "El texto no es palindromo" << endl;
    }

    // Liberar memoria
    delete[] noSpaceText;

    return 0;
}

