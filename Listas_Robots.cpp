/*
Ingreso de valores numericos en dos Listas 
-- el programa genera los un listado de los numeros de las dos Listas
-- El programa genera un reporte de los numeros que han quedado en cada lista 
   ganadora "Robots" despues de compararse
-- el programa maneja dos apuntador por cada Robots de numeros
*/

#include<iostream>
#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Robots
{ 
	int numero;
	Robots *ap_der; // apuntador Robots
	Robots *ap_izq; // apuntador Robots
} *cola, *cab, *nuevo, *cab2, *cola2, *aux_nuevo,    	// punteros Robots1
  *cola3, *cab3, *nuevo2, *cab4, *cola4, *aux_nuevo2;	// punteros Robots2

void menu(void);
void ingresar1(void);  // se captura numeros en la Robots 1
void ingresar2(void);  // se captura numeros en la Robots 2
void mostrar1(void);   // se muestra el contenido de las dos (2) Robotss
void mostrar_compara(void); // compara el contenido y muestra los Robots Resultado
void limpiar_Robots(void);
void espera();

main()
{
	menu();
}

void menu(void)
{
	int y, opc;
	opc = 9;
	while ( opc != 0)
	{
		system("cls");
		cout<<"\n 1 Ingresar numero en Robots 1";
		cout<<"\n 2 Ingresar numero en Robots 2";
		cout<<"\n 3 Robots numeros Digitados "; 
		cout<<"\n 4 Compara Datos Robots y Genera informe  "; 
		cout<<"\n ................          "; 
		cout<<"\n 5 Limpiar <Borrar> Robots  "; 
		cout<<"\n 0 Terminar";
		cout<<"\n Ingrese Opcion";
		cin>>opc;
		
		switch(opc)
		{
			case 1:
				ingresar1();
				break;
			case 2:
				ingresar2();
				break;
			case 3:
				mostrar1();	  
				break;
			case 4:
				mostrar_compara();
				break;
			case 5:
				limpiar_Robots();
				break;
			default:
				cout <<"\n Opcion no Valida !! ";
				break;
		}
	}
}

void ingresar1(void)
{
	// Ingresa los numeros en la Robots 1
	// y los ordena en forma de "cola" utiliza dos apuntadores 
	
	int sw;
    
	// PRIMERA PARTE	
	nuevo = new(Robots); // creamos nuevo Nodo
	fflush(stdin); // funsion para liberar la memoria 
	
	cout<<"\n"<<"Digite el numero  : ";
	cin >> nuevo->numero;
	nuevo->ap_der = NULL;
	nuevo->ap_izq = NULL;
	// las variable apuntador se inicia en NULL ... 
	fflush(stdin);
	
	if (!cab)
	{   // si el Robots no esta creado ... la creamos
		// y asignamos los punteros a nuevo Nodo
		
		cab   = new(Robots);	cola  = new(Robots);
		cab2  = new(Robots);	cola2  = new(Robots);
		cab   = nuevo;  		cola = nuevo;
		cab2  = nuevo;  		cola2 = nuevo;

		cout <<"\n"<<"se creo Lista Robots";
	}
    else
	{ 
	//  insertamos al final de la Robots en forma de "COLA"	
  		cola->ap_der  = nuevo;
  		nuevo->ap_izq = cola;
   		cola          = nuevo;
   		cab2          = cola;
   		
	}
	espera(); //funcio para dar <Enter>	
}

void ingresar2(void)
{
	// Ingresa los numeros en la Robots 2
	// y los ordena en forma de "cola" utiliza dos apuntadores 
	
	int sw;
    
	// PRIMERA PARTE	
	nuevo2 = new(Robots); // creamos nuevo Nodo
	fflush(stdin); // funsion para liberar la memoria 
	
	cout<<"\n"<<"Digite el numero  : ";
	cin >> nuevo2->numero;
	nuevo2->ap_der = NULL;
	nuevo2->ap_izq = NULL;
	// las variable apuntador se inicia en NULL ... 
	fflush(stdin);
	
	if (!cab3)
	{   // si la Robots no esta creada ... la creamos
		// y asignamos los punteros a nuevo Nodo
		cab3  = new(Robots);	cola3  = new(Robots);
		cab4  = new(Robots);	cola4  = new(Robots);
		cab3  = nuevo2;  		cola3  = nuevo2;
		cab4  = nuevo2;  		cola4  = nuevo2; 

		cout <<"\n"<<"se creo lista Robots";
	}
    else
	{ 
	//  insertamos al final de la Robots en forma de "COLA"	
  		cola3->ap_der  = nuevo2;
  		nuevo2->ap_izq = cola3;
   		cola3          = nuevo2;
   		cab4           = cola3;
	}
	espera(); //funcio para dar <Enter>	
}

