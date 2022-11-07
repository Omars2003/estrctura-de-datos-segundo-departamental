#include<iostream>
#include<conio.h>
#include<time.h>
#include <stdlib.h>


void imprimir(struct nodo *);
void insertarDer(struct nodo *);
nodo * insertarIzq(struct nodo *);
nodo * insertarDerAle(struct nodo *, int);
nodo * insertarIzqAle(struct nodo *p, int);
int Suma(nodo *);
int busqueda(nodo *p,int);
nodo * insertarAntesX(nodo *p,int);
void insertarDespuesX(nodo *p,int);
nodo* InsertarDespuesX(struct nodo*, int);
void modificarNodo(nodo*,int);
void intervalo(nodo* , int );
nodo * eliminarInicio(nodo *);
nodo * eliminarFinal(nodo *);
nodo* eliminarRango(struct nodo* &p, int x);
nodo * EliminarAntesX(nodo *p, int x);
nodo * DelBlock(nodo *p);

struct nodo
{
	
	int dato;
	nodo *enlace;
	
};

using namespace std;
int main()
{
	srand(time(NULL));
	int opc, ale, suma, bus, dato, X;
	struct nodo *p=NULL,*aux,*nuevoP;
	while(1)
	{
		
		cout<<"\tMENU\n\n";
		cout<<"0. Imprimir\n";
		cout<<"1. Insertar a la derecha\n";
		cout<<"2. Insertar a la izquierda\n";
		cout<<"3. Insertar aleatorio a la derecha\n";
		cout<<"4. Insertar aleatorio a la Izquierda\n";
		cout<<"5. Suma\n";
		cout<<"6. Busqueda\n";
		cout<<"7. Insertar antes de X \n";
		cout<<"8. Insertar despues de X \n";
		cout<<"9. Modificar nodo \n";
		cout<<"10. Intervalos x numeros \n";
		cout<<"11. Eliminar inicio \n";
		cout<<"12. Eliminar final \n";
		cout<<"13. Eliminar antes que X \n";
		cout<<"14. Eliminar despues que X \n";
		cout<<"15. Eliminar un bloque al inicio \n";
		cout<<"16. Eliminar del dato X al dato Y \n";
		
		cout<<"\nSelecciona una opcion: ";
		cin>>opc;
		
		switch(opc)
		{
			
			case 0:
				if(p==NULL)
					cout<<"Lista vacia\n";
				else
					imprimir(p);
			break;
			
			case 1:
				if(p==NULL)
				{
					
					p=new (nodo);
					cout<<"Ingresa el dato: ";
					cin>>p->dato;
					p->enlace=NULL;
					
				}
				else
					insertarDer(p);
				break;
				
			case 2:
				if(p==NULL)
				{
					
					p=new(nodo);
					cout<<" Ingrese el dato: ";
					cin>>p->dato;
					p->enlace=NULL;
					
				}
				else
				{
					
					nuevoP=insertarIzq(p);
					p=nuevoP;
					
				}
				break;	
			
			case 3:
				cout<<" Cuantos datos aleatorios deseas?:  ";
				cin>>ale;
				nuevoP=insertarDerAle(p,ale);
				p=nuevoP;
			break;	
			
			
			case 4:
				cout<<" Cuantos datos aleatorios deseas?:  ";
				cin>>ale;
				nuevoP=insertarIzqAle(p,ale);
				p=nuevoP;
			break;
			
			case 5:
			suma=0;
			suma=Suma(p);
			cout<<"\nLa sumatoria de los elementos es: "<<suma<<endl;
			break;
			
			case 6:
				cout<<"Ingresa dato a buscar: ";
				cin>>dato;
				bus=busqueda(p,dato);
				if(bus==1)
					cout<<"\nDato encontrado en la lista\n";
				else
					cout<<"\nDato NO encontrado en la lista\n";
			break;
			
			case 7:
				cout<<"\nIngrese el valor de X: ";
				cin>>X;
				nuevoP=insertarAntesX(p,X);
				p=nuevoP;
			break;
				
			case 8:
            cout << "Ingresa el valor de X: ";
            cin >> X;
            nuevoP = InsertarDespuesX(p, X);
            p = nuevoP;
            break;
       		default:
        	break;
        	
			case 9:
            	
				modificarNodo(p,X);
				break;
			
			case 10:
				intervalo(p,X);
				break;
			
			case 11:
				nuevoP=eliminarInicio(p);
				p=nuevoP;
			break;
			
			case 12:
				nuevoP=eliminarFinal(p);
				p=nuevoP;
			break;
			
			case 13:
			cout<<"Ingresa el valor a buscar en la lista x: ";	
			cin>>X;	
			nuevoP=EliminarAntesX(p, X);
			p=nuevoP;
			cout<<"\n";
			break;
				
			
			case 15:
				cout<<"Ingresa el intervalo: ";
				cin>>X;
				for(int i=0;i<X;i++){
					nuevoP=DelBlock(p);
					p=nuevoP;	
				}
			break;		
		
			case 16:
            	
				eliminarRango(p,X);
			
			break;
			
			
		}
		cout<<endl;

	}
	
}


