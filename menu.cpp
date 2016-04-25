#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;


void wypiszOdzywki();

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
				break;

			case '2':
				cout << "Usuniecie ostatniej odzywki" << endl;
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
