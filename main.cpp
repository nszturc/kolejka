#include "kolejka.hpp"
#include "sortowanie.hpp"
#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    queue<int> *lis = new queue<int>;
    queue<int> k;
    sorting<int> s;
    int c = 1;

    while(c != 0)
    {
        system("cls");
        cout << "Program sluzacy do obslugi kolejki priorytetowej." << endl;
        cout << "Mozna w nim rowniez stworzyc nieuporzadkowana liste  " << endl;
        cout << "oraz wykonac na niej sortowanie" << endl;
        cout << " [prio,liczba] " << endl << endl;
        k.printk();
        lis->printl();
        cout << "Polecenia dotyczace kolejki priorytowej" << endl;
        cout << "1 - dodaj element do kolejki" << endl;
        cout << "2 - zwroc element o najmniejszym kluczu " << endl;
        cout << "3 - usun oraz zwroc element o najmniejszym kluczu" << endl;
        cout << "4 - pokaz rozmiar kolejki priorytetowej" << endl;
        cout << "5 - sprawdz czy kolejka pusta" << endl;
        cout << "6 - zwroc element o zadanym indeksie" << endl;
        cout << "7 - zwroc indeks podanego elementu" << endl;
        cout << endl << "Polecenia dotyczace tworzenia i sortowania listy" << endl;
        cout << "8 - dodaj element na poczatek listy" << endl;
        cout << "9 - dodaj element na koniec listy" << endl;
        cout << "10 - sortuj liste przez wybieranie" << endl;
        cout << "11 - sortuj liste przez wstawianie" << endl;
        cout << "12 - test(tworzy liste z dowolna iloscia elementow) " << endl << endl;
        cout << "13 - czysci liste oraz kolejke" << endl;
        cout << "0 - konczy program" << endl << endl << ">>";

        cin >> c;


        switch(c)
        {

        case 0:
            cout << "DO ZOBACZENIA :D" << endl;
            break;

        case 1:
        {
            int prio, liczba;
            cout << "Podaj liczbe ";
            cin >> liczba;
            cout << endl << "oraz jej priorytet " << endl;
            cin >> prio;
            k.insert(liczba, prio);
            break;
        }

        case 2:
        {
            if(!k.isEmpty())
            {
                int c = k.getdata(1);
                int b = k.getprio(1);
                cout << "Element o najmniejszym kluczu to [" << b << "," << c << "]" << endl;
                Sleep(1500);
            }
            else
                cout << "Kolejka pusta!! " << endl;
            Sleep(1000);
            break;
        }
        case 3:
        {
            if(!k.isEmpty())
            {
                int c = k.getdata(1);
                int b = k.getprio(1);
                k.removeMin();
                cout << "Usunieto [" << b << "," << c << "]" << endl;
                Sleep(1000);
            }
            else
                cout << "Kolejka pusta!! " << endl;
            Sleep(1000);
            break;
        }
        case 4:
        {
            int c = k.getcount();
            cout << "Kolejka ma rozmiar : " << c << endl;
            Sleep(1000);
            break;
        }
        case 5:
        {
            bool b = k.isEmpty();
            if(b)
                cout << "Kolejka Pusta!" << endl;
            else
                cout << "Cos tam jest" << endl;
            Sleep(2000);
            break;
        }
        case 6:
        {
            int index;
            cout << "Podaj indeks  >> ";
            cin >> index;
            cout << endl;
            if((index > 0) && (index < k.size()+1))
            {
                cout << "szukany element to [" << k.getprio(index) << "," << k.getdata(index) << "]" << endl;
                Sleep(1500);
                break;
            }
            else
            {
                cout << "Brak elementu o indeksie " << index << endl;
                Sleep(1000);
                break;
            }

        }
        case 7:
        {
            int liczba,prio,index;
            cout << "Priorytet >>";
            cin >> prio;
            cout << "Liczba >> ";
            cin >> liczba;
            index = k.indexOf(liczba,prio);

            if(index>0)
            {
            cout << endl << "Element - [" << prio << ", " << liczba << "]" << endl;
            cout << "ma indeks  -  " << index << endl;
            }
            else cout << "brak takiego elementu jak [" << prio << ", " << liczba << "]" << endl;
            Sleep(2500);
            break;

        }
        case 8:
        {
            int prio, liczba;
            cout << "Podaj liczbe ";
            cin >> liczba;
            cout << endl << "oraz jej priorytet " << endl;
            cin >> prio;
            lis->push_front(liczba, prio);
            break;
        }
        case 9:
        {
            int prio, liczba;
            cout << "Podaj liczbe ";
            cin >> liczba;
            cout << endl << "oraz jej priorytet " << endl;
            cin >> prio;
            lis->push_back(liczba, prio);
            break;
        }
        case 10:
        {
            s.selection(lis);
            break;
        }
        case 11:
        {
            s.insert(lis);
            break;
        }
        case 12:
        {
            while(lis->size()) lis->removeMin();
            int ilosc;
            cout << "Ile chcesz elementow? >>" ;
            cin >> ilosc;
            for(int i=0;i<ilosc;i++)
            {
                int prio = (rand() % 100) + 0;
                int liczba = (rand() % 100) + 0;
                lis->push_front(liczba,prio);
            }
            break;
        }
        case 13:
        {
            while(lis->size()) lis->removeMin();
            while(k.size()) k.removeMin();
            break;
        }
        default:
            cout << "Brak dostepnej funkcji!!" << endl;
            Sleep(1000);
            cout << "Sprobuj jeszcze raz" << endl;
            Sleep(1000);
            break;
        }
    }

    return 0;
}
