#define UP_ARROW    72
#define DOWN_ARROW  80
#define LEFT_ARROW  75
#define RIGHT_ARROW 77
#define ENTER 13
#define SPACE 32
#define F1 59
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <algorithm>
#include <time.h>

using namespace std;

class Kasyno{
	
public:
string imie;
int pieniadze;
int wynik;

int losowaniePieniedzy(){
	
	srand(time(NULL));
	pieniadze=rand()%100000+10000;
	
	return pieniadze;
}

void podajNazwe(){
	
	cout<<"podaj nazwe"<<endl;
	
	
	
	getline(cin,imie);
	for(int i=0,dlg = imie.length();i<dlg;i++){
		if(imie.at(i)==' ' && i<dlg)
			imie.at(i)='_';
		}
		
		
	
	
}
private:
//////////////////////////////////////////////////////////////////////////////////
void zapisywanieWynikow(string imie, int wynik){
	
	fstream plik;
	 
	plik.open("tablicaWynikow.txt",ios::out|ios::app);
	
	plik<<imie<<" "<<wynik<<endl;
	
	plik.close();
	
	wybieranie();
	
}
//////////////////////////////////////////////////////////////////////////////////
void bandyta(int &pieniadze, int &wynik){
	
					if(pieniadze == 0){
					cout<<wynik;
					zapisywanieWynikow(imie,wynik);
					}
	
	int kasa = 0;
	int roznica = pieniadze - kasa;
	char klawisz;
	
	
	
	cout<<"strzalka w gore pieniadze + 100,w dol -100, w lewo /2 w prawo *2, spacja ustawia 1000 //2x F1 zeby wyjsc"<<endl;
	do{
	
	
	
	
	klawisz = _getch();
	
	
	
	switch(klawisz){
		
		
		
		//--------------------------------------
		case UP_ARROW:
			system("cls");
			cout<<"strzalka w gore pieniadze + 100,w dol -100, w lewo /2 w prawo *2, spacja ustawia 1000 "<<endl;
		if(kasa+100<=pieniadze){
			kasa+=100;
			cout<<"kasa = "<<kasa<<endl;
			roznica = pieniadze - kasa;
			cout<<"pieniadze = "<<roznica<<endl;
		}
		else{
			kasa = pieniadze;	
			cout<<"kasa = "<<kasa<<endl;
			roznica = pieniadze - kasa;
			cout<<"pieniadze = "<<roznica<<endl;		
		}
		break;
		//--------------------------------------
		case DOWN_ARROW:
		system("cls");
		cout<<"strzalka w gore pieniadze + 100,w dol -100, w lewo /2 w prawo *2, spacja ustawia 1000"<<endl;
		if(kasa-100>=0){
			kasa-=100;
			cout<<"kasa = "<<kasa<<endl;
			roznica = pieniadze - kasa;
			cout<<"pieniadze = "<<roznica<<endl;
		}
		else{
			kasa = 0;
			cout<<"kasa = "<<kasa<<endl;
			roznica = pieniadze - kasa;
			cout<<"pieniadze = "<<roznica<<endl;			
		}
		break;
		//--------------------------------------
		case LEFT_ARROW:
		system("cls");
		cout<<"strzalka w gore pieniadze + 100,w dol -100, w lewo /2 w prawo *2, spacja ustawia 1000"<<endl;
		if(kasa/2>=0){
			kasa/=2;
			cout<<"kasa = "<<kasa<<endl;
			roznica = pieniadze - kasa;
			cout<<"pieniadze = "<<roznica<<endl;
		}
		else{
			kasa = 0;
			cout<<"kasa = "<<kasa<<endl;
			roznica = pieniadze - kasa;
			cout<<"pieniadze = "<<roznica<<endl;			
		}
		break;
		//--------------------------------------
		case RIGHT_ARROW:
		system("cls");
		cout<<"strzalka w gore pieniadze + 100,w dol -100, w lewo /2 w prawo *2, spacja ustawia 1000"<<endl;
		if(kasa*2<=pieniadze){
			kasa*=2;
			cout<<"kasa = "<<kasa<<endl;
			roznica = pieniadze - kasa;
			cout<<"pieniadze = "<<roznica<<endl;
		}
		else{
			kasa = pieniadze;
			cout<<"kasa = "<<kasa<<endl;
			roznica = pieniadze - kasa;
			cout<<"pieniadze = "<<roznica<<endl;			
		}
		break;
		//--------------------------------------
		case SPACE:
			system("cls");
			cout<<"strzalka w gore pieniadze + 100,w dol -100, w lewo /2 w prawo *2, spacja ustawia 1000"<<endl;
			kasa = 1000;
			cout<<"kasa = "<<kasa<<endl;
			roznica = pieniadze - kasa;
			cout<<"pieniadze = "<<roznica<<endl;
			break;
		
	}
	
	if(klawisz==F1){
		
		wybieranie();
		
	}
}while(klawisz!=ENTER);
	
	
	
	
	if(kasa ==0){
			cout<<"Musisz podac wiecej niz 0"<<endl;
			bandyta(pieniadze, wynik);
		}
	
	
	system("cls");
	//-----------------------------------------
	pieniadze = roznica;
	cout<<"wynik = "<<wynik<<endl;
	cout<<"Do obstawienia "<<kasa<<" $$$"<<endl;
	cout<<"Portfel "<<pieniadze<<endl;
	
		
		cout<<endl<<endl<<"zakrec ... (spacja)"<<endl;
		do{
		klawisz = _getch();	
		}while(klawisz!=SPACE);
		
		int tab[3];
		string symbole[3] = {"$","7","@"};	
					
				cout<<endl<<endl<<endl;
				
				//---------------------------------------
				cout<<"=================================="<<endl;
			
				cout<<"\t";
				srand(time(NULL));
			for(int i=0; i<3;i++){
				
				int los = rand()%3;
				tab[i] = los;
				cout<<symbole[los]<<"\t";
				Sleep(500);
			}
		
			cout<<endl;
			cout<<"=================================="<<endl;
			cout<<endl<<endl<<endl;
			//---------------------------------------
			int licznik = 0 ;
			
				
				if(tab[0]==tab[1] && tab[0]==tab[2]){
				wynik += kasa*3;
				pieniadze +=	kasa*3;
				cout<<"Wygrales ... [mnoznik x3]"<<endl;
				Sleep(1000);
				bandyta(pieniadze,wynik);
				
				}
					
				else if(tab[0]==tab[1]){
				wynik += kasa*2;
				pieniadze +=	kasa*2;
				cout<<"Wygrales ... [mnoznik x2]"<<endl;
				Sleep(1000);
				bandyta(pieniadze,wynik);		
				}
				else{
				cout<<"Przegrales ..."<<endl;
				Sleep(1000);
				if(pieniadze == 0){
					cout<<"Wynik :"<<wynik<<endl<<endl;
					zapisywanieWynikow(imie,wynik);
					wyswietlanieWynikow();
					}
				bandyta(pieniadze,wynik);			
				}
			
	
	
}	
//////////////////////////////////////////////////////////////////////////////////
void oczko(int &pieniadze,int &wynik){
	
	int kasa = 0;
	int roznica = pieniadze - kasa;
	char klawisz;
	
	
	
	cout<<"strzalka w gore pieniadze + 100,w dol -100, w lewo /2 w prawo *2, spacja ustawia 1000 //2x F1 zeby wyjsc"<<endl;
	do{
	
	
	
	
	klawisz = _getch();
	
	
	
	switch(klawisz){
		
		
		
		//--------------------------------------
		case UP_ARROW:
			system("cls");
			cout<<"strzalka w gore pieniadze + 100,w dol -100, w lewo /2 w prawo *2, spacja ustawia 1000 "<<endl;
		if(kasa+100<=pieniadze){
			kasa+=100;
			cout<<"kasa = "<<kasa<<endl;
			roznica = pieniadze - kasa;
			cout<<"pieniadze = "<<roznica<<endl;
		}
		else{
			kasa = pieniadze;	
			cout<<"kasa = "<<kasa<<endl;
			roznica = pieniadze - kasa;
			cout<<"pieniadze = "<<roznica<<endl;		
		}
		break;
		//--------------------------------------
		case DOWN_ARROW:
		system("cls");
		cout<<"strzalka w gore pieniadze + 100,w dol -100, w lewo /2 w prawo *2, spacja ustawia 1000"<<endl;
		if(kasa-100>=0){
			kasa-=100;
			cout<<"kasa = "<<kasa<<endl;
			roznica = pieniadze - kasa;
			cout<<"pieniadze = "<<roznica<<endl;
		}
		else{
			kasa = 0;
			cout<<"kasa = "<<kasa<<endl;
			roznica = pieniadze - kasa;
			cout<<"pieniadze = "<<roznica<<endl;			
		}
		break;
		//--------------------------------------
		case LEFT_ARROW:
		system("cls");
		cout<<"strzalka w gore pieniadze + 100,w dol -100, w lewo /2 w prawo *2, spacja ustawia 1000"<<endl;
		if(kasa/2>=0){
			kasa/=2;
			cout<<"kasa = "<<kasa<<endl;
			roznica = pieniadze - kasa;
			cout<<"pieniadze = "<<roznica<<endl;
		}
		else{
			kasa = 0;
			cout<<"kasa = "<<kasa<<endl;
			roznica = pieniadze - kasa;
			cout<<"pieniadze = "<<roznica<<endl;			
		}
		break;
		//--------------------------------------
		case RIGHT_ARROW:
		system("cls");
		cout<<"strzalka w gore pieniadze + 100,w dol -100, w lewo /2 w prawo *2, spacja ustawia 1000"<<endl;
		if(kasa*2<=pieniadze){
			kasa*=2;
			cout<<"kasa = "<<kasa<<endl;
			roznica = pieniadze - kasa;
			cout<<"pieniadze = "<<roznica<<endl;
		}
		else{
			kasa = pieniadze;
			cout<<"kasa = "<<kasa<<endl;
			roznica = pieniadze - kasa;
			cout<<"pieniadze = "<<roznica<<endl;			
		}
		break;
		//--------------------------------------
		case SPACE:
			system("cls");
			cout<<"strzalka w gore pieniadze + 100,w dol -100, w lewo /2 w prawo *2, spacja ustawia 1000"<<endl;
			kasa = 1000;
			cout<<"kasa = "<<kasa<<endl;
			roznica = pieniadze - kasa;
			cout<<"pieniadze = "<<roznica<<endl;
			break;
		
	}
	
	if(klawisz==F1){
		
		wybieranie();
		
	}
}while(klawisz!=ENTER);
	
	
	
	
	if(kasa ==0){
			cout<<"Musisz podac wiecej niz 0"<<endl;
			oczko(pieniadze, wynik);
		}
	
	
	system("cls");
	//-----------------------------------------
	pieniadze = roznica;
	cout<<"wynik = "<<wynik<<endl;
	cout<<"Do obstawienia "<<kasa<<" $$$"<<endl;
	cout<<"Portfel "<<pieniadze<<endl;
	
	//tutaj bylo if pieniadze = 0 zapisywanie
	
	//-----------------------------------------
	
	cout<<endl<<endl;
	srand(time(NULL));
	
	int wartosc = 0;
	int suma = 0;
	int sumaSI=0;
	string nazwaKarty="";
	int iloscKart=0;
	system("cls");
	
	do{		
	
	
	
	int wylosowana = rand()%52+1;
	int wylosowanaSI = rand()%14+1;
	if(wylosowanaSI!=1){
		if(wylosowanaSI==12){
			sumaSI+=2;
		}
		else if(wylosowanaSI==13){
			sumaSI+=3;
		}
		else if(wylosowanaSI==14){
			sumaSI+=4;
		}
		else{
		sumaSI+=wylosowanaSI;
		}
	}
	else{
		int wylosowanaSI = rand()%13+1;
		sumaSI+=wylosowanaSI;
	}
	
	
	if(wylosowana>=1 && wylosowana<=4){
		wartosc = 2;
		nazwaKarty="2";
		suma+=wartosc;
		}
	if(wylosowana>=5 && wylosowana<=8){
		wartosc = 3;
		nazwaKarty="3";
		suma+=wartosc;
		}
	if(wylosowana>=9 && wylosowana<=12){
		wartosc = 4;
		nazwaKarty="4";
		suma+=wartosc;
		}
	if(wylosowana>=13 && wylosowana<=16){
		wartosc = 5;
		nazwaKarty="5";
		suma+=wartosc;
		}
	if(wylosowana>=17 && wylosowana<=20){
		wartosc = 6;
		nazwaKarty="6";
		suma+=wartosc;
		}
	if(wylosowana>=21 && wylosowana<=24){
		wartosc = 7;
		nazwaKarty="7";
		suma+=wartosc;
		}
	if(wylosowana>=25 && wylosowana<=28){
		wartosc = 8;
		nazwaKarty="8";
		suma+=wartosc;
		}
	if(wylosowana>=29 && wylosowana<=32){
		wartosc = 9;
		nazwaKarty="9";
		suma+=wartosc;
		}
	if(wylosowana>=33 && wylosowana<=36){
		wartosc = 10;
		nazwaKarty="10";
		suma+=wartosc;
		}
	if(wylosowana>=37 && wylosowana<=40){
		wartosc = 2;
		nazwaKarty="Walet";
		suma+=wartosc;
		}
	if(wylosowana>=41 && wylosowana<=44){
		wartosc = 3;
		nazwaKarty="Dama";
		suma+=wartosc;
		}
	if(wylosowana>=45 && wylosowana<=48){
		wartosc = 4;
		nazwaKarty="Krol";
		suma+=wartosc;
		}
	if(wylosowana>=49 && wylosowana<=52){
		wartosc = 11;
		nazwaKarty="As";
		suma+=wartosc;
		}
		////////////////////////////////////////////////////////SI//////////////////
	
	
	
	
	
	iloscKart++;

	cout<<"Wylosowana >> "<<nazwaKarty<<" o wartosci "<<wartosc<<endl;
	cout<<"Suma wynosi >> "<<suma<<endl;
	 
	if(suma <=21 && sumaSI<=21){
		do{
		
		cout<<"nacisnij enter aby dobrac karte, spacja aby zakonczyc"<<endl;
		klawisz = _getch();	
		
			if(klawisz == SPACE){
				
				if((suma>sumaSI && suma<=21) || sumaSI>21){
					
					cout<<"Wygrales, gratulacje !"<<endl;
					wynik+=kasa*2;
					pieniadze+=kasa*2;
					cout<<"Wynik >> "<<wynik<<endl;
					cout<<"Pieniadze >> "<<pieniadze<<" $$$"<<endl;
					cout<<"suma Gracza "<<suma<<endl;	
					cout<<"suma SI "<<sumaSI<<endl;
					wybieranie();
					
				}
				else if(suma==sumaSI){
				cout<<"REMIS!!!"<<endl;	
				cout<<"suma Gracza "<<suma<<endl;	
				cout<<"suma SI "<<sumaSI<<endl;
				wybieranie();
				
				}
				
				
				else if(suma==22 && iloscKart==2){
					cout<<"perskie oczko, gratulacje !"<<endl;
					wynik+=kasa*2;
					pieniadze+=kasa*2;
					cout<<"suma Gracza "<<suma<<endl;	
					cout<<"suma SI "<<sumaSI<<endl;
					wybieranie();
				
				}
				else{
					cout<<"przegrana :("<<endl;
					cout<<wynik<<endl;
					oczko(pieniadze,wynik);
					cout<<"suma Gracza "<<suma<<endl;	
					cout<<"suma SI "<<sumaSI<<endl;
						
						if(pieniadze>0){
							wybieranie();
						}
						else{
							cout<<"Wynik :"<<wynik<<endl<<endl;
							zapisywanieWynikow(imie,wynik);
							wyswietlanieWynikow();
						}
					
					
				}
				
				
			}
		
		}while(klawisz!=ENTER);				
	}						
}while(suma<=21 && sumaSI <=21);

if((suma>sumaSI && suma<=21) || sumaSI>21){
	
					cout<<"Wygrales, gratulacje !"<<endl;
					wynik+=kasa*2;
					pieniadze+=kasa*2;
					cout<<"Wynik >> "<<wynik<<endl;
					cout<<"Pieniadze >> "<<pieniadze<<" $$$"<<endl;
					cout<<"suma Gracza "<<suma<<endl;	
					cout<<"suma SI "<<sumaSI<<endl;
					wybieranie();
				}
				
				else if(suma==sumaSI){
				cout<<"REMIS!!!"<<endl;	
				cout<<"suma Gracza "<<suma<<endl;	
				cout<<"suma SI "<<sumaSI<<endl;
				wybieranie();
				}
				
				
				else if(suma==22 && iloscKart==2){
					cout<<"perskie oczko, gratulacje !"<<endl;
					wynik+=kasa*2;
					pieniadze+=kasa*2;
					cout<<"suma Gracza "<<suma<<endl;	
					cout<<"suma SI "<<sumaSI<<endl;
					wybieranie();
				}
				else{
					cout<<"przegrana :("<<endl;
					cout<<wynik<<endl;
					oczko(pieniadze,wynik);
					cout<<"suma Gracza "<<suma<<endl;	
					cout<<"suma SI "<<sumaSI<<endl;
					
						if(pieniadze>0){
							wybieranie();
						}
						else{
							cout<<"Wynik :"<<wynik<<endl<<endl;
							
							zapisywanieWynikow(imie,wynik);
							wyswietlanieWynikow();
						}
					
				}

}					
							
////////////////////koniec funkcji oczko	
//////////////////////////////////////////////////////////////////////////////////
void fun(int &pieniadze, int &wynik){
	
		
		
	
	
	
	int kasa = 0;
	int roznica = pieniadze - kasa;
	char klawisz;
	
	
	
	cout<<"strzalka w gore pieniadze + 100,w dol -100, w lewo /2 w prawo *2, spacja ustawia 1000 //2x F1 zeby wyjsc"<<endl;
	do{
	
	
	
	
	klawisz = _getch();
	
	
	
	switch(klawisz){
		
		
		
		//--------------------------------------
		case UP_ARROW:
			system("cls");
			cout<<"strzalka w gore pieniadze + 100,w dol -100, w lewo /2 w prawo *2, spacja ustawia 1000 "<<endl;
		if(kasa+100<=pieniadze){
			kasa+=100;
			cout<<"kasa = "<<kasa<<endl;
			roznica = pieniadze - kasa;
			cout<<"pieniadze = "<<roznica<<endl;
		}
		else{
			kasa = pieniadze;	
			cout<<"kasa = "<<kasa<<endl;
			roznica = pieniadze - kasa;
			cout<<"pieniadze = "<<roznica<<endl;		
		}
		break;
		//--------------------------------------
		case DOWN_ARROW:
		system("cls");
		cout<<"strzalka w gore pieniadze + 100,w dol -100, w lewo /2 w prawo *2, spacja ustawia 1000"<<endl;
		if(kasa-100>=0){
			kasa-=100;
			cout<<"kasa = "<<kasa<<endl;
			roznica = pieniadze - kasa;
			cout<<"pieniadze = "<<roznica<<endl;
		}
		else{
			kasa = 0;
			cout<<"kasa = "<<kasa<<endl;
			roznica = pieniadze - kasa;
			cout<<"pieniadze = "<<roznica<<endl;			
		}
		break;
		//--------------------------------------
		case LEFT_ARROW:
		system("cls");
		cout<<"strzalka w gore pieniadze + 100,w dol -100, w lewo /2 w prawo *2, spacja ustawia 1000"<<endl;
		if(kasa/2>=0){
			kasa/=2;
			cout<<"kasa = "<<kasa<<endl;
			roznica = pieniadze - kasa;
			cout<<"pieniadze = "<<roznica<<endl;
		}
		else{
			kasa = 0;
			cout<<"kasa = "<<kasa<<endl;
			roznica = pieniadze - kasa;
			cout<<"pieniadze = "<<roznica<<endl;			
		}
		break;
		//--------------------------------------
		case RIGHT_ARROW:
		system("cls");
		cout<<"strzalka w gore pieniadze + 100,w dol -100, w lewo /2 w prawo *2, spacja ustawia 1000"<<endl;
		if(kasa*2<=pieniadze){
			kasa*=2;
			cout<<"kasa = "<<kasa<<endl;
			roznica = pieniadze - kasa;
			cout<<"pieniadze = "<<roznica<<endl;
		}
		else{
			kasa = pieniadze;
			cout<<"kasa = "<<kasa<<endl;
			roznica = pieniadze - kasa;
			cout<<"pieniadze = "<<roznica<<endl;			
		}
		break;
		//--------------------------------------
		case SPACE:
			system("cls");
			cout<<"strzalka w gore pieniadze + 100,w dol -100, w lewo /2 w prawo *2, spacja ustawia 1000"<<endl;
			kasa = 1000;
			cout<<"kasa = "<<kasa<<endl;
			roznica = pieniadze - kasa;
			cout<<"pieniadze = "<<roznica<<endl;
			break;
		
	}
	
	if(klawisz==F1){
		
		wybieranie();
		
	}
	
	
	
	
	}while(klawisz!=ENTER);
	
	
	
	
	if(kasa ==0){
			cout<<"Musisz podac wiecej niz 0"<<endl;
			fun(pieniadze, wynik);
		}
	
	cout<<"kk "<<kasa<<endl;
	system("cls");
	//-----------------------------------------
	pieniadze = roznica;
	cout<<"wynik = "<<wynik<<endl;
	cout<<"Do obstawienia "<<kasa<<" $$$"<<endl;
	cout<<"Portfel "<<pieniadze<<endl;
	
	//tutaj tez bylo if pieniadze = 0 to zapisywanie wynikow
	
	//-----------------------------------------
	
	srand(time(NULL));
	
	int losuj = rand()%1000+1; //1-1000
	string wybrany ="";
	string wylosowana="";
	string kolor[3] = {"czarny","czerwony","zielony"};
	
	if(losuj != 45 && losuj!= 321 && losuj!= 532 && losuj!= 699 && losuj!= 811 && losuj!=999 && losuj!=11 && losuj!= 730 &&losuj !=11 &&losuj !=900)
	{
	
		if(losuj%2==0){
			
		wylosowana = kolor[0];		
				
		}
		else{
		
		wylosowana = kolor[1];	
			
		}
	}
	else{
		wylosowana = kolor[2];
	}
	
	//----------------------------------------------------------
	klawisz = 0;
	int pointerPosition =1;	
	//----------------------------------------------------------
	
	cout<<"Kliknij cos ..."<<endl;
	do{
		
	klawisz = _getch();	
	
	
	if(klawisz == UP_ARROW){
	
		pointerPosition--;
		
			if(pointerPosition<1)
				pointerPosition = 3;
	}
	if(klawisz == DOWN_ARROW){
		
		pointerPosition++;
		
			if(pointerPosition>3)
				pointerPosition = 1;
	}
	
	switch(pointerPosition){
	
	
	pieniadze = roznica;
	cout<<"wynik = "<<wynik<<endl;
	cout<<"Obstawione "<<kasa<<" $$$"<<endl;
	cout<<"Calkowite pieniadze "<<pieniadze<<endl;

	
	case 1:
	system("cls");
    cout<<">> czerwony"<<endl;
    cout<<"   zielony"<<endl;
    cout<<"   czarny"<<endl;
    cout<<endl;
    break;
   
	case 2:
	system("cls");
    cout<<"   czerwony"<<endl;
    cout<<">> zielony"<<endl;
    cout<<"   czarny"<<endl;
    cout<<endl;  
    break;
    
    case 3:
    system("cls");
    cout<<"   czerwony"<<endl;
    cout<<"   zielony"<<endl;
    cout<<">> czarny"<<endl;
    cout<<endl;
    break;
	}
	
	//tutaj tez if pieniadze = 0 to zapisywanie
		
}while(klawisz!=ENTER);

switch(pointerPosition){
	
	case 1:
    cout<<"Czerwony"<<endl;
	wybrany = kolor[1];
	break;
	
    case 2:
    cout<<"Zielony"<<endl;
    wybrany = kolor[2];
	break;
	
    case 3:
    cout<<"Czarny"<<endl;
    wybrany = kolor[0];
	break;
	
}
	
	if(wybrany == wylosowana){
		
		cout<<"brawo"<<endl;
		
		if(wybrany == kolor[2]){
			pieniadze+=kasa*14;
			wynik+=kasa*14;
		}
		else{
			pieniadze+=kasa*2;
			wynik+=kasa*2;	
		}
		cout<<"wynik = "<<wynik<<endl;
		cout<<"Calkowite pieniadze "<<pieniadze<<endl;	
		fun(pieniadze, wynik);		
	}
	else{
		cout<<"nastepnym razem sie uda !!!"<<endl;
		cout<<"wynik = "<<wynik<<endl;
		cout<<"Calkowite pieniadze "<<pieniadze<<endl;
		if(pieniadze == 0){
			cout<<"Wynik :"<<wynik<<endl<<endl;
			zapisywanieWynikow(imie,wynik);
		}
		else{
		
		fun(pieniadze, wynik);
		}
	}

	
	
		
	
}

	
//////////////////////////////////////////////////////////////////////////////////	
void wyswietlanieWynikow(){
	
	fstream plik;
	plik.open("tablicaWynikow.txt",ios::in |ios::out| ios::app);	
	
		if(plik.good() == false){
			cout<<"Nie mozna otworzyc pliku"<<endl;
			exit(0);
		}
			
	int licznik=1;
	int nrP = 0;
	int nrP2 = 0;	
	string nazwa[200];
	int wynik[200] = {0};
	string linia;
	
/////////////////////////////////////////////////////////////////
do{
	plik>>linia;
		
	switch(licznik%2)
{
case 1:
    nazwa[nrP]=linia;
    nrP++;
    break;
    
   
case 0:
    wynik[nrP2]=stoi(linia);
    nrP2++;
    break; 
	 
	}
licznik++;
}while(!plik.eof());




	
///////////////////////////////////////////////////////////////////
/////////////////////Tutaj bedzie sortowanie///////////////////////
/////////////////////////////////////////////////////////////////// 
   
int tabSize = nrP2;
int liczEl = 0;
	
while(liczEl!=tabSize){
	for(int i=0;i<=tabSize;i++){
		
		if(i!=0 && wynik[i]>wynik[i-1]){
			swap(wynik[i-1],wynik[i]);
			swap(nazwa[i-1],nazwa[i]);
		
			}
		
		
	
	}
	
	liczEl++;
}
	
    
/////////////////////////////////////////////////////////////////// 

   
	for(int i=0;i<nrP2;i++){
		
		
		if(i<=99){
		
		cout<<i+1<<".\t"<<nazwa[i]<<" "<<wynik[i]<<endl;
		}
	}	
	 	
	plik.close();
	///////////////////////
	int klawisz = _getch();
	wybieranie();
	//////////////////////
}


///////////////////////////////////////////////
/////funkcja wybierania gry////////////////////
///////////////////////////////////////////////



///////////////////////////////////////////////
public:
void wybieranie(){

	char klawisz;
	int pointerPosition =1;
	int menuSize = 4;
	cout<<"Nacisnij dowolny klawisz ..."<<endl;
	do{		
	
	klawisz = _getch();
	system("cls");	
	
	if(klawisz == UP_ARROW){
	
		pointerPosition--;
		
			if(pointerPosition<1)
				pointerPosition = menuSize;
	}
	if(klawisz == DOWN_ARROW){
		
		pointerPosition++;
		
			if(pointerPosition>menuSize)
				pointerPosition = 1;
	}
	
		
	switch(pointerPosition){
	
	case 1:
    cout<<">> oczko"<<endl;
    cout<<"   ruletka"<<endl;
    cout<<"   bandyta"<<endl;
    cout<<endl;
    cout<<"   WYNIKI"<<endl;
    break;
   
	case 2:
    cout<<"   oczko"<<endl;
    cout<<">> ruletka"<<endl;
    cout<<"   bandyta"<<endl;
    cout<<endl;
    cout<<"   WYNIKI"<<endl;
    break;
    
    case 3:
    cout<<"   oczko"<<endl;
    cout<<"   ruletka"<<endl;
    cout<<">> bandyta"<<endl;
    cout<<endl;
    cout<<"   WYNIKI"<<endl;
    break;
    
    case 4:
    cout<<"   oczko"<<endl;
    cout<<"   ruletka"<<endl;
    cout<<"   bandyta"<<endl;
    cout<<endl;
    cout<<">> WYNIKI"<<endl;
    break;
    
	}	
}while(klawisz!=ENTER);
	
	system("cls");

switch(pointerPosition){

	
	case 1:
    cout<<"Wybrales oczko..."<<endl;
	Sleep(1000); 
    system("cls");
    oczko(pieniadze,wynik);
	break;
	
    case 2:
    cout<<"Wybrales ruletke..."<<endl;
    Sleep(1000);
    system("cls");
    fun(pieniadze, wynik);
	break;
	
    case 3:
    cout<<"Wybrales bandyte..."<<endl;
    Sleep(1000);
    system("cls");
    bandyta(pieniadze,wynik);
	break;
	
    case 4:
	wyswietlanieWynikow(); 
	break;  
    
    
    
	}
}

///////////////// koniec klasy kasyno
}; 


int main(){
	
Kasyno gracz;	
gracz.podajNazwe();
gracz.losowaniePieniedzy();
cout<<gracz.imie<<" ma "<<gracz.pieniadze<<" $$$"<<endl;	
Sleep(1000);
system("cls");
gracz.wybieranie();
	
}
