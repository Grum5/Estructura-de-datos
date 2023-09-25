/*
    Tarea 4: Funciones NO recursivas

    Javier Osvaldo Perez Bretado - 22760591
*/

#include<iostream>
#include<math.h>

using namespace std;

//------------------------- Funciones -------------------------//

int suma_sucesivas(int n, int m){
    /* Funcion que realiza sumas sucesivas */

    int resultado = 0;
    for(int i = 1; i<=m; i++){
        resultado = resultado + n;
    }
    return resultado;
}

//----------------------------------------------------------------

void dec_bin(int dec){
    /* Funcion que convierte un decimal a binario y lo imprime */

    int residuos[1000]; 
    int i = 0;

    while(dec > 0){
        residuos[i] = (dec % 2);
        dec = dec / 2;
        i++;
    }

    for(i-- ; i>=0; i--){
        cout << residuos[i];
    }

    cout << endl;
}

//----------------------------------------------------------------

int suma_N(int n){
    /* Funcion que suma numeros del 0 hasta N */

    int resultado = 0;

    for(int i = 0; i<=n; i++){
        resultado = resultado + i;
    }
    return resultado;
}

//----------------------------------------------------------------

int suma_potencia(int x, int n){
    /* Funcion que suma un numero x por una potencia 1, 2, 3, 4... n */
    
    int resultado = 0;

    for(int i = 0; i<=n; i++){
        resultado = resultado + pow(x,i);
            
    }
    return resultado;
}

// ------------------------- Main -------------------------//

int main(){
    cout << suma_sucesivas(5,3) << endl;
    dec_bin(13);
    cout << suma_potencia(3,3) << endl;
    cout << suma_N(5) << endl;

    return 0;
}

