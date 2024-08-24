#include<iostream>
#include<time.h>
#include <stdlib.h>
//Para reproducir
#include <windows.h>
//Para la lectura de strings
#include <string>
using namespace std;

struct nodo
{
	string Nombre, Artista, Genero;
	nodo *ant,*sig;
};

//Prototipos
void Reproducir();
void Iniciar_Nodos();

//Variables
int opc,i,j,k;
bool trigger;
nodo *p=NULL,*f=NULL,*aux,*aux2,*aux3,*aux4,*Nueva,*Eliminado,*Actual=NULL;//es la cansion actual, se usa para reproducir la que sigue o la anterior

//Base de datos emulada con arreglos
string nombre []={"Lay Me Down","Como Antes","Dont Hate On Me","Estamos Bien","Hasta La Raiz","Know No Better","Pero Ya No","RLNDT","Save That Shit","Si Estuviesemos Juntos","Treat You Better","Dont Forget My Love","Habitual","Summer Time Blood","Stay","Ride","La Fama","No Dudes","I Love You Baby","Sheep May Safely Graze"};
string genero []={"Electronica","Trap","pop","Trap","Pop","Electronica","Regaeton","Trap","Rock","Regaeton","Pop","Electronica","Pop","Electronica","Pop","Pop, Electronica","Pop","Balada","Balada","Clasica"};
string artista []={"Avicii","Bad Bunny","Vincent Pontare","Bad Bunny","Natalia Lauforcade","Major Lazer","Bad Bunny","Bad Bunny","Shauntrack","Bad Bunny","Shawn Mendez","Miguel y Diplo","Justin Bieber","Jung Lean y Skrillex","The Kid LAROI y Justin Bieber","Twenty One Pilots","Rosalia y The Weekend","Jose Jose","Frank Sinatra","Johann Sebastian Bach y Kindgren "};
string Desmontadas[]={"Attention","Dancin","X Ultima Vez","Chanel","As It Was","Home","Girls Like You","Rock With You","Nubes","Tacones Rojos","","","","","","","","","","","","","","","","","","","",""};
string DesmontadasArt[]={"de Justin Bieber y Omar","de Aaron Smith","de Daddy Yankee y Bad Bunny","de Frank Ocean","de Harry Styles","de Vince Staples","de Maroon 5 y Cardi B","de Michael Jackson","de Rauw Alejandro","de Sebastian Yatra","","","","","","","","","","","","","","","","","","","",""};

