//Przemyslaw Cichocki - KOSTKA RUBIKA.

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

int const MAX_WIERSZY	=9;
int const MAX_KOLUMN	=12;

char const LEWY_GORA	=0xC9;
char const LEWY_DOL		=0xC8;
char const PRAWY_GORA	=0xBB;
char const PRAWY_DOL	=0xBC;
char const POZIOM		=0xCD;
char const PION			=0xBA;
char const SRODEK		=0xCE;
char const SRODEK_GORA	=0xCB;
char const SRODEK_DOL	=0xCA;
char const SPACJA		=' ';

typedef char TABELA[MAX_WIERSZY][MAX_KOLUMN];


void Rysuj_Poziom (int b){
	for(int i=0; i<b; i++){
		cout<<POZIOM;
	}
}

void Wypelnianie_Tabeli3x3(TABELA& tab, int y, int x, char znak){
	for(int i=y; i<y+3; i++){
		for(int j=x; j<x+3; j++){
			tab[i][j]=znak;
		}
	}
}

void Wypelnianie_Tabeli9x12(TABELA& tab){
	Wypelnianie_Tabeli3x3(tab, 0, 0, SPACJA);
	Wypelnianie_Tabeli3x3(tab, 0, 3, 'c');
	Wypelnianie_Tabeli3x3(tab, 0, 6, SPACJA);
	Wypelnianie_Tabeli3x3(tab, 0, 9, SPACJA);

	Wypelnianie_Tabeli3x3(tab, 3, 0, 'a');
	Wypelnianie_Tabeli3x3(tab, 3, 3, 'b');
	Wypelnianie_Tabeli3x3(tab, 3, 6, 'e');
	Wypelnianie_Tabeli3x3(tab, 3, 9, 'f');

	Wypelnianie_Tabeli3x3(tab, 6, 0, SPACJA);
	Wypelnianie_Tabeli3x3(tab, 6, 3, 'd');
	Wypelnianie_Tabeli3x3(tab, 6, 6, SPACJA);
	Wypelnianie_Tabeli3x3(tab, 6, 9, SPACJA);
}

void Rysowanie_Tablicy(TABELA& tab){
	for(int i=0; i<MAX_WIERSZY; i++){
		for(int j=0; j<MAX_KOLUMN; j++){
			cout<<tab[i][j];
		}
		cout<<endl;
	}
}

void Rysowanie_Kostki(TABELA& tab){
	cout<<setw(9)<<LEWY_GORA;
		Rysuj_Poziom(7);
	cout<<PRAWY_GORA;
	cout<<endl;
	for(int i=0; i<MAX_WIERSZY; i++){
		if(i==0)
			cout<< SPACJA;
		for(int j=0; j<MAX_KOLUMN; j++){
			if(j>=0 && j<3)
				cout<< SPACJA << tab[i][j];
			if(j==3)
				cout<<SPACJA << PION << SPACJA << tab[i][j];
			if(j>3 && j<6)
				cout<< SPACJA << tab[i][j];
			if(j==6)
				cout<< SPACJA << PION << SPACJA << tab[i][j];
			if(j>6 && j<9)
				cout<< SPACJA << tab[i][j];
			if(j==9 && i>=3 && i<6)
				cout<< SPACJA << PION << SPACJA << tab[i][j];
			if(j>9 && j<12)
				cout<< SPACJA << tab[i][j];
			if(j==11 && i>=3 && i<6)
				cout<< SPACJA << PION;
		}
		if(i>0 && i<2)
			cout<< SPACJA;
		cout<<endl;
		if(i>=0 && i<2)
			cout<< SPACJA;
		if(i==2){
			cout<<LEWY_GORA;
			Rysuj_Poziom(7);
			cout<<SRODEK;
			Rysuj_Poziom(7);
			cout<<SRODEK;
			Rysuj_Poziom(7);
			cout<<SRODEK_GORA;
			Rysuj_Poziom(7);
			cout<<PRAWY_GORA<<endl;}
		if(i>=2 && i<5)
			cout<<PION;
		if(i==5){
			cout<<LEWY_DOL;
			Rysuj_Poziom(7);
			cout<<SRODEK;
			Rysuj_Poziom(7);
			cout<<SRODEK;
			Rysuj_Poziom(7);
			cout<<SRODEK_DOL;
			Rysuj_Poziom(7);
			cout<<PRAWY_DOL<<endl;}
		if(i>4 && i<9)
			cout<< SPACJA;
	}
	cout<<setw(8)<<LEWY_DOL<<POZIOM<<POZIOM<<POZIOM<<POZIOM<<POZIOM<<POZIOM<<POZIOM<<PRAWY_DOL<<endl;
}

