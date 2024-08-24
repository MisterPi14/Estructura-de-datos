//Operaciones con Arreglos
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
void imprime(int []);
int iniManu(int [],int);
int iniAlea(int [],int);
int iniN(int [],int);
int sumatoria(int [], int);
void valorMax(int [],int);
void valorMin(int [],int);
void busqueda(int [],int,int);
float promedio(int [],int);
void mayoresProm(int [],int);
int insertaPosCero(int [],int);
int insertaPosFinal(int[],int);
int insertaBloqueIni(int[],int,int);
int insertaBloqueFinal(int[],int,int);
int insertaBloqueNPos(int[],int,int,int);
int eliminarPrim(int[],int);
int eliminarUlt(int[],int);
int eliminarPares(int[],int);
int eliminarBusqueda(int[],int);
void actualizarBusqueda(int[],int);
void eliminarHuecos(int[],int);
void burbuja(int[],int);
void Shakersort(int[],int);
void Inserccion_Directa(int[],int);
void Seleccion_Directa(int[],int);
int TipoC(int [],int);
void TipoD(int [],int);

int main()
{
    int datos[20]={0},n,up=-1, res, opc,d,x, pos;
    float res2;
    srand(time(NULL));//Para que cada vez que se use la funci�n "rand" genere datos diferentes
    while(1)
    {
        cout<<"                MENU\n";
        cout<<"-------------------------------------\n";
        cout<<"0.  Impresi�n\n";
        cout<<"1.  Inicializaci�n manual\n";
        cout<<"2.  Inicializaci�n aleatoria\n";
        cout<<"3.  Inicializaci�n con N\n";
        cout<<"4.  Sumatoria del arreglo\n";
        cout<<"5.  M�ximo\n";
        cout<<"6.  M�nimo\n";
        cout<<"7.  B�squeda\n";
        cout<<"8.  Promedio\n";
        cout<<"9.  Mayores al promedio\n";
        cout<<"10. Insertar en la primera posicision\n";
        cout<<"11. Inserta en la posici�n final\n";
        cout<<"12. Insertar un bloque al inicio\n";
        cout<<"13. Insertar un bloque al final\n";
        cout<<"14. Insertar un bloque en la posicion n\n";
        cout<<"15. Eliminar dato inicial\n";
        cout<<"16. Eliminar dato final\n";
        cout<<"17. Eliminar datos pares\n";
        cout<<"18. Buscar y eliminar\n";
        cout<<"19. Buscar y actualizar\n";
        cout<<"20. Metodo burbuja\n";
        cout<<"21. Shakersort\n";
        cout<<"22. Inserccion Directa\n";
        cout<<"23. Seleccion Directa\n";
        cout<<"************Examenes*************\n";
        cout<<"24. Examen Tipo C\n";
        cout<<"25. Examen Tipo D\n";
        cout<<"100. Salir\n";
        cout<<"\n    Selecciona una opcion: ";
        cin>>opc;
        switch(opc)
        {
            case 0://Impresi�n del arreglo
                imprime(datos);
                break;
            case 1://Inicializaci�n manual
                cout<<"    �Cu�ntos datos deseas ingresar?: ";
                cin>>n;
                if(n<=20)
                {
                    up=iniManu(datos,n);
                    cout<<"Ultima posici�n usada: "<<up<<"\n";
                }
                else
                    cout<<"    * * * Se excede el tama�o del arreglo * * *\n";
                break;
            case 2://Inicializaci�n aleatoria
                cout<<"    �Cu�ntos datos deseas ingresar?: ";
                cin>>n;
                if(n<=20)
                    up=iniAlea(datos,n);
                else
                    cout<<"    * * * Se excede el tama�o del arreglo * * *\n";
                break;
            case 3://Inicializaci�n con N
                cout<<"    �Cu�ntos datos deseas ingresar?: ";
                cin>>n;
                if(n<=20)
                    up=iniN(datos,n);
                else
                    cout<<"    * * * Se excede el tama�o del arreglo * * *\n";
                break;
            case 4://Sumatoria
                res=sumatoria(datos,n);
                cout<<"El resultado de la sumatoria es: "<<res<<"\n";
                break;
            case 5://Valor m�ximo
                valorMax(datos,n);
                break;
            case 6://Valor m�nimo
                valorMin(datos,n);
                break;
            case 7://B�squeda
                cout<<"    Ingresa el dato a buscar: ";
                cin>>d;
                busqueda(datos,n,d);
                break;
            case 8://Promedio
                res=promedio(datos,n);
                cout<<"El promedio es: "<<res<<"\n";
                break;
            case 9://Mayores al promedio
                mayoresProm(datos,n);
                break;
            case 10:
            	up=insertaPosCero(datos,up);
        		break;
        	case 11:
        		up=insertaPosFinal(datos,up);
        		break;
        	case 12:
        		cout<<"Cual es el numero de datos para el bloque?";
        		cin>>n;
        		up=insertaBloqueIni(datos,up,n);
        		break;
        	case 13:
        		cout<<"Cual es el numero de datos para el bloque?";
       			cin>>n;
        		up=insertaBloqueFinal(datos,up,n);
        		break;
        	case 14:
        		cout<<"A partir de que posicion desea insertar el bloque?";
        		cin>>pos;
        		cout<<"De que tama�o desea que sea?";
        		cin>>n;
        		up=insertaBloqueNPos(datos,up,n,pos);
        		break;
        	case 15:
        		up=eliminarPrim(datos,up);
        		break;
        	case 16:
        		up=eliminarUlt(datos,up);
        		break;
        	case 17:
        		up=eliminarPares(datos,up);
        		break;
       		case 18:
        		up=eliminarBusqueda(datos,up);
        		break;
        	case 19:
        		actualizarBusqueda(datos,up);
        		break;
        	case 20:
        		burbuja(datos,up);
        		break;
        	case 21:
        		Shakersort(datos,up);
        		break;
        	case 22:
        		Inserccion_Directa(datos,up);
        		break;
        	case 23:
        		Seleccion_Directa(datos,up);
        		break;
        	case 24:
        		TipoC(datos,up);
        		break;
        	case 25:
        		TipoD(datos,up);
        		break;
       }
    }
}


