#include <iostream>
using namespace std;
class Nodo
{
private:
    int dato;
    Nodo *sig,*ant;
public:
    Nodo()
    {   dato=0;
        ant=NULL;
		sig=NULL;
    }
    Nodo(int x)
    {   dato=x;
    	ant=NULL;
        sig=NULL;
    }
    void Asignasig(Nodo*);
    void Asignaant(Nodo*);
    void Leer(int);
    void Imprimir();
    Nodo *Obtienesig();
    Nodo *Obtieneant();
    int Obtienedato();
};
void Nodo::Asignasig(Nodo *x)
{   this->sig=x;
}
void Nodo::Asignaant(Nodo *x)
{	this->ant=x;
}
void Nodo::Imprimir()
{   cout<<this->dato<<endl;
}
Nodo* Nodo::Obtienesig()
{  return(this->sig);
}
Nodo* Nodo::Obtieneant()
{  return(this->ant);
}
int Nodo::Obtienedato()
{   return(this->dato);
}
class LSE
{    private:
    Nodo *Inicio;
public:
    void InsertarI(int);
    void InsertarF(int);
    void BorrarI();
    void BorrarF();
    void Imprimir();
    void ImprimirR();
    int Contar();
    Nodo *Buscar(int);
    void Borrar(int);
    LSE()
    {   Inicio=NULL;
    
    }
    
};
void LSE::InsertarI(int x)
{   if(!Inicio)	Inicio=new Nodo(x);
	else
	{	Nodo *helpx3=new Nodo(x);
   		helpx3->Asignasig(Inicio);
   		Inicio->Asignaant(helpx3);
		Inicio=helpx3;  		
   	}
}
void LSE::InsertarF(int x)
{   if(Inicio==NULL)
    Inicio=new Nodo(x);
    else
        {   Nodo *help=Inicio;
            while(help->Obtienesig()!=NULL)			help=help->Obtienesig();
            Nodo *helpx2=new Nodo(x);
            help->Asignasig(helpx2);
            helpx2->Asignaant(help);
        }
}
void LSE::BorrarI()
{
    if(!Inicio)
        cout<<"Lista Vacia"<<endl;
    else
        {   if(Inicio->Obtienesig()==NULL)
            {  	delete Inicio;
            	Inicio=NULL;
            }
            else
            {   Nodo *hay=Inicio;
                Inicio=Inicio->Obtienesig();
                Inicio->Asignaant(NULL);
                hay->Asignasig(NULL);
                delete hay;
            }
        }
}
void LSE::BorrarF()
{   if(!Inicio)
    cout<<"Lista Vacia";
	else
	{  	if(Inicio->Obtienesig()==NULL)
		{   delete Inicio;
    		Inicio=NULL;
		}
		else
		{  	Nodo *Ad,*Sh;
    		Ad=Inicio;
    		while(Ad->Obtienesig()!=NULL)
    		{   Sh=Ad;
        		Ad=Ad->Obtienesig();
    		}
    		Sh->Asignasig(NULL);
    		delete Ad;
		}
	}
}
void LSE::Borrar(int x)
{   Nodo *simi=Buscar(x);
    if(simi==NULL)       cout<<"DATO NO ENCONTRADO";
    else
    {   if(simi==Inicio)           BorrarI();
    	else
   		{
        	if(simi->Obtienesig()==NULL)    BorrarF();
        	else
        	{   Nodo *XL;
				XL=simi->Obtieneant();
				XL->Asignasig(simi->Obtienesig());
            	simi->Asignasig(NULL);
            	delete simi;
        	}
    	}
    }
}
void LSE::Imprimir()
{   if(!Inicio)
    cout<<"Lista Vacia"<<endl;
    else
        {   Nodo *Aux=Inicio;
            while(Aux!=NULL)   
            {	Aux->Imprimir();
				Aux=Aux->Obtienesig();
			}
        }
}
void LSE::ImprimirR()
{   if(!Inicio)
    cout<<"Lista Vacia"<<endl;
    else
        {   Nodo *Aux=Inicio;
            while(Aux->Obtienesig()!=NULL)	Aux=Aux->Obtienesig();
			while(Aux!=NULL)   
            {	Aux->Imprimir();
				Aux=Aux->Obtieneant();
			}
        }
}
Nodo* LSE::Buscar(int x)
{
    Nodo *covid=Inicio;
    if(Inicio)
    {    while (covid!=NULL)
    {    if (covid->Obtienedato()==x)
        return covid;
        covid=covid->Obtienesig();
    }
    }
    return covid;
}
int LSE::Contar()
{    int ESCA=0;
    if(!Inicio)       ESCA=0;
    else
    {    Nodo *REC=Inicio;
        while(REC!=NULL)
        {    ESCA++;
            REC=REC->Obtienesig();
        }
    }	
	return ESCA;
}
int main(int argc, const char * argv[])
{   LSE A;
    int opc, dato;
    do{
        cout<<"1.- Insertar Inicio"<<endl;
        cout<<"2.- Insertar Fin"<<endl;
        cout<<"3.- Borrar Inicio"<<endl;
        cout<<"4.- Borrar Fin"<<endl;
        cout<<"5.- Contar"<<endl;
        cout<<"6.- Borrar"<<endl;
        cout<<"7.- Imprimir"<<endl;
        cout<<"8.- Imprimir en Reversa"<<endl;
        cout<<"9.- Salir"<<endl;
        cout<<"Teclee la opcion"<<endl;
        cin>>opc;
        
        switch(opc)
        {
            case 1:
                cout<<"teclee el dato a insertar"<<endl;
                cin>>dato;
                A.InsertarI(dato);
                break;
            case 2:
                cout<<"Teclee el dato a insertar"<<endl;
                cin>>dato;
                A.InsertarF(dato);
                break;
            case 3:
                A.BorrarI();
                break;
            case 4:
                A.BorrarF();
                break;
            case 5:
                dato=A.Contar();
                cout<<"Hay "<<dato<<" nodos en la Lista"<<endl;
                break;
            case 6:
                cout<<"Teclee el dato a borrar"<<endl;
                cin>>dato;
                A.Borrar(dato);
                break;
            case 7:
                A.Imprimir();
                break;
            case 8:
                A.ImprimirR();
                break;
            default:
                cout<<"opcion salir...";
                break;
        }
        system("pause"); system("cls"); 
    }while(opc<9);
    
    return 0;
}
