#include <iostream>
#include <conio.h> 
#include <stdlib.h>
#include <windows.h> 
#include <time.h> 
#include <fstream> 
#include <string.h> 

#define tecla_arriba 72
#define tecla_abajo 80
#define enter 13

double _cod= 174904;
double _admin= 74761925;

using namespace std;

int flecha(const char *titulo, const char *opciones[], int nopciones);
void gotoxy(int x,int y);
void Finesi();

void gotoxy(int x,int y)
{  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos); 
}

void Finesi()
{
	gotoxy(37,11);
	cout<<"F"; Sleep(100);
	cout<<"I"; Sleep(100);
	cout<<"N"; Sleep(100);
	cout<<"E"; Sleep(100);
	cout<<"S"; Sleep(100);
	cout<<"I"; Sleep(1000);
	
	gotoxy(2,21);
	cout<<"Creado Por:";
	gotoxy(2,22);
	cout<<"Rodrigo Alexander Becerra Lucano";
	Sleep(4000);
	system("cls");
}

class Cajero
{
	private:
		int codigo;
		int saldo;
		int verificador;
		int registro;
		int add;
		int sust;
		int agbill;
		int nbill= 0;
		int tipobill[5]={10, 20, 50, 100, 200};
		int cantbill[5]={10, 10, 10, 10, 10};
		
	public:	
		Cajero(int= 0, int= 0, int= 0);
		void menu();
		void inicio();	
		void tipocliente();
		void puntos();
		int historial(int= 0);
		void mostrarhistorial();
		void borrarhistorial();
		int agregarbill(int= 0);
};

Cajero::Cajero(int cod, int _saldo, int _verificador)
{
	codigo= cod;	
	saldo= _saldo;
	verificador= _verificador;
}

void Cajero::puntos()
{
	for(int i=0; i<3; i++)
	{
		cout<<".";
		Sleep(1000);
	}
}

int Cajero::agregarbill(int _agbill)
{
	agbill= _agbill;
	
	system("cls");
	gotoxy(25,9);
	cout<<"Ingrese la cantidad a agregar";
	gotoxy(38,11);
	cin>>nbill;
	
	if(agbill == 0)
		cantbill[0]+= nbill;
	if(agbill == 1)
		cantbill[1]+= nbill;
	if(agbill == 2)
		cantbill[2]+= nbill;
	if(agbill == 3)
		cantbill[3]+= nbill;
	if(agbill == 4)
		cantbill[4]+= nbill;
	
	system("cls");
	gotoxy(38,11);
	cout<<"Hecho";
	Sleep(2000);
}

int Cajero::historial(int _registro)
{
	registro= _registro;
	
	ofstream archivo;
	archivo.open("Historial.txt", ios::app);
	
	if(registro==1)
		archivo<<"Cliente: "<<codigo<<"\n================================================="<<endl;

	if(registro==2)
		archivo<<"Cliente "<<codigo<<" tiene "<<saldo<<" nuevos soles\n================================================="<<endl;

	if(registro==3)
		archivo<<"Cliente "<<codigo<<" deposito "<<add<<" y ahora tiene "<<saldo<<" nuevos soles\n================================================="<<endl;

	if(registro==4)
		archivo<<"Cliente "<<codigo<<" retiro "<<sust<<" y ahora tiene "<<saldo<<" nuevos soles\n================================================="<<endl;

	archivo.close();
}

void Cajero::mostrarhistorial()
{
	
	string txt;
	
	ifstream archivo;
	archivo.open("Historial.txt", ios::in);
	
	while(!archivo.eof())
	{
		getline(archivo, txt);
		cout<<txt<<endl;
	}
	
	archivo.close();
}

void Cajero::borrarhistorial()
{
	ofstream archivo;
	archivo.open("Historial.txt", ios::trunc);
	archivo.close();
}

void Cajero::inicio()
{	
	system("color 17");
	gotoxy(19,4);
	cout<<"Bienvenido al Cajero Automatico De FINESI "<<endl;
	gotoxy(31,8);
	cout<<"Ingrese su codigo"<<endl;
	gotoxy(36,10);
	cin>>codigo;
	
	system("cls");
	
	gotoxy(34,11);
	cout<<"Comprobando";
	
	for(int i=0; i<2; i++)
	{
		cout<<".";
		Sleep(1000);
	}
	
	system("cls");
}

