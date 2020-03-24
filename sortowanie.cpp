#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <chrono>
using namespace std;



template <class typ>
void wyswietl(vector <typ> tab);
template <class typ>
void sprawdz(vector <typ> & tab);
template <class typ>
void Quicksort(vector <typ> & tab, int lewy, int prawy);
template <class typ>
void Introsort(vector <typ> & tab, int lewy, int prawy);
template <class typ>
void Mergesort(vector <typ> & tab, int pocz, int kon);
template <class typ>
void Odwrotnie(vector <typ> & tab, int lewy, int prawy);

int main()
{
int wielkosc, procent;
int wybor, zmienna, z;
int STOP=0;

const int ilosc = 100;
vector <vector <int>> t(ilosc); 
vector <vector <int>> kopia(ilosc); 
vector <vector <int>> kopia2(ilosc); 

chrono::duration<double> sekundy[ilosc];
auto start = chrono::system_clock::now();
auto stop = chrono::system_clock::now();

    
cout << "Wybierz wielkosc tablic (10000; 50000; 100000; 500000; 1000000) " << endl;
cout << "(Można wybrać inne dla testu)" << endl;
cout << "Twój wybór: ";
cin >> wielkosc;

	for (int i = 0; i < ilosc; i++)		//losowanie
		{
			t[i].clear();
			for (int j = 0; j < wielkosc; j++)
			{
				t[i].push_back(rand() % 1000);
				kopia[i]=t[i];
				kopia2[i]=t[i];
			}
		}
do
{
	cout << endl;
cout << "Co chcesz zrobić? " << endl;
cout << endl;
cout << "1- Losój tablice" << endl;
cout << "2- Wyświel tablice" << endl;
cout << "3- Sortowanie szybkie" << endl;
cout << "4- Sortowanie przez scalanie" << endl;
cout << "5- Sortowanie inrospektywne" << endl;
cout << "6- Sprawdź tablice" << endl;
cout << "7- Wybierz stopień posortowania tablic" << endl;
cout << "8- Porównanie sortowania" << endl;
cout << "0- Zakończ" << endl;
cin >> wybor;

switch (wybor)
	{
	case 1:
	cout << "Wybierz wielkosc tablic (10000; 50000; 100000; 500000; 1000000) " << endl;
	cout << "(Można wybrać inne dla testu)" << endl;
	cout << "Twój wybór: ";
	cin >> wielkosc;

	for (int i = 0; i < ilosc; i++)		//losowanie
		{
			t[i].clear();
			for (int j = 0; j < wielkosc; j++)
			{
				t[i].push_back(rand() % 1000);
				kopia[i]=t[i];
				kopia2[i]=t[i];
			}
		}	
	break;
	case 2:
	  cout << "Tablica:" << endl;
		wyswietl(t[0]);
		break;
	case 3:
		start = chrono::system_clock::now();
		for(int i=0; i<ilosc; i++)
		Quicksort(t[i] , 0, wielkosc - 1);
		stop = chrono::system_clock::now();
		sekundy[0] = stop - start;
		cout << "Czas sortowania szybkiego: " << sekundy[0].count() << " s" << endl;
		break;
	case 4:
		start = chrono::system_clock::now();
		for(int i=0; i<ilosc; i++)
		Mergesort(kopia[i], 0, wielkosc -1);
		stop = chrono::system_clock::now();
		sekundy[0] = stop - start;
		cout << "Czas sortowania przez scalanie: " << sekundy[0].count() << " s" << endl;
		break;
	case 5:
		start = chrono::system_clock::now();
		for(int i=0; i<ilosc; i++)
		Introsort(kopia2[i], 0, wielkosc -1); 
		stop = chrono::system_clock::now();
		sekundy[0] = stop - start;
		cout << "Czas sortowania introspektywnego: " << sekundy[0].count() << " s" << endl;
		break;
		
	case 6:
		sprawdz(t[0]);
		sprawdz(kopia[0]);
		sprawdz(kopia2[0]);
		break;
	case 7:
		cout << "1- Posortowana w 25%" << endl;
		cout << "2- Posortowana w 50%" << endl;
		cout << "3- Posortowana w 75%" << endl;
		cout << "4- Posortowana w 99%" << endl;
		cout << "5- Posortowana w 99.7%" << endl;
		cout << "6- Posortowana w odwrotnej kolejnosci" << endl;
		cin >> zmienna;
		switch (zmienna)
		{
			case 1:
				procent=wielkosc*0.25;
				for(int i=0; i<ilosc; i++){
				Quicksort(t[i] , 0, procent);
				kopia[i]=t[i];
				kopia2[i]=t[i];}
				break;
			case 2:
				procent=wielkosc*0.5;
				for(int i=0; i<ilosc; i++){
				Quicksort(t[i] , 0, procent);
				kopia[i]=t[i];
				kopia2[i]=t[i];}
				break;
			case 3:
				procent=wielkosc*0.75;
				for(int i=0; i<ilosc; i++){
				Quicksort(t[i] , 0, procent);
				kopia[i]=t[i];
				kopia2[i]=t[i];}
				break;
			case 4:
				procent=wielkosc*0.99;
				for(int i=0; i<ilosc; i++){
				Quicksort(t[i] , 0, procent);
				kopia[i]=t[i];
				kopia2[i]=t[i];}
				break;
			case 5:
				procent=wielkosc*0.997;
				for(int i=0; i<ilosc; i++){
				Quicksort(t[i] , 0, procent);
				kopia[i]=t[i];
				kopia2[i]=t[i];}
				break;
			case 6:
				for(int i=0; i<ilosc; i++){
				Odwrotnie(t[i] , 0, wielkosc-1);
				kopia[i]=t[i];
				kopia2[i]=t[i];}
				break;
		}
		break;
	case 8:
	  start = chrono::system_clock::now();
		for(int i=0; i<ilosc; i++)
		Quicksort(t[i] , 0, wielkosc - 1);
		stop = chrono::system_clock::now();
		sekundy[0] = stop - start;
		cout << "Czas sortowania szybkiego: " << sekundy[0].count() << " s" << endl;
		start = chrono::system_clock::now();
		for(int i=0; i<ilosc; i++)
		Mergesort(kopia[i], 0, wielkosc -1);
		stop = chrono::system_clock::now();
		sekundy[0] = stop - start;
		cout << "Czas sortowania przez scalanie: " << sekundy[0].count() << " s" << endl;
		start = chrono::system_clock::now();
		for(int i=0; i<ilosc; i++)
		Introsort(kopia2[i], 0, wielkosc -1); 
		stop = chrono::system_clock::now();
		sekundy[0] = stop - start;
		cout << "Czas sortowania introspektywnego: " << sekundy[0].count() << " s" << endl;
	
		break;
	case 0:
	  STOP=1;
		break;
	}
} while (STOP!=1);



}