void mostrar1(void)  
{
   // mostramos el contenido de la Robots1
   if (!cab)
   {
      cout<<"no hay datos o el Robots 1 no esta creada";
	  getch();	
   }	
   else
   {
   	  nuevo = new(Robots);
   	  nuevo = cab;
   	  cout <<"\n"<<" Reporte de los numeros del Robots 1"<<endl;
   	  while (nuevo != NULL)
   	  {
		 cout <<nuevo->numero<<"  ";
		 nuevo = nuevo->ap_der; 	
	  }
   }

   // mostramos el contenido de la Robots2
   if (!cab3)
   {
      cout<<endl<<endl<<"no hay datos o el Robots 2 no esta creada";
	  getch();	
   }	
   else
   {
   	  nuevo2 = new(Robots);
   	  nuevo2 = cab3;
   	  cout <<"\n"<<" Reporte de los numeros de la Robots 2"<<endl;
   	  while (nuevo2 != NULL)
   	  {
		 cout <<nuevo2->numero<<"  ";
		 nuevo2 = nuevo2->ap_der; 	
	  }
   }
   espera();   
}

void mostrar_compara(void)
{
   int encontro, dias;
   encontro = 0;
   if ((!cab2) || (!cab4))
   {
      if (!cab2)
	  {
	  	cout<<"no hay datos o el Robots1 no esta creado";
	  	getch();
	  }
	  if (!cab4)
	  {
	  	cout<<"no hay datos o la Robots2 no esta creada";
	  	getch();
	  }
   }	
   else
   {
	  nuevo = new(Robots);   //Robots1
   	  nuevo = cab2; 
   	  nuevo2 = new(Robots);  //Robots2
   	  nuevo2 = cab4;
   	  cout<<endl<<endl<<" Elementos retirados o eliminados "<<endl;
   	  //recorremos la lista Robots 1 en forma descendente para ser comparada
   	  // y recorremos la Lista Robots 2 en forma descendente para ser comparada
   	  while ( nuevo != NULL && nuevo2 != NULL )
	  {
	  	 // si los # de las dos Lista son iguales
         if ( nuevo->numero == -(nuevo2->numero) ) 
         {	
		 	cout<<"robot 1  "<<nuevo->numero<<endl;
			cab2  = cab2->ap_izq;   //se mueven los punteros de la Lista1
         	cab2->ap_der = NULL;
         	cola = cab2;
         	
         	delete (nuevo);   // retiramos un nodo Lista1
         	nuevo = cab2;
         	
         	cout<<"robot 2  "<<nuevo2->numero<<endl;
         	cab4  = cab4->ap_izq;   //se mueven los punteros de la Lista2
         	cab4->ap_der = NULL;
         	cola3 = cab4;
         	delete (nuevo2);   // retiramos un nodo Lista2
         	nuevo2 = cab4;
        }
        else
        { 	
			if ( nuevo->numero > -(nuevo2->numero) )
          	{   cout<<"robot 2  "<<nuevo2->numero<<endl;
          		cab4  = cab4->ap_izq;   //se mueven los punteros de la Lista2
          		if ( cab4 == NULL )
          		{
          			cab3 = NULL; cab4 = NULL; nuevo2 = NULL;
         			delete (nuevo2);   // retiramos un nodo Lista2
				}
				else
				{
         			cab4->ap_der = NULL;
         			cola3 = cab4;
         			
         			delete (nuevo2);   // retiramos un nodo Lista2
         			nuevo2 = cab4;
				}
			}
			else
			{
				cout<<"robot 1  "<<nuevo->numero<<endl;
				cab2  = cab2->ap_izq;   //se mueven los punteros de la Lista1
         		if ( cab2 == NULL )
          		{
          			cab = NULL; cab2 = NULL; nuevo = NULL;
         			delete (nuevo);   // retiramos un nodo Lista1
				}
				else
				{
					cab2->ap_der = NULL;
         			cola = cab2;
         			
         			delete (nuevo);   // retiramos un nodo Lista1
         			nuevo = cab2;
				}
			}	 	
		}
      }
   }
   
   cout<<endl<<endl<<" mostramos los numeros resultados en Robots 1"<<endl;
   if (cab)
	{
		nuevo = new(Robots);
   	  	nuevo = cab;
   	  	while (nuevo != NULL)
   	  	{
			cout <<nuevo->numero<<"  ";
		 	nuevo = nuevo->ap_der; 	
	  	}
	  	cout<<endl;
	}
	
	cout<<endl<<endl<<" mostramos los numeros resultados en Robots 2"<<endl;
   	if (cab3)
	{
		nuevo2 = new(Robots);
   	  	nuevo2 = cab3;
   	  	while (nuevo2 != NULL)
   	  	{
			cout <<nuevo2->numero<<"  ";
		 	nuevo2 = nuevo2->ap_der; 	
	  	}
	  	cout<<endl<<endl;
	}
	espera();
}

void limpiar_Robots(void)
{   //inicializamos los nodos de Inicio y Fin de la Lista
 	cab   = NULL;  	cola  = NULL;	
	cab2  = NULL;   cola2 = NULL;
		
	cab3  = NULL;   cola3 = NULL;
	cab4  = NULL;   cola4 = NULL;
}

void espera(void)
{
    cout <<"\n"<<"<Enter";
    getch();	
}
