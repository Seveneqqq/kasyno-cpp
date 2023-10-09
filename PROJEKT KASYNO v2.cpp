//Biblioteki
#include <iostream>
#include <time.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <stdio.h>
#include <windows.h>
#include <algorithm>
#include <conio.h>
#include <fstream>

//Przypisanie klawiszy
const int UP_ARROW = 72;
const int DOWN_ARROW = 80;
const int RIGHT_ARROW = 77;
const int ENTER = 13;
const int SPACE = 32;
const int F1 = 59;


//Przypisanie klawiszy

using namespace std;

//KLASA
class KASYNO{

public:
	
string imie;	
int	gotowka;
int ilePostawione=0;	
int	wynik=0;
int cash;

string wczytanieImienia(){
	
	do{	
	cout<<"podaj imie (maks 15 znakow)"<<endl;
	getline(cin,imie);
	}while(imie.length()>15 || imie.length()<=0);
	
	
	for(int i=0;i<imie.length();i++){
		if(imie.at(i)==' ' && i<imie.length())
			imie.at(i)='_';
		}
	
	return imie;
}

int losowanieGotowki(){
	
	srand(time(NULL));
	gotowka = rand()%15000+5000;
	return gotowka;
	
}

//wybieranie
void menu(){

	char przycisk;
	
	Sleep(1000);
	system("cls");
	
	cout<<"Wybierz sterujac numerami"<<endl;
	
	//wyglad menu	
	cout<<"1.	oczko"<<endl;
    cout<<"2.	ruletka"<<endl;
    cout<<"3.	bandyta"<<endl;
    cout<<endl;
    cout<<"4.	WYNIKI"<<endl;
    //wyglad menu
    
	do{
	przycisk = _getch();	
	switch(przycisk){
	
	case 49:
    cout<<"Wybrales oczko"<<endl;
	Sleep(1000);
	system("cls");
	oczko(gotowka,wynik,ilePostawione);
	break;
	
    case 50:
    cout<<"Wybrales ruletke"<<endl;
    Sleep(1000);
    system("cls");
    ruletka(gotowka,wynik,ilePostawione);
	break;
	
    case 51:
    cout<<"Wybrales bandyte"<<endl;
    Sleep(1000);
    system("cls");
    bandyta(gotowka,wynik,ilePostawione);
	break;
	
    case 52:
	cout<<"Wybrales wyniki"<<endl;
	Sleep(1000);
	system("cls");
	wyniki();
	break;
    
		}	
	}while(przycisk!=49/* 1 */ && przycisk!=50/* 2 */ && przycisk!=51/* 3 */ && przycisk!=52/* 4 */);
	
}
//koniec wybierania

private:

//funkcja ile pieniedzy chce gracz obstawic

void obstawianie(int &ilePostawione, int &gotowka){
	
	char przycisk;
	
	do{
		
	cash = gotowka - ilePostawione; 

	cout<<"Ile chcesz obstawic : 1>>1000, ^ == +100, v == -100, > == *2  ENTER PO WYBRANIU KWOTY ||| SPACJA POWROT DO MENU"<<endl;

	 przycisk=_getch();
		
			switch(przycisk){

		case UP_ARROW:
			system("cls");
			cout<<"Ile chcesz obstawic : 1>>1000, ^ == +100, v == -100, > == *2  ENTER PO WYBRANIU KWOTY ||| SPACJA POWROT DO MENU"<<endl;
		if(ilePostawione+100<=gotowka){
			ilePostawione+=100;
			cout<<"IlePostawione = "<<ilePostawione<<endl;
			cash= gotowka - ilePostawione;
			cout<<"Gotowka = "<<cash<<endl;
		}
		else{
			ilePostawione = gotowka;	
			cout<<"ilePostawione = "<<ilePostawione<<endl;
			cash = gotowka - ilePostawione;
			cout<<"gotowka = "<<cash<<endl;		
		}
		break;
		
		case DOWN_ARROW:
		system("cls");
		cout<<"Ile chcesz obstawic : 1>>1000, ^ == +100, v == -100, > == *2  ENTER PO WYBRANIU KWOTY ||| SPACJA POWROT DO MENU"<<endl;
		if(ilePostawione-100>=0){
			ilePostawione-=100;
			cout<<"ilePostawione = "<<ilePostawione<<endl;
			cash = gotowka - ilePostawione;
			cout<<"gotowka = "<<cash<<endl;
		}
		else{
			ilePostawione = 0;
			cout<<"ilePostawione = "<<ilePostawione<<endl;
			cash = gotowka - ilePostawione;
			cout<<"gotowka = "<<cash<<endl;			
		}
		break;
	
	
		case RIGHT_ARROW:
		system("cls");
		cout<<"Ile chcesz obstawic : 1>>1000, ^ == +100, v == -100, > == *2  ENTER PO WYBRANIU KWOTY ||| SPACJA POWROT DO MENU"<<endl;
		if(ilePostawione*2<=gotowka){
			ilePostawione*=2;
			cout<<"ilePostawione = "<<ilePostawione<<endl;
			cash = gotowka - ilePostawione;
			cout<<"gotowka = "<<cash<<endl;
		}
		else{
			ilePostawione = gotowka;
			cout<<"ilePostawione = "<<ilePostawione<<endl;
			cash = gotowka - ilePostawione;
			cout<<"gotowka = "<<cash<<endl;			
		}
		break;
		
		case 49: //1
			system("cls");
			cout<<"Ile chcesz obstawic : 1>>1000, ^ == +100, v == -100, > == *2  ENTER PO WYBRANIU KWOTY ||| SPACJA POWROT DO MENU"<<endl;
			ilePostawione = 1000;
			cout<<"ilePostawione = "<<ilePostawione<<endl;
			cash = gotowka - ilePostawione;
			cout<<"gotowka = "<<cash<<endl;
			break;
		
	}
	
	if(przycisk==SPACE){
		
		menu();
		
	}
		
}while(przycisk !=ENTER);

	if(ilePostawione == 0){
			cout<<"Zla kwota"<<endl;
			obstawianie(ilePostawione,gotowka);
		}


	system("cls");	
	gotowka = cash;	
	cout<<"Gotowka (portfel)>> "<<gotowka<<endl;
	cout<<"Postawiono >> "<<ilePostawione<<endl;
	
}

//koniec obstawiania

//oczko
void oczko(int &gotowka, int &wynik,int &ilePostawione){
	
	obstawianie(ilePostawione,gotowka);
	system("cls");
	cout<<"---------------------------------------"<<endl;
	cout<<"Wynik >> "<<wynik<<endl;
	cout<<"Gotowka >> "<<gotowka<<endl;
	cout<<endl<<endl<<"Ile postawiono >> "<<ilePostawione<<endl;
	cout<<"---------------------------------------"<<endl<<endl;
	Sleep(1000);
	
	srand(time(NULL));
	char przycisk;
	int ruchGracza,ruchKomputera;
	int sumaGracza = 0,sumaKomputera = 0;
	do{
	Sleep(500);
	system("cls");
	cout<<"Suma aktualna "<<sumaGracza<<endl;
	cout<<endl<<"ENTER LOSUJE DALEJ KARTE,SPACJA KONCZY RUNDE"<<endl<<endl;
	
	
	do{
	przycisk=_getch();
	}while(przycisk!=SPACE && przycisk != ENTER);
	if(przycisk==ENTER){
		
		
	
	
	system("cls");
	ruchGracza = rand()%24+1;
	Sleep(500);
	ruchKomputera = rand()%6+9;
	
	if(ruchGracza== 1 || ruchGracza== 7 || ruchGracza== 13 || ruchGracza== 19){
		cout<<"Twoja karta to >> 9"<<endl;
		cout<<"Suma "<<sumaGracza<<" +"<<0<<endl;
		sumaGracza+=0;
		cout<<"Suma aktualna "<<sumaGracza<<endl;
	}
	else if(ruchGracza== 2 || ruchGracza== 8 || ruchGracza== 14 || ruchGracza== 20){
		cout<<"Twoja karta to >> 10"<<endl;
		cout<<"Suma "<<sumaGracza<<" +"<<10<<endl;
		sumaGracza+=10;
		cout<<"Suma aktualna "<<sumaGracza<<endl;
	}
	else if(ruchGracza== 3 || ruchGracza== 9 || ruchGracza== 15 || ruchGracza== 21){
		cout<<"Twoja karta to >> WALET"<<endl;
		cout<<"Suma "<<sumaGracza<<" +"<<2<<endl;
		sumaGracza+=2;
		cout<<"Suma aktualna "<<sumaGracza<<endl;
	}
	else if(ruchGracza== 4 || ruchGracza== 10 || ruchGracza== 16 || ruchGracza== 22){
		cout<<"Twoja karta to >> DAMA"<<endl;
		cout<<"Suma "<<sumaGracza<<" +"<<3<<endl;
		sumaGracza+=3;
		cout<<"Suma aktualna "<<sumaGracza<<endl;
	}
	else if(ruchGracza== 5 || ruchGracza== 11 || ruchGracza== 17 || ruchGracza== 23){
		cout<<"Twoja karta to >> KROL"<<endl;
		cout<<"Suma "<<sumaGracza<<" +"<<4<<endl;
		sumaGracza+=4;
		cout<<"Suma aktualna "<<sumaGracza<<endl;
	}
	else if(ruchGracza== 6 || ruchGracza== 12 || ruchGracza== 18 || ruchGracza== 24){
		cout<<"Twoja karta to >> AS"<<endl;
		cout<<"Suma "<<sumaGracza<<" +"<<11<<endl;
		sumaGracza+=11;
		cout<<"Suma aktualna "<<sumaGracza<<endl;
	}
	
	switch(ruchKomputera){
		
		case 9:
			sumaKomputera+=0;
		break;
		
		case 10:
			sumaKomputera+=10;
		break;
		
		case 11:
			sumaKomputera+=2;
		break;
		
		case 12:
			sumaKomputera+=3;
		break;
		
		case 13:
			sumaKomputera+=4;
		break;
		
		case 14:
			sumaKomputera+=11;
		break;
		
	}
	
	
	
}
else if(przycisk == SPACE){
	break;
}	
	
	}while(przycisk!=SPACE && sumaGracza<21 && sumaKomputera<21);
	cout<<"Suma koncowa Gracza "<<sumaGracza<<endl;
	cout<<"Suma koncowa Komputera "<<sumaKomputera<<endl;
	cout<<"koniec"<<endl;
	
	cout<<"---------------------------------------"<<endl;

	if(sumaGracza>sumaKomputera && sumaGracza<22 ){
		//wygrana
		
					cout<<"BRAWO !!!"<<endl;
					wynik+=ilePostawione*2;
					gotowka+=ilePostawione*2;
					cout<<"Wynik >> "<<wynik<<endl;
					cout<<"Gotowka >> "<<gotowka<<" $$$"<<endl;
					cout<<"suma Gracza "<<sumaGracza<<endl;	
					cout<<"suma przeciwnika "<<sumaKomputera<<endl;
					cout<<"---------------------------------------"<<endl;
					oczko(gotowka,wynik,ilePostawione);
		
		
	}
	else if(sumaGracza<sumaKomputera && sumaKomputera>21){
		//wygrana
					cout<<"BRAWO !!!"<<endl;
					wynik+=ilePostawione*2;
					gotowka+=ilePostawione*2;
					cout<<"Wynik >> "<<wynik<<endl;
					cout<<"Gotowka >> "<<gotowka<<endl;
					cout<<"suma Gracza "<<sumaGracza<<endl;	
					cout<<"suma przeciwnika "<<sumaKomputera<<endl;
					cout<<"---------------------------------------"<<endl;
					oczko(gotowka,wynik,ilePostawione);
		
		
	}
	else if(sumaGracza==sumaKomputera && sumaGracza<22){
		//remis
					cout<<"REMIS !!!"<<endl;
					cout<<"suma Gracza "<<sumaGracza<<endl;	
					cout<<"suma przeciwnika "<<sumaKomputera<<endl;
					cout<<"---------------------------------------"<<endl;
					wynik+=ilePostawione;
					gotowka+=ilePostawione;
					oczko(gotowka,wynik,ilePostawione);
	}
	else if(sumaGracza<22 && sumaKomputera>21){
		//wygrana
					cout<<"BRAWO !!!"<<endl;
					wynik+=ilePostawione*2;
					gotowka+=ilePostawione*2;
					cout<<"Wynik >> "<<wynik<<endl;
					cout<<"Gotowka >> "<<gotowka<<endl;
					cout<<"suma Gracza "<<sumaGracza<<endl;	
					cout<<"suma przeciwnika "<<sumaKomputera<<endl;
					cout<<"---------------------------------------"<<endl;
					oczko(gotowka,wynik,ilePostawione);
	}
	else{
		
					cout<<"Powodzenia nastepnym razem"<<endl;
					cout<<"Wynik >> "<<wynik<<endl;
					cout<<"Gotowka >> "<<gotowka<<endl;
					cout<<"suma Gracza "<<sumaGracza<<endl;	
					cout<<"suma przeciwnika "<<sumaKomputera<<endl;
					cout<<"---------------------------------------"<<endl;
					if(gotowka!=0){
					oczko(gotowka,wynik,ilePostawione);
					}
					else{
					zapisywanie(imie,wynik);
					wyniki();
					}
		
	}
	
}//koniec oczka

//ruletka
void ruletka(int &gotowka, int &wynik,int &ilePostawione){
	
	obstawianie(ilePostawione,gotowka);
	system("cls");
	cout<<"---------------------------------------"<<endl;
	cout<<"Wynik >> "<<wynik<<endl;
	cout<<"Gotowka >> "<<gotowka<<endl;
	cout<<endl<<endl<<"Ile postawiono >> "<<ilePostawione<<endl;
	cout<<"---------------------------------------"<<endl<<endl;
	Sleep(1000);
	
	srand(time(NULL));
	
	int wylosowana = rand()%5;
	int wybrana,przycisk;
	
	string markaSamochodu[5]={"BMW","AUDI","MERCEDES","FORD","VOLKSWAGEN"};
	
	system("cls");
	cout<<"1."<<markaSamochodu[0]<<endl;
	cout<<"2."<<markaSamochodu[1]<<endl;
	cout<<"3."<<markaSamochodu[2]<<endl;
	cout<<"4."<<markaSamochodu[3]<<endl;
	cout<<"5."<<markaSamochodu[4]<<endl;
	
do{
	
	
	 przycisk =_getch();
	
}while(przycisk!=49/* 1 */ && przycisk!=50/* 2 */ && przycisk!=51/* 3 */ && przycisk!=52/* 4 */ && przycisk!=53 /*5*/);	
	
	switch(przycisk){
		
	case 49:
	system("cls");	
	cout<<"1."<<markaSamochodu[0]<<endl;
	wybrana = 0;
	
	break;	
		
	case 50:
	system("cls");	
	cout<<"2."<<markaSamochodu[1]<<endl;	
	wybrana = 1;
	
	break;
	
	case 51:
	system("cls");	
	cout<<"3."<<markaSamochodu[2]<<endl;
	wybrana = 2;

	break;
	
	case 52:
	system("cls");	
	cout<<"4."<<markaSamochodu[3]<<endl;
	wybrana = 3;

	break;
	
	case 53:
	system("cls");
	cout<<"5."<<markaSamochodu[4]<<endl;
	wybrana = 4;

	break;	
		
	}
	
	
	if(wybrana == wylosowana){
		
		wynik+=ilePostawione*2;
		gotowka+=ilePostawione*2;
		
		cout<<"---------------------------------------"<<endl;
		cout<<"Brawo wygrales"<<endl;
		cout<<"Obstawiles "<<ilePostawione<<" na "<<markaSamochodu[wybrana]<<endl;
		cout<<"Wynik >> "<<wynik<<endl;
		cout<<"Gotowka >> "<<gotowka<<endl;
		cout<<"---------------------------------------"<<endl<<endl;
		Sleep(1000);
		ruletka(gotowka,wynik,ilePostawione);
	}
	else{
		
		cout<<"---------------------------------------"<<endl;
		cout<<"Niestety nie udalo ci sie, wylosowany samochod to >> "<<markaSamochodu[wylosowana]<<endl;
		cout<<"Obstawiles "<<ilePostawione<<" na "<<markaSamochodu[wybrana]<<endl;
		cout<<"Wynik >> "<<wynik<<endl;
		cout<<"Gotowka >> "<<gotowka<<endl;
		cout<<"---------------------------------------"<<endl<<endl;
		Sleep(1000);
		if(gotowka!=0){	
		ruletka(gotowka,wynik,ilePostawione);	
		}
		else{
		zapisywanie(imie,wynik);
		wyniki();
		}
		
	}
	
}
//koniec ruletki

//bandyta
void bandyta(int &gotowka,int &wynik,int &ilePostawione){
	int przycisk;
	
	obstawianie(ilePostawione,gotowka);
	system("cls");
	cout<<"---------------------------------------"<<endl;
	cout<<"Wynik >> "<<wynik<<endl;
	cout<<"Gotowka >> "<<gotowka<<endl;
	cout<<endl<<endl<<"Ile postawiono >> "<<ilePostawione<<endl;
	cout<<"---------------------------------------"<<endl<<endl;
	Sleep(1000);
	

		cout<<endl<<endl<<"Losuj ENTER"<<endl;
		
		do{
		przycisk = _getch();	
		}while(przycisk!=ENTER);
		
		int tablica[3];
		string znaki[3] = {"=)","=|","=("};	
					
				cout<<endl<<endl<<endl;
				
				
				cout<<"------------------------------"<<endl;
				cout<<"\t";
				srand(time(NULL));
				
				
				for(int i=0; i<3;i++){
				
				int wylosowana = rand()%3;
				tablica[i] = wylosowana;
				cout<<znaki[wylosowana]<<"\t";
				Sleep(500);
			}
					
			cout<<endl<<"------------------------------"<<endl<<endl<<endl<<endl;
			
				if(tablica[0]==tablica[1] && tablica[0]==tablica[2]){
				wynik += ilePostawione*3;
				gotowka += ilePostawione*3;
				cout<<"Wygrales 3 w rzedzie"<<endl;
				Sleep(1000);
				bandyta(gotowka,wynik,ilePostawione);
				
				}
					
				else if(tablica[0]==tablica[1]){
				wynik += ilePostawione*2;
				gotowka +=	ilePostawione*2;
				cout<<"Wygrales 2 w rzedzie"<<endl;
				Sleep(1000);
				bandyta(gotowka,wynik,ilePostawione);		
				}
				
				else{
				cout<<"Przegrales "<<endl;
				cout<<"Wynik >> "<<wynik<<endl;
				cout<<"Gotowka >> "<<gotowka<<endl;
				Sleep(1000);
				if(gotowka == 0){
					
					zapisywanie(imie,wynik);
					wyniki();
					}
				bandyta(gotowka,wynik,ilePostawione);			
				}
}
//koniec bandyty
//wyniki
	void wyniki(){
	
	fstream plik;
	plik.open("wyniki.txt",ios::in |ios::out| ios::app);	
	
		if(plik.good() == false){
			cout<<"Program napotkal problem"<<endl;
			
		}
		
	string wiersz;		
	int licznik=1;
	int tab1 = 0;
	int tab2 = 0;	
	string imie[200];
	int wynik[200] = {0};
	
	

do{
	plik>>wiersz;
		
	switch(licznik%2)
{
	
	case 0:
    wynik[tab2]=stoi(wiersz);
    tab2++;
    break; 
    
    case 1:
    imie[tab1]=wiersz;
    tab1++;
    break;
	 
	}
licznik++;
}while(!plik.eof());
    
int licznik2 = 0;   
int rozmiarTablicy = tab2;

	
while(licznik2!=rozmiarTablicy){
	for(int i=0;i<=rozmiarTablicy;i++){
		
		if(i!=0 && wynik[i]>wynik[i-1]){
			swap(wynik[i-1],wynik[i]);
			swap(imie[i-1],imie[i]);
		
			}
	
	}
	
	licznik2++;
}
	
	for(int i=0;i<tab2;i++){	
		if(i<100){
		cout<<i+1<<".\t"<<imie[i]<<" "<<wynik[i]<<endl;
		}
	}	
	 	
	plik.close();

	int przycisk = _getch();
	menu();
	
}
//koniec wynikow
//zapisywanie
void zapisywanie(string imie, int wynik){
	
	fstream plik;
	 
	plik.open("wyniki.txt",ios::out|ios::app);
	
	plik<<imie<<" "<<wynik<<endl;
	
	plik.close();
	
	menu();
	
}	
//koniec zapisywania
public:
//deklaracja konstruktora
KASYNO(string imie,int gotowka){
	
	wczytanieImienia();
	losowanieGotowki();
	if(imie.length()>0){
		
		cout<<"Stworzono obiekt"<<endl;
	}
	else{
		cout<<"Program napotkal jakis blad"<<endl;
		}
	
	}	
//koniec deklaracji	
	
};
//KONIEC KLASY

int main(){
	
	//tworzenie obiektu 
	KASYNO gracz("dasd", 0);
	Sleep(1000);
	system("cls");
	cout<<"imie >> "<<gracz.imie<<endl;
	cout<<"gotowka >> "<<gracz.gotowka<<endl;
	gracz.menu();
	
}
