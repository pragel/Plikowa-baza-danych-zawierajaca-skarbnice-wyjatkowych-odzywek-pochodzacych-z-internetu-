#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>

using namespace std;


void wypiszOdzywki(const char* fileName);




int main(int argc, char* argv[])
{
	if (argc != 2) {
		cerr << "Nie podano nazwy pliku bazy danych" << endl;
		return -1;
	}
	const char* plikBazy = argv[1];

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
				wypiszOdzywki(plikBazy);
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

void wypiszOdzywki(const char* fileName)
{
	ifstream infile(fileName);
	string line;

	// Ignore first line
	getline(infile, line);

	while (getline(infile, line)) {
		cout << line << endl;
	}
}
