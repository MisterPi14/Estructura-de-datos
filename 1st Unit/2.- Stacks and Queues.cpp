//Pilas
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void Lifo(int[],int);
void Fifo(int[],int);
void eliminarHuecos(int[],int);

int main()
{
	int op,pila[8]={0};
	
	cout<<"***1.-Estructura PILA Tipo LIFO || 2.-Estructura COLA Tipo FIFO***\n\n...:";
	cin>>op;
	if(op==1)
	{
		Lifo(pila,-1);
	}
	else if(op==2)
	{
		Fifo(pila,-1);
	}
	else
	{
		cout<<"Ingrese una opcion valida\n";
	}
}

void Lifo(int pila[8],int cima)
{
	int dato,ope,i;
	
	cout<<"\nMENU\n1.-Push (entrada)\n2.-Pop(salida)\n3.-Impresion\n4.-Salir al menu\n";
	cin>>ope;
	switch(ope)
	{
		case 1:
			if(cima<7)
			{
				cout<<"ingrese el dato:\n";
				cin>>dato;
				cima++;
				pila[cima]=dato;
				cout<<"Se ingreso el dato a la pila\n";
				Lifo(pila,cima);	
			}
			else
			{
				cout<<"La pila ya esta llena\n";
				Lifo(pila,cima);	
			}

			break;
		case 2:
			if(cima>=0)
			{
				cout<<"El dato "<<pila[cima]<<" ha sido eliminado de la pila\n";
				pila[cima]=0;
				cima--;
				Lifo(pila,cima);	
			}
			else
			{
				cout<<"La pila ya esta vacia\n";
				Lifo(pila,cima);
			}

			break;
		case 3:
			if(cima>=0)
			{
				cout<<"Pila\n";
				for(i=7;i>=0;i--)
				{
					cout<<i<<".- "<<pila[i]<<"\n";
				}
				Lifo(pila,cima);	
			}
			else
			{
				cout<<"La pila esta vacia\n";
				Lifo(pila,cima);
			}
			break;
		case 4:
			main();
			break;
		default:
				cout<<"Ingrese una opcion valida\n";
				Lifo(pila,cima);
			break;
	}
}

void Fifo(int pila[8],int fin)
{
	int dato,ope,i;
	
	cout<<"\nMENU\n1.-Entrada\n2.-Salida\n3.-Impresion\n4.-Salir al menu\n";
	cin>>ope;
	switch(ope)
	{
		case 1:
			if(fin<7)
			{
				cout<<"ingrese el dato:\n";
				cin>>dato;
				fin++;
				pila[fin]=dato;
				cout<<"Se ingreso el dato a la cola\n";
				Fifo(pila,fin);	
			}
			else
			{
				cout<<"La cola ya esta llena\n";
				Fifo(pila,fin);	
			}

			break;
		case 2:
			if(fin>=0)
			{
				cout<<"El dato "<<pila[0]<<" ha sido eliminado de la cola\n";
				pila[0]=0;
				eliminarHuecos(pila,fin);
				fin--;
				Fifo(pila,fin);	
			}
			else
			{
				cout<<"La cola ya esta vacia\n";
				Fifo(pila,fin);
			}

			break;
		case 3:
			if(fin>=0)
			{
				cout<<"cola\n";
				for(i=0;i<=7;i++)
				{
					cout<<i<<" ";
				}
				cout<<"\n";
				for(i=0;i<=7;i++)
				{
					cout<<pila[i]<<" ";
				}
				Fifo(pila,fin);	
			}
			else
			{
				cout<<"La cola esta vacia\n";
				Fifo(pila,fin);
			}
			break;
		case 4:
			main();
			break;
		default:
				cout<<"Ingrese una opcion valida\n";
				Fifo(pila,fin);
			break;
	}
}

void eliminarHuecos(int x[8],int fin)
{
	int array_aux[8]={0};
	int j=0;
	
	for (int i=0;i<=fin;i++)
	{
		if(x[i]!=0)
		{
			array_aux[j]=x[i];
			j++;
		}		
	}
	
	for (int i=0;i<=fin;i++)
	{
		x[i]=0;
	}
	for (int i=0;i<=fin;i++)
	{
		x[i]=array_aux[i];
	}
}
