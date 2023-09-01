/*
  Realizar un ejercicio que permita ingresar los datos de un empleado.
  Los datos son: Matricula, Nombre, Salario, Departamento
  Debe poder registrar 10 empleados y hacer lo siguiente:
    a) Altas = Registrar un empleado
    b) Consultas  = Consultar todos los datos de un empleado por su matricula de empleado
    c) Reportes = Imprimir todos los registros de los empleados

  Javier Osvaldo Perez Bretado - 22760591

*/

#include<iostream>
#include<stdlib.h>
#include<limits>

using namespace std;

//Declaracion del prototipo de funciones
//-------------------------------------------------------

void reporte_datos(struct Empleados[]);
void mostrar_datos(struct Empleados[], int);
void ingresar_datos(struct Empleados[], int);
void DibujarMenu();
void verificador(struct Empleados[]);
void pause();

//-------------------------------------------------------
//-------------------------------------------------------

//Declaracion de estructuras
//-------------------------------------------------------

struct Empleados{
  bool registro = false;
  int matricula;
  string nombre;
  float salario;
  string departamento;
};

//-------------------------------------------------------
//-------------------------------------------------------

//Funcion principal
//-------------------------------------------------------

int main(){
  //Declaracion de variables
  struct Empleados empleados[10];
  char opcion; 
  bool running = true;

  //Ciclo principal
  while(running){
    system("clear");

    DibujarMenu();  //Dibujar menu principal
    cin >> opcion;

    switch (opcion) {
      
      case '1':
        //Ingresar datos del empleado
        verificador(empleados);
        break;
      
      case '2':
        //Mostrar reporte de datos
        reporte_datos(empleados);
        break;
      
      case '3':
        //Mostrar datos de un empleado
        pause();
        break;
      
      case '4':
        //Salir del programa
        running = false;
        break;
      
      default:
        //Opcion no valida del menu
        
        system("clear");
        cout << "Opcion invalida" << endl;
        pause();
    }
  
  }

  return 0;

}

//Funciones auxiliares
//-------------------------------------------------------

void verificador(struct Empleados empleados[]){
  /*Funcion que verifica si hay datos en el registro*/
  
  system("clear");

  for(int i = 0; i<10; i++){
  
    if(empleados[i].registro == false){
      //Verificar si hay espacio para un nuevo registro

      empleados[i].registro = true;
      ingresar_datos(empleados, i);
      break;

    }
    else if(i == 9){
      //Verificar si no hay espacio para un nuevo registro

      cout << "No hay espacio para un nuevo registro" << endl;
    }
  
  }

}


//-------------------------------------------------------
//-------------------------------------------------------


void reporte_datos(struct Empleados empleados[]){
  /*Funcion que muestra un reporte general de los datos obtenidos*/
 
  system("clear");
  
  for(int i = 0; i<10; i++){
    
    if(empleados[i].registro == true){
      //Verificar si hay datos en el registro

      cout << "Matricula: " << empleados[i].matricula << endl;
      cout << "Nombre: " << empleados[i].nombre << endl;
      cout << "Salario: " << empleados[i].salario << endl;
      cout << "Departamento: " << empleados[i].departamento << endl;
      cout << endl;

    }
  }
  pause();

}

//-------------------------------------------------------
//-------------------------------------------------------

void mostrar_datos(struct Empleados empleados[], int registro){
  /*Funcion que muestra los datos del empleado*/
 
}

//-------------------------------------------------------
//-------------------------------------------------------

void ingresar_datos(struct Empleados empleados[], int index){
  /*Funcion que ingresa los datos del empleado*/

  cout << "Ingrese la matricula del empleado: ";
  cin >> empleados[index].matricula;
  cout << "Ingrese el nombre del empleado: ";
  cin >> empleados[index].nombre;
  cout << "Ingrese el salario del empleado: ";
  cin >> empleados[index].salario;
  cout << "Ingrese el departamento del empleado: ";
  cin >> empleados[index].departamento;

}

//-------------------------------------------------------
//-------------------------------------------------------

void DibujarMenu(){
  /*Funcion que dibuja el menu principal*/

  cout << "MENU" << endl;
  cout << "1. INGRESO Ingresar datos del empleado" << endl;
  cout << "2. REPORTE Mostrar reporte de datos" << endl;
  cout << "3. Mostrar datos de un empleado" << endl;
  cout << "4. Salir" << endl;
  cout << "Ingrese una opcion: ";

}

//-------------------------------------------------------
//-------------------------------------------------------

void pause(){
  /*Funcion para hacer un pause en ubuntu*/

  // Limpiar el búfer de entrada
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Presiona Enter para continuar...";
  cin.get();
}