void Cajero::tipocliente()
{
	
	int contador= 3;
	
	for(int i= 0; i<3; i++)
	{
		if(codigo == _admin)
		{
			system("cls");
			gotoxy(26,11);
			cout<<"::::[Modo Administrador]::::"<<endl;
			
			Sleep(3000);
			
			verificador= 2;
			
			break;
		}
		
		if(codigo != _cod)
		{
			system("cls");
			contador--;
			
			if(contador == 0)
			{
				system("cls");
				
				gotoxy(26,11);
				cout<<"::::[Reteniendo tarjeta]::::";
				
				Sleep(3000);
				
				system("cls");
			
				verificador= 0;
			
				break;		
			}
			gotoxy(20,7);
			cout<<"Codigo incorrecto, le quedan "<<contador<<" intento(s)"<<endl;
			gotoxy(37,10);
			cin>>codigo;		
			
			system("cls");
			gotoxy(34,11);
			cout<<"Comprobando";
			for(int i=0; i<2; i++)
			{
				cout<<".";
				Sleep(1000);
			}
			
			system("cls");
		}
					
		if(codigo == _cod)
		{
			gotoxy(29,11);
			cout<<"Accediendo a la cuenta";
			Sleep(1000);
			historial(1);
			historial(2);
			puntos();
			
			verificador= 1;
			
			break;
		}
	}
}

void Cajero::menu()
{
	int op, opcionadmin, opcionbill;
	int cont[5]={0, 0, 0, 0, 0};
	int ntipos= 5, isaldo, ret;
	bool repite = true;
	
	if(verificador == 0)
		return inicio();
		
	if(verificador == 1)
	{
		const char *titulo= "Bienvenido al Menu";
		const char *opciones[]= {"Consultar Saldo", "Depositar", "Retirar", "Salir"};
		int nopciones= 4;
		
		do
		{
			op= flecha(titulo, opciones, nopciones);
		
			switch(op)
			{
				case 1:
					
					system("cls");
					gotoxy(17,11);
					cout<<"Su cuenta actualmente tiene "<<saldo<<" nuevos soles";
					
					gotoxy(2,22);
					cout<<"Presione una tecla para continuar";
					getch();
				
					return menu();
					break;
					
				case 2:
					
					system("cls");
					gotoxy(24,9);
					cout<<"Ingrese la cantidad a depositar";
					gotoxy(39,11);
					cin>>add;
					system("cls");
					
					if(add%10 == 0)
					{
						
						saldo= saldo + add;
						
						gotoxy(19,11);
						cout<<"Ahora su cuenta tiene "<<saldo<<" nuevos soles";
						gotoxy(2,22);
						cout<<"Presione una tecla para continuar";
						getch();	
						historial(3);
						
						do
						{
							isaldo= add;
							
							for(int i= ntipos - 1; i>=0; i--)
							{
								if(add >= tipobill[i])
									if(cantbill[i] > 0)
									{
										add= add - tipobill[i];
										cantbill[i]++;
										cont[i]--;
											
										break;	
									}
							}
						}while(add > 0 && isaldo != add);
				
						return menu();	
					}
					
					else
					{
						gotoxy(20,11);
						cout<<"Solo se pueden depositar billetes";
						
						gotoxy(2,22);
						cout<<"Presione una tecla para continuar";
						getch();
						return menu();
					}
					break;
					
				case 3:
				{
					system("cls");
					gotoxy(20,9);
					cout<<"Ingrese la cantidad que quiere retirar";
					gotoxy(39,11);
					cin>>ret;
					
					system("cls");
					
					if(ret%10 == 0)
					{
						if(ret > saldo)
						{
							gotoxy(19,11);
							cout<<"Usted no cuenta con esa cantidad de dinero"<<endl;
							gotoxy(2,22);
							cout<<"Presione una tecla para continuar";
							getch();
							return menu();
							break;
						}
						
						int acum, totalbill= 0;
						
						sust= ret;
						
						for(int i=0; i<5; i++)
						{
							acum= tipobill[i] * cantbill[i];
							totalbill+= acum;
							
						}
						
						if(ret <= totalbill)
						{
							do
							{
								isaldo= ret;
							
								for(int i= ntipos - 1; i>=0; i--)
								{
									if(ret >= tipobill[i])
										if(cantbill[i] > 0)
										{
											ret= ret - tipobill[i];
											cantbill[i]--;
											cont[i]++;
											
											break;	
										}
								}
							
							}while(ret > 0 && isaldo != ret);
						
							if(isaldo == ret)
							{
								gotoxy(22,11);
								cout<<"No hay billetes disponibles";
								gotoxy(2,22);
								cout<<"Presione una tecla para continuar";
								getch();
							}
							
							else if(ret == 0)
							{
								saldo = saldo - sust;
								gotoxy(19,9);
								cout<<"Ahora su cuenta tiene "<<saldo<<" nuevos soles";
								gotoxy(32,11);
								cout<<"Usted recibio: ";
								for(int i=0; i<5; i++)
								{
									gotoxy(24,14+i);
									for(int j=i; j<5; j++)
										if(cont[i]>0 && i == j)
											cout<<cont[i]<<" billete(s) de "<<tipobill[j]<<" nuevos soles";	
								}
									
								gotoxy(2,22);
								cout<<"Presione una tecla para continuar";
								getch();	
								historial(4);
								return menu();
								break;
							}
						}
						
						else
						{
							gotoxy(24,11);
							cout<<"No se puede retirar esa cantidad";
							gotoxy(6,13);
							cout<<"El saldo disponible actualmente en el cajero es de "<<totalbill<<" nuevos soles";
							gotoxy(2,22);
							cout<<"Presione una tecla para continuar";
							getch();	
							return menu();
							break;
						}
					}
					
					else
					{
						system("cls");
						gotoxy(24,11);
						cout<<"Solo se pueden retirar billetes";
						gotoxy(2,22);
						cout<<"Presione una tecla para continuar";
						getch();	
						return menu();
						break;
					}
					break;
				}
	
				case 4:
					
					system("cls");
					gotoxy(31,11);
					cout<<"Saliendo del menu";
		
					Sleep(1000);
					
					puntos();
					
					system("cls");
					
					repite = false;
					return inicio();
					break;		
			}
		}while(repite);
	}
		
	if(verificador == 2)
	{
		system("color 0A");
		bool repite = true;
		const char *tadmin= "Bienvenido al modo administrador";
		const char *opadmin[]= {"Consultar cantidad de billetes", "Agregar cantidad de billetes", "Ver historial de transacciones", "Borrar historial de transacciones", "Salir"};
		int nopadmin= 5;
			
		do
		{
			opcionadmin= flecha(tadmin, opadmin, nopadmin);
			
			switch(opcionadmin)
			{
				case 1:
					
					system("cls");
					cout<<"\n\n\t La cantidad de billetes disponibles se muestra a continuacion"<<endl;
					cout<<"\n\n\n\t\t[10]\t[20]\t[50]\t[100]\t[200]"<<endl;
					cout<<"\t";
					for(int i=0; i<5; i++)
						cout<<"\t["<<cantbill[i]<<"]";
					
					cout<<"\n\n\t\t  Pulse cualquier tecla para volver al menu";
					getch();
					system("cls");
					
					return menu();
					break;
					
				case 2:
				{
					system("cls");
					bool repite= true;
					const char *tbill= "Seleccione el tipo de billete";
					const char *opbill[]= {"Doscientos [200]", "Cien [100]", "Cincuenta [50]", "Veinte [20]", "Diez [10]", "Salir"};
					int nopbill= 6;
					
					do
					{
						opcionbill= flecha(tbill, opbill, nopbill);
						
						switch(opcionbill)
						{
							case 1:
								
								agregarbill(4);
								return menu();
								break;
							
							case 2:
								
								agregarbill(3);
								return menu();
								break;
								
							case 3:
								
								agregarbill(2);
								return menu();
								break;
								
							case 4:
								
								agregarbill(1);
								return menu();
								break;
								
							case 5:
								
								agregarbill(0);
								return menu();
								break;
								
							case 6:
								
								system("cls");
								gotoxy(37,11);
								cout<<"Saliendo";
								Sleep(2000);
								repite = false;
								return menu();
								break;
									
						}
					}while(repite);
					
					break;
				}
						
				case 3:
					
					system("cls");
					gotoxy(28,11);
					cout<<"Historial de transacciones";
					Sleep(2000);
					system("cls");
					mostrarhistorial();
					
					getch();
					system("cls");
					return menu();
					break;
					
				case 4:
					
					char del;
					
					system("cls");
					gotoxy(10,9);
					cout<<"Seguro que desea borrar el historial de transacciones? (Y/N)";
					gotoxy(40,11);
					cin>>del;
					
					if(del == 'Y')
					{
						system("cls");
						gotoxy(31,11);
						cout<<"Borrando historial";
						puntos();
						
						borrarhistorial();
						system("cls");
						
						gotoxy(38,11);
						cout<<"Hecho";
						Sleep(2000);
						
						return menu();
						break;
					}
					
					if(del == 'N')
					{
						system("cls");
						gotoxy(37,11);
						cout<<"Cancelado";
						Sleep(2000);
						
						return menu();
						break;
					}
					
					break;
					
				case 5:
					
					system("cls");
					gotoxy(24,11);
					cout<<"Saliendo del Modo Administrador";
					Sleep(1000);
					
					puntos();
					
					repite = false;
					system("cls");
					
					return inicio();
					break;		
			}
		}while(repite);
	}
}

