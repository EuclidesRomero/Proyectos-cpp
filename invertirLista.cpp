#include <iostream>
using namespace std;


struct numero {
	int num;
	numero *siguiente;
	numero *anterior;
};

void ingresarNumero(int, numero*&, numero*&);
void numerosIngresados(numero*&, numero*&);
void invertirLista(numero*&, numero*&);

 int main(){
	int opc=0, num;
	numero *cab = new numero();
	numero *ultimo = new numero();
	cab = NULL;
	ultimo = NULL;
	
	
	do{
		cout<<"¿Desea continuar? 1 --> SI 2--->NO: ";
		cin>>opc;
		switch(opc){
			case 1:
				cout<<"ingrese un numero para añadir a la lista: ";
				cin>>num;
				ingresarNumero(num, cab, ultimo);
				break;
				case 2:
				cout<<"los numeros ingresados son: ";
				numerosIngresados(cab,ultimo);
				break;
				case 3:
				cout<<"La lista invertida es: ";
				invertirLista(cab, ultimo);
				break;
		}
	} while(opc!=4); 
}

void ingresarNumero(int num, numero*&cab, numero*&ultimo){
	numero *nuevo = new numero();
	nuevo->num = num;
	cout<<"ingresado correctamente\n";
	
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

void numerosIngresados(numero*&cab, numero*&ultimo){
		numero *x;
		x = NULL;
		
			
		if(cab == NULL) {
		  cout<<"No hay datos"<<endl;
		} 
		else {
				x = cab;
				while(x!=NULL){
				cout<<" "<<x->num<<" ";
				x = x->siguiente;
			}
			 cout << endl;
     	}
}

void invertirLista(numero*&cab, numero*&ultimo){
	numero *p, *q;
	p = NULL;
	q = NULL;
	int aux=0;
	bool sw = false;
	
	q=cab;
	p = cab;
	while(q->siguiente!= NULL){
		q = q->siguiente;
	}

	while( p!= q && sw == false){
		aux = p->num;
		p->num = q->num;
		q->num = aux;
		
		 if (p->siguiente == q){
		 	sw = true;
		 }    
		 p = p->siguiente;
		 q = q->anterior;
			
	}
	
	cout<<"la lista invertida es: ";
	p=NULL;
	p = cab;
	while(p != NULL){
	cout<<" "<<p->num<<" ";
	 p = p->siguiente;
	}
}



















