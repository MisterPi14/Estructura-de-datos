#include<iostream>
#include<time.h>
#include <stdlib.h>
/*
Observaciones del programa: las variables apuntador f, p, nuevo, aux, aux2 en realidad manipulan los datos pero estos pueden moverse como quieran y el valor se queda en su sitio
*/
using namespace std;

struct nodo
{
    int dato; //C1
    nodo *liga; //C2 al ser de tipo nodo involucra que la variable tendra todos los datos de la estructura, en este caso al ser puntero guarda la direccion del int
};

int main()
{
    int opc,n,i,suma,d,band,x,n_ale;
    nodo *p=NULL,*f,*aux,*aux2,*aux3,*nuevo;//P Y F son los apuntadores de los nodos P rincipal y F inal
    //p y f son el mismo nodo en el inicio del programa
	srand(time(NULL));

   while(1)
   {
        cout<<"\n\n* * * * * * * MENU * * * * * * *\n";
        cout<<"0.- Imprimir\n";
        cout<<"1.- Insertar a la derecha\n";
        cout<<"2.- Insertar por la izquierda\n";
        cout<<"3.- Insertar aleatorios por la derecha\n";
        cout<<"4.- Insertar aleatorios por la izquierda\n";
        cout<<"5.- Sumatoria de nodos\n";
        cout<<"6.- Busqueda de un nodo\n";
		cout<<"7.- Insertar nodo antes del nodo x\n";
		cout<<"8.- Insertar nodo despues del nodo x\n";
		cout<<"9.- Actualizar valor de un nodo\n";
		cout<<"10.- Eliminar el primer nodo\n";
		cout<<"11.- Eliminar el ultimo nodo\n";
		cout<<"12.- Eliminar x nodo\n";
		cout<<"13.- Eliminar antes de x nodo\n";
		cout<<"14.- Eliminar despues de x nodo\n";
		cout<<".-\n";
		cout<<".-\n";
        cout<<"\n   * * * * Seleccione una opción: ";
        cin>>opc;
       switch(opc)
       {
        case 0://Imprimir
               aux=p;
               if(aux==NULL)
                   cout<<"\t\tLista vacía\n";
               else
               {
                   cout<<"\t\tContenido de la lista\n";
                   while(aux!=NULL)
                   {
                       cout<<aux->dato<<" ";
                       aux=aux->liga;
                   }
                   cout<<"\n";
                }
               break;
    	case 1://Insertar a la derecha
               if(p==NULL)
               {
                   p=new(nodo);//Esta funcion new hace que se recerve espacio en memoria para el apuntador, lo hace de manera dinamica Hipotesis: es una instancia de objeto y como tal no es necesario que se llame explicitamente a la estructura
                   //En este caso el compilador lo que hace es buscar una direccion de memoria para una variable que tiene dos campos (como definimos nodo en struct) esta localidad es la que se guardara en los punteros *liga de cada nodo
                   //En pocas palabras, se crea el objeto p de la clase nodo
				   cout<<"Ingresa el dato: ";
                   cin>>p->dato;//p es una variable de tipo nodo (con las caracteristicas de poseer 2 argumentos asi como lo definimos), y es un apuntador que guarda el valor en el argumento dato de la variable p 
                   p->liga=NULL;//hacemos que la liga de la variable apuntador p sea null ya que se recorrera hasta la derecha para que el ultimo nodo f tenga esa liga null
                   f=p;//igualamos los nodos puesto que en el primer registro son el mismo nodo
               }
               else
               {
                   aux=new(nodo);//se crea variable aux
                   cout<<"Ingresa el dato: ";
                   cin>>aux->dato;
                   aux->liga=NULL;
                   f->liga=aux;
                   f=aux;
               }
                                  //MODELO:
                   //1 iteracion: p=(45,null) y p=f por tanto f=(45,null)
                   //2da hasta n: aux=(85,null) luego f
           break;
        case 2://Insertar por la izquierda
        		if(p==NULL)
				{
					p=new(nodo);
					cout<<"Ingresa el dato: ";
					cin>>p->dato;
					p->liga=NULL;
					f=p; 
				}
				else
				{
					aux=new(nodo);
					cout<<"Ingresa el dato: ";
					cin>>aux->dato;
					aux->liga=p;
					p=aux;
				}
        	break;
       	case 3: //aleatorios por derecha
       			cout<<"Cuantos aleatorios quiere insertar?: \n";
       			cin>>n_ale;
       			
        	    if(p==NULL)
               {
					p=new(nodo);
					p->dato=1+rand()%100;
					p->liga=NULL;
					f=p; 
					n_ale--;//lo decrementa por que ya ingreso 1 dato
               }
               for(int i=1;i<=n_ale;i++)//for hace n numeros aleatorios o n-1 si realizo el primero desde null
               {
               	    aux=new(nodo);
                    aux->dato=1+rand()%100;
                    aux->liga=NULL;
                    f->liga=aux;
                    f=aux;
			   }
				break;
        case 4://aleatorios por la izquierda
        	   	cout<<"Cuantos aleatorios quiere insertar?: \n";
       			cin>>n_ale;
       			
        	    if(p==NULL)
               {
					p=new(nodo);
					p->dato=1+rand()%100;
					p->liga=NULL;
					f=p; 
					n_ale--;//lo decrementa por que ya ingreso 1 dato
               }
               for(int i=1;i<=n_ale;i++)//for hace n numeros aleatorios o n-1 si realizo el primero desde null
               {
			   		aux=new(nodo);
					aux->dato=1+rand()%100;
					aux->liga=p;
					p=aux;
			   }
        	break;
		case 5://Sumatoria de todos los nodos
		suma=0;
		aux=p;
		if(aux==NULL)
		{
			cout<<"La lista esta vacia\n";
		}
		else
		{
			while(aux!=NULL)
			{
				suma=suma+aux->dato;
				aux=aux->liga;
			}
		}
		cout<<"La sumatoria es: "<<suma<<"\n";
        	break;
        case 6://Busqueda
        	aux=p;
        	if(aux==NULL)
			{
				cout<<"Lista Vacia\n";
			}
			else
			{
				band=0;
				cout<<"Ingresa el dato a buscar:\n";
				cin>>d;
				while(aux!=NULL)
				{
					if(d==aux->dato)
					{
						band=1;
						break;
					}
					aux=aux->liga;
				}
				if(band==1)
				{
					cout<<"Dato encontrado\n";
				}
				else
				{
					cout<<"Dato no encontrado\n";
				}
			}
        	break;
        case 7://insertar nodo antes de x nodo
        	if(p==NULL)
			{
				cout<<"***Lista vacia***\n";
			}
			else
			{
				band=0;
				cout<<"Ingresa el valor de x: ";
				cin>>x;
				aux=p;
				while(aux!=NULL)
				{
					if(x==aux->dato)
					{
						band=1;
						if(aux==p)
						{
							nuevo=new(nodo);
							cout<<"Ingresa el dato: ";
							cin>>nuevo->dato;
							nuevo->liga=p;
							p=nuevo;
						}
						else
						{
							nuevo=new(nodo);
							cout<<"Ingresa el dato ";
							cin>>nuevo->dato;
							aux2->liga=nuevo;//se vincula el nodo de atras al nodo nuevo
							nuevo->liga=aux;//se vincula el nodo nuevo al nodo actual en el recorrido para que quede detras de el
						}
						break;
					}
					aux2=aux;
					aux=aux->liga;
				}
				if(band==0)
				cout<<"***Dato no encontrado***\n";
			}
        	break;
        case 8://insertar nodo despues de x nodo
        	if(p==NULL)
			{
				cout<<"***Lista vacia***\n";
			}
			else
			{
				band=0;
				cout<<"Ingresa el valor de x: ";
				cin>>x;
				aux=p;
				while(aux!=NULL)
				{
					if(x==aux->dato)
					{
						band=1;
						if(aux==f)
						{
							nuevo=new(nodo);
							cout<<"Ingresa el dato: ";
							cin>>nuevo->dato;
							nuevo->liga=NULL;
							f->liga=nuevo;
							f=nuevo;
						}
						else
						{
							nuevo=new(nodo);
							cout<<"Ingresa el dato ";
							cin>>nuevo->dato;
							nuevo->liga=aux->liga;//al nuevo nodo se le vincula con la liga del nodo actual en el recorrido (aux) que apunta a "aux+1" 
							aux->liga=nuevo;//a aux se le vincula con el nuevo nodo
						}
						break;
					}
					aux=aux->liga;
				}
				if(band==0)
				cout<<"***Dato no encontrado***\n";
			}
        	break;
        case 9://Actualizar valor de un nodo
        	cout<<"Ingresa el valor del nodo x\n";
			cin>>d;
        	aux=p;
        	if(p==NULL)
			{
				cout<<"La lista esta VACIA\n";
			}
			else
			{
				band=0;
				while(aux!=NULL)
				{
					if(d==aux->dato)
					{
						band=1;
						cout<<"Ingresa el valor actualizado\n";
						cin>>aux->dato;
						break;
					}
					aux=aux->liga;
				}
				if(band==0)
				{
					cout<<"Dato no encontrado\n";
				}
     	   }
        	break;
        case 10://Eliminar nodo uno
        	if(p==NULL)
			{
				cout<<"La lista esa vacia\n";
			}
			else
			{
				aux=p;
				if(aux==p && aux==f)
				{
					delete(aux);
					p=NULL;
				}
				else
				{
					p=p->liga;
					aux->liga=NULL;
					delete(aux);
				}
			}
        	break;
        	case 11://eliminar ultimo nodo
        		if(p==NULL)
				{
					cout<<"La lista esa vacia\n";
				}
				else
				{
					if(p==f)
					{
						delete(p);
						p=NULL;
					}
					else
					{
						aux=p;
						while(aux->liga!=NULL)
						{
							aux2=aux;
							aux=aux->liga;
						}
						f=aux2;
						f->liga=NULL;
						delete(aux);
					}
				}
        		break;
        	case 12:
        		if(p==NULL)
				{
					cout<<"La lista esa vacia\n";
				}
				else
				{
					band=0;
					cout<<"Ingresa x: ";
					cin>>x;
					aux=p;
					while(aux!=NULL)
					{
						if(x==aux->dato)
						{
							band=1;
							if(p==f)
							{
								delete(p);
								p=NULL;
							}
							else
							{
								if(x==p->dato)//nodo del inicio?
								{
									p=p->liga;
									aux->liga=NULL;
									delete(aux);
								}
								else
								{
									if(x==f->dato)//nodo final?
									{
										f=aux2;
										f->liga=NULL;
										delete(aux);
									}
									else//centro de la lista
									{
										aux2->liga=aux->liga;
										aux->liga=NULL;
										delete(aux);
									}
								}
							}
						}
						aux2=aux;
						aux=aux->liga;
					}
				}
				if(band==0)
				cout<<"El dato no fue encontrado\n";
        		break;
        	case 13://Eliminar antes de x
        	  	if(p==NULL)
				{
					cout<<"La lista esa vacia\n";
				}
				else
				{
					cout<<"Ingresa el valor de x: \n";
					cin>>x;
					aux2=p;

					if(x==p->dato)
					{
						cout<<"No es posible eliminar por que es el primer nodo\n";
					}
					else
					{
						aux=aux2->liga;
						while(aux->liga!=NULL)
						{			
							if(aux->dato==x)
							{
								//si el auxiliar es el segundo nodo
								if(p->liga==aux)
								{
									p->liga=NULL;
									delete(p);
									p=aux;
								}
								//para cualquier auxiliar
								else if(aux->dato==x)
								{
									aux3->liga=aux2->liga;
									aux2->liga=NULL;
									delete(aux2);
								}
							}
							aux3=aux2;
							aux2=aux;
							aux=aux->liga;
						}	
					}
					
				}
        		break;
        	case 14://Eliminar despues de x CHECAR
        	    if(p==NULL)
				{
					cout<<"La lista esa vacia\n";
				}
				else
				{
					cout<<"Ingresa el valor de x: \n";
					cin>>x;

					if(x==f->dato)
					{
						cout<<"No es posible eliminar por que es el ultimo nodo\n";
					}
					else
					{
						aux=p->liga;
						aux2=p;
						while(aux2->liga!=NULL)
						{
							if(x==aux2->dato)
							{
	
								aux2->liga=aux->liga;
								aux->liga=NULL;
								delete(aux);
								break;
							}
							aux=aux->liga;
							aux2=aux2->liga;
						}	
					}
				}
        		break;
 	   }
    }
}

