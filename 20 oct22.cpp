#include <conio.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct nodo {
	int dato;
	struct nodo* sig, * ant;
};

int main() {
	int opc, datos, i, a, j, k, l, n, band, x, cambio, contador, camb, totaldedatos, s, ini, fin, min, tam, inter;
	nodo* p = NULL, * f=NULL, * aux=NULL, * aux2=NULL, * aux3=NULL, * temp=NULL, * der, * izq, * nuevo;
	while (1) {
		system("cls");
		cout << "\nMENU\n";
		cout << "0.- Impresion de Izq a Der\n";
		cout << "1.- Impresion de Der a Izq\n";
		cout << "2.- Insertar a la izquierda\n";
		cout << "3.- Insertar a la derecha\n";
		cout << "4.- Insertar N Alea la derecha\n";


		cout << "5.- Eliminar al incio \n";
		cout << "6.- Eliminar al final \n";

		/////////////////////////////////////////////////////////////////////////////

		//cout << "7.- Eliminar N al inicio de la lista\n";
		//cout << "8.- Eliminar N al final de la lista\n";

		cout << "7.- Eliminar X\n";
		cout << "8.- Eliminar cada N nodos\n";

		//cout << "11.- Insertar en X\n";
		//cout << "12.- Insertar N antes de X\n";
		//cout << "13.- Insertar N despues de X\n";

		cout << "Elige : ";

		cin >> opc;
		switch (opc) {
		case 0://imprecion de izq a der
			if (p == NULL) {
				cout << "Lista vacia\n";
			}
			else {
				aux = p;
				do {
					cout << aux->dato << " ";
					aux = aux->sig;
				} while (aux != p);
				cout << "\n";
			}
			system("pause");
			break;
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case 1://Imprimir de derecha a izquierda
			if (p == NULL) {
				cout << "Lista vacia\n";
			}
			else {
				aux = f;
				do {
					cout << aux->dato << " ";
					aux = aux->ant;
				} while (aux != f);
				cout << "\n";
			}
			system("pause");
			break;
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case 2://Insertar al inicio
			if (p == NULL) {
				p = new(nodo);
				cout << "Ingresa el dato: ";
				cin >> p->dato;
				f = p;
				p->sig = p;
				p->ant = p;
			}
			else {
				aux = new(nodo);
				cout << "Inserta el dato: ";
				cin >> aux->dato;
				aux->sig = p;
				aux->ant = f;
				p->ant = aux;
				f->sig = aux;
				p = aux;
			}
			system("pause");
			break;
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case 3://Incertar al final
			if (p == NULL) {
				p = new(nodo);
				cout << "Inserta el dato: ";
				cin >> p->dato;
				f = p;
				p->sig = p;
				p->ant = p;
			}
			else {
				aux = new(nodo);
				cout << "Ingresa el dato: ";
				cin >> aux->dato;
				f->sig = p;
				aux->sig = p;
				aux->ant = f;
				p->ant = aux;
				f = aux;
			}
			system("pause");
			break;
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case 4://N aleatoreos al final
			srand(time(NULL));
			cout << "cuantos datos quieres agregar: ";
			cin >> n;
			for (int i = 1; i <= n; i++) {
				if (p == NULL) {
					p = new(nodo);
					p->dato = 1 + rand() % 100;
					f = p;
					p->sig = p;
					p->ant = p;
				}
				else {
					aux = new(nodo);
					aux->dato = 1 + rand() % 100;
					aux->sig = p;
					aux->ant = f;
					p->ant = aux;
					f->sig = aux;
					f = aux;
				}
			}
			system("pause");
			break;
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case 11://insertar en X
			if (p == NULL) {
				cout << "**Lista vacia**\n";
			}
			else {
				band = 0;
				cout << "ingresa el dato a buscar: ";
				cin >> x;
				aux = p;
				do {
					if (x == aux->dato) {
						band = 1;
						break;
					}
					aux = aux->sig;
				} while (aux != p);
				if (band == 1) {
					cout << "dato encontrado\n";
					cout << "Con que dato lo quieres cambiar? ";
					cin >> cambio;
					aux->dato = cambio;
				}
				else {
					cout << "dato no encontrado\n";
				}
			}
			system("pause");
			break;
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case 12://n antes de x
			band = 0;
			if (p == NULL) {
				cout << "La lista esta vacia";
			}
			else {
				cout << "Insertar antes de N: ";
				cin >> x;
				cout << "Total de datos a ingresar: ";
				cin >> n;
				for (int i = 1; i <= n; i++) {
					aux = p;
					do {
						if (x == aux->dato) {
							if (aux == p) {
								nuevo = new(nodo);
								nuevo->dato = 1 + rand() % 100;
								nuevo->sig = p;
								nuevo->ant = NULL;
								p->ant = nuevo;
								p = nuevo;
							}
							else {
								nuevo = new(nodo);
								nuevo->dato = 1 + rand() % 100;
								nuevo->sig = aux;
								nuevo->ant = aux2;
								p->ant = aux2;
								aux2->sig = nuevo;
							}
							band = 1;
						}
						aux2 = aux;
						aux = aux->sig;
					} while (aux != p);
				}
				if (band == 0) cout << "\nDato no encontrado\n";
			}
			system("pause");
			break;
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case 13://n despues de x
			if (p == NULL) {
				cout << "La lista esta vacia";
			}
			else {
				cout << "Insertar despues de N: ";
				cin >> x;
				cout << "Total de datos a ingresar: ";
				cin >> n;
				for (int i = 1; i <= n; i++) {
					aux = p;
					do {
						if (x == aux->dato) {
							if (aux == f) {
								nuevo = new(nodo);
								nuevo->dato = 1 + rand() % 100;
								nuevo->ant = aux;
								nuevo->sig = NULL;
								nuevo->sig = nuevo;
								f = nuevo;
							}
							else {
								if (aux == p) {
									nuevo = new(nodo);
									nuevo->dato = 1 + rand() % 100;
									nuevo->ant = p;
									nuevo->sig = aux->sig;
									p->sig = nuevo;
								}
								else {
									nuevo = new(nodo);
									nuevo->dato = 1 + rand() % 100;
									nuevo->ant = aux;
									nuevo->sig = aux->sig;
									aux2->ant = nuevo;
									aux->sig = nuevo;
								}
							}
							band = 1;
						}
						aux2 = aux;
						aux = aux->sig;
					} while (aux != p);
				}
				if (band == 0) cout << "\nDato no encontrado\n";
			}
			break;
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		case 5://eliminar al incio
			if (p == NULL) {
				cout << "La lista esta vacia";
			}
			else {
				aux = p;
				if (p == f) {
					delete(aux);
					p = NULL;
					cout << "listo\n";
				}
				else {
					if (p != f) {
						p = p->sig;
						p->ant = f;
						f->sig = p;
						aux->sig = NULL;
						aux->ant = NULL;
						delete(aux);
						cout << "listo\n";
					}
				}
			}
			system("pause");
			break;
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case 6: //eliminar al final
			if (p == NULL) {
				cout << "La lista esta vacia\n";
			}
			else {
				aux = f;
				if (f == p) {
					delete(aux);
					f = NULL;
					cout << "listo\n";
				}
				else {
					if (f != p) {
						f = f->ant;
						f->sig = p;
						p->ant = f;
						aux->sig = NULL;
						aux->ant = NULL;
						delete(aux);
						cout << "listo\n";
					}
				}
			}
			system("pause");
			break;
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case 9: //Eliminar N numeros al inicio de la lista
			if (p == NULL) {
				cout << "Lista vacia\n";
			}
			else {
				cout << "Cuantos datos quieres eliminar: ";
				cin >> x;
				for (int i = 0; i < x; i++) {
					p = p->sig;
					p->ant = f;
					f->sig = p;
					aux->sig = NULL;
					aux->ant = NULL;
					delete(aux);
					aux = p;
				}
				cout << "listo\n";
			}
			system("pause");
			break;
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case 10: //Eliminar N numeros al final de la lista
			if (p == NULL) {
				cout << "No hay datos\n";
			}
			else {
				cout << "cantidad de datos a eliminar: ";
				cin >> n;
				for (int i = 0; i < n; i++) {
					aux = f;
					f = f->ant;
					f->sig = p;
					p->ant = f;
					aux->sig = NULL;
					aux->ant = NULL;
					delete(aux);
					aux = f;
				}
				aux = p;
			}
			system("pause");
			break;
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		case 7:
			aux = p;
			aux2 = p;

			cout << "Ingresa el numero que quieres eliminar: ";
			cin >> datos;

			if (p == NULL)
				cout << "\t---Lista vacia---" << endl;
			else
			{
				while (aux2 != f)
				{
					aux3 = aux->sig;

					if (aux->dato == datos)
					{
						cout << "Dato " << datos << " encontrado" << endl;
						band = 1;
						if (aux == p)
						{
							aux3->ant = f;
							f->sig = aux3;
							p = aux3;
							delete(aux);
						}
						else
						{
							aux2->sig = aux3;
							aux3->ant = aux2;
							delete(aux);
						}
						break;
					}

					aux2 = aux;
					aux = aux->sig;
				}
				if (band == 0)
					cout << "El dato no se encuentra en la lista" << endl;
			}
			break;

			///////////////////////////////////////////////////////////////////////////////////////////////////////

		case 8:
			aux = p;
			aux2 = p;
			int cont = 0;

			cout << "Ingresa el intervalo: ";
			cin >> inter;

			if (p != NULL)
			{
				if (inter != 0)
				{
					while (aux2 != f)
					{
						aux3 = aux->sig;

						if (cont == inter)
						{
							if (aux == f)
								f = aux2;

							aux2->sig = aux3;
							aux3->ant = aux2;
							delete(aux);
							cont = -1;
							aux = aux3;
						}
						else
						{
							aux2 = aux;
							aux = aux->sig;
						}
						cont++;
					}
				}
				else
					cout << "El intervalo no puede ser 0" << endl;
			}
			else
				cout << "\t---Lista vacia---" << endl;
			break;
		}
	}
}