void imprime(int x[20])
{
    int i;
    cout<<"    Contenido del arreglo\n";
    cout<<"    Sub�ndice    Valor almacenado\n";
    for(i=0; i<20; i++)
        cout<<"        "<<i<<"\t\t\t\t"<<x[i]<<"\n";
 }
int iniManu(int x[20],int n)
{
    int i,up;
    for(i=0; i<n; i++)
    {
        cout<<"   Ingresa el valor de datos["<<i<<"]: ";
        cin>>x[i];
    }
    up=n-1;
    return up;
}
int iniAlea(int x[20],int n)
{
    int i,up;
    for(i=0; i<n; i++)
        x[i]=1+rand()%100;
    up=n-1;
    return up;
}
int iniN(int x[20],int n)
{
    int i,ini,up;
    cout<<"    Ingresa el valor de inicializaci�n: ";
    cin>>ini;
        for(i=0; i<n; i++)
            x[i]=ini;
    up=n-1;
    return up;
}
int sumatoria(int x[20],int n)
{
    int i,suma=0;
    for(i=0; i<n; i++)
        suma=suma+x[i];
    return suma;
}
void valorMax(int x[20],int n)
{
    int i, max, pmax;
    max=x[0];
    for(i=1; i<n; i++)
    {
        if(x[i]>max)
        {
            max=x[i];
            pmax=i;
        }
    }
    cout<<"El valor m�ximo encontrado es: "<<max<<" y est� en el sub�ndice: "<<pmax<<"\n";
}
void valorMin(int x[20],int n)
{
    int i, min, pmin;
    min=x[0];
    for(i=1; i<n; i++)
    {
        if(x[i]<min)
        {
            min=x[i];
            pmin=i;
        }
    }
    cout<<"El valor m�ximo encontrado es: "<<min<<" y est� en el sub�ndice: "<<pmin<<"\n";
}
void busqueda(int x[20],int n, int d)
{
    int i,band,sub;
    band=0;
    i=0;
    while(i<n)
    {
        if(d==x[i])
        {
            band=1;
            sub=i;
            break;
        }
        i++;
    }
    if(band==1)
        cout<<"    Dato encontrado en el sub�ndice: "<<sub<<"\n";
    else
        cout<<"    Dato NO encontrado\n";
}
float promedio(int x[20],int n)
{
    int r;
    float prom;
    r=sumatoria(x,n);
    prom=r/n;
    return prom;
}
void mayoresProm(int x[20],int n)
{
    int i;
    float prom;
    prom=promedio(x,n);
    cout<<"    El promedio es: "<<prom<<"\n";
    cout<<"    Datos mayores al promedio: ";
    for(i=0; i<n; i++)
    {
        if(x[i]>prom)
            cout<<x[i]<<", ";
    }
}