void Operacja_Na_Kostce(TABELA& tab){
	int b;
	cout<<setw(11)<<LEWY_GORA;
		Rysuj_Poziom(7);
	cout<<PRAWY_GORA;
	cout<<endl;
	for(int i=0; i<MAX_WIERSZY; i++){
		if(i==0)
			cout<<setw(4);
		for(int j=0; j<MAX_KOLUMN; j++){
			if(j>=0 && j<3)
				cout<< SPACJA << tab[i][j];
			if(j==3 && i==6)
				cout<<" 7";
			if(j==3 && i==7)
				cout<<" 8";
			if(j==3 && i==8)
				cout<<" 9";
			if(j==3)
				cout<<SPACJA << PION << SPACJA << tab[i][j];
			if(j>3 && j<6)
				cout<< SPACJA << tab[i][j];
			if(j==6)
				cout<< SPACJA << PION << SPACJA << tab[i][j];
			if(j==6 && i==2)
				cout<<setw(12)<<"6 5 4";
			if(j>6 && j<9)
				cout<< SPACJA << tab[i][j];
			if(j==9 && i>=3 && i<6)
				cout<< SPACJA << PION << SPACJA << tab[i][j];
			if(j>9 && j<12)
				cout<< SPACJA << tab[i][j];
			if(j==11 && i>=3 && i<6)
				cout<< SPACJA << PION;
		}
		cout<<endl;
		if(i>=0 && i<2)
			cout<< setw(4);
		if(i==2){
			cout<<setw(3)<<LEWY_GORA;
			Rysuj_Poziom(7);
			cout<<SRODEK;
			Rysuj_Poziom(7);
			cout<<SRODEK;
			Rysuj_Poziom(7);
			cout<<SRODEK_GORA;
			Rysuj_Poziom(7);
			cout<<PRAWY_GORA<<endl;}
		if(i==2)
			cout<<"1 "<<PION;
		if(i==3)
			cout<<"2 "<<PION;
		if(i==4)
			cout<<"3 "<<PION;
		if(i==5){
			cout<<setw(3)<<LEWY_DOL;
			Rysuj_Poziom(7);
			cout<<SRODEK;
			Rysuj_Poziom(7);
			cout<<SRODEK;
			Rysuj_Poziom(7);
			cout<<SRODEK_DOL;
			Rysuj_Poziom(7);
			cout<<PRAWY_DOL<<endl;}
		if(i>4 && i<9)
			cout<< SPACJA;
	}
	cout<<setw(10)<<LEWY_DOL<<POZIOM<<POZIOM<<POZIOM<<POZIOM<<POZIOM<<POZIOM<<POZIOM<<PRAWY_DOL<<endl;
	cout<<setw(17)<<"4 5 6"<<endl;
}

