#include<iostream>
#include<conio.h>
#include<time.h>
#include <stdlib.h>

using namespace std;

//Estructura
struct nodo{
	int dato;
	nodo *der, *izq;
};



void ImprimirIzqDer(nodo*);
void ImprimirDerIzq(nodo*);
void InsertarDer(nodo*);
nodo InsertarIzq(nodo);

nodo * InsertarAleIn(nodo *, int);
void InsertarAleFin(nodo *, int); 
int Busqueda(nodo *, int);
void burbuja(nodo*);


int main(){
	
	srand(time(NULL));
	int opc, ale, dato, bus;
	nodo *p=NULL, *nuevoP;
	
	while(1){
		
		cout<<"Menu"<<endl;
		cout<<"0. Imprimir de Izquierda a Derecha\n";
		cout<<"1. Imprimir de Derecha a Izquierda\n";	
		cout<<"2. Insertar a la Derecha\n";	
		cout<<"3. Insertar a la Izquierda\n";
		cout<<"4. Insertar ale al inicio\n";
		cout<<"5. Insertar ale al final\n";
		cout<<"6. Busqueda\n";
		cout<<"17.Burbuja\n";
		cout<<"99. Salir\n";	
		cout<<"\nSeleccione una opcion:";
		cin>>opc;
		
		switch(opc){
			case 0:
				if(p==NULL){
					cout<<"\nLa lista esta vacia\n";
				}
				else{
					ImprimirIzqDer(p);
					cout<<"\n";
				}
				cout<<"\n";
				break;
			case 1:
				if(p==NULL){
					cout<<"\nLa lista esta vacia\n";
				}
				else{
					ImprimirDerIzq(p);
					cout<<"\n";
				}
				cout<<"\n";
				break;
			case 2:
				if(p==NULL){
					p=new(nodo);
					cout<<"\nIngresa el dato: ";
					cin>>p->dato;
					p->der=NULL;
					p->izq=NULL;
				}
				else{
					InsertarDer(p);
					cout<<"\n";
				}
				cout<<"\n";
				break;
			case 3:
				if(p==NULL){
					p=new(nodo);
					cout<<"\nIngresa el dato: ";
					cin>>p->dato;
					p->der=NULL;
					p->izq=NULL;
				}
				else{
					
					cout<<"\n";
				}
				cout<<"\n";
				break;
			case 4:
				cout<<"\nCuantos datos aleatorios deseas? ";
				cin>>ale;
				nuevoP=InsertarAleIn(p, ale);
				p=nuevoP;
				cout<<"\n";
				break;
			case 5:
				cout<<"\nCuantos datos aleatorios deseas? ";
				cin>>ale;
				InsertarAleFin(p, ale);
				cout<<"\n";
				break;
			case 6:
				cout<<"\nQue dato desea buscar? ";
				cin>>dato;
				bus=Busqueda(p, dato);
				if(bus==1){
					cout<<"\nENCONTRADO\n";
				}
				else{
					cout<<"\nNO ENCONTRADO\n";
				}
				cout<<"\n";
				break;
				
			case 17:
				if(p==NULL)
				cout<<"Lista vacia\n";
				else
				burbuja(p);
				break;
				case 20:
					
					exit(0);
					break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}



void ImprimirIzqDer(nodo *p){
	nodo *aux;
	aux=p;
	cout<<"\nContenido de la lista:\n";
	
	while(aux != NULL){
		cout<<aux->dato<<"  ";
		aux=aux->der;
	}
}

void ImprimirDerIzq(nodo *p){
	nodo *aux;
	aux=p;
	
	while(aux->der != NULL){
		aux=aux->der;
	}
	cout<<"\nContenido de la lista:\n";
	while(aux != NULL){
		cout<<aux->dato<<"  ";
		aux=aux->izq;
	}
}

void InsertarDer(nodo *p){
	nodo *aux, *f;
	f=p;
	
	while(f->der != NULL){
		f=f->der;
	}
	
	aux=new(nodo);
	cout<<"\nIngresa el dato: ";
	cin>>aux->dato;
	aux->der=NULL;
	aux->izq=f;
	f->der=aux;
	f=aux;
}

nodo * InsertarIzq(nodo *p){
	nodo *aux, *f;
	f=p;
	
	while(f->izq != NULL){
		f=f->izq;
	}
	
	aux=new(nodo);
	cout<<"\nIngresa el dato: ";
	cin>>aux->dato;
	aux->der=f;
	aux->izq=NULL;
	f->izq=aux;
	f=aux;
	cout<<endl;
	
	return f;
}

nodo * InsertarAleIn(nodo *p, int ale){
	nodo *f, *aux;
	int i;

	if(p==NULL){
		p=new(nodo);
		p->dato=1+rand()%100;
		p->izq=NULL;
		p->der=NULL;
		f=p;
		for(i=2; i<=ale; i++){
			aux=new(nodo);
			aux->dato=1+rand()%100;
			aux->der=f;
			aux->izq=NULL;
			f->izq=aux;
			f=aux;
		}
	}
	else{
		f=p;
		while(f->izq != NULL){
			f=f->izq;
		}
		for(i=1; i<=ale; i++){
			aux=new(nodo);
			aux->dato=1+rand()%100;
			aux->der=f;
			aux->izq=NULL;
			f->izq=aux;
			f=aux;
			cout<<endl;
		}
	}
	return f;
}

void InsertarAleFin(nodo *p, int ale){
	nodo *f, *aux;
	int i;

	if(p==NULL){
		p=new(nodo);
		p->dato=1+rand()%100;
		p->der=NULL;
		p->izq=NULL;
		f=p;
		for(i=2; i<=ale; i++){
			aux=new(nodo);
			aux->dato=1+rand()%100;
			aux->der=NULL;
			aux->izq=f;
			f->der=aux;
			f=aux;
		}
	}
	else{
		f=p;
		while(f->der != NULL){
			f=f->der;
		}
		for(i=1; i<=ale; i++){
			aux=new(nodo);
			aux->dato=1+rand()%100;
			aux->der=NULL;
			aux->izq=f;
			f->der=aux;
			f=aux;
		}
			cout<<endl;
	}
}

int Busqueda(nodo *p, int dato){
	nodo *aux;
	int band=0;
	aux=p;
	
	while(aux != NULL){
		if(dato==aux->dato){
			band=1;
			break;
		}
		aux=aux->der;
	}
	return band;
}
void burbuja(nodo*p){
	int total=0,i,j,temp;
	nodo*aux,*aux2;
	aux =p;
	while(aux!=NULL){
		total++;
		aux=aux->der;
	}
	for(i=1;i<total;i++){
		aux=p;
		aux2=aux->der;
		for(j=1;j<total;j++){
			if(aux->dato>aux2->dato){
				temp=aux->dato;
				aux->dato=aux2->dato;
				aux2->dato=temp;
			}
			aux=aux2;
			aux2=aux2->der;
		}
	}
}
