/*
  Hacer la serie de fibonacci por recursividad para n cantidad de nummeros

  Javier Osvaldo Perez Bretado - 22760591
*/


// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 ...

#include<iostream>
#include<stdlib.h>

using namespace std;

int fibonacci(int);

int main(){
  
  int n;

  cout <<"Ingrese la cantidad de numeros de la serie de fibonacci que desea ver: ";
  cin >> n;
  

  cout << fibonacci(n-1) << endl;

}


int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    else{
      return (fibonacci(n-1) + fibonacci(n-2));
    }
    

}
