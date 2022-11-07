#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;
//variables de canciones:
char soundfile[]="C:\Nem.wav" ;//NEM
char soundfile1[]="C:\Papa.wav" ;//PAPA
char soundfile2[]="C:\A mi.wav" ;
char soundfile3[]="C:\jgl.wav" ;
char soundfile4[] = "C:\Primer dia.wav"  ;
char soundfile5[]= "C:\soy.wav" ;
char soundfile6[]= "C:\feliz.wav" ;
char soundfile7[]="C:\Papa.wav" ;
char soundfile8[]= "C:\como dormiste.wav" ;
char soundfile9[]= "C:\La suburban.wav" ;
char soundfile10[]= "C:\leve.wav" ;
char soundfile11[]= "C:\MEMORIAS.wav" ;
char soundfile12[]="C:\Mora-TUYO.wav" ;
char soundfile13[]="C:\yanosomos.wav" ;
char soundfile14[]="C:\bachata.wav" ;
char soundfile15[]="C:\Anuel AA-MC.wav" ;
char soundfile16[]="C:\leve.wav" ;
char soundfile17[]="C:\postura.wav" ;
char soundfile18[]="C:\MEMORIAS.wav" ;
char soundfile19[]="C:\leve.wav" ;

struct  nodo{
    struct nodo *ant, *sig;
    string numero,nombre,interprete,genero;
};
int musica(int x);
int main(){
 system("color 2F");
    int num, opc,cont,mov,band,aleatorio, fin, song;
    string bus;
    nodo *p=NULL, *f, *aux, *aux2, *aux3;
    
    {
    string nume[20]={"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15","16", "17", "18", "19", "20"};
                                 
    string nomb[20]={"Nem", "Papa", "A-mi", "jgl", "Primer-dia", "Asi-soy", "Feliz-cumpleaños","Papa1", "Como-dormiste", "La-suburban", "leve", "Memorias", "Tuyo",
	 "ya-no-somos-ni-seremos", "La-bachata", "Mcgregor", "leve", "postura", "MEMORIAS", "leve"};
                                 
    string inter[20]={"cercle", "cercle-music", "rels-b", "la-adictiva", "mora", "sata-fe-klan", "feid", "unknown", "RELS", "uzielito-mix", "cartel-de-santa", "jhayco", "bad-bunny", "Chrisitan-nodal",
	"MTl", "ANuel", "cartel", "Bandams", "Sech", "sech"};

    string gen[20]={"electronica", "techno", "reggeaton-tranqui", "corridos", "electro-reggeaton", "rap", "techno", "reggeaton-chill", "bellaqueo", "hip-hop-sad", "electro", "mora", "bachata", "rancheras", "hip-hop", "rap-triste", "banda", "urbano",
	"pop", "hip"};
								 
                                 
                                 if(p==NULL)
                                 {
                                            p=new(nodo);
                                            p->numero=nume[0];
                                            p->nombre=nomb[0];
                                            p->interprete=inter[0];
                                            p->genero=gen[0];
                                            p->ant=NULL;
                                            p->sig=NULL;
                                            f=p;
                                            for(int i=1;i<20;i++)
                                            {
                                                    aux=new(nodo);
                                                    aux->numero=nume[i];
                                                    aux->nombre=nomb[i];
                                                    aux->interprete=inter[i];
                                                    aux->genero=gen[i];
                                                    aux->ant=f;
                                                    aux->sig=NULL;
                                                    f->sig=aux;
                                                    f=aux;
                                            }
                                 }
     }
     
     while(1)
     {
     		f->sig=p;
     		p->ant=f;
     	   
			 cout<<"EQUIPO ESTRUCTURA FINAL \n";
			 cout<<"JARED DIAZ\nOMAR MARTINEZ\nALAN REYES\nLUIS ANGEL TORRES\nCynthia Pitaluas\n";
             cout<<"\n\nSPOTIFY\n";
             cout<<"\n\t1.- Aleatorio \n";    
             cout<<"\n\t2.- Ordenada \n";      
             cout<<"\n\t3.- buscar  cancion\n";
             cout<<"\n\t4.- salir \n";
             cout<<"\n\tcomo quieres esuchar tu musica? ";   
             cin>>opc;
             
             switch(opc){
                        case 1:
                        	band=0;
                             cout<<"\n\n\nALEATORI\n";
                             srand(time(NULL));                     
                             aleatorio=rand()%29+1;
                             cout<<"\n EL NUMERO ALEATORIO ES: "<<aleatorio;
                             aux=p;
                             
                             for(int j=2;j<=aleatorio;j++)
                             {
                                     aux=aux->sig;
                             }
                             cout<<"\n********************************************************************* ";
                             cout<<"\n\n\t\t\:";
                             cout<<"\n\n\tCANCION  "<<aux->numero;
                             cout<<"\n\n\tTITULO: "<<aux->nombre;
                             cout<<"\n\n\tARTISTA: "<<aux->interprete;
                             cout<<"\n\n\tGENERO: "<<aux->genero;
                             cout<<"\n---------------------------------------------------- ";
                             istringstream(aux->numero) >> song;
                             musica(song);
                             do 
                             {
                            cout<<"\n-------------------------------------------------- ";
                             cout<<"\n\n\n\t\t\t\tSELECCIONA UNA OPCION: \n";
                             cout<<"\n\t\t\t1-.SIGUIENTE CANCION \n";
                             cout<<"\n\t\t\t2-.ANTERIOR CANCION \n";
                         
                             cout<<"\n\t\t\t4-.REGRESAR AL MENU PRINCIPAL \n";
                             cout<<"\n\t\t\tSELECCIONE UNA OPCION: ";  
							 cout<<"\n--------------------------------------------------- ";  
                             cin>>mov;
                             
                             switch(mov)
                             {
                                        case 1:
                                            aux=aux->sig;
                                            cout<<"\n---------------------------------------------------- ";
                                          
						                    cout<<"\n\n\t\t\t\tCANCION # "<<aux->numero;
						                    cout<<"\n\n\t\t\t\tTITULO: "<<aux->nombre;
						                    cout<<"\n\n\t\t\t\tARTISTA: "<<aux->interprete;
						                    cout<<"\n\n\t\t\t\tGENERO: "<<aux->genero;
						                    cout<<"\n------------------------------------------------------ ";
						                    band=1;
											istringstream(aux->numero) >> song;
                         				    musica(song);
                                            break;
                                        
                                        case 2:
                                            aux=aux->ant;
                                            cout<<"\n--------------------------------------------------------";
                                            cout<<"\n\n\t\t\t\tESTAS ESCUCHANDO:";
						                    cout<<"\n\n\t\t\t\tCANCION # "<<aux->numero;
						                    cout<<"\n\n\t\t\t\tTITULO: "<<aux->nombre;
						                    cout<<"\n\n\t\t\t\tARTISTA "<<aux->interprete;
						                    cout<<"\n\n\t\t\t\tGENERO: "<<aux->genero;
						                    cout<<"\n------------------------------------------------------- ";
						                    band=1;
											istringstream(aux->numero) >> song;
           					                musica(song);
                                            break;
                                        case 3:
                                        	cout<<"\n\n\nREPRODUCCION ALEATORIA\n";
                           					srand(time(NULL));                     
				                            aleatorio=rand()%29+1;
				                            cout<<"\n NUMERO CANCION ALEATORIA: "<<aleatorio;
				                            aux=p;
				                             
				                            for(int j=1;j<=aleatorio;j++){
				                                     aux=aux->sig;
				                            }
				                            cout<<"\n----------------------------------------------------- ";
				                            cout<<"\n\n\t\t\t\tESTAS ESCUCHANDO:";
						                    cout<<"\n\n\t\t\t\tNUMERO: "<<aux->numero;
						                    cout<<"\n\n\t\t\t\tTITULO: "<<aux->nombre;
						                    cout<<"\n\n\t\t\t\tARTISTA "<<aux->interprete;
						                    cout<<"\n\n\t\t\t\tGENERO: "<<aux->genero;
						                    cout<<"\n----------------------------------------------------- ";
						                    band=1;
											istringstream(aux->numero) >> song;
            				                musica(song);
                                        	break;
                                        
                                        case 4:
                                             {
                                                   cout<<"\n\n ------------ REGRESANDO -----------------\n\n\n\n\n\n";
                              						return main();
                                                   break;
                                             }
                             }
                             } while(band==1);
                             break;
                        
                        case 2:
                             cont=0;
                             int o;
                             o=0;
                             cout<<"\n------------------------------------------------- ";
                             cout<<"\n\n\nReproduccion en orden \n";
                             cout<<"\n1.-Iniciar\n\n2.-VOLVER AL MENU PRINCIPAL\n\nelige una opcion: ";
                             cout<<"";
                             cin>>o;
                             if(o==2)
                             {
                             	cout<<"\n\n REGRESANDO AL  MENU PRINCIPAL \n\n\n\n\n\n";
                                return main();
							 }
							 else
							 {
							 	mov=1; 
                             	aux=p;
                             	aux=aux->ant;
							 }
                             do
                             {
                                 switch(mov)
                                 {
                                           case 1: 
                                        		aux=aux->sig;
                                        	cout<<"\n-----------------------------------------------";
                                            cout<<"\n\n\t\t\t\tESTAS ESCUCHANDO:";
						                    cout<<"\n\n\t\t\t\tCANCION #  "<<aux->numero;
						                    cout<<"\n\n\t\t\t\tTITULO: "<<aux->nombre;
						                    cout<<"\n\n\t\t\t\tARTISTA "<<aux->interprete;
						                    cout<<"\n\n\t\t\t\tGENERO: "<<aux->genero;
											cout<<"\n----------------------------------------------- ";
						                    istringstream(aux->numero) >> song;
            				                musica(song);
                                     
                             cout<<"\n\n\n\t\t\t\tSELECCIONA UNA OPCION: \n";
                             cout<<"\n\t\t\t1-.Siguiente cancion \n";
                             cout<<"\n\t\t\t2-.Anterior cancion \n";
                             cout<<"\n\t\t\t3-.Otra cancion \n";
                             cout<<"\n\t\t\t4-.Regresar \n";
                             cout<<"\n\t\t\tSelecciona opcion: "; 
							 cout<<"\n----------------------------------------------- ";     
					                            cin>>mov;
					                            if(mov!=3)
					                            {
					                            	band=1;
												}
                                                break;					
                                           		
                                           case 2:
												aux=aux->ant;		       
											cout<<"\n------------------------------------- ";                                    	
                                            cout<<"\n\n\t\t\t\tESTAS ESCUCHANDO:";
						                    cout<<"\n\n\t\t\t\tCANCION #  "<<aux->numero;
						                    cout<<"\n\n\t\t\t\tTITULO: "<<aux->nombre;
						                    cout<<"\n\n\t\t\t\tARTISTA: "<<aux->interprete;
						                    cout<<"\n\n\t\t\t\tGENERO: "<<aux->genero;
						                    cout<<"\n------------------------------------- ";
						                    istringstream(aux->numero) >> song;
            				                musica(song);
                                                
                             cout<<"\n\n\n\t\t\t\tSELECCIONA UNA OPCION: \n";
                             cout<<"\n\t\t\t1-.Siguiente \n";
                             cout<<"\n\t\t\t2-.Anterior \n";
                             cout<<"\n\t\t\t3-.Otra cancion \n";
                             cout<<"\n\t\t\t4-.Regresar \n";
                             cout<<"\n\t\t\tSelecciona opcion: ";     
					                            cin>>mov; 
					                            if(mov!=3)
					                            {
					                            	band=1;
												}
                                                break;
                                           
                                           case 3:
                                                cout<<"\n\n REGRESANDO AL MENU PRINCIPAL\n";
                                                return main();
                                                break;
                                 }
                             }
                             while(band==1);
                             break;
                             
                        case 3:
                        	do
                        	{
                        		fin=0;
                        		cout<<"\n\n\n\n\n\n--------- \n";
                        		cout<<"\n\n[REPRODUCTOR POR BUSQUEDA] \n";
	                             cout<<"\n1.- Por cancion\n\n2.- Por Artista\n\nSELECCIONA UNA OPCION: ";
	                             cout<<"\n---------------------------------------------------------------- ";
	                             cin>>mov;
	                             switch(mov)
	                             {
	                             	case 1:
									 	
										cout<<"\n\nNombre de la cancion:\t";
										cin>>bus;
										aux=p;
										do
										{
											if(bus==aux->nombre){
											cout<<"\n-------------------------------------------------- ";
										
						                    cout<<"\n\n\t\t\t\tNUMERO: "<<aux->numero;
						                    cout<<"\n\n\t\t\t\tTITULO: "<<aux->nombre;
						                    cout<<"\n\n\t\t\t\tARTISTA "<<aux->interprete;
						                    cout<<"\n\n\t\t\t\tGENERO: "<<aux->genero;
						                    cout<<"\n---------------------------------------------------- ";
						                    fin=1;
						                    istringstream(aux->numero) >> song;
            				                musica(song);
										    break;
											}
											else{
												aux=aux->sig;
											}
										}while(aux!=p);
										if(fin!=1)
										{
											cout<<"\n\n\n\nno tienes esa cancion \n\n\n\n";
										}
	                             		break;
	                             	case 2:
	                             		
										cout<<"\n\nNombre del artista:\t";
										cin>>bus;
										aux=p;
										do
										{
											if(bus==aux->interprete){
										
						                    cout<<"\n\n\t\t\t\tNUMERO: "<<aux->numero;
						                    cout<<"\n\n\t\t\t\tTITULO: "<<aux->nombre;
						                    cout<<"\n\n\t\t\t\tARTISTA "<<aux->interprete;
						                    cout<<"\n\n\t\t\t\tGENERO: "<<aux->genero;
							                fin=1;
							                istringstream(aux->numero) >> song;
            				                musica(song);
							                break;
											}
											else
											{
												aux=aux->sig;
											}
										}while(aux!=p); 
										if(fin!=1)
										{
											cout<<"\n\n\n\nno tienes esa cancion \n\n\n\n";
										}
									 	break;
									case 3: 
										cout<<"\n\n REGRESA AL MENU\n";
	                                                return main();
	                                                break;	
	                            
								 }
                        		cout<<"\n\n\nSELECCIONA UNA OPCION: \n";
	                            cout<<"\n1-.Nueva busqueda\n";
	                            cout<<"\n2-.Menu Principal\n";
	                            cout<<"\nSELECCIONE UNA OPCION: ";  
	                            cin>>band;
	                            if(band==2)
	                            {
	                            	cout<<"\n\n REGRESANDO AL MENU PRINCIPAL\n";
                                    return main();
                                    break;
								}
							}while(band==1);
                             break;
                             
                        case 4:
                             cout<<"\n\n SALIENDO DEL PROGRAMA \n";
                             return 0;
                             break;
                        
                        default:
                                cout<<"\n\n OPCION INCORRECTA\n";
                                
                                break;
             }
     }
}
int musica(int x){
	switch(x){
		case 1:
			cout<<PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC );
		return 0;
		break;
		
		case 2:
			cout<<PlaySound((LPCSTR)soundfile1, NULL, SND_FILENAME | SND_ASYNC );
		return 0;
		break;
		
		case 3:
			cout<<PlaySound((LPCSTR)soundfile2, NULL, SND_FILENAME | SND_ASYNC );
		return 0;
		break;
		
		case 4:
			cout<<PlaySound((LPCSTR)soundfile3, NULL, SND_FILENAME | SND_ASYNC );
		return 0;
		break;
		
		case 5:
			cout<<PlaySound((LPCSTR)soundfile4, NULL, SND_FILENAME | SND_ASYNC );
		return 0;
		break;
		
		case 6:
			cout<<PlaySound((LPCSTR)soundfile5, NULL, SND_FILENAME | SND_ASYNC );
		return 0;
		break;
		
		case 7:
			cout<<PlaySound((LPCSTR)soundfile6, NULL, SND_FILENAME | SND_ASYNC );
		return 0;
		break;
		
		case 8:
			cout<<PlaySound((LPCSTR)soundfile7, NULL, SND_FILENAME | SND_ASYNC );
		return 0;
		break;
		
		case 9:
			cout<<PlaySound((LPCSTR)soundfile8, NULL, SND_FILENAME | SND_ASYNC );
		return 0;
		break;
		
		case 10:
			cout<<PlaySound((LPCSTR)soundfile9, NULL, SND_FILENAME | SND_ASYNC );
		return 0;
		break;
		
		case 11:
			cout<<PlaySound((LPCSTR)soundfile10, NULL, SND_FILENAME | SND_ASYNC );
		return 0;
		break;
		
		case 12:
			cout<<PlaySound((LPCSTR)soundfile11, NULL, SND_FILENAME | SND_ASYNC );
		return 0;
		break;
		
		case 13:
			cout<<PlaySound((LPCSTR)soundfile12, NULL, SND_FILENAME | SND_ASYNC );
		return 0;
		break;
		
		case 14:
			cout<<PlaySound((LPCSTR)soundfile13, NULL, SND_FILENAME | SND_ASYNC );
		return 0;
		break;
		
		case 15:
			cout<<PlaySound((LPCSTR)soundfile14, NULL, SND_FILENAME | SND_ASYNC );
		return 0;
		break;
		
		case 16:
			cout<<PlaySound((LPCSTR)soundfile15, NULL, SND_FILENAME | SND_ASYNC );
		return 0;
		break;
		
		case 17:
			cout<<PlaySound((LPCSTR)soundfile16, NULL, SND_FILENAME | SND_ASYNC );
		return 0;
		break;
		
		case 18:
			cout<<PlaySound((LPCSTR)soundfile17, NULL, SND_FILENAME | SND_ASYNC );
		return 0;
		break;
		
		case 19:
			cout<<PlaySound((LPCSTR)soundfile18, NULL, SND_FILENAME | SND_ASYNC );
		return 0;
		break;
		
		case 20:
			cout<<PlaySound((LPCSTR)soundfile19, NULL, SND_FILENAME | SND_ASYNC );
		return 0;
		break;		
	}
}
