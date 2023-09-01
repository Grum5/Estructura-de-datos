/*
  Ejercicio 3
  Perez Bretado Javier Osvaldo - 22760591
*/

#include<iostream>

using namespace std;

int main(){

  //Declaracion de variables
  int numero = 10;
  int temp_num;
  
  for (int i = 0 ; i < numero ; i++){

    for(int j = 0 ; j <= i ; j++ ){

      cout<<( numero - i + j )<<" ";
 
    }

    cout << endl;

  }

  return 0;

}

