#include<iostream>
#include<time.h>
#include <stdlib.h>

using namespace std;

struct nodo
{
	int dato;
	nodo *der,*izq;
};
void Contar_Nodos(void);
void Burbuja_pirata(void);
//Variables
int opc,n,i,j,k,l,suma,d,band,x,cont,temp,menor,menorImp;
nodo *p=NULL,*f=NULL,*aux,*aux2,*aux3,*aux4,*nuevo,*Impr;

int main()
{
   srand(time(NULL));				//1+rand()%100
   while(1)
   {
        cout<<"\n\n* * * * * * * MENU * * * * * * *\n";
        cout<<"0.- Imprimir de inicio a fin\n";
        cout<<"1.- Imprimir de fin a inicio\n";
        cout<<"2.- Insertar un dato al final\n";
        cout<<"3.- Insertar un dato al inicio\n";
        cout<<"4.- Insertar aleatorios derecha\n";//de aqui a delante
        cout<<"5.- Insertar aleatorios izquierda\n";
        cout<<"6.- Insertar consecutivos de 1 a n (de izq a der)\n";
        cout<<"7.- Insertar consecutivos de 1 a n (de der a izq)\n";
		cout<<"8.- Eliminar Inicio\n";
		cout<<"9.- Eliminar Final\n";
		cout<<"10.- Busqueda\n";
		cout<<"11.- Eliminar x\n";
		cout<<"12.- Metodo Burbuja Ascendente\n";
		cout<<"13.- Shakersort\n";
		cout<<"14.- Inserccion directa\n";
		cout<<"15.- Seleccion directa\n";
		cout<<".-\n";
		cout<<".-\n";
		cout<<".-\n";
		cout<<".-\n";
        cout<<"\n   * * * * Seleccione una opción: ";
        cin>>opc;
        
       switch(opc)
       {
        case 0://Imprimir de izquierda a derecha
			aux=p;
			if(aux==NULL)
			{
				cout<<"Lista vacia\n";
			}
			else
			{
				cout<<"***Contenido de la lista***\n";
				while(aux!=NULL)
				{
					cout<<aux->dato<<" ";
					aux=aux->der;
				}
				cout<<"\n\n";
			}
               break;
    	case 1://Imprimir de derecha a izquierda
               aux=f;
               if(aux=NULL)
			   {
			   		cout<<"***Lista vacia***";
			   }
			   else
			   {
			   		cout<<"***Contenido de la lista***";
			   		while(aux!=NULL)
					{
						cout<<aux->dato<<" ";
						aux=aux->izq;		   	
				    }
				    cout<<"\n\n";
			   }
           break;
        case 2://Insertar a la derecha
        	if(p==NULL)
			{
				p=new(nodo);
				cout<<"Ingresa el dato: ";
				cin>>p->dato;
				p->der=NULL;
				p->izq=NULL;
				f=p;
			}
			else
			{
				aux=new(nodo);
				cout<<"Ingresa el dato: ";
				cin>>aux->dato;
				aux->der=NULL;
				aux->izq=f;
				f->der=aux;
				f=aux;
			}
        	break;
       	case 3: //Insertar a la izquierda
       			if(p==NULL)
				   {
				   		p=new(nodo);
				   		cout<<"Ingrese el dato: ";
				   		cin>>p->dato;
				   		p->der=NULL;
				   		p->izq=NULL;
				   		f=p;
				   }
				   else
				   {
				   		aux=new(nodo);
				   		cout<<"Ingresa el dato";
				   		cin>>aux->dato;
				   		aux->der=p;
				   		p->izq=aux;
				   		aux->izq=aux;
				   		p=aux;
				   }
				break;
        case 4://Insertar aleatorios derecha
			cout<<"Cuantos datos requiere? \n";
	        cin>>n;
	        for(i=0; i<n; i++)
			{
				if(p==NULL)
			    {
			    	p=new(nodo);
			    	p->dato=1+rand()%100;
				   	p->der=NULL;
				   	p->izq=NULL;
				   	f=p;
				}
				else
				{
					aux=new(nodo);
					aux->dato=1+rand()%100;
					f->der=aux;
					aux->izq=f;
					aux->der=NULL;
					f=aux;
				}
			}
        	break;
		case 5://Insertar aleatorios izquierda
			cout<<"Cuantos datos requiere? \n";
	        cin>>n;
	        for(i=0; i<n; i++)
			{
				if(p==NULL)
			    {
			    	p=new(nodo);
			    	p->dato=1+rand()%100;
				   	p->der=NULL;
				   	p->izq=NULL;
				   	f=p;
				}
				else
				{
					aux=new(nodo);
					aux->dato=1+rand()%100;
					p->izq=aux;
					aux->der=p;
					aux->izq=NULL;
					p=aux;
				}
			}	
        	break;
        case 6://Insertar consecutivos derecha
	        cout<<"Ingrese el valor de n\n";
	        cin>>n;
	        for(i=0; i<n; i++)
			{
				if(p==NULL)
			    {
			    	p=new(nodo);
			    	p->dato=i+1;
				   	p->der=NULL;
				   	p->izq=NULL;
				   	f=p;
				}
				else
				{
					aux=new(nodo);
					aux->dato=i+1;
					f->der=aux;
					aux->izq=f;
					aux->der=NULL;
					f=aux;
				}
			}
        	break;
        case 7://Insertar consecutivos izquierda
	        cout<<"Ingrese el valor de n\n";
	        cin>>n;
	        for(i=0; i<n; i++)
			{
				if(p==NULL)
			    {
			    	p=new(nodo);
			    	p->dato=i+1;
				   	p->der=NULL;
				   	p->izq=NULL;
				   	f=p;
				}
				else
				{
					aux=new(nodo);
					aux->dato=i+1;
					p->izq=aux;
					aux->der=p;
					aux->izq=NULL;
					p=aux;
				}
			}
        	break;
        case 8: //Eliminar inicio
        	if(p==NULL)
			{
			 	cout<<"***Lista vacia***";
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
					p=p->der;
					p->izq=NULL;
					aux->der=NULL;
					delete(aux);
				}
			}
        	break;
        case 9://Eliminra final
        	if(p==NULL)
			{
			 	cout<<"***Lista vacia***";
			}
			else
			{
				aux=f;
				if(aux==p && aux==f)
				{
				 	delete(aux);
				 	p=NULL;
				}
				else
				{
					f=aux->izq;
					aux->izq=NULL;
					f->der=NULL;
					delete(aux);
				}
			}
        	break;
        case 10://Busqueda
        	if(p==NULL)
			{
			 	cout<<"***Lista vacia***";
			}
			else
			{
				band=0;
				cout<<"Ingresa el dato a buscar: ";
				cin>>d;
				aux=p;
				while(aux!=NULL)
				{
					if(d==aux->dato)
					{
						band=1;
						cout<<"***Dato encontrado en la lista***\n";
						break;
					}
					aux=aux->der;
				}
				if(band==0)
				{
					cout<<"***Dato NO encontrado en la lista***\n";
				}
			}
        	break;
        case 11://Eliminar x
        	cout<<"Ingrese el valor de x: ";
        	cin>>x;
			if(p==NULL)
			{
			 	cout<<"***Lista vacia***";
			}
			else
			{
				if(x==p->dato)//si x es el nodo p
				{	
					aux=p;
					if(aux==p && aux==f)
					{
					 	delete(aux);
					 	p=NULL;
					}
					else
					{
						p=p->der;
						p->izq=NULL;
						aux->der=NULL;
						delete(aux);
					}	
				}
				else if(x==f->dato)//si x es el nodo f
				{
					aux=f;
					if(aux==p && aux==f)
					{
					 	delete(aux);
					 	p=NULL;
					}
					else
					{
						f=aux->izq;
						aux->izq=NULL;
						f->der=NULL;
						delete(aux);
					}
				}
				else
				{
					aux=p->der;
					band=0;
					while(aux->der!=NULL)
					{
						if(x==aux->dato)
						{
							cout<<"Dato encontrado\n\teliminando...";
							band=1;
							//Creando aux 2 y 3
							aux2=aux->izq;
							aux3=aux->der;
							//vinculando aux 3 y 2
							aux2->der=aux->der;
							aux3->izq=aux->izq;
							//eliminando conexiones de aux
							aux->der=NULL;
							aux->izq=NULL;
							delete(aux);//eliminamos aux
							break;
						}
						aux=aux->der;
					}
					if(band==0)
					{
						cout<<"Dato No encontrado";
					}
				}
			}
        	break;
       	case 12://Metodo Bubuja ascendente
        	if(p==NULL)
			{
				cout<<"***Lista Vacia***\n";
			}
			else
			{
			 	Contar_Nodos();
				cout<<"Total de datos: "<<cont<<"\n";
				cout<<"Metodo bubuja\n";
				for(i=1; i<cont; i++)//pasadas
				{
					aux=p;
					aux2=aux->der;
					for(j=1; j<cont; j++)
					{
						if(aux->dato>aux2->dato)
						{
							temp=aux->dato;
							aux->dato=aux2->dato;
							aux2->dato=temp;
						}
						aux=aux2;
						aux2=aux2->der;
					}
				}
			}
			
        	break;
       	case 13://Shakersort
       	    if(p==NULL)
			{
				cout<<"***Lista Vacia***\n";
			}
			else
			{
				Contar_Nodos();
				int final=cont,ini=0;
				cout<<"\n	*** Shaker Sort ***\n";
				for(i=0;i<cont/2;i++)// pasadas
				{
					cout<<"\nPasada "<<i+1<<"\n";
					cout<<"\nDerecha a izq\n";
					////Repitiendo iniciacion de aux 2 y 3 (los ultimos de la lista) 
					j=final;
					aux3=f->izq;
					aux4=f;
					for(int a=0; a<i; a++)//ajustando los aux a el decremento de la variable final 
					{
						if(aux3->der!=NULL)
							aux3=aux3->izq;
							aux4=aux4->izq;
					}
					while(j>ini+1)//derecha a izquierda
					{
						cout<<aux4->dato<<" < "<<aux3->dato;
						if(aux4->dato<aux3->dato)
						{
							cout<<"\tVerdadero\t";
							temp=aux4->dato;
							aux4->dato=aux3->dato;
							aux3->dato=temp;
							Impr=p;
							for(l=0;l<cont;l++)
							{
								cout<<Impr->dato<<" ";
								Impr=Impr->der;
							}
							cout<<"\n";
						}
						else
						{
							cout<<"\tFalso\t";
							Impr=p;
							for(l=0;l<cont;l++)
							{
								cout<<Impr->dato<<" ";
								Impr=Impr->der;
							}
							cout<<"\n";
						}
						j--;
						if(aux3->izq!=NULL)
							aux3=aux3->izq;
							aux4=aux4->izq;						
					}
					cout<<"\nIzq a Der\n";
					k=ini+1;
					aux=p->der;
					aux2=aux->der;
					for(int a=0; a<i; a++)//ajustando los aux a el decremento de la variable ini 
					{
						if(aux->der!=NULL)
							aux=aux->der;
							aux2=aux2->der;
					}
					while(k<final-1)//izquierda a derecha
					{
						cout<<aux->dato<<" > "<<aux2->dato;
						if(aux->dato>aux2->dato)
						{
							cout<<"\tVerdadero\t";
							temp=aux->dato;
							aux->dato=aux2->dato;
							aux2->dato=temp;
							Impr=p;
							for(l=0;l<cont;l++)
							{
								cout<<Impr->dato<<" ";
								Impr=Impr->der;
							}
							cout<<"\n";
						}
						else
						{
							cout<<"\tFalso\t";
							Impr=p;
							for(l=0;l<cont;l++)
							{
								cout<<Impr->dato<<" ";
								Impr=Impr->der;
							}
							cout<<"\n";
						}
						k++;
						if(aux2->der!=NULL)
							aux=aux->der;
							aux2=aux2->der;
					}
					ini++;
					final--;	
					}
			}
       	/*
       	void Shakersort(int x[],int up)
{
	int i,j,k,l,aux,final=up,ini=0;
	if(up==-1)
	{
		cout<<"	*** No hay datos en el arreglo  ***\n";
	}
	else
	{
		cout<<"\n	*** Shaker Sort ***\n";
		for(i=0;i<up;i++)// pasadas
		{
			cout<<"\nPasada "<<i+1<<"\n";
			cout<<"\nDerecha a izq\n";
			j=final;
			while(j>ini)//derecha a izquierda
			{
				cout<<x[j]<<" < "<<x[j-1];
				if(x[j]<x[j-1])
				{
					cout<<"\tV\t";
					aux=x[j];
					x[j]=x[j-1];
					x[j-1]=aux;
					for(l=0;l<=up;l++)
					{
						cout<<x[l]<<"	";
					}
					cout<<"\n";
				}
				else
				{
					cout<<"\tF\t";
					for(l=0;l<=up;l++)
					{
						cout<<x[l]<<"	";
					}
					cout<<"\n";
				}
				j--;
			}
			cout<<"\nIzq a Der\n";
			k=ini+1;
			while(k<final)//izquierda a derecha
			{
				cout<<x[k]<<" > "<<x[k+1];
				if(x[k]>x[k+1])
				{
					cout<<"\tV\t";
					aux=x[k];
					x[k]=x[k+1];
					x[k+1]=aux;
					for(l=0;l<=up;l++)
					{
						cout<<x[l]<<"	";
					}
					cout<<"\n";
				}
				else
				{
					cout<<"\tF\t";
					for(l=0;l<=up;l++)
					{
						cout<<x[l]<<"	";
					}
					cout<<"\n";	
				}
				k++;
			}
			if(ini==final-1)
			{
				i=up;
			}
			ini++;
			final--;	
		}
	}
}

       	*/
        	break;
        case 14: //Inserccion directa
			if(p==NULL)
			{
				cout<<"	*** No hay datos en el arreglo  ***\n";
			}
			else
			{
				Contar_Nodos();
				for(i=0;i<cont;i++)
				{
					aux=p;
					aux2=p->der;
					//Recorriendo aux 1y2 a la derecha i veces
					for(int a=0;a<i;a++)
					{
						aux=aux->der;
						if(aux2!=f)
						aux2=aux2->der;
					}
					cout<<"\nPasada "<<i+1<<"\n";

					//haciendo comparaciones desde el i nodo hacia la izquierda
					while(aux2!=p)//tener cuidado habia puesto do while pensando que la comparacion d p y p+1 se compilara aunque while() fuera falso, se compila pero no se toma en cuenta al final del dia
					{
						cout<<aux2->dato<<" < "<<aux->dato;
						if(aux2->dato<aux->dato)
						{
							cout<<"\tVerdadero \t";
							//Canmbio de posicion
							temp=aux2->dato;
							aux2->dato=aux->dato;
							aux->dato=temp;
							//Impresion
							Impr=p;
							for (k = 0; k < cont; k++)
							{
						 		cout <<Impr->dato<<" ";
						 		Impr=Impr->der;
							}
							cout << "\n\n";
							//recorriendo a la izquierda los aux salvo que aux sea p puesto que ya no hay nada antes
							if(aux!=p)
							aux=aux->izq;
							aux2=aux2->izq;
						}
						else
						{
							cout<<"\tFalso \t";
							//Impresion
							Impr=p;
							for (k = 0; k < cont; k++)
							{
						 		cout <<Impr->dato<<" ";
						 		Impr=Impr->der;
							}
							cout << "\n\n";
							break;	
						}
							
					}
						
					if(aux2!=f)//recorriendo l a la derecha salvo que aux 2 sea f pues despues no hay nada
					{
						aux=aux->der;
						aux2=aux2->der;		
					}
				}
			}
        	break;
        case 15://Seleccion directa
			if(p==NULL)
			{
			    cout <<"Lista vacia\n";
		 	}
		 	else 
			{
			 	cout << "\t\t***Seleccion directa\n";
			 	//Contando
			 	Contar_Nodos();
				//metodo sel
				aux=p;
				cout<<"****Numero de datos: "<<cont<<"****\n\n";
				menor = aux->dato;
				menorImp = menor;
			  	for (int i = 0; i < cont; i++) 
				{	
					//Imprimiendo el proceso
					cout << "Numero menor: " <<menorImp<< "\tLista: ";
					Impr=p;
					for (k = 0; k < cont; k++)
					{
				 		cout <<Impr->dato<<" ";
				 		Impr=Impr->der;
					}
					cout << "\n\n";
					//Metodo
					menor = aux->dato, band=0, aux2=aux->der;
					if(aux->der!=NULL)
					{
						menorImp=aux2->dato;
					}
				    for (int j = (i + 1); j < cont; j++) 
					{
					    if (aux2->dato < menor) 
						{
					        menor = aux2->dato;
					        aux3=aux2;
					    	band=1;
					    }
						aux2=aux2->der;
				    }
				    if (band==1)
					{
						aux3->dato=aux->dato;
						aux->dato=menor;
				    }
					aux=aux->der;
	    		}	
			}
        	break; 	
 	   }
    }
}

void Contar_Nodos()
{
	cont=0;
	aux=p;
	while(aux!=NULL)
	{
		cont++;
		aux=aux->der;
	}
}

void Burbuja_pirata()
{
	Contar_Nodos();
	for(i=1; i<cont; i++)//pasadas
	{
		aux=p;
		aux2=aux->der;
		for(j=1; j<cont; j++)
		{
			if(aux->dato>aux2->dato)
			{
				temp=aux->dato;
				aux->dato=aux2->dato;
				aux2->dato=temp;
			}
			aux=aux2;
			aux2=aux2->der;
		}
	}	
}