void imprimir(struct nodo *p)
{
	
	nodo *aux;
	aux=p;
	while(aux!=NULL)
	{
		
		cout<<aux->dato<<" ";
		
		aux=aux->enlace;

		}	
	
}

void insertarDer(struct nodo *p)
{
	
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


nodo * insertarIzq(struct nodo *p)
{
    struct nodo *f, *aux;
    f=p;
    while(f->enlace!=NULL)
    	f=f->enlace;
    aux=new(nodo);
    cout<<"Ingresa el dato: ";
    cin>>aux->dato;
    aux->enlace=p;
    p=aux;
    return p;
}

nodo * insertarDerAle(struct nodo *p, int ale)
{
	
	struct nodo *f,*aux;
	int i;
	if(p==NULL)
	{
		
		p=new(nodo);
		p->dato=1+rand()%100;
		p->enlace=NULL;
		f=p;
		for(i=2;i<=ale;i++)
		{
			
			aux=new(nodo);
			aux->dato=1+rand()%100;
			aux->enlace=NULL;
			f->enlace=aux;
			f=aux;
			
		}
		
	}
	else
	{
		
		f=p;
		while(f->enlace!=NULL)
			f=f->enlace;
		for(i=1;i<=ale;i++)
		{
			
			aux=new(nodo);
			aux->dato=1+rand()%100;
			aux->enlace=NULL;
			f->enlace=aux;
			f=aux;
			
		}
		
	}
	return p;
}

nodo * insertarIzqAle(struct nodo *p, int ale)
{
	
	struct nodo *f,*aux;
	int i;
	if(p==NULL)
	{
		
		p=new(nodo);
		p->dato=1+rand()%100;
		p->enlace=NULL;
		f=p;
		for(i=2;i<=ale;i++)
		{
			
			aux=new(nodo);
			aux->dato=1+rand()%100;
			aux->enlace=NULL;
			aux->enlace=p;
			p=aux;

			
		}
		
	}
	else
	{
		
		f=p;
		while(f->enlace!=NULL)
			f=f->enlace;
		for(i=1;i<=ale;i++)
		{
			
			aux=new(nodo);
			aux->dato=1+rand()%100;
			aux->enlace=NULL;
			aux->enlace=p;
			p=aux;
			
		}
		
	}
	return p;
}

int Suma(struct nodo *p){
	int sum = 0;
	nodo *aux;
	aux = p;
	while(aux!=NULL){
		sum = sum + aux->dato;
		aux=aux->enlace;
	}
	return sum;
}

int busqueda(nodo *p,int dato)
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

nodo * insertarAntesX(nodo *p,int X)
{
	
	nodo *aux,*nuevo,*aux2;
	int band=0,dato;
	if(p==NULL)
		cout<<"Lista vacia \n\n";
	else
	{
		
		aux=p;
		while(aux!=NULL)
		{
			
			if(X==aux->dato)
			{
				
				band=1;
				cout<<"Ingresa el nuevo dato: ";
				cin>>dato;
				if(aux==p)
				{
					
					nuevo=new nodo;
					nuevo->dato=dato;
					nuevo->enlace=p;
					p=nuevo;
					
				}
				else
				{
					
					nuevo=new nodo;
					nuevo->dato=dato;
					nuevo->enlace=aux;
					aux2->enlace=nuevo;	
						
				}
			}
			aux2=aux;
			aux=aux->enlace;
		}
		if(band==0)
			cout<<"Dato NO encontrado\n";
		
	}
	return p;
}

nodo* InsertarDespuesX(nodo *p, int X)
{
    nodo* aux, * nuevo;
    int band = 0, dato;
    if (p == NULL)
    {
        cout << "Lista Vaci" << endl;
    }
    else
    {
        aux = p;
        while (aux != NULL)
        {
            if (X == aux->dato)
            {
                band = 1;
                cout << "Ingresa el nuevo dato: ";
                cin >> dato;
                if (aux == p)
                {
                    nuevo = new nodo;
                    nuevo->dato = dato;
                    nuevo->enlace = aux ->enlace;
                    aux->enlace = nuevo;
                }
                else
                {
                    nuevo = new nodo;
                    nuevo->dato = dato;
                    nuevo->enlace = aux ->enlace;
                    aux->enlace = nuevo;
                }
            }
            aux = aux->enlace;
        }
        if (band == 0)
        {
            cout << "Dato no encontrado " << endl;
        }
    }
    return p;

}

void modificarNodo(struct nodo* p,int X)
{
nodo* actual = new nodo();
	actual = p;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << " Ingrese el dato del nodo a buscar para modificar: ";
	cin >> nodoBuscado;
	if(p != NULL){
		
		while(actual != NULL && encontrado != true){
			
			if(actual->dato == nodoBuscado){
				cout << "Nodo con el dato " << nodoBuscado << " Encontrado\n";
				cout << "Ingrese el nuevo dato para este nodo: ";
				cin >> actual->dato;
				encontrado = true;
			}
			
			actual = actual->enlace;
		}
		if(!encontrado){
			cout << "El nodo no se encontro en la lista\n\n";
		}
	}else{
		cout  << "La lista se encuentra vacia\n\n";
	}
}

void intervalo(struct nodo* p, int X){
    nodo *aux, *nuevo;
    int cont = 1, inter, dato;
    aux = p;
    cout<<"Ingresa el intervalo: ";
    cin>>inter;
    cout<<"Ingresa el numero: ";
    cin>>dato;
    if(p != NULL){
        if(inter != 0){
            while(aux != NULL){
                if(cont == inter){
                    nuevo = new nodo;
                    nuevo->dato = dato;
                    nuevo->enlace = aux->enlace;
                    aux->enlace = nuevo;
                    cont = -1;
                }
                aux = aux->enlace;
                cont++;
            }
        }
    }
    else{
        cout<<"Lista vacia\n";
    }
}


nodo * eliminarFinal(nodo *p)
{
	
	nodo *aux, *aux2;
	aux=p;
	if(aux==NULL)
		cout<<"Lista vacia\n";
		else
		{
			
			if(aux->enlace=NULL)
			{
				
				delete(aux);
				p=NULL;
				
			}
			else
			{
		
				while(aux->enlace!=NULL)
				{
					
					aux2=aux;
					aux=aux->enlace;
					
				}
					aux2->enlace=NULL;
					delete(aux);
			}

}
return p;

}



nodo * eliminarInicio(nodo *p)
{
	
	nodo *aux;
	aux=p;
	if(aux==NULL)
		cout<<"Lista vacia\n";
		else
		{
			
			if(aux->enlace=NULL)
			{
				
				delete(aux);
				p=NULL;
				
			}
			else
		{
		
			p=aux->enlace;
			aux->enlace=NULL;
			delete(aux);
			cout<<"dato eliminado";
		}

}
return p;

}

void uwunt(struct nodo*&);
nodo * eliminarRango(struct nodo*&, int);


void uwunt(struct nodo* &p){
    nodo *aux = p;
    p = aux->enlace;
    delete aux;
}

nodo* eliminarRango(struct nodo* &p, int x){
    nodo *aux, *anterior = NULL, *f = NULL;
    int cont = 1, inter, num, bandera, arre[1001], i = 0;
    aux = p;
    if(p != NULL){
        cout<<"Ingresa el numero inicial: ";
        cin>>inter;
        bandera = 0;
        cout<<"Ingresa el numero final: ";
        cin>>num;
        while(aux != NULL){
            if(inter == aux->dato){
                bandera = 1;
            }
            if(num == aux->dato){
                bandera = 0;
            }
            if(bandera != 1){
                arre[i] = aux->dato;
                i++;
            }
            aux = aux->enlace;
        }
        while(p != NULL){
            uwunt(p);
        }

        while(aux != NULL){
            uwunt(aux);
        }
        if(arre[0] == num){
            if(p == NULL){
                p = new nodo;
                p->dato = arre[1];
                p->enlace = NULL;
            }
            f = p;
            while(f->enlace != NULL){
                f = f->enlace;
            }
            for(int j = 2; j < i; j++){
                aux = new(nodo);
                aux->dato = arre[j];
                aux->enlace = NULL;
                f->enlace = aux;
                f = aux;

            }
        }
        else{
            if(p == NULL){
                p = new nodo;
                p->dato = arre[0];
                p->enlace = NULL;
            }
            f = p;
            while(f->enlace != NULL){
                f = f->enlace;
            }
            for(int j = 1; j < i; j++){
                if(num == arre[j]){

                }
                else if(arre[j] != num){
                    aux = new(nodo);
                    aux->dato = arre[j];
                    aux->enlace = NULL;
                    f->enlace = aux;
                    f = aux;
                }
            }
        }

    }
    return p;
}

nodo * EliminarAntesX(nodo *p, int x)

{
	nodo *aux, *aux2, *aux3;
	int band=0, dato;
	
	if(p==NULL){
		cout<<"\nLa lista esta vacia";
	}
	else{
		aux=p;
		while(aux != NULL){
			if(x==aux->dato){
				band=1;
				cout<<"\nDato encontrado"<<endl;
				if(aux==p){
					cout<<"\nNO hay nada"<<endl;
					break; 
				}
				else{
					aux3->enlace=aux;
					delete(aux2);
					break;
				}
			}
			aux3=aux;
			aux2=aux->enlace;	
			aux=aux->enlace;	
			aux=aux->enlace;
		}
		if(band==0){
			cout<<"\nDato NO encontrado"<<endl;
		}
	}
	return p;
}

nodo * DelBlock(nodo *p){
	nodo *aux;
	aux=p;
	if(aux==NULL)
		cout<<"Lista vacia!"<<endl;
	else{
		if(aux->enlace==NULL){
			delete(aux);
			p=NULL;
		}
		else{
			p=aux->enlace;
			aux->enlace=NULL;
			delete(aux);
		}
	}
	return p;
}
