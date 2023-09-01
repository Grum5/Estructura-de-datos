/*
  Realizar un programa que capture un numero entero (n)
  y reducirlo a 1 de la siguiente manera:
    Si n es impar: Multiplicarlo por 3 y sumarle 1
    Si n es par: Dividirlo entre 2
  Javier Osvaldo Perez Bretado - 22760591
*/

#include<iostream>

using namespace std;

int main (){

  int n, par = 0, impar = 0;
  cout<<"Ingrese un numero entero positivo mayor a 0: ";
  cin>>n;
  if (n > 0){
    while (n!=1){
      if( n%2 != 0 ){
        n = n*3+1;
        impar++;
      }
      else {
        n = n / 2;
        par++;
      }
      cout<<n<<endl;
    }
    cout<<"Total impares: "<<impar<<endl;
    cout<<"Total pares: "<<par<<endl;
  }
  else{
    cout<<"Ingresa un numero mayor a 0"<<endl;
  }
  return 0;
}