int insertaPosCero(int x[20],int up)
{
	int i,uSub;
	if(up==-1)
	{
		cout<<"Inserta el valor de datos [0]";
		cin>>x[0];
		up++;
	}
	else
	{
		if(up<19)
		{
			up++;
			for(i=up; i>0; i--)
			x[i]=x[i-1];
			cout<<"Inserta el valor de datos[0]";
			cin>>x[0];
		}
		else
		{
			cout<<"		***Se exede el tama�o del arreglo***\n";
		}
	}
	uSub=up;
	return uSub;
}

int insertaPosFinal(int x[20],int up)
{
	int uSub;
	if(up==-1)
	{
		cout<<"Inserta el valor de datos[0]";
		cin>>x[0];
		up++;
	}
	else
	{
		if(up<19)
		{
			up++;
			cout<<"Inserta el valor de datos["<<up<<"]:";
			cin>>x[up];
		}
		else
		{
			cout<<"		***Se exede el tama�o del arreglo***\n";
		}
	}
	uSub=up;
	return uSub;
}

int insertaBloqueIni(int x[20],int up,int n)
{
	int uSub,i,temp,j;
	if(up==-1)
	{
		up=iniAlea(x,n);
	}
	else
	{
		temp=up+n;
		if(temp<=19)
		{
			//moviendo posisiones ocupadas adelante
			for(i=1; i<=n; i++)
			{
				up++;
				for(j=up; j>0; j--)//aqui es >0 por que es el recorrido de todo el arreglo
				x[j]=x[j-1];
			}
			//llenando espacios vacios con los nuevos valores
			for(i=0; i<n; i++)
			x[i]=1+rand()%100;
		}
		else
		{
			cout<<"No es posible por que exede el limite del arreglo";
		}
	}
	uSub=up;
	return uSub;
}

int insertaBloqueFinal(int x[20],int up,int n)
{
	if(up+n<20)
	{
		for(int i=up+1; i<=(up+n); i++)
		x[i]=1+rand()%100;
	}
	else
	{
		cout<<"El numero supera las dimensiones del arreglo";
	}
}

int insertaBloqueNPos(int x[20],int up,int n,int pos)
{
	if((n+up)<=19)
	{
		if(up==-1)
		{
			for(int i=pos; i<pos+n; i++)
	        x[i]=1+rand()%100;
		}
		else
		{
			if(up>=pos)
			{
				for(int a=1; a<=n; a++)
				{
					up++;
					for(int j=up;j>pos-1;j--)//tambien puede ser >=pos y es pos por que es el recorrido hasta la posicion n que da el usuario
					x[j]=x[j-1];
				}
				
				for(int i=pos; i<pos+n; i++)
	        	x[i]=1+rand()%100;
			}
			else
			{
				for(int i=pos; i<pos+n; i++)
	        	x[i]=1+rand()%100;
			}
		}
		return pos+n;
	}
	else
	{
		cout<<"El tama�o exede la capacidad del arreglo";
	}
}

int eliminarPrim(int x[20],int up)
{
	cout<<"El valor inicial "<<x[0]<<" a sido eliminado";
	for(int j=0;j<=up;j++)
	{
		x[j]=x[j+1];
	}
	up--;
	return up;
}

int eliminarUlt(int x[20],int up)
{
	cout<<"El valor final "<<x[up]<<" fue eliminado.";
	x[up]=0;
	up--;
	return up;
}

int eliminarPares(int x[20],int up)
{
	int aux=up;
	for (int i=0;i<=up;i++)
	{
		if(x[i]%2==0)
		{
			x[i]=0;
			aux--;
		}
	}
	
	eliminarHuecos(x,up);
	
	return aux;
}

