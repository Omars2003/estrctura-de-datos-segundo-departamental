#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct nodo{
	int dato;
	nodo *enlace;
};

void Imprimir(nodo *);
void InsertarDer(nodo *);
nodo * InsertarIzq(nodo *);
nodo * InsDerRandom(nodo *, int);
nodo * InsIzqRandom(nodo *, int);
int Sumatoria(nodo *);
int busqueda(nodo *p, int);
nodo * insertarAntesX(nodo *, int);
int main(){
	srand(time(NULL));
	nodo *p=NULL, *aux, *nuevoP;
	int opc, ale, suma, dato, bus, X;
	while(opc!=100){
		cout<<"\n     MENU"<<endl;
		cout<<" 0.Imprimir"<<endl;
		cout<<" 1.Ingresar a la derecha"<<endl;
		cout<<" 2.Ingresar a la Izquierda"<<endl;
		cout<<" 3.Ingresar aleatorio a la Derecha"<<endl;
		cout<<" 4.Ingresar aleatorio a la Izquierda"<<endl;
		cout<<" 5.Sumar todos los elementos"<<endl;
		cout<<" 6.Buscar elemento"<<endl;
		cout<<" 7.Insertar antes de X"<<endl;
		cout<<" 100 = SALIR"<<endl;
		cin>>opc;
		switch(opc){
			case 0:
				if(p==NULL)
				cout<<"Lista vacia"<<endl;
				else
				Imprimir(p);
			break;
			case 1:
				if(p==NULL){
					p=new(nodo);
					cout<<"Ingresa el dato: ";
					cin>>p->dato;
					p->enlace=NULL;
				}else
					InsertarDer(p);
			break;	
			case 2:
				if(p==NULL){
					p=new(nodo);
					cout<<"Ingresa el dato: ";
					cin>>p->dato;
					p->enlace=NULL;
				}
				else{
					nuevoP=InsertarIzq(p);
					p=nuevoP;
				}
			break;
			case 3:
				cout<<"¿Cuantos datos aleatorios quieres?: ";
				cin>>ale;
				nuevoP=InsDerRandom(p,ale);
				p=nuevoP;
			break;
			case 4:
				cout<<"¿Cuantos datos aleatorios quieres?:";
				cin>>ale;
				nuevoP=InsIzqRandom(p,ale);
				p=nuevoP;
			break;
			case 5:
				if(p==NULL)
				cout<<"Lista vacia"<<endl;
				else
				suma=Sumatoria(p);
				cout<<"La suma es:   "<<suma<<endl;
			break;
			case 6:
				cout<<"Ingrese el dato a buscar:\n";
				cin>>dato;
				bus=busqueda(p,dato);
				if(bus==1)
				cout<<"****Dato encontrado en la lista****\n";
				else
				cout<<"***Dato N0 encontrado en la lista***\n";
			break;
			case 7:
				cout<<"Ingrese el valor de X:";
				cin>>X;
				nuevoP=insertarAntesX(p,X);
				p=nuevoP;
			break;
		}
	
	}	
	return 0;
}
void InsertarDer(struct nodo*p){
	nodo *f, *aux;
	f=p;
	while(f->enlace!=NULL)
		f=f->enlace;
	aux=new(nodo);
	cout<<"Ingresa el dato: ";
	cin>>aux->dato;
	aux->enlace=NULL;
	f->enlace=aux;
	f=aux;
}

void Imprimir(struct nodo *p){
	nodo *aux;
	aux = p;
	while(aux!=NULL){
		cout<<aux->dato<<"  ";
		aux=aux->enlace;
	}
}

nodo * InsertarIzq(struct nodo *P){
	struct nodo *f, *aux;
	f=P;
	while(f->enlace!=NULL)
		f=f->enlace;
	aux=new(nodo);
	cout<<"Ingresa el dato: ";
	cin>>aux->dato;
	aux->enlace=P;
	P=aux;
	return P;
}

nodo * InsDerRandom(struct nodo *P,int ale){
	struct nodo *f, *aux;
	int i;
	srand(time(NULL));
	if(P==NULL){
		P=new(nodo);
		P->dato=1+rand()%100;
		P->enlace=NULL;
		f=P;
		for(i=2;i<=ale;i++){
			aux=new(nodo);
			aux->dato=1+rand()%100;
			aux->enlace=NULL;
			f->enlace=aux;
			f=aux;
		}
	}else{
		f=P;
		while(f->enlace!=NULL)
			f=f->enlace;
		for(i=1;i<=ale;i++){
			aux=new(nodo);
			aux->dato=1+rand()%100;
			aux->enlace=NULL;
			f->enlace=aux;
			f=aux;
		}
	}
	return P;
}

nodo * InsIzqRandom(struct nodo *P,int ale){
	struct nodo *f, *aux;
	int i;
	srand(time(NULL));
	if(P==NULL){
		P=new(nodo);
		P->dato=1+rand()%100;
		P->enlace=NULL;
		f=P;
		for(i=2;i<=ale;i++){
			aux=new(nodo);
			aux->dato=1+rand()%100;
			aux->enlace=P;
			P=aux;
		}
	}else{
		f=P;
		while(f->enlace!=NULL)
			f=f->enlace;
		for(i=1;i<=ale;i++){
			aux=new(nodo);
			aux->dato=1+rand()%100;
			aux->enlace=P;
			P=aux;
		}
	}
	return P;
}

int Sumatoria(struct nodo *P){
	int sum = 0;
	nodo *aux;
	aux = P;
	while(aux!=NULL){
		sum = sum + aux->dato;
		aux=aux->enlace;
	}
	return sum;
}

int busqueda(nodo *p, int dato)
{
	nodo *aux;
	int band=0;
	aux=p;
	
	while(aux!=NULL)
	{
		if(dato==aux->dato)
		{
		
		band=1;
		break;
	}
	aux=aux->enlace;
}
return band;

}


nodo* insertarAntesX(nodo *p, int X)
{
    nodo *aux, *nuevo, *aux2=NULL;
    int band = 0, dato;
    if (p == NULL)
    {
        cout << "*Lista Vacia*" << endl;
    }
    else
    {
        aux = p;
        while (aux != NULL)
        {
            if (X == aux ->dato)
            {
                band = 1;
                cout << "Ingresa el nuevo dato: "<<endl;
                cin >> dato;
                if (aux == p)
                {
                    nuevo = new nodo;
                    nuevo->dato = dato;
                    nuevo->enlace = p;
                    p = nuevo;
                }
                else
                {
                    nuevo = new nodo;
                    nuevo->dato = dato;
                    nuevo->enlace = aux;
                    aux2->enlace = nuevo;

                }
            }
            aux2 = aux;
            aux = aux->enlace;
        }
        if (band == 0)
        {
            cout << "Dato no encontrado"<<endl;
        }
    }
    return p;
}