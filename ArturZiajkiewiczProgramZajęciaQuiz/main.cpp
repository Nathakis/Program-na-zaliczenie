#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
string slowa[20];
int punkty=0;
int *liczba;
int ilosc;
string poprawna;
string odpowiedz;

int main()
{
    setlocale(LC_ALL, "");
    srand(time(NULL));

    cout<<"Witaj w quizie na 5 pytañ!"<<endl;
    cout<<"liczba punktów, któr¹ zdobêdziesz na koniec zostanie powiêkszona o 1 i pomno¿ona razy 365"<<endl;
    cout<<"Otrzymana liczba, bêdzie iloœci¹ wylosowanych liczb, które program ustawi od najmniejszej do najwiêkszej"<<endl;
    cout<<"Gotowy na pierwsze pytanie? Jeœli tak, naciœnij ENTER"<<endl<<endl<<endl<<endl;
    system("pause");
    system ("cls");
    fstream plik ;
    plik.open("pytania_do_quizu.txt",ios::in);
    if(plik.good()==false)
    {
        cout<<"B£¥D ODCZYTU PLIKU, SPRAWD CZY PLIK Z PYTANIAMI JEST W FOLDERZE PROGRAMU";
        exit (0);
    }
    for(int i=0;i<20;i++)
    {
        getline(plik,slowa[i]);
    }
    for(int j=0;j<20;j+=5)
    {
        cout<<slowa[j]<<endl;
        cout<<slowa[j+1]<<endl;
        cout<<slowa[j+2]<<endl;
        cout<<slowa[j+3]<<endl;
        cout<<"Twoja odpowiedz: ";
        cin>>odpowiedz;
        transform(odpowiedz.begin(),odpowiedz.end(),odpowiedz.begin(),::toupper);
        poprawna = slowa [j+4];
        if (poprawna==odpowiedz)
        {
            punkty+=1;
            cout<<endl<<"GRATULACJE, ZDOBY£EŒ PUNKT!!!"<<endl;
            cout<<"Liczba twoich punktów to: "<<punkty<<endl;

        }else{cout<<endl<<"Z£A ODPOWIED!!!"<<endl;}

    }
    cout<<"To ju¿ koniec quizu, teraz przechodzimy dalej, do sortowania. Chcesz przejœæ dalej? Naciœnij ENTER"<<endl<<endl<<endl;
    system("echo off");
    system("pause");
    system("cls");
    cout<<"W poprzednim etapie uda³o Ci siê zdobyæ: "<<punkty<<" punktów"<<endl;
    ilosc=(punkty+1)*365;
    cout<<"Liczba otrzymana po dodaniu do punktów liczby 1 i przemno¿eniu razy 365, to: "<<ilosc<<endl;
    cout<<endl<<endl<<endl;
    cout<<"liczba otrzymana powy¿ej to iloœæ wylosowanych liczb."<<endl<<endl<<endl;
    cout<<"WYLOSOWANE I POSORTOWANE LICZBY: "<<endl;

    liczba = new int [ilosc];
    //LOSOWANIE
    for(int m=0;m<ilosc;m++)
    {
        liczba[m]=rand()%4294967294;
    }

    //SORTOWANIE
    for(int j=0;j<ilosc;j++)
        for(int k=1;k<ilosc;k++)
        if(liczba[k-1]>liczba[k])
            swap(liczba[k-1],liczba[k]);
    //WYPISYWANIE
    for(int l=0;l<ilosc;l++)
    {
        cout<<liczba[l]<<"   ";
    }

    return 0;
}
