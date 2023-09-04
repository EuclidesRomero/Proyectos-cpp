using namespace std;
#include <iostream>

struct donaciones {
 string fecha;
 //persona *nombre;
 //tipoSangre *tipo;
};

struct persona {
string nombre;
string telefono;
string direccion;
donaciones *derecha;
persona *sig;
persona *ant;
};

//declaracion de los struct

struct tipoSangre {
	string tipo;
	tipoSangre *sig;
	persona *cabecera;
	int cantidad;
};


//declaracion de funciones y metodos
void ingresarTiposDeSangre(string, tipoSangre *&, tipoSangre *&);
void mostrarTiposDeSangre(tipoSangre *&);
void ingresarDonantes(string, string, string, persona*&, persona*&);
void mostrarDonantes(persona *&, persona*&);
void validarTipoSangre(tipoSangre*&, string, bool&);





int main () {
	int opc=1;
	string tipo, nombre, direccion, telefono;
	bool validator;
		
	//Tipo sangre
	tipoSangre *cab = new tipoSangre();
	cab = NULL;
	tipoSangre *ultimo = new tipoSangre();
	ultimo = NULL;	
	//Persona
	persona *cab1 = new persona();
	persona *ultimo1 = new persona();
	cab1 = NULL;
	ultimo1 = NULL;

	//<-------------------------------->
	do {
	cout<<"          CRUZ ROJA NACIONAL \n";
	cout<<"1. ingresar tipos de sangre \n";
	cout<<"2. mostrar tipos de sangre ingresados \n";
	cout<<"3. ingresar donantes y su i nformacion \n";
	cout<<"4. mostrar pacientes ingresados\n";
	cout<<"5. <-------------------------->\n";
	cin >> opc;
	
	switch (opc) {
		case 1: 
		/*El error esta en esta validacion, estoy intentando que no se ingrese el mismo tipo de sangre 2 veces
		para eso utilizo un metodo llamado Void ValidarTipoSangre que se encarga de eso*/
		
		cout<<"ingrese un tipo de sangre en mayuscula: ";
		cin>>tipo;
		validarTipoSangre(cab, tipo, validator);
		 if(tipo == 'A+' || tipo =='A-' || tipo=='O+' || tipo =='O-' || tipo =='AB+' || tipo == 'AB-'){
		 	if(validator){
		 		cout<<"este tipo de sangre ya ha sido ingresado"<<endl;
			 } else{
			  ingresarTiposDeSangre(tipo, cab, ultimo);
			  break;
		    }
		 }
		else {
			cout<<"el tipo de sangre es incorrecto"<<endl;
		 	cout<<tipo;
     	   
		}
		break;
		case 2: mostrarTiposDeSangre(cab);
		break;	
		case 3: cout<<"ingrese el nombre del paciente: ";
		cin>>nombre;
		cout<<"ingrese el telefono: ";
		cin>>telefono;
		cout<<"ingrese la direccion del paciente: ";
		cin>>direccion;
		ingresarDonantes(nombre, telefono, direccion, cab1, ultimo1);
		break;
		case 4: mostrarDonantes(cab1, ultimo1);
		break;	
	}
			
	}while(opc!=5);
	system("pause");
}

void ingresarTiposDeSangre(string tipo, tipoSangre*&cab, tipoSangre*&ultimo){
	tipoSangre *nuevo = new tipoSangre();
	//ingresamos el nuevo nodo y aterrizamos a null
	nuevo ->tipo = tipo;	
	nuevo ->sig = NULL;
	
	if(cab == NULL) {
     cab = nuevo;
     ultimo = nuevo;
	}
 	else {
 	ultimo->sig = nuevo;
 	ultimo = nuevo;
    } 
	 cout<<"el tipo de sangre fue ingresado correctamente \n"<<endl;
}
//segundo requerimiento
void mostrarTiposDeSangre(tipoSangre *&cab){
	tipoSangre *x;
	x = cab;

	if(cab == NULL) {
	  cout<<"No hay tipos de sangre ingresados"<<endl;
	}
	else {
		cout<<"los tipos de sangre ingresados son :"<<endl;
		 while(x != NULL){
		cout<<"["<<x->tipo<<"]";
		x = x->sig;
		}
	}

	
	cout<<"\n\n\n";
}

//<------------------------------------------------------------------------------------------------------------------------>
void ingresarDonantes(string nombre, string telefono, string direccion, persona*&cab1, persona*&ultimo1) {
     persona *nuevo = new persona();
     nuevo->nombre = nombre;
     nuevo->telefono = telefono;
     nuevo->direccion = direccion;
     
     
     cout<<endl<<"ingresado correctamente"<<endl;
     
     if(cab1 == NULL){
     	cab1 = nuevo;
     	ultimo1 = nuevo;
	 } 
	 else {
	    ultimo1->sig = nuevo;
	    nuevo->ant = ultimo1;
	 	ultimo1 = nuevo;	
	 
	 }
	 
	 cab1->ant = ultimo1;
	 ultimo1->sig = cab1;
}

void mostrarDonantes(persona *&cab1, persona *&ultimo1){
 	persona *x;
 	x = cab1;
 	
 	if(cab1 == NULL){
 		cout<<endl<<"No hay datos";
	 }else{
	 	do{
	 		cout<<endl<<"["<<x->nombre<<"]"<<endl;
 			cout<<"["<<x->telefono<<"]"<<endl;
 			cout<<"["<<x->direccion<<"]"<<endl;
			 x = x->sig;	
		 }while(x != cab1);
	 		
	 }

}

void validarTipoSangre(tipoSangre*&cab, string tipo, bool&validator){
	tipoSangre*x;
	validator = false; //vale falso
	
	if(cab ==NULL){
		validator = false;
	} else {
		x=cab;
		while(x!=NULL){
			if(x->tipo == tipo){
				validator =true;
			 	x = x->sig;
			} 
		
		}
	}
		
}

	
	