void Akcja_1(TABELA& tab){
	int buff1;
	int buff2;
	int buff3;
//Scianka od gory.
	int box3;
	int box2;
	int box1;

	buff3 = tab[3][11];
	buff2 = tab[3][10];
	buff1 = tab[3][9];
	for(int i=1; i<10; i++){
		tab[3][12-i]=tab[3][(12-i)-3];
	}
	tab[3][2] = buff3;
	tab[3][1] = buff2;
	tab[3][0] = buff1;
///Scianka od gory.
	box3 = tab[0][3];
	box2 = tab[1][3];
	box1 = tab[2][3];

	tab[2][3] = tab[2][5];
	tab[1][3] = tab[2][4];
	tab[0][3] = tab[2][3];

	tab[2][5] = tab[0][5];
	tab[2][4] = tab[1][5];
	tab[2][3] = tab[2][5];

	tab[0][5] = tab[0][3];
	tab[1][5] = tab[0][4];
	tab[2][5] = tab[0][5];

	tab[0][5] = box3;
	tab[0][4] = box2;
	tab[0][3] = box1;
}

void Akcja_2(TABELA& tab){
	int buff1;
	int buff2;
	int buff3;

	buff3 = tab[4][11];
	buff2 = tab[4][10];
	buff1 = tab[4][9];
	for(int i=1; i<10; i++){
		tab[4][12-i]=tab[4][(12-i)-3];
	}
	tab[4][2] = buff3;
	tab[4][1] = buff2;
	tab[4][0] = buff1;
}

void Akcja_3(TABELA& tab){
	int buff1;
	int buff2;
	int buff3;
//Scianka dolna
	int box3;
	int box2;
	int box1;

	buff3 = tab[5][11];
	buff2 = tab[5][10];
	buff1 = tab[5][9];
	for(int i=1; i<10; i++){
		tab[5][12-i]=tab[5][(12-i)-3];
	}
	tab[5][2] = buff3;
	tab[5][1] = buff2;
	tab[5][0] = buff1;
//Scianka dolna
	box3 = tab[6][3];
	box2 = tab[7][3];
	box1 = tab[8][3];

	tab[6][3] = tab[6][3];
	tab[7][3] = tab[6][4];
	tab[8][3] = tab[6][5];

	tab[6][3] = tab[6][5];
	tab[6][4] = tab[7][5];
	tab[6][5] = tab[8][5];

	tab[6][5] = tab[8][5];
	tab[7][5] = tab[8][4];
	tab[8][5] = tab[8][3];

	tab[8][5] = box1;
	tab[8][4] = box2;
	tab[8][3] = box3;
}//w przeciwna strone.

void Akcja_4(TABELA& tab){
	int buff3;
	int buff2;
	int buff1;

//Scianka lewa
	int box3;
	int box2;
	int box1;

	buff3 = tab[0][3];
	buff2 = tab[1][3];
	buff1 = tab[2][3];
	for(int i=6; i>0; i--){
		tab[(9-i)-3][3]=tab[9-i][3];
	}
	tab[6][3] = tab[5][11];
	tab[7][3] = tab[4][11];
	tab[8][3] = tab[3][11];

	tab[5][11] = buff3;
	tab[4][11] = buff2;
	tab[3][11] = buff1;

//Scianka lewa
	box3 = tab[3][0];
	box2 = tab[4][0];
	box1 = tab[5][0];

	tab[3][0] = tab[5][0];
	tab[4][0] = tab[5][1];
	tab[5][0] = tab[5][2];

	tab[5][0] = tab[5][2];
	tab[5][1] = tab[4][2];
	tab[5][2] = tab[3][2];

	tab[5][2] = tab[3][2];
	tab[4][2] = tab[3][1];
	tab[3][2] = tab[3][0];

	tab[3][2] = box3;
	tab[3][1] = box2;
	tab[3][0] = box1;
}

void Akcja_5(TABELA& tab){
	int buff3;
	int buff2;
	int buff1;

	buff3 = tab[0][4];
	buff2 = tab[1][4];
	buff1 = tab[2][4];
	for(int i=6; i>0; i--){
		tab[(9-i)-3][4]=tab[9-i][4];
	}
	tab[6][4] = tab[5][10];
	tab[7][4] = tab[4][10];
	tab[8][4] = tab[3][10];

	tab[5][10] = buff3;
	tab[4][10] = buff2;
	tab[3][10] = buff1;
}

