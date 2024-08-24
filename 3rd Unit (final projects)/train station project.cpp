#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;
struct Lineas
{
	string estacion;
	int linea;
	Lineas *sig,*ant,*tras;
}*pL4=NULL,*fL4=NULL,*pL6=NULL,*fL6=NULL,*pL9=NULL,*fL9=NULL,*aux,*aux2,*aux3;

// 4 y 9 jamaica 4 y 6 martin carrera
string L4[]={"Martin Carrera","Talisman","Bondojito","Consulado","Canal del Norte","Morelos","Candelaria","Fray Servando","Jamaica","Santa Anita"};
string L6[]={"Rosario","Tezozomoc","Azcapotzalco","Ferreria","Norte 45","Vallejo","Instituto del petroleo","Linda vista","Deportivo 18 de Marzo","La Villa Basilica","Martin Carrera"};
string L9[]={"Tacubaya","Patriotismo","Chilpancingo","Centro Medico","Lazaro Cardenas","Chabacano","Jamaica","Mixiuhca","Velodromo","Ciudad Deportiva","Puebla","Pantitlan"};
//Variables
int opc,i,j,k;
CrearLineas()
{
	//Linea 4
	for(i=0;i<10;i++)
	{
		if(pL4==NULL)
		{
			pL4=new(Lineas);
			pL4->estacion=L4[0];
			pL4->linea=4;
			pL4->sig=NULL;
			pL4->ant=NULL;
			pL4->tras=NULL;
			fL4=pL4;
		}
		else
		{
			aux=new(Lineas);
			aux->estacion=L4[i];
			aux->linea=4;
			aux->sig=NULL;
			aux->ant=fL4;
			aux->tras=NULL;
			fL4->sig=aux;
			fL4=aux;
		}
	}
	//Linea 6
	for(i=0;i<11;i++)
	{
		if(pL6==NULL)
		{
			pL6=new(Lineas);
			pL6->estacion=L6[0];
			pL4->linea=6;
			pL6->sig=NULL;
			pL6->ant=NULL;
			pL6->tras=NULL;
			fL6=pL6;
		}
		else
		{
			aux=new(Lineas);
			aux->estacion=L6[i];
			aux->linea=6;
			aux->sig=NULL;
			aux->ant=fL6;
			aux->tras=NULL;
			fL6->sig=aux;
			fL6=aux;
		}
	}
	//Linea 9
	for(i=0;i<12;i++)
	{
		if(pL9==NULL)
		{
			pL9=new(Lineas);
			pL9->estacion=L9[0];
			pL9->linea=9;
			pL9->sig=NULL;
			pL9->ant=NULL;
			pL9->tras=NULL;
			fL9=pL9;
		}
		else
		{
			aux=new(Lineas);
			aux->estacion=L9[i];
			aux->linea=9;
			aux->sig=NULL;
			aux->ant=fL9;
			aux->tras=NULL;
			fL9->sig=aux;
			fL9=aux;
		}
	}
}


Conexiones()
{
	//Linea 4
	aux=pL4; aux2=pL6; aux3=pL9;
	for(i=0;i<10;i++)
	{
		//Con linea 6
		for(j=0;j<11;j++)
		{
			if(aux->estacion==aux2->estacion)
			{
				aux->tras=aux2;
				aux2->tras=aux;
			}	
			aux2=aux2->sig;
		}
		//Con linea 9
		for(k=0;k<12;k++)
		{
			if(aux->estacion==aux3->estacion)
			{
				aux->tras=aux3;
				aux3->tras=aux;
			}
			aux3=aux3->sig;
		}
		aux=aux->sig;
		aux2=pL6; aux3=pL9;
	}
}

imprimir(Lineas *prm, int tam, int linea)
{
	aux=prm; 
	cout<<"*******Linea "<<linea<<"*******\n";
	for(i=0;i<tam;i++)
	{
		cout<<aux->estacion;
		if(aux->tras!=NULL)
		cout<<"->Linea "<<aux->tras->linea;
		cout<<"  ";
		aux=aux->sig;
	}
	cout<<"\n\n";
}

Lineas *origen=NULL,*destino=NULL;
Buscar(Lineas *prm, string estacion, int linea, bool d)
{
	aux=prm;
	while(aux!=NULL)
	{
		if(estacion==aux->estacion&&linea==aux->linea)
		{
			if(d==0)origen=aux;
			if(d==1)destino=aux;
			break;
		}
		aux=aux->sig;
	}
}

Ingresar()
{
	string inicio,final;
	int LineaIni,LineaFin;
	//ESTACION DE ORIGEN
	cout<<"Desde que estacion comenzara tu recorrido?: ";
	cin.ignore(); getline(cin, inicio);
	cout<<"En que linea esta: ";
	cin>>LineaIni; 
	if(LineaIni==4)
	Buscar(pL4,inicio,LineaIni,0);	
	else if(LineaIni==6)
	Buscar(pL6,inicio,LineaIni,0);
	else if(LineaIni==9)
	Buscar(pL9,inicio,LineaIni,0);
	//ESTACION FINAL
	cout<<"En que estacion deseas que finalice?: ";
	cin.ignore(); getline(cin, final);
	cout<<"En que linea esta: ";
	cin>>LineaFin; 
	if(LineaFin==4)
	Buscar(pL4,final,LineaFin,1);
	else if(LineaFin==6)
	Buscar(pL6,final,LineaFin,1);
	else if(LineaFin==9)
	Buscar(pL9,final,LineaFin,1);
}

