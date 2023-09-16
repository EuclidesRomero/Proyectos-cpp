using namespace std;
#include<iostream>

struct Numero {
	int numero;
	Numero *siguiente;
	Numero *anterior;
};

void llenarLista(int, Numero *&, Numero*&);
void llenarLista2(int, Numero *&, Numero*&);
void imprimirLista(Numero *&, Numero*&);
void imprimirLista2(Numero *&, Numero*&);
void imprimirRepetidos(Numero *&, Numero*&);


int main() {
	Numero *cab = new Numero();
	Numero *ultimo = new Numero();	
	cab = NULL;
	ultimo = NULL;
	Numero *cab2 = new Numero();
	Numero *ultimo2 = new Numero();	
	cab2 = NULL;
	ultimo2 = NULL;
	int opc = 0, numero, numero2;
	do {
			cout<<" NUMEROS REPETIDOS \n";
			cout<<"1. ingresar numeros lista #1 \n";
			cout<<"2. ingresar numeros lista #2 \n";
			cout<<"3. imprimir numeros insertadose en la lista #1 \n";
			cout<<"4. imprimir numeros insertados en la lista #2 \n";
			cout<<"5. imprimir numeros repetidos \n";
		    cin>>opc;
		    
	 switch(opc) {
			case 1:
			cout<<"Ingrese un numero para insertar en la primera lista: ";
			cin>>numero;
			llenarLista(numero, cab, ultimo);
			break;
			case 2:
			cout<<"Ingrese un numero para insertar en la segunda lista: ";
			cin>>numero2;
			llenarLista2(numero2, cab2, ultimo2);
			break;
			case 3:
			cout<<"Los numeros ingresados en la #1 lista son \n";
			imprimirLista(cab, ultimo);
			break;	
			case 4:
			cout<<"Los numeros ingresados en la #2 lista son \n";
			imprimirLista2(cab2,ultimo2);
			break;
			case 5:
			imprimirRepetidos(cab, cab2);
			break;
			
	}
	
	}while(opc!=0);

}
void llenarLista(int numero, Numero *&cab, Numero*&ultimo){
 Numero *Nuevo = new Numero();
 Nuevo->numero = numero;
 cout<<"ingresado correctamente\n ";
 
 if(cab == NULL){
 	cab = Nuevo;
 	ultimo = Nuevo;
 } 
 else {
 	Nuevo->anterior = ultimo;
	ultimo->siguiente = Nuevo;
	ultimo = Nuevo;
 }
}

void llenarLista2(int numero2, Numero*&cab2, Numero*&ultimo2){
 Numero *Nuevo = new Numero();
 Nuevo->numero = numero2;
 cout<<"ingresado correctamente\n";
 
 if(cab2 == NULL){
 	cab2 = Nuevo;
 	ultimo2 = Nuevo;
 } 
 else {
 	Nuevo->anterior = ultimo2;
	ultimo2->siguiente = Nuevo;
	ultimo2 = Nuevo;
 }
}
void imprimirLista(Numero *&cab, Numero*&ultimo){
 Numero *x;
 x = NULL;
 if(cab ==NULL){
 	cout<<"no hay numeros que mostrar";
 } 
 else {
 	x=cab;
 	while(x!=NULL){
 		cout<<" "<<x->numero<<" ";
 		x = x->siguiente;
	 }
	 cout << endl;
 }
}

void imprimirLista2(Numero *&cab2, Numero*&ultimo2){
 Numero *x;
 x = NULL;
 if(cab2 ==NULL){
 	cout<<"no hay numeros que mostrar";
 } 
 else {
 	x=cab2;
 	while(x!=NULL){
 		cout<<" "<<x->numero<<" "; 
 		x = x->siguiente;
	 }
	 cout << endl;
 }
}

void imprimirRepetidos(Numero *&cab, Numero*&cab2){
 Numero *x, *y;
 x = NULL;
 y = NULL;
 bool sw;
 

 		if(cab ==NULL && cab2 ==NULL){
 		cout<<"no hay numeros ingresados";
	 	}
	  	else if(cab->siguiente == NULL && cab2->siguiente ==NULL){
  		cout<<"Las listas son unitarias\n";
        } 
        
	   else {
	   	x=cab;
	    while(x->siguiente!=NULL) {
	    	x = x->siguiente;
		}

		 while(x != NULL) {
		    y =cab2;
		      sw = false;
		    	while(y!=NULL && !sw){
		    		if(x->numero == y->numero){
		    		cout<<"["<<x->numero<<"]"<<" ";
		    	      sw = true;
			   } 
			   else {
			   	y = y->siguiente;
			   }
			   	 
			   		  	
			}
          x = x->anterior;
		}
	}
}
