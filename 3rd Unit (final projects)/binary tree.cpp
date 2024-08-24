#include <iostream>
#include <iomanip>
using namespace std;
void creaArbol(struct nodo*);
void preOrden(struct nodo*);
void inOrden(struct nodo*);
void postOrden(struct nodo*);
///////////////////////////
void sumatoria(struct nodo*);
void contador(struct nodo*);
void promedio(struct nodo*);
void maximo(struct nodo*);
void busqueda(struct nodo*);

struct nodo
{
	int dato;
	nodo *izq,*der;
};
float suma=0,cont=0,n=0,prom=0,mayor=0;
bool found=0;
int main()
{
	int op;

	nodo *raiz;
	raiz=new(nodo);
	creaArbol(raiz);
	cout<<"\n\nRecorrido Pre Orden: ";
	preOrden(raiz);
	cout<<"\n\nRecorrido In Orden: ";
	inOrden(raiz);
	cout<<"\n\nRecorrido Post Orden: ";
	postOrden(raiz);
	while(1)
	{
		cout<<"\n//////////Menu//////////\n";
		cout<<"\n1.-Sumatoria";
		cout<<"\n2.-Promedio";
		cout<<"\n3.-Maximo";
		cout<<"\n4.-Busqueda";
		cout<<"\n";
		cin>>op;
		switch(op)
		{
			case 1:
				sumatoria(raiz);
				cout<<"La sumatoria de todo el arbol es: "<<suma;
				suma=0;
				break;		
			case 2:
				promedio(raiz);
				cout<<"El promedio de todo el arbol es: "<<prom;
				break;		
			case 3:
				promedio(raiz);
				maximo(raiz);
				cout<<"El numero mas grande en el arbol es: "<<mayor;
				break;
			case 4:
				cout<<"Ingresa el numero que deseas buscar ";
				cin>>n;
				busqueda(raiz);
				if(found==1)
				{
					cout<<"El dato fue encontrado";
				}
				else
				{
					cout<<"No se encontro el dato";
				}
				found=0;
				break;
			default:
				cout<<"\ningresa una opcion valida.\n";
		}
	}

}
void creaArbol(struct nodo *raiz)
{
	int resp;
	nodo *nuevo;
	cout<<"Ingresa el valor: ";
	cin>>raiz->dato;
	cout<<"El nodo "<<raiz->dato<<" tiene hijo a la izquierda? 1=Si 0=No";
	cin>>resp;
	if(resp==1)//afirmativo
	{
		nuevo=new(nodo);
		raiz->izq=nuevo;
		creaArbol(nuevo);
	}	
	else
	{
		raiz->izq=NULL;
	}
	cout<<"El nodo "<<raiz->dato<<" tiene hijo a la derecha? 1=Si 0=No";
	cin>>resp;
	if(resp==1)//afirmativo
	{
		nuevo=new(nodo);
		raiz->der=nuevo;
		creaArbol(nuevo);
	}
	else
	{
		raiz->der=NULL;
	}
}
void preOrden(struct nodo*raiz)
{
	if(raiz!=NULL)
	{
	cout<<raiz->dato<<" ";
	preOrden(raiz->izq);
	preOrden(raiz->der);
	}
}

void inOrden(struct nodo *raiz)//rama izquierda, raiz, rama derecha
{
	if(raiz!=NULL)
	{
		inOrden(raiz->izq);
		cout<<raiz->dato<<" ";
		inOrden(raiz->der);
	}
}
void postOrden(struct nodo *raiz)//rama izquierda, rama derecha, raiz
{
	if(raiz!=NULL)
	{
		postOrden(raiz->izq);
		postOrden(raiz->der);
		cout<<raiz->dato<<" ";
	}
}
void sumatoria(struct nodo* raiz)
{
	if(raiz!=NULL)
	{
		suma=raiz->dato+suma;	
		sumatoria(raiz->izq);
		sumatoria(raiz->der);
	}
}
void contador(struct nodo* raiz)
{
	if(raiz!=NULL)
	{
		cont++;
		contador(raiz->izq);
		contador(raiz->der);
	}
}
void promedio(struct nodo* raiz)
{
	sumatoria(raiz);
	contador(raiz);
	prom = suma/cont;
}
void maximo(struct nodo* raiz)
{
	if(raiz!=NULL)
	{
		if(raiz->dato>=prom && raiz->dato>=mayor)
		{
			mayor=raiz->dato;
		}
		maximo(raiz->izq);
		maximo(raiz->der);
	}
}
void busqueda(struct nodo* raiz)
{
	if(raiz!=NULL)
	{
		if(raiz->dato==n)
		{
			found=1;
		}
		busqueda(raiz->izq);
		busqueda(raiz->der);
	}
}

/*
la funcion pre orden debe imprimir los nodos de la izquierda y despues se va con los de la derecha

El programa genera los arboles empezando por la izquierda, despues hace uso de la recursion viendo a todos los nodos como raices
para llenar la parte derecha de cada nodo

En los arboles se le dice recorrido a la accion de pasar por los nodos para imprimir el contenido
*/
