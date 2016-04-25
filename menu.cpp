#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;


void wypiszOdzywki();
void dodajOdzywke();
void usunOstatniaOdzywke();

int rozmiarBazy = 0;	// tu zapisujemy ile jest odzywek
string* odzywki;	// tu trzymamy odzywki



int main(int argc, char* argv[])
{
	if (argc != 2) {
		cerr << "Nie podano nazwy pliku bazy danych" << endl;
		return -1;
	}

	/** Wczytywanie bazy do pamięci */
	// Najpierw otwieramy plik
	ifstream infile(argv[1]);

	string line;

	// Pierwsza linia zawiera ilosc wpisow
	getline(infile, line);
	rozmiarBazy = atoi(line.c_str());

	cout << "Baza ma " << rozmiarBazy << " wpisow" << endl;
	odzywki = new string[rozmiarBazy];	// dynamiczna tablica ze stringami, gdzie odzywki sobie zapiszemy dla dalszych potrzeb

	for (int n = 0; n < rozmiarBazy; n++) {
		if (!getline(infile, odzywki[n])) break;
	}

	while (true) {
		cout << "MENU GLOWNE" << endl;
		cout << "-----------------" << endl;
		cout << "1. Dodanie odzywki" << endl;
		cout << "2. Usuniecie ostatniej odzywki" << endl;
		cout << "3. Zapisz odzywke" << endl;
		cout << "4. Znajdz odzywke" << endl;
		cout << "5. Wypisanie wszystkich odzywek" << endl;
		cout << "6. Koniec programu" << endl;

		cout << endl;

		switch (getchar()) {
			case '1':
				cout << "Dodanie odzywki" << endl;
				dodajOdzywke();
				break;

			case '2':
				cout << "Usuniecie ostatniej odzywki" << endl;
				usunOstatniaOdzywke();
				break;

			case '3':
				cout << "Zapisz odzywke" << endl;
				break;

			case '4':
				cout << "Znajdz odzywke" << endl;
				break;

			case '5':
				cout << "Wypisanie wszystkich odzywek" << endl;
				wypiszOdzywki();
				break;

			case '6':
				return 0;
				break;

			default:
				cout << "Nie ma takiej opcji w menu!" << endl;
				break;
		}
		getchar();	// chwytamy jeszcze znak enter
	}
	return 0;
}

void wypiszOdzywki()
{
	for (int n = 0; n < rozmiarBazy; n++) {
		cout << (n + 1) << ". " << odzywki[n] << endl;
	}
}

void dodajOdzywke()
{
	string nowaOdzywka;
	cout << "? ";
	cin.ignore();	// Pozbywam sie entera ze strumienia
	getline(cin, nowaOdzywka, '\n');

	string* odzywki2 = new string[rozmiarBazy+1];
	for (int n = 0; n < rozmiarBazy; n++) {
		odzywki2[n] = odzywki[n];
	}
	odzywki2[rozmiarBazy] = nowaOdzywka;	// Dodatkowo dopisuje nowa odzywke
	delete[] odzywki;		// usuwam stare odzywki
	odzywki = odzywki2;	// zapisuje nowe odzywki pod starym wskaznikiem
	rozmiarBazy++;		// zwiekszamy rozmiar bazy
}

void usunOstatniaOdzywke()
{
	if (rozmiarBazy == 0) {
		cerr << "Brak odzywek do usuniecia" << endl;
		return;
	}

	string* odzywki2 = new string[rozmiarBazy-1];
	for (int n = 0; n < rozmiarBazy - 1; n++) {
		odzywki2[n] = odzywki[n];
	}
	delete[] odzywki;
	odzywki = odzywki2;
	rozmiarBazy--;
}