string ruta[25];//25 es n nodos del camino mas largo
subRuta(Lineas *subOrigen, Lineas *subDestino)
{
		for(i=0;i<25;i++) ruta[i]=" ";//Lenando de voids el arreglo
		bool band=0;
		//Por la derecha
		i=0; aux=subOrigen;
		while(aux!=NULL)
		{
			ruta[i]=aux->estacion;
			if(aux->estacion==subDestino->estacion)
			{band=1; break;}
			aux=aux->sig; i++;
		}
		if(band==0)
		{
			for(i=0;i<25;i++)
			ruta[i]=" ";
			//Por la izquierda
			j=0; aux=subOrigen;
			while(aux!=NULL)
			{
				ruta[j]=aux->estacion;
				if(aux->estacion==subDestino->estacion)
				{band=1; break;}
				aux=aux->ant; j++;
			}
		}
		
	//Imprimiendo
	k=0; cout<<"\n\n*****Linea*****"<<aux->linea;
	if(aux->linea==4) cout<<"\n("<<pL4->estacion<<" - "<<fL4->estacion<<"): ";
	if(aux->linea==6) cout<<"\n("<<pL6->estacion<<" - "<<fL6->estacion<<"): ";
	if(aux->linea==9) cout<<"\n("<<pL9->estacion<<" - "<<fL9->estacion<<"): ";
	while(ruta[k]!=subDestino->estacion)
	{
		if(ruta[k]!=" ")
		cout<<ruta[k]<<" - "; k++;
	}cout<<ruta[k];
}

Lineas *buscarSubDestino(Lineas *prm, string estacion)
{
	aux=prm;
	while(aux!=NULL)
	{
		if(estacion==aux->estacion)
		{
			return aux;
			break;
		}
		aux=aux->sig;
	}
}

Ruta()
{	
	//4 y 9 jamaica 4 y 6 martin carrera
	Lineas *subDestino,*subDestino2;
	cout<<"\nLa ruta a seguir es:\n";
	if(origen->linea==destino->linea)//si esta en la misma linea
	{
		subRuta(origen,destino);
	}
	else if(origen->linea==4&&destino->linea==9)//si es 4y9
	{
		subDestino=buscarSubDestino(pL4,"Jamaica");
		subRuta(origen,subDestino);
		subRuta(subDestino->tras,destino);
	}	
	else if(origen->linea==9&&destino->linea==4)//si es 9y4
	{
		subDestino=buscarSubDestino(pL9,"Jamaica");
		subRuta(origen,subDestino);
		subRuta(subDestino->tras,destino);
	}
	else if(origen->linea==4&&destino->linea==6)//si es 4y6
	{
		subDestino=buscarSubDestino(pL4,"Martin Carrera");
		subRuta(origen,subDestino);
		subRuta(subDestino->tras,destino);
	}	
	else if(origen->linea==6&&destino->linea==4)//si es 6y4
	{
		subDestino=buscarSubDestino(pL6,"Martin Carrera");
		subRuta(origen,subDestino);
		subRuta(subDestino->tras,destino);
	}
	else if(origen->linea==6&&destino->linea==9)//si es 6y9
	{
		subDestino=buscarSubDestino(pL6,"Martin Carrera");
		subRuta(origen,subDestino);
		subDestino2=buscarSubDestino(pL4,"Jamaica");
		subRuta(subDestino->tras,subDestino2);
		subRuta(subDestino2->tras,destino);
	}	
	else if(origen->linea==9&&destino->linea==6)//si es 9y6
	{
		subDestino=buscarSubDestino(pL9,"Jamaica");
		subRuta(origen,subDestino);
		subDestino2=buscarSubDestino(pL4,"Martin Carrera");
		subRuta(subDestino->tras,subDestino2);
		subRuta(subDestino2->tras,destino);
	}
}
int main()
{
	CrearLineas();
	Conexiones();
   while(1)
   {
        cout<<"\n\n* * * * * * * MENU * * * * * * *\n";
        cout<<"Metro (Lineas 1,3 y B)\n";
        cout<<"1.- Visualizar Lineas\n";
        cout<<"2.- Buscar una ruta\n";
        cout<<"\n   * * * * Seleccione una opcion: ";
        cin>>opc;
       switch(opc)
       {
        case 1://Imprimir de izquierda a derecha
        	cout<<"Leyenda: El simbolo (->) simboliza un trasborde\n\n";
        	imprimir(pL4,10,4);
        	imprimir(pL6,11,6);
        	imprimir(pL9,12,9);
            break;
        case 2://Busqueda
        	pL4->linea=4; pL6->linea=6;//AJUSTANDO POR ERROR EN EL QUE pl4=6 y pl6=0
	       	Ingresar();
			Ruta();
        	break;
        default:
        	cout<<"Ingresa una opcion valida";
 	   }
    }
    return 0;
}





