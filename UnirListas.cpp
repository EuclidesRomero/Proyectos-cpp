using namespace std;
#include<iostream>

struct fullName {
	char letra;
	fullName *siguiente;
	fullName *anterior;
};

void ingresarNombre(char, fullName*&,fullName*& );
void ingresarApellido(char, fullName*&,fullName*&);
void mostrarNombre(fullName*&, fullName*&);
void mostrarApellido(fullName*&, fullName*&);


int main(){
fullName *cabecera = new fullName();
fullName *ultimo = new fullName();

cabecera = NULL;
ultimo = NULL;
char nombre, apellido;
int opc =0;
int cont =1;
int cont2 =1;



while(opc != 3){
	    cout<<"1-->Ingresar nombre\n";
		cout<<"2-->Ingresar apellido\n";
		cout<<"3-->mostrar nombre\n";
		cout<<"3-->mostrar apellido\n";
    	cin>>opc;
	switch (opc){
		case 1: 
		cout<<"ingrese la letra "<<cont<<" del nombre: ";
		cin>>nombre;
		cont ++;
		ingresarNombre(nombre, cabecera, ultimo);
		break;
		case 2:
		cout<<"ingrese la letra : "<<cont2<< "del apellido";
		cin>>apellido;
		cont2++;
		
		ingresarApellido(apellido, cabecera, ultimo);
		break;
		case 3:
		mostrarNombre(cabecera, ultimo);
		break;
		case 4:
		mostrarApellido(cabecera, ultimo);
		break;

	}
	
}
system("pause");
}

void ingresarNombre(char nombre, fullName*&cabecera, fullName*&ultimo){
	fullName *nuevo = new fullName();
	nuevo->letra = nombre;
	cout<<"ingresado correctamente \n";
	
	if(cabecera == NULL){
		cabecera = nuevo;
		ultimo = nuevo;
	}
   	else {
     nuevo->anterior = ultimo;
	 ultimo->siguiente = nuevo;
	 ultimo = nuevo;
	}
}
void ingresarApellido(char apellido, fullName*&cabecera, fullName*&ultimo){
	fullName *nuevo =  new fullName();
	nuevo ->letra = apellido;	
	if(cabecera == NULL){
		cabecera = nuevo;
		ultimo = nuevo;
	}
   	else {
     nuevo->anterior = ultimo;
	 ultimo->siguiente = nuevo;
	 ultimo = nuevo;
	}
}



void mostrarNombre(fullName*&cabecera, fullName*&ultimo){
	fullName *x;
	x = NULL;
	cout<<"El nombre ingresado es \n";
	x = cabecera;
	while(x!=NULL){
		cout<< " " << x->letra<<" ";
		x = x->siguiente;
	}

}

void mostrarApellido(fullName*&cabecera, fullName*&ultimo){
	fullName *x;
	x = NULL;
	cout<<"El apellido ingresado es es \n";
	x = cabecera;
	while(x!=NULL){
		cout<< " " << x->letra<<" ";
		x = x->siguiente;
	}

}




















