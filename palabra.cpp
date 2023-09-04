
//Hecho por Euclides Romero Ibarra, hecho en C++ para exigirme mas!!!
//Ingeniero Jose carmona, el programa no distingue entre minúsculas y mayúsculas, poner el nombre en minúscula al testear :D

                   //ENUNCIADO
/*   DADA UNA LISTA DOBLE APUNTADA POR CAB, LA CUAL CONTIENE UNA PALABRA CUALQUIERA 
DEL ESPAÑOL,  IMPRIMA LA PALABRA AL REVES SI ESTA CONTIENE AL MENOS DOS VOCALES IGUALES
CONSECUTIVAS.*/


using namespace std;
#include<iostream>
struct palabra {
	char letra;
	palabra *siguiente;
	palabra *anterior;
};

void ingresarNombre(char, palabra*&, palabra*&);
void mostrarNombre(palabra*&, palabra*&);
void validarNombre(palabra*&, palabra*&);
bool validarLetra(char);

int main(){
  int opc=1;
  char letra;
  palabra *cab = new palabra();
  palabra *ultimo = new palabra();
  cab = NULL;
  ultimo = NULL;
  
 
  
  do {
  	cout<<" Imprimir palabra \n";
	cout<<"1. Ingresar nombre \n";
	cout<<"1. Mostrar nombre ingresado\n";
	cout<<"3. Imprimir palabra al reves si contiene 2 vocales consecutivas \n";
	cin>>opc;
	
	switch (opc) {
		case 1:
			cout<<"Ingrese el nombre letra por letra: ";
			cin>>letra;
			ingresarNombre(letra, cab, ultimo);
		break;
		
		case 2:
		 cout<<"El nombre ingresado fue: \n\n\n";
		 mostrarNombre(cab, ultimo);
		 cout<<"\n\n\n";
		 break;
		 
		 case 3:
		 validarNombre(cab, ultimo);
		 cout<<"\n\n\n";
	   	break;
	}
  	
  }while(opc !=3);
  
}

/*Se crea la funcion con el fin de modularizar y que el condicional de mas adelante sea más corto*/
 bool validarLetra(char letra) {
   if(letra == 'a' || letra == 'e'|| letra =='i' || letra=='o' || letra == 'u'){
   	return true;
    } 
    else {
   	return false;
	}
  }

void ingresarNombre(char letra, palabra*&cab, palabra*&ultimo){
	palabra *nuevo = new palabra();
	nuevo ->letra = letra;
	cout<<"ingresado correctamente\n\n\n";
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

void mostrarNombre(palabra *&cab, palabra *&ultimo){
		palabra *x;
		x = cab;
		
	if(cab == NULL) {
	  cout<<"No hay datos\n"<<endl;
	} 
	else {
			while(x!=NULL){
			cout<<"[" <<x->letra<< "]";
			x = x->siguiente;
		}
		 cout << endl;
}

}

void validarNombre(palabra *&cab, palabra*&ultimo){
	palabra* x;
	palabra* y;
	palabra* z;
	x=NULL;
	y=NULL;
	z=NULL;
	bool sw= false;
	
	if(cab ==NULL){
     	cout<<"Error, no hay datos que procesar\n";
		}
		
		else if((cab->siguiente == NULL)){
			cout<<"No se puede procesar la lista, es unitaria \n";
		}
		else {
		 x = cab;
		 y = x->siguiente;
		 
		 while(y!= NULL && sw == false){
		 	if(validarLetra(x->letra) && validarLetra(y->letra) && x->letra == y->letra){
		 		sw = true;
		  } 
			else {
				x = x->siguiente;
				y = x ->siguiente;
			}	 	
		 }
	}
	if(sw == true){
     z = cab;
	 while (z->siguiente != NULL){
	 	z = z->siguiente;
	 }
	 cout<<"El nombre al reves es: \n";
	   while(z!=NULL){
	   	cout<<z->letra;
	   	z = z->anterior;
	   }
	} 
	else {
	
		cout<<"El nombre no tiene dos vocales consecutivas o no tiene vocales";
	
		}
	
	
}

		
	
