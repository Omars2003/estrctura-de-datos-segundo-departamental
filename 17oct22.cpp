#include<iostream>
#include<stdlib.h>


void imprimirIzqDer(struct nodo *);
void imprimirDerIzq(nodo *);
void insertarDer(nodo *);
nodo * insertarIzq(nodo *);
nodo * insertarAleInicio(nodo *, int);
nodo * insertarAleFinal(nodo *, int);
int busqueda(nodo *p,int);
int suma(nodo *);
nodo * insertarAntesX(nodo *,int);
void insertarDespuesX(nodo *,int);
void insertarCadaNNodosX(nodo *,int,int);
void modificarX(nodo *, int,int);
nodo * eliminarInicio(nodo *);
nodo * eliminarFinal(nodo *);
nodo * eliminarAntesX(nodo *, int);
nodo * eliminarDespuesX(nodo *, int);
nodo * eliminarBloqueInicio(nodo *, int);
nodo * eliminarDeXaY(nodo *, int,int);
void burbuja(nodo*);


struct nodo{
	int dato;
	nodo *der, *izq;
};
using namespace std;

int main(){
	nodo *p=NULL;
	int opc, ale, dato, bus, x, y, n;
	
	while(1)
	{
		cout<<"MENU\n";
		cout<<"0. Imprimir de izquierda a derecha\n";
		cout<<"1. Imprimir de derecha a izquierda\n";
		cout<<"2. Insertar a la derecha\n";
		cout<<"3. Insertar a la izquierda\n";
		cout<<"4. Insertar aleatorios al inicio\n";
		cout<<"5. Insertar aleatorios al final\n";
		cout<<"6. Busqueda\n";
		cout<<"7. Sumar datos\n";
		cout<<"8. Insertar antes de X\n";
		cout<<"9. Insertar despues de X\n";
		cout<<"10.Insertar cada N nodos X\n";
		cout<<"11.Modificar X\n";
		cout<<"12.Eliminar inicio\n";
		cout<<"13.Eliminar final\n";
		cout<<"14.Eliminar antes de X\n";
		cout<<"15.Eliminar despues de X\n";
		cout<<"16.Eliminar un bloque al inicio\n";
		cout<<"17.Eliminar del dato X al dato Y\n";
		cout<<"18. Burbuja\n";

		cout<<"Selecciona una opcion\n";
		
		cin>>opc;
		switch(opc)
		{
			case 0:
				if(p==NULL)
				cout<<"Lista vacia\n\n";
				else
				imprimirIzqDer(p);
			break;
			case 1:
				if(p==NULL)
				cout<<"Lista vacia\n\n";
				else
				imprimirDerIzq(p);
			break;
			case 2:
				if(p==NULL){
					p=new(nodo);
					cout<<"Ingresa el dato\n";
					cin>>p->dato;
					p->der=NULL;
					p->izq=NULL;
				}
				else
				insertarDer(p);
			break;
			case 3:
				if(p==NULL){
					p=new(nodo);
					cout<<"Ingresa el dato\n";
					cin>>p->dato;
					p->der=NULL;
					p->izq=NULL;
				}
				else
				p=insertarIzq(p);
			break;
			case 4:
				cout<<"Ingresa cuantos datos aleatorios insertar: \n";
				cin>>ale;
				if(p==NULL)
				{
					p=new (nodo);
					p->dato = 1 + rand() % 100;
					p->der=NULL;
					p->izq=NULL;
					p=insertarAleInicio(p,ale-1);
				}
				else{
				p=insertarAleInicio(p,ale);
				}
				cout<<"Se agregaron correctamente "<<ale<<" n\n";
			break;
			case 5:
				cout<<"Ingresa cuantos datos aleatorios insertar: \n";
				cin>>ale;
				if(p==NULL)
				{
					p=new (nodo);
					p->dato = 1 + rand() % 100;
					p->der=NULL;
					p->izq=NULL;
					p=insertarAleFinal(p,ale-1);
				}
				else{
				p=insertarAleFinal(p,ale);
				}
				cout<<"Se agregaron correctamente "<<ale<<" datos\n\n";
			break;
			case 6:
				cout<<"Ingresa el dato que quieres buscar:\n";
				cin>>dato;
				bus=busqueda(p,dato);
				if(bus==1){
					cout<<"\nENCONTRADO\n\n";
				}
				else{
					cout<<"\nNO ENCONTRADO\n\n";
				}
			break;
			case 7:
				if(p==NULL)
				cout<<"Lista vacia\n\n";
				
				else
				cout<<"La suma total es: "<<suma(p)<<"\n\n";
			break;
			case 8:
				cout<<"Ingresa el valor de X\n";
				cin>>x;
				p=insertarAntesX(p,x);
			break;
			case 9:
				cout<<"Ingresa el valor de X\n";
				cin>>x;
				insertarDespuesX(p,x);
			break;
			case 10:
				cout<<"Ingresa el valor de N \n";
				cin>>n;
				cout<<"Ingresa el valor de X que quieres agregar:\n";
				cin>>x;
				insertarCadaNNodosX(p,n,x);
			break;
			case 11:
				cout<<"Valor a sustituir:\n";
				cin>>n;
				cout<<"Ingresa el nuevo dato:\n";
				cin>>x;
				modificarX(p,n,x);
			break;
			case 12:
				p=eliminarInicio(p);
			break;
			case 13:
				p=eliminarFinal(p);
			break;
			case 14:
				cout<<"Escribe el valor de X:\n";
				cin>>x;
				p=eliminarAntesX(p,x);
			break;
			case 15:
				cout<<"Escribe el valor de X:\n";
				cin>>x;
				p=eliminarDespuesX(p,x);
			break;
			case 16:
				cout<<"Escribe cuantos valores eliminar\n";
				cin>>x;
				p=eliminarBloqueInicio(p,x);
			break;
			case 17:
				cout<<"Escribe el valor de X\n";
				cin>>x;
				cout<<"Escribe el valor de Y\n";
				cin>>y;
				p=eliminarDeXaY(p,x,y);
			break;
			
			case 18:
				if(p==NULL){
					cout<<"Lista vacia\n\n";
				}
				else{
					burbuja(p);
				}
				break;
			
			
		}
	}
}
void burbuja (nodo * p){
	int total=0, i, j, temp;
	nodo * 	aux, * aux2;
	aux=p;
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

nodo * eliminarAntesX(nodo *p,int x){
	nodo * aux, * aux2, * aux3;
	aux=p;
	aux2=aux;
	aux3=aux2;
	if (aux==NULL){
		cout<<"\nLista vacia\n\n";
	}
	else{
		while(aux!=NULL){
				if(aux->dato==x)
				{
					if(aux==aux2){
						cout<<"\nNo hay un nodo antes de "<<x<<"\n\n";
						break;
					}
					else{
						if(aux3==aux2){
							p=aux;
							p->izq=NULL;
							cout<<"\nElemento borrado\n\n";
							delete(aux2);
							
							break;
						}
						else{
							aux3->der=aux;
							aux->izq=aux3;
							delete(aux2);
							cout<<"\nElemento borrado\n\n";
							break;
						}
					}		
				}
				else{
					aux3=aux2;
					aux2=aux;
					aux=aux->der;
				}
			}
	}
	return p;
}
nodo * eliminarDespuesX(nodo *p,int x){
	nodo * aux, * aux2, * aux3;
	aux=p;
	if(aux->der==NULL){aux2=NULL;}
	else{aux2=aux->der;}
	if(aux2==NULL){aux3=NULL;}
	else{aux3=aux2->der;}
	
	if (aux==NULL){
		cout<<"\nLista vacia\n\n";
	}
	else{
		while(aux!=NULL){
				if(aux->dato==x)
				{
					if(aux->der==NULL){
						cout<<"\nNo hay un nodo despues de "<<x<<"\n\n";
						break;
					}
					else{
						if(aux2->der==NULL){
							aux->der=NULL;
							delete(aux2);
							delete(aux3);
							cout<<"\nElemento borrado\n\n";
							break;
						}
						else{
							aux->der=aux3;
							aux3->izq=aux;
							delete(aux2);
							cout<<"\nElemento borrado\n\n";
							break;
						}
					}		
				}
				else{
					aux=aux2;
					if(aux->der==NULL){aux2=NULL;}
					else{aux2=aux->der;}
					if(aux2==NULL){aux3=NULL;}
					else{aux3=aux2->der;}
				}
			}
	}
	return p;
}
nodo * eliminarBloqueInicio(nodo *p,int x){
	nodo * aux;
	int band=0;
	aux=p;
	if (aux==NULL){
		cout<<"\nLista vacia\n\n";
	}
	else{
		while(aux!=NULL){
			aux=aux->der;
			band++;
		}
		if(x<=band){
			for(int i=0;i<x;i++){
				aux=p;
				if(aux->der==NULL){
					delete(aux);
					p=NULL;
				}
				else{
					p=aux->der;
					p->izq=NULL;
					delete(aux);
				}
			}
			cout<<"\n"<<x<<" elementos borrados correctamente\n\n";
		}
		else{
			cout<<"\nNo hay suficientes nodos que borrar\n\n";
		}
	}
	return p;
}
nodo * eliminarDeXaY(nodo * p, int x, int y){
	nodo *aux, *aux2;
	int band = 0, band2=0;
	aux = p;
	aux2 = p;
	while(aux!=NULL)
	{
		if (x==aux->dato){
			band++;
			break;
		}
		aux=aux->der;
	}
	while(aux2!=NULL)
	{
		if (y==aux2->dato){
			band2++;
			break;
		}
		aux2=aux2->der;
	}
	if(band==0){
		cout<<"No se encontro el valor X\n\n";
	}
	else{
		if(band2==0){
		cout<<"No se encontro el valor Y\n\n";
		}
		else{
			aux->der=aux2;
			aux2->izq=aux;
		}
	}
	return p;
}




void insertarCadaNNodosX(nodo *p, int n, int x){
	nodo *aux,*nuevo,*aux2;
	int band=0,dato=x,i=2;
	if(p==NULL){
		cout<<"\nLista vacia\n\n";
	}
	else{
		aux=p;
		while(aux->der!=NULL && band==0){
			for (i;i<=n;i++){
				if(aux->der!=NULL){
					aux=aux->der;
				}
				else{
					i=n;
					band++;
				}
			}
			if(band==0){
					nuevo = new (nodo);
					nuevo->dato=dato;
					nuevo->izq=aux;
					if(aux->der!=NULL){
						aux2=aux->der;
						aux2->izq=nuevo;
						nuevo->der=aux2;
					}
					else{
						nuevo->der=NULL;
					}
					aux->der=nuevo;
			}
			i=0;
		}
	}
}
void modificarX(nodo *p, int n, int x){
	nodo *aux;
	aux = p;
	while(aux!=NULL)
	{
		if (n==aux->dato){
			cout<<"Se encontro el nodo con valor: "<<n<<" y se reemplazo con: "<<x<<"\n\n";
			aux->dato=x;
		//	break;
		}
		aux=aux->der;
	}
}
nodo * eliminarInicio(nodo *p){
	nodo * aux;
	aux=p;
	if (aux==NULL){
		cout<<"\nLista vacia\n\n";
	}
	else{
		if(aux->der==NULL){
			delete(aux);
			p=NULL;
		}
		else{
			p=aux->der;
			p->izq=NULL;
			aux->der=NULL;
			
		}
	}
	return p;
}
nodo * eliminarFinal(nodo *p){
	nodo * aux, * aux2;
	aux=p;
	if (aux==NULL){
		cout<<"\nLista vacia\n\n";
	}
	else{
		if(aux->der==NULL){
			delete(aux);
			p=NULL;
		}
		else{
			while(aux->der!=NULL){
				aux2=aux;
				aux=aux->der;
			}
			aux2->der=NULL;
			delete(aux);
		}
	}
	return p;
}
nodo * insertarAntesX(nodo *p,int x){
	nodo *aux,*nuevo,*aux2;
	int band=0,dato;
	if(p==NULL){
		cout<<"\nLista vacia\n\n";
	}
	else{
		aux=p;
		while(aux!=NULL){
			if(x==aux->dato){
				band=1;
				cout<<"Ingresa el nuevo dato\n";
				cin>>dato;
				if(aux==p){
					nuevo = new (nodo);
					nuevo->dato=dato;
					nuevo->der=p;
					nuevo->izq=NULL;
					p->izq=nuevo;
					p=nuevo;
					break;
				}
				else{
					nuevo = new (nodo);
					nuevo->dato=dato;
					nuevo->der=aux;
					nuevo->izq=aux->izq;
					aux->izq=nuevo;
					aux2->der=nuevo;
					break;
				}
			}
			aux2=aux;
			aux=aux->der;
		}
		if(band==0){
			cout<<"\nDato no encontrado\n\n";
		}
	}
	return p;
}

void insertarDespuesX(nodo *p,int x){
	nodo *aux,*nuevo, *aux2;
	int band=0,dato;
	if(p==NULL){
		cout<<"\nLista vacia\n\n";
	}
	else{
		aux=p;
		while(aux!=NULL){
			if(x==aux->dato){
				band=1;
				cout<<"Ingresa el nuevo dato\n";
				cin>>dato;
				nuevo = new (nodo);
				nuevo->dato=dato;
				nuevo->izq=aux;
				if(aux->der!=NULL){
					aux2=aux->der;
					aux2->izq=nuevo;
					nuevo->der=aux2;
				}
				else{
					nuevo->der=NULL;
				}
				aux->der=nuevo;
			}
			aux=aux->der;
			
		}
		if(band==0){
			cout<<"\nDato no encontrado\n\n";
		}
	}
}
int suma (struct nodo *p){
	int sumaTotal=0;
	nodo *aux;
	aux=p;
	while(aux!=NULL)
	{
		sumaTotal=sumaTotal+aux->dato;
		aux=aux->der;
	}
	return sumaTotal;
}
int busqueda(nodo *p, int dato){
	nodo *aux;
	int band = 0;
	aux = p;
	while(aux!=NULL)
	{
		if (dato==aux->dato){
			band=1;
			break;
		}
		aux=aux->der;
	}
	return band;
}
nodo * insertarAleFinal(struct nodo *p, int ale)
{	
	for(int i=0;i<ale;i++){
		nodo *f, *aux;
		f=p;
		while(f->der!=NULL){
			f=f->der;
		}	
		aux=new(nodo);
		aux->dato = 1 + rand() % 100;
		aux->der=NULL;
		aux->izq=f;
		f->der=aux;
		f=aux;
	}
	return p;
}
nodo * insertarAleInicio(struct nodo *p, int ale)
{
	for(int i=0;i<ale;i++){
		struct nodo *aux;
		aux=new(nodo);
		aux->dato = 1 + rand() % 100;
		aux->der=p;
		aux->izq=NULL;
		p->izq=aux;
		p=aux;
		}
	return p;
}
nodo * insertarIzq(nodo *p){
	nodo *aux,*f;
	f=p;
	aux=new(nodo);
	cout<<"Ingresa el dato:\n";
	cin>>aux->dato;
	aux->der=p;
	aux->izq=NULL;
	f->izq=aux;
	return aux;
}
void insertarDer(nodo *p){
	nodo *aux,*f;
	f=p;
	while (f->der!=NULL){
		f=f->der;
	}
	aux=new(nodo);
	cout<<"Ingresa el dato:\n";
	cin>>aux->dato;
	aux->der=NULL;
	aux->izq=f;
	f->der=aux;
	f=aux;
}

void imprimirIzqDer(nodo *p){
	nodo *aux;
	aux=p;
	cout<<"\nContenido de la lista\n\n";
	while(aux!=NULL){
		cout<<aux->dato<<"-->";
		aux=aux->der;
	}
	cout<<"\n\n";
}

void imprimirDerIzq(nodo *p){
	nodo *aux;
	aux=p;
	while(aux->der!=NULL){
		aux=aux->der;
	}
	cout<<"\nContenido de la lista\n\n";
	while(aux!=NULL){
		cout<<aux->dato<<"-->";
		aux=aux->izq;
	}
	cout<<"\n\n";
}

