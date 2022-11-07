#include <iostream>

using namespace::std;

struct nodo{
	int dato;
	nodo* siguiente;
} *primero, *ultimo;


void insertarNodo();
void buscarNodo();
void modificarNodo();
void desplegarCola();

int main(){	
	int opc=0;
	do
	{
		 system("cls");
        cout <<"OMAR CESAR ALAN"<<endl;
        cout << "Menu" << endl;
        cout << "0. Imprimir" << endl;
        cout << "1. Insertar a la derecha" << endl;
        cout << "2. Insertar a la izquierda" << endl;
        cout << "3. Insertar a la datos aleatorios a la derecha" << endl;
        cout << "4. Insertar a la datos aleatorios a la izquierda" << endl;
        cout << "5. Obtiene la sumatoria de los datos en la lista" << endl;
        cout << "6. Buscar un dato en la lista" << endl;
        cout << "7. Insertar antes de x" << endl;
        cout << "8. Insertar despues de x" << endl;
        cout <<  "9. Eliminar x"<<endl;
        cout << "100. Salir" << endl;
        cout << "Selecciona una opc: " << endl;
        cin >> opc;
		cin >> opc;
		switch(opc){
			case 1:
				cout << endl << endl << " INSERTA NODO EN LA COLA " << endl << endl;
				insertarNodo();
				break;
			case 2:
				cout << endl << endl << " BUSCAR UN NODO EN LA COLA " << endl << endl;
				buscarNodo();
				break;
			case 3:
				cout << endl << endl << " MODIFICAR UN NODO DE LA COLA " << endl << endl;
				modificarNodo();
				break;
			case 4:
				cout << endl << endl << " ELIMINAR UN NODO DE LA COLA " << endl << endl;
				break;
			case 5: 
				cout << endl << endl << " DESPLEGAR COLA DE NODOS " << endl << endl;
				desplegarCola();
				break;
			case 6:
				cout << endl << endl << " Programa finalizado..." << endl << endl;
				break;
			default:
				cout << endl << endl << " Opcion No Valida " << endl << endl;
			}
	
	return 0;
}

// primero = 45    ultimo = 12      actual = 12       encontrado = true          nodoBuscado = 7               45, 6, 7 , 12
 
// COLA            45 -> 6 -> 100 -> 12 -> NULL                

void insertarNodo(){
	nodo* nuevo = new nodo();
	cout << " Ingrese el dato del nuevo Nodo: ";
	cin >> nuevo->dato;

	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		ultimo = primero;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo = nuevo;
	}
	cout << endl << " Nodo Ingresado " << endl << endl;
}

void buscarNodo(){
	nodo* actual = new nodo();
	actual = primero;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << " Ingrese el dato del nodo a Buscar: ";
	cin >> nodoBuscado;
	if(primero != NULL){
		while(actual!=NULL && encontrado != true){
			
			if(actual->dato == nodoBuscado){
				cout << "\n Nodo con el dato ( " << nodoBuscado << " ) Encontrado";
				encontrado = true;
			}
			
			actual = actual->siguiente;
		}
		if(!encontrado){
			cout << "\n Nodo No Encontrado";
		}
	}else{
		cout << endl << " La cola se encuentra Vacia " << endl << endl;
	}	
}

void modificarNodo(){
	nodo* actual = new nodo();
	actual = primero;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << " Ingrese el dato del nodo a Buscar para Modificar: ";
	cin >> nodoBuscado;
	if(primero != NULL){
		while(actual!=NULL && encontrado != true){
			
			if(actual->dato == nodoBuscado){
				cout << "\n Nodo con el dato ( " << nodoBuscado << " ) Encontrado";
				cout << "\n Ingrese el nuevo dato para este Nodo: ";
				cin >> actual -> dato;
				cout << "\n Nodo Modificado\n\n";
				encontrado = true;
			}
			
			actual = actual->siguiente;
		}
		if(!encontrado){
			cout << "\n Nodo No Encontrado\n\n";
		}
	}else{
		cout << endl << " La cola se encuentra Vacia " << endl << endl;
	}		
}

void desplegarCola(){
	nodo* actual = new nodo();
	actual = primero;
	if(primero!=NULL){
		while(actual!=NULL){
			cout << endl << " " << actual->dato;
			actual = actual->siguiente;
		}
	}else{
		cout << endl << " La cola se encuentra Vacia " << endl << endl;
	}
}