int main()
{
   srand(time(NULL));//Para los aleatorios
   Iniciar_Nodos();
   while(1)
   {

        cout<<"\n\n* * * * * * * Reproductor de Musica * * * * * * *\n";
        cout<<"----Menu\n";
        cout<<"1.- Listas de reproduccion\n";//imprimir todas las rolas en 3 columnas (nombre, artissta, genero)
        cout<<"2.- Siguiente\n";
        cout<<"3.- Anterior\n";
        cout<<"4.- Reproduccion aleatoria\n";//de aqui a delante
        cout<<"5.- Eliminar cansion\n";
        cout<<"6.- Agregar cansion\n";
        cout<<"7.- Buscar y reproducir\n";
		cout<<".-\n";
		cout<<".-\n";
        cout<<"\n   * * * * Seleccione una opción: ";
        cin>>opc;
        
       switch(opc)
       {
    	case 1://Listas de reproduccion
			if(p==NULL)
			{
				cout<<"Lista vacia\n";
			}
			else
			{
				aux=p;
				cout<<"\n\t\t******Mi Playlist******\n\nNombre del track\t\tArtista\t\t\tGenero\n\n\n";
				do
				{
					cout<<aux->Nombre<<"\t\t\t"<<aux->Artista<<"\t\t\t"<<aux->Genero<<"\n\n";
					aux=aux->sig;
				}while(aux!=p);
			}
           break;
        case 2://Siguiente Cansion
			if(Actual!=NULL)
			{
				Actual=Actual->sig;
				Reproducir();
			}
			else
			{
				system("cls");
				cout<<"\n-> No se esta reproduciendo nada aun\n";
			}
        	break;
		case 3://Anterior Cansion
			if(Actual!=NULL)
			{
				Actual=Actual->ant;
				Reproducir();
			}
			else
			{
				system("cls");
				cout<<"\n-> No se esta reproduciendo nada aun\n";
			}
			break;
        case 4://Reproduccion Aleatoria
        	aux=p;
			for(i=0;i<rand()%100;i++)
			{
				aux=aux->sig;
			}
			Actual=aux;
			Reproducir();
        	break;
		case 5://Eliminar Cansion
		{//se usan estas llaves por que ocurre un fallo debido a que las variables declaradas en case 5 no se sabe donde terminan y no deja pasar al otro case
			string Cansion; bool find=0;
			cout<<"\nCual es el nombre de la cansion que deseas eliminar?: ";
			cin.ignore();
			getline(cin, Cansion);
			Eliminado=p;
			do
			{
				if(Eliminado->Nombre==Cansion)
				{
					if(Eliminado==Actual)
					{
						Actual=NULL;
					}
					if(Eliminado==p)
					{
						p=p->sig;
						
					}
					else if(Eliminado==f)
					{
						f=f->ant;
					}
					//Guardando Cansion Eliminada en desmontados PENDIENTE
					i=-1;
					do
					{
						i++;
						if(Desmontadas[i]=="")
						{
							Desmontadas[i]=Cansion;
							DesmontadasArt[i]="de "+Eliminado->Artista;
							break;
						}
					}while(Desmontadas[i]!="");
					//Eliminando
					aux=Eliminado->ant;
					aux2=Eliminado->sig;
					aux->sig=aux2;
					aux2->ant=aux;
					Eliminado->ant=NULL;
					Eliminado->sig=NULL;
					delete(Eliminado);

					find=1;
					break;
				}
				else
				{
					Eliminado=Eliminado->sig;
				}
			}
			while(Eliminado!=p);
			
			if(find==1)
			{
				cout<<"\n\nLa cansion fue encontrada y eliminada\n";
			}
			else
			{
				cout<<"\n\nNo se encontro la cansion que deseas eliminar\n";
			}
		}
        	break;
        case 6://Agregar Cansion
        {
			cout<<"********Cansiones Desmontadas disponibles para agregar a playlist********\n";
			i=0;trigger=0;
			while(Desmontadas[i]!="")
			{
				cout<<(i+1)<<".- "<<Desmontadas[i];
				cout<<" "<<DesmontadasArt[i]<<"\n";
				trigger=1;
				i++;
			}
			if(trigger==1)
			{
				Nueva=new(nodo);
				cin.ignore();
				
				cout<<"\nCual desea agregar?: ";
				getline(cin, Nueva->Nombre);
				cout<<"\nQue artista la interpreta?: ";
				getline(cin, Nueva->Artista);
				cout<<"\nQue genero es?: ";
				getline(cin, Nueva->Genero);	
				//Vinculando nodo
				Nueva->ant=f;
				Nueva->sig=p;
				p->ant=Nueva;
				f->sig=Nueva;
				f=Nueva;
				
				j=0;
				while(Desmontadas[j]!="")//Se elimina la cansion agregada al playlist de la base de datos para las desmontadas
				{
					if(Desmontadas[j]==Nueva->Nombre)
					{
						Desmontadas[j]="";	
						DesmontadasArt[j]="";	
						k=j;
						do//se recorren las demas para no dejar huecos
						{
							Desmontadas[k]=Desmontadas[k+1];
							DesmontadasArt[k]=DesmontadasArt[k+1];
							k++;
						}while(Desmontadas[k]!="");
						break;
					}
					j++;
				}	
			}
			else
			{
				cout<<"\n**********No hay cansiones disponibles para agregar :()";
			}
		}
        	break;
		case 7://Buscar y Reproducir
		bool found=0;
		string Busqueda;
		cout<<"Que cansion desea reproducir?: ";
		//ignore se usa para poder usar getline (para introducir cadenas con espacios) en un switch
		cin.ignore();
		getline(cin, Busqueda);
		Actual=p;
		do
		{
			if(Actual->Nombre==Busqueda)
			{
				found=1;
				break;
			}
			else
			{
				Actual=Actual->sig;
			}
		}
		while(Actual!=p);
		
		if(found==1)
		{	
			Reproducir();
	  	}
		else
		{
			system("cls");
			cout<<"\n-> No se encontro la cansion que buscaste\n";
		}
			break;
 	   }
    }
}
void Iniciar_Nodos()
{
	//Iniciando los nodos con las 20 cansiones de la abse de datos
	for(int i=0;i<20;i++)
	{
		if(i==0)
		{
			p=new(nodo);
			p->Nombre=nombre[i];
			p->Genero=genero[i];
			p->Artista=artista[i];
			p->sig=p;
			p->ant=p;
			f=p;
		}
		else
		{
			aux=new(nodo);
			aux->Nombre=nombre[i];
			aux->Genero=genero[i];
			aux->Artista=artista[i];
			f->sig=aux;
			aux->sig=p;
			p->ant=aux;
			aux->ant=f;
			f=aux;
		}	 	
	}
}
void Reproducir()
{
	string Ruta = "open \""+Actual->Nombre+".mp3\" type mpegvideo alias mp3";
	mciSendString(TEXT(Ruta.c_str()), NULL, 0, NULL);
	mciSendString("play mp3", NULL, 0, NULL);
	
	char control;
	while(1)
	{
		system("cls");
		cout<<"\nReproduccion En Curso...\nCansion: "<<Actual->Nombre<<"\n"<<"Artista: "<<Actual->Artista<<"\n"<<"Genero: "<<Actual->Genero<<"\n";
		cout<<"\n///////////////Control//////////////\n";
		cout<<"Pulse p para Pausar r para Reanudar \n\td para Detener.\n";
		cin>>control;
		if(control=='p')
		{
			mciSendString("pause mp3", NULL, 0, NULL);
		}
		else if(control=='r')
		{
			mciSendString("play mp3", NULL, 0, NULL);
		}
		else if(control=='d')
		{
			mciSendString("close mp3", NULL, 0, NULL);
			break;
		}     
	}
	system("cls");	
}





