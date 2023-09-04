


//Realizado por Euclides Romero, hecho en C++ para exigirme mas!!!//

           //ENUNCIADO
/*DADA UNA LISTA DOBLE APUNTADA POR CAB, LA CUAL CONTIENE UNA DIRECCIÓN DE CORREO
ELECTRONICO CUALQUIERA ( UN NODO POR CARACTER), ESCRIBA UN ALGORITMO QUE PERMITA
DETERMINAR SI DICHO CORREO ES  "   .com   "  O  NO.*/

using namespace std;
#include <iostream>

struct correo {
char letra;	
correo *siguiente;
correo *anterior;
};


void ingresarCorreo(char, correo*&, correo*&);
void mostrarCorreo(correo *&, correo*&);
void validarCorreo(correo*&, correo*&);
int main (){
	int opc=1;
	char letra;
	correo *cab = new correo();
	correo *ultimo = new correo();
	cab = NULL;
	ultimo=NULL;
	
	
	do{
	cout<<" Validar correo \n";
	cout<<"1. ingresar correo \n";
	cout<<"1. mostrar correo \n";
	cout<<"3. validar si el correo termina en .com \n";
	cin>>opc;
	
	switch (opc) {
		  case 1: 
		  cout<<"Ingrese el correo letra por letra : ";  
		  cin>>letra;
		  ingresarCorreo(letra, cab, ultimo );
		  break;
		  
		  case 2:
		  cout<<"El correo ingresado fue: ";
		  mostrarCorreo(cab, ultimo);
		  break;
		
		case 3:
			 validarCorreo(cab, ultimo);	 
	}
	
	}while(opc !=3);
	  system("pause");
}




void ingresarCorreo(char letra, correo*&cab, correo*&ultimo){
    correo *nuevo = new correo();
    nuevo->letra = letra;
    cout<<"ingresado correctamente\n\n";
    
    if(cab == NULL){
    	cab = nuevo;
    	ultimo = nuevo;
	} 
	else {
		nuevo->anterior = ultimo;
		ultimo->siguiente = nuevo;
		ultimo = nuevo;
	}

}
	
void mostrarCorreo(correo *&cab, correo *&ultimo){
		correo *x;
		x = cab;
			
		if(cab == NULL) {
		  cout<<"No hay datos"<<endl;
		} 
		else {
				while(x!=NULL){
				cout<<x->letra;
				x = x->siguiente;
			}
			 cout << endl;
     	}
	}
	
	void validarCorreo(correo *&cab, correo*&ultimo){
			correo *x;
			 x=NULL;
			if(cab ==NULL){
				cout<<"Error, no hay datos que procesar";
			}
			
			else if((cab->siguiente == NULL)){
				cout<<"No se puede procesar la lista, es unitaria";
			}
			else 
			 if((cab->siguiente)->siguiente ==NULL){
				cout<<"no se puede procesar la lista";
			}
			else if ((cab->siguiente)->siguiente->siguiente == NULL){
				cout<<"no se puede procesar la lista";
			}
			else {
				x= cab;
				while(x->siguiente != NULL){
					x = x->siguiente;
				}
				
				if(x->letra =='m'&& x->anterior->letra =='o'&&(x->anterior)->anterior->letra=='c'&&(x->anterior)->anterior->anterior->letra=='.'){
					cout<<"El correo si cumple con la condicion\n";
				}
				
				else {
				cout<<"el correo ingresado no cumple con la condicion \n";			
			    }
			  	
		   }
	}
	
