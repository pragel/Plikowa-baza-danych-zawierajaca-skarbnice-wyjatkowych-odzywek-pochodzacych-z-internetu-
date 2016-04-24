#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;

int main()
{
	char wybor;
	while(true)
	{
	cout << "MENU GLOWNE" << endl;
    cout << "-----------------" << endl;
    cout << "1. Dodanie odzywki" << endl;
    cout << "2. Usuniecie ostatniej odzywki" << endl;
    cout << "3. Zapisz odzywke" << endl;
    cout << "4. Znajdz odzywke" << endl;
    cout << "5. Wypisanie wszystkich odzywek" << endl;
    cout << "6. Koniec programu" << endl;

	cout << endl;
 
	


    wybor=getch();
    switch(wybor)
    {
    case '1':
            cout << "Dodanie odzywki";
    break;

    case '2':
            cout << "Usuniecie ostatniej odzywki";
    break;

    case '3':
            cout << "Zapisz odzywke";
    break;

    case '4':
    		cout << "Znajdz odzywke";
    break;
	
	case '5':
			cout << "Wypisanie wszystkich odzywek";
	break;
	
    case '6':
            exit(0);
    break;

    default: cout<<"Nie ma takiej opcji w menu!";
    }
 
    getchar();
    system("cls");
	}

return 0;
}
