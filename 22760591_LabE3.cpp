/*
  Realizar un programa de registro de alumnos con los siguientes datos:
    Numero de control
    Nombre
    Carrera
    Materias [3] (Clave, numero, nombre de la materia, calificacion y promedio)

   Javier Osvaldo Perez Bretado - 22760591
*/

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

#include <iostream>
#include <stdlib.h>
#include <limits>
#include <string>

using namespace std;

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

// Prototipo de funciones ---------------------------------------------------

void reporte(struct Alumno[]);
void alta_alumno(struct Alumno[], int);
void verificador_espacio(struct Alumno[]);
void dibujar_menu();
void pause();

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


// Definir estructuras ------------------------------------------------------

struct Nombre{
  string nombre_completo;
  string apellido_paterno;
  string apellido_materno;

};

struct Materia{
  int clave;
  float calificacion;
  string nombre_materia;

};

//Estructura anidada (Practicamente hereda las 2 estructuras anteriores)
struct Alumno{
  struct Nombre nombre;
  struct Materia materia[3];
  int numero_control = -1;
  string nombre_carrera;
  float promedio;

};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

// Funcion principal --------------------------------------------------------

int main(){
  // Declaracion variables
  struct Alumno alumnos[20];
  bool running = true;
  char opcion;

  // Ciclo principal
  while(running){

    system("clear"); //Windows -> System("CLS")

    dibujar_menu();
    cin>>opcion;

    switch (opcion){
      
      case '1':
        system("clear"); // Windows -> system("CLS")
        verificador_espacio(alumnos);
        break;
      
      case '2':
        system("clear"); // Windows -> system("CLS")
        reporte(alumnos);
        break;
      
      case '3':
        system("clear"); // Windows -> system("CLS")
        cout<<"Adios"<<endl;
        running = false;
        break;
      
      default:
        system("clear"); // Windows -> system("CLS")
        cout << "Opcion invalida" <<endl;
    }

  } 
  


  return 0;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

// Funciones auxiliares -----------------------------------------------------

void reporte(struct Alumno alumno[]){
  
  for(int i = 0; i<20; i++){
    if(alumno[i].numero_control != -1){
      cout<<"-----------------------------------------"<<endl;
      cout<<"---------- ALUMNO NO."<<i+1<<" ----------"<<endl;
      cout<<"-----------------------------------------"<<endl<<endl;
      cout<<"Numero de control: "<<alumno[i].numero_control<<endl;
      cout<<"Carrera: "<<alumno[i].nombre_carrera<<endl;
      cout<<"Nombre completo del alumno: "<<alumno[i].nombre.apellido_paterno<<" "<<alumno[i].nombre.apellido_materno<<" "<<alumno[i].nombre.nombre_completo<<endl;
      
      cout<<"-----------------------------------------"<<endl<<endl;

      //Ciclo para mostrar las materias
      for (int j = 0; j<3; j++){ 
        cout<<"---------- MATERIA NO."<<j+1<<" ----------"<<endl<<endl;
        cout<<"Clave: "<<alumno[i].materia[j].clave<<endl;
        cout<<"Nombre de la materia: "<<alumno[i].materia[j].nombre_materia<<endl;
        cout<<"Calificacion: "<<alumno[i].materia[j].calificacion<<endl;

      }
      cout<<"-----------------------------------------"<<endl<<endl;
      cout<<"Promedio: "<<alumno[i].promedio<<endl<<endl;
    }
    else if(i==19 && alumno[i].numero_control == -1){
      pause();
      cout<<"No hay alumnos registrados"<<endl;
    }
    else{
      pause();
      break;
    }
    cout<<endl;
  
  }
}

//---------------------------------------------------------------------------

void alta_alumno(struct Alumno alumno[], int index){
  /* Funcion que se encarga de dar de alta a un alumno en el sistema */

  //Declaracion de variables
  char opcion;
  bool verificacion = true;
  float promedio_temp = 0;

  do{ //Ciclo para que el usuario no se equivoque en el ingreso de datos
    system("clear"); //Windows -> system("CLS")
    cout<<"---------- DATOS BASICOS ----------"<<endl;

    cout<<"Ingresar numero de control:"<<endl;
    cin>>alumno[index].numero_control;
    cout<<endl;

    cout<<"Ingresar nombre de carrera del alumno:"<<endl;
    cin>>alumno[index].nombre_carrera;
    cout<<endl;
  
    cout<<"Ingresar apellido paterno del alumno"<<endl;
    cin>>alumno[index].nombre.apellido_paterno;
    cout<<endl;
  
    cout<<"Ingresar apellido materno del alumno"<<endl;
    cin>>alumno[index].nombre.apellido_materno;
    cout<<endl;
  
    cout<<"Ingresar nombre del alumno"<<endl;
    cin>>alumno[index].nombre.nombre_completo;
    cout<<endl;
    
    system("clear"); //Windows -> system("CLS)

    cout<<"Los siguientes datos son correctos?"<<endl;
    cout<<"Numero de control: "<<alumno[index].numero_control<<endl;
    cout<<"Nombre de carrera: "<<alumno[index].nombre_carrera<<endl;
    cout<<"Apellido paterno: "<<alumno[index].nombre.apellido_paterno<<endl;
    cout<<"Apellido materno: "<<alumno[index].nombre.apellido_materno<<endl;
    cout<<"Nombre completo: "<<alumno[index].nombre.nombre_completo<<endl;
    
    cout<<"Si son correctos oprime (S) en caso contrario oprime cualquier otra tecla"<<endl;
    cin>>opcion;

    if(opcion == 'S' || opcion == 's') verificacion = false;

  }while(verificacion);
  system("clear"); //Windows -> system("CLS")

  //Ciclo para registrar las materias
  for(int i = 0; i<3; i++){

    verificacion = true;

    do{ //Ciclo para que el usuario no se equivoque en el ingreso de datos
      cout<<"---------- MATERIA "<<i+1<<" ----------"<<endl;
      
      cout<<"Clave de la materia:"<<endl;
      cin>>alumno[index].materia[i].clave;
      cout<<endl;
      
      cout<<"Nombre de la materia:"<<endl;
      cin>>alumno[index].materia[i].nombre_materia;
      cout<<endl;

      cout<<"Calificacion:"<<endl;
      cin>>alumno[index].materia[i].calificacion;
      cout<<endl;

      system("clear"); //Windows -> system("CLS")

      cout<<"Los siguientes datos son correctos?"<<endl;
      cout<<"Clave de la materia: "<<alumno[index].materia[i].clave<<endl;
      cout<<"Nombre de la materia: "<<alumno[index].materia[i].nombre_materia<<endl;
      cout<<"Calificacion: "<<alumno[index].materia[i].calificacion<<endl;
      
      cout<<"Si son correctos oprime (S) en caso contrario oprime cualquier otra tecla"<<endl;
      cin>>opcion;
      
      if(opcion == 'S' || opcion == 's') verificacion = false;

      // Guardar las calififaciones en una variable temporal
      promedio_temp += alumno[index].materia[i].calificacion;

    }while(verificacion);
  }

  alumno[index].promedio = promedio_temp / 3;
}

//---------------------------------------------------------------------------

void verificador_espacio(struct Alumno alumno[]){
  /* Funcion que verifica el espacio disponible en el arreglo */
  
  // Declaracion de variables

  for(int index = 0; index<20; index++){
    
    // Si el numero de control es -1, entonces hay espacio disponible para un registro
    if(alumno[index].numero_control == -1){
      
      // Llamar mandar la funcion alta_alumno para registrar al alumno y terminar el ciclo
      alta_alumno(alumno, index);
      break;
  
    }
    // Si no hay un solo numero de control que sea -1 entonces no hay espacio para otro registro
    else if(index == 19){
      cout<<"No hay espacio para registrar a otro alumno"<<endl;
      pause();
    }
  }

}

//---------------------------------------------------------------------------

void dibujar_menu(){
  /* Funcion para dibujar el menu */

  cout<<"-------------- MENU PRINCIPAL --------------"<<endl;
  cout<<"1) Dar de alta "<<endl;
  cout<<"2) Reporte general"<<endl;
  cout<<"3) Salir"<<endl;

}

//---------------------------------------------------------------------------

void pause(){
  /* Funcion para hacer un pause en ubuntu */

  // Limpiar el búfer de entrada
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Presiona Enter para continuar...";
  cin.get();

}