void Akcja_6(TABELA& tab){
	int buff3;
	int buff2;
	int buff1;

//Scianka prawa
	int box3;
	int box2;
	int box1;

	buff3 = tab[0][5];
	buff2 = tab[1][5];
	buff1 = tab[2][5];
	for(int i=6; i>0; i--){
		tab[(9-i)-3][5]=tab[9-i][5];
	}
	tab[6][5] = tab[5][9];
	tab[7][5] = tab[4][9];
	tab[8][5] = tab[3][9];

	tab[5][9] = buff3;
	tab[4][9] = buff2;
	tab[3][9] = buff1;

//Scianka prawa
	box3 = tab[3][6];
	box2 = tab[4][6];
	box1 = tab[5][6];

	tab[3][6] = tab[3][8];
	tab[4][6] = tab[3][7];
	tab[5][6] = tab[3][6];

	tab[3][6] = tab[3][8];
	tab[3][7] = tab[4][8];
	tab[3][8] = tab[5][8];

	tab[3][8] = tab[5][8];
	tab[4][8] = tab[5][7];
	tab[5][8] = tab[5][6];

	tab[5][8] = box1;
	tab[5][7] = box2;
	tab[5][6] = box3;
}

void Akcja_7(TABELA& tab){
	int buff3;
	int buff2;
	int buff1;
//Tutaj miejsce dla wewnetrznej tablicy kostki.
	int box3;
	int box2;
	int box1;

	buff3 = tab[3][2];
	buff2 = tab[4][2];
	buff1 = tab[5][2];

	tab[5][2] = tab[2][3];
	tab[4][2] = tab[2][4];
	tab[3][2] = tab[2][5];

	tab[2][3] = tab[3][6];
	tab[2][4] = tab[4][6];
	tab[2][5] = tab[5][6];

	tab[3][6] = tab[6][5];
	tab[4][6] = tab[6][4];
	tab[5][6] = tab[6][3];

	tab[6][5] = buff1;
	tab[6][4] = buff2;
	tab[6][3] = buff3;
//Wewnetrzna tablica.
	box3 = tab[3][3];
	box2 = tab[4][3];
	box1 = tab[5][3];

	tab[5][3] = tab[3][3];
	tab[4][3] = tab[3][4];
	tab[3][3] = tab[3][5];

	tab[3][3] = tab[3][5];
	tab[3][4] = tab[4][5];
	tab[3][5] = tab[5][5];

	tab[3][5] = tab[5][5];
	tab[4][5] = tab[5][4];
	tab[5][5] = tab[5][3];

	tab[5][5] = box1;
	tab[5][4] = box2;
	tab[5][3] = box3;
}

void Akcja_8(TABELA& tab){
	int buff3;
	int buff2;
	int buff1;

	buff3 = tab[3][1];
	buff2 = tab[4][1];
	buff1 = tab[5][1];

	tab[5][1] = tab[1][3];
	tab[4][1] = tab[1][4];
	tab[3][1] = tab[1][5];

	tab[1][3] = tab[3][7];
	tab[1][4] = tab[4][7];
	tab[1][5] = tab[5][7];

	tab[3][7] = tab[7][5];
	tab[4][7] = tab[7][4];
	tab[5][7] = tab[7][3];

	tab[7][5] = buff1;
	tab[7][4] = buff2;
	tab[7][3] = buff1;
}