int eliminarBusqueda(int x[20],int up)
{
	int valor,i,aux=up;
    cout<<"Cual es el valor del numero que deseas eliminar?";
	cin>>valor;
	for(i=0; i<=up; i++)
	{
		if(x[i]==valor)
		{
			x[i]=0;
			cout<<"\t***El valor "<<valor<<", con subindice "<<i<<", fue eliminado.\n";
			aux--;
		}
	}
	if(aux==up)
	{
		cout<<"\t***No se encontro el valor solicitado\n\n";
	}
	eliminarHuecos(x,up);//eliminando huecos en el arreglo
	return aux;
}
void actualizarBusqueda(int x[20],int up)
{
	int i,valor,act;
	bool find=false;
    cout<<"Cual es el valor del numero que deseas actualizar?\n";
   	cin>>valor;
   	cout<<"Por cual valor deseas actualizarlo\n";
	cin>>act;
	for(i=0; i<=up; i++)
	{
		if(x[i]==valor)
		{
			x[i]=act;
			cout<<"\t***El valor "<<valor<<", con subindice "<<i<<", fue actualizado por "<<act<<".\n";
			find=true;
		}
	}
	if(find==false)
	{
		cout<<"\t***No se encontro el valor solicitado\n\n";
	}
}
void eliminarHuecos(int x[20],int up)
{
	int array_aux[20]={0};
	int j=0;
	
	for (int i=0;i<=up;i++)
	{
		if(x[i]!=0)
		{
			array_aux[j]=x[i];
			j++;
		}		
	}
	
	for (int i=0;i<=up;i++)
	{
		x[i]=0;
	}
	for (int i=0;i<=up;i++)
	{
		x[i]=array_aux[i];
	}
}
void burbuja(int x[20],int up)
{
	int i,j,k,aux;
	if(up==-1)
	{
		cout<<"\t\t****No hay datos en el arreglo***\n";
	}
	else
	{
		cout<<"\n\t\t***Metodo Burbuja***\n";
		for(i=0; i<up; i++)//recorrido de las pasadas
		{
			cout<<"\nPasada "<<i+1<<"\n";
			for(j=0; j<up; j++)//Comparaciones
			{
				cout<<x[j]<<" > "<<x[j+1];
				if(x[j]>x[j+1])
				{
					cout<<"\tV\t";
					aux=x[j];
					x[j]=x[j+1];
					x[j+1]=aux;
					for(k=0;k<=up;k++)
					cout<<x[k]<<"	";
					cout<<"\n";
				}
				else
				{
					cout<<"\tF\t";
					for(k=0;k<=up;k++)
					cout<<x[k]<<"	";
					cout<<"\n";
				}
			}
		}
	}
}


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

void Inserccion_Directa(int x[],int up)
{
	int i,aux,j,k,pos=1;
	if(up==-1)
	{
		cout<<"	*** No hay datos en el arreglo  ***\n";
	}
	else
	{
		for(i=0;i<up;i++)
		{
			j=i+1;
			cout<<"\nPasada "<<j<<"\n";
			while(j!=0)
			{
				cout<<x[j]<<" < "<<x[j-1];
				if(x[j]<x[j-1])
				{
					cout<<"\tVerdadero \t";
					aux=x[j];
					x[j]=x[j-1];
					x[j-1]=aux;
					for(k=0;k<=up;k++)
					cout<<x[k]<<"	";
					cout<<"\n";
					j--;
					
				}
				else
				{
					cout<<"\tFalso \t";
					for(k=0;k<=up;k++)
					cout<<x[k]<<"	";
					cout<<"\n";
					j=0;
					
				}
			}
		}
	}
}

void Seleccion_Directa(int x[], int up) 
{
	if(up<=0)
	{
	    cout << "    No hay suficientes elementos para ordenar";
	    return;
 	}

  	cout << "\t\t***Seleccion directa" << endl;
  	for (int i = 0; i < up; i++) 
	{
	    int menor = x[i], indice = -1;
	    for (int j = i + 1; j < up; j++) 
		{
	      if (x[j] < menor) 
		  {
	        menor = x[j];
	        indice = j;
	      }
	    }
	    if (indice != -1)
		{
	      int temp = x[i];
	      x[i] = x[indice];
	      x[indice] = temp;
	    }
	    
		cout << "Numero menor: " <<menor<< "\t Arreglo: ";
	    
		for (int k = 0; k < up; k++)
		{
		   cout << x[k] << " ";
		}
		cout << "\n\n";
    }
  
}

int TipoC(int x[],int up)
{
	up=iniAlea(x,20);
	for(int i=0; i<=up; i++)//haciendo recorrido por cada valor del arreglo
	{
		for(int j=2; j<x[i]; j++)//evaluando si es primo
		{
			if(x[i]%j!=0)//si se cumple es primo
			{
				x[i]=0;
			}
		}
	}
	eliminarHuecos(x,up);
}

void TipoD(int array[],int up)
{
	int x,valor,pos;
	bool disponible=false;
	cout<<"Ingresa x siendo este un valor en el arreglo, para remplazar un valor en x-1\n";
	cin>>x;
	for(int i=1; i<=up; i++)
	{
		if(array[i]==x)
		{
			disponible=true;
			pos=i-1;
		}
	}
	if(disponible==true)
	{
		cout<<"Ingresa el valor actualizado para x-1\n";
		cin>>valor;
		array[pos]=valor;
	}
	else
	{
		cout<<"El valor x no fue encontrado en el arreglo o es la primera posicion\n";
	}
}