template <class typ>
void wyswietl(vector <typ> tab)
{
	for (int i = 0; i < tab.size(); i++)
	{
		cout << tab[i] << endl;
	}
}

template <class typ>
void sprawdz(vector <typ> & tab)
{
	bool ok;
	for (size_t i = 0; i < tab.size() - 2; i++)
	{
		if (tab[i] <= tab[i + 1])
		{
			ok = true;
		}
		else
		{
			ok = false;
		}
	}
	if (ok == true)
	{
		cout << "Tablica posortowana poprawnie" << endl;
	}
	else
	{
		cout << "Tablica posortowana błędnie" << endl;
	}
}

template <class typ>
void Mergesort(vector <typ> & tab, int pocz, int kon)
{
	int srodek;
	if (pocz < kon) {
		srodek = (pocz + kon) / 2;
		Mergesort(tab, pocz, srodek);    // lewa część
		Mergesort(tab, srodek + 1, kon);   // prawa część
	    int *	t = new int[kon+1];
	    int i, j, k;
	    for (i = pocz; i <= kon; i++) t[i] = tab[i];  // kopa tablicy 
	    i = pocz; j = srodek + 1; k = pocz;           // Ustawienie wskaźników tablic
	    for (int k=pocz; k<=kon; k++){
				if (i<= srodek){
					if (j<= kon){
		  		  if (t[i] < t[j]){
			    		tab[k++] = t[i++];
						}
    				else{
	    				tab[k++] = t[j++];
	   			  }}
					else{
	    				tab[k++] = t[i++];
	   			}}
	    else{
			tab[k++] = t[j++];
    }
	}
	delete[] t;
}}


template <class typ>
void Quicksort(vector <typ> & tab, int lewy, int prawy)
{
	int i = lewy;
	int j = prawy;
	int s = tab[(prawy + lewy) / 2];
	do
	{
		while (tab[i] < s)
			i++;

		while (tab[j] > s)
			j--;

		if (i <= j)
		{
			swap(tab[i], tab[j]);

			i++;
			j--;
		}
	} while (i <= j);

	if (lewy < j) 
	Quicksort(tab, lewy, j);

	if (prawy > i) 
	Quicksort(tab, i, prawy);
}


template <class typ>
void Heapify(vector <typ> & tab, int rozmiar, int i)
{
	int lewy = (i + 1) * 2 - 1;
	int prawy = (i + 1) * 2;
	int cos = 0;

	if (lewy < rozmiar && tab[lewy] > tab[i])
		cos = lewy;
	else
		cos = i;

	if (prawy < rozmiar && tab[prawy] > tab[cos])
		cos = prawy;

	if (cos != i)
	{ 
		swap(tab[i], tab[cos]);
		Heapify(tab, rozmiar, cos);
	}
}
template <class typ>
void Heapsort(vector <typ> & tab, int lewy, int prawy)
{

	for (int p = (prawy - 1) / 2; p >= 0; --p)
		Heapify(tab, prawy, p);

	for (int i = prawy - 1; i > 0; --i)
	{
		swap(tab[i], tab[0]);
		--prawy;
		Heapify(tab, prawy, 0);
	}
}
template <class typ>
void Insertionsort(vector <typ> & tab, int lewy, int prawy)
{
	for (int i = 1; i < prawy; ++i)
	{
		int j = i;

		while ((j > lewy))
		{
			if (tab[j - 1] > tab[j])
			{
				swap(tab[j], tab[j - 1]);

				--j;
			}
			else
			{
				break;
			}
		}
	}
}

template <class typ>
void Introsort(vector <typ> & tab, int lewy, int prawy)

{
  if (prawy < 9)
	{
		Insertionsort(tab, lewy, prawy);
	}
	else if (0 > (2*log(prawy)))
	{
		Heapsort(tab, lewy, prawy);
	}
	else
	{
		Quicksort(tab , lewy, prawy);
	}
}

template <class typ>
void Odwrotnie(vector <typ> & tab, int lewy, int prawy)
{
	int i = lewy;
	int j = prawy;
	int s = tab[(prawy + lewy) / 2];
	do
	{
		while (tab[i] > s)
			i++;

		while (tab[j] < s)
			j--;

		if (i <= j)
		{
			swap(tab[i], tab[j]);

			i++;
			j--;
		}
	} while (i <= j);

	if (lewy < j) 
	Odwrotnie(tab, lewy, j);

	if (prawy > i) 
	Odwrotnie(tab, i, prawy);
}