void Akcja_9(TABELA& tab){
	int buff3;
	int buff2;
	int buff1;
//Tutaj miejsce dla wewnetrznej tablicy kostki.
	int box3;
	int box2;
	int box1;

	buff3 = tab[3][0];
	buff2 = tab[4][0];
	buff1 = tab[5][0];

	tab[5][0] = tab[0][3];
	tab[4][0] = tab[0][4];
	tab[3][0] = tab[0][5];

	tab[0][3] = tab[3][8];
	tab[0][4] = tab[4][8];
	tab[0][5] = tab[5][8];

	tab[3][8] = tab[8][5];
	tab[4][8] = tab[8][4];
	tab[5][8] = tab[8][3];

	tab[8][5] = buff1;
	tab[8][4] = buff2;
	tab[8][3] = buff3;
//Wewnetrzna tablica.
	box3 = tab[3][9];
	box2 = tab[4][9];
	box1 = tab[5][9];

	tab[5][9] = tab[3][9];
	tab[4][9] = tab[3][10];
	tab[3][9] = tab[3][11];

	tab[3][9] = tab[3][11];
	tab[3][10] = tab[4][11];
	tab[3][11] = tab[5][11];

	tab[3][11] = tab[5][11];
	tab[4][11] = tab[5][10];
	tab[5][11] = tab[5][9];

	tab[5][11] = box1;
	tab[5][10] = box2;
	tab[5][9] = box3;
}

void Sekwencja(TABELA& tab, const string& sekwencja){
	for(int i=0; i<(int)sekwencja.length(); i++){
		char komenda = sekwencja[i];
		switch(komenda){
			case '1':
				Akcja_1(tab);break;

			case '2':
				Akcja_2(tab);break;

			case '3':
				Akcja_3(tab);break;

			case '4':
				Akcja_4(tab);break;

			case '5':
				Akcja_5(tab);break;

			case '6':
				Akcja_6(tab);break;

			case '7':
				Akcja_7(tab);break;

			case '8':
				Akcja_8(tab);break;

			case '9':
				Akcja_9(tab);break;

			default:
				cout<<"!";break;
		}
	}
}

void Menu_Operacji(TABELA& tab){
	bool koniec = false;
	char znak;
	string linia;
	do{
		cout<<endl;
		Operacja_Na_Kostce(tab);
		cout<<endl;
		cout<<"Masz do wyboru operacje: ( 1 - 9 ): "<<endl;
		cout<<"Wcisnij t, aby wpisac sekwencje akcji"<<endl;
		cout<<"0 - Powrot do MENU GLOWENGO"<<endl;
		//znak = getchar();
		cin>>linia;
		znak=linia[0];

		switch(znak){
			case '1':
				Akcja_1(tab);break;

			case '2':
				Akcja_2(tab);break;

			case '3':
				Akcja_3(tab);break;

			case '4':
				Akcja_4(tab);break;

			case '5':
				Akcja_5(tab);break;

			case '6':
				Akcja_6(tab);break;

			case '7':
				Akcja_7(tab);break;

			case '8':
				Akcja_8(tab);break;

			case '9':
				Akcja_9(tab);break;

			case 't':
				{
					string sekwencja;
					cout<<"Podaj sekwencje: ";
					cin>>sekwencja;
					Sekwencja(tab, sekwencja);
				}
				break;

			case '0':
				cout<<"Powrot";
				koniec = true;break;
			default:
				cout<<"Zly klawisz!"<<endl;break;
		}
	}while(!koniec);
}


void Menu(TABELA& tab){
	bool koniec = false;
	char znak;
	string linia;
	do {

		cout<<endl<<"Kostka Rubika - Przemyslaw Cichocki"<<endl<<endl;
		cout<<setw(12)<<".:Menu:."<<endl;
		cout<<"1. Rysuj nowa kostke"<<endl;
		cout<<"2. Operacje na kostce"<<endl;
		cout<<"0. Zakoncz Program"<<endl;
		//znak = getchar();
		//getchar();
		cin>>linia;
		znak = linia[0];
		cout<<endl<<endl;

		switch(znak) {
			case '1':
				Wypelnianie_Tabeli9x12(tab);
				Rysowanie_Kostki(tab);break;

			case '2':
				Menu_Operacji(tab);break;

			case '0':
				cout<<"Koniec"<<endl;
				koniec = true;break;

			default :
				cout<<endl<<"Nieprawidlowy klawisz"<<endl<<endl;break;
		}
	} while(!koniec);
};
		
		
int main()
{
	TABELA kostka;
	Wypelnianie_Tabeli9x12(kostka);
	Menu(kostka);

return 0;
}