int flecha(const char *titulo, const char *opciones[], int nopciones)
{
	int opseleccion= 1;
	int tecla;
	bool repite= true;
	
	do
	{
		system("cls");
		
		gotoxy(23,8+opseleccion);
		cout<<"==>";
		
		gotoxy(30,6);
		cout<<titulo;
		
		for(int i=0; i<nopciones; i++)
		{
			gotoxy(27,9+i);
			cout<<i+1<<") "<<opciones[i];
		}
		
		do
		{
			tecla= getch();
		}while((tecla!= tecla_arriba) && (tecla!= tecla_abajo) && (tecla!= enter));
		
		switch(tecla)
		{
			case tecla_arriba:
				opseleccion--;
				
				if(opseleccion == 0)
					opseleccion= nopciones;
				break;
				
			case tecla_abajo:
				opseleccion++;
				
				if(opseleccion > nopciones)
					opseleccion = 1;
				break;
				
			case enter:
				repite= false;
				break;
		}		
	}while(repite);
	
	return opseleccion;	
}

int main()
{
	srand(time(NULL));
	int i, random, random2, tcarga= 0, tiporand= 0, nrandom;
	
	system("color 0A");
	
	Finesi();
	
	cout<<"\n\n Cargando Sistema, por favor espere";
	cout<<"\n\n ";
	
	ofstream binario;
	binario.open("Binario.txt", ios::trunc);
	binario.close();
	
	tiporand= rand()%2;
	
	if(tiporand == 0)
	{
		for(i=0; i<6; i++)
		{
			random= 200+rand()%1001;
			cout<<"==";
			Sleep(random);
			tcarga+= random;	
		}
	}
	
	if(tiporand == 1)
	{
		system("color 0A");
		ofstream binario;
		
		random2= 200+rand()%901;
		for(i=0; i<random2; i++)
		{
			binario.open("Binario.txt", ios::app);
			nrandom= rand()%2;
			cout<<nrandom<<" ";
			binario<<nrandom;
			binario.close();
			Sleep(7);
		}
		tcarga= 7*random2;
	}
	
	system("cls");
	system("color 17");

	gotoxy(2,22);
	cout<<"El sistema se cargo en "<<tcarga<<" milisegundos";
	
	Cajero c1= Cajero(0,10000);
	
	c1.inicio();
	
	while(true)
	{
		c1.tipocliente();
		c1.menu();
	}
	
	return 0;	
}






