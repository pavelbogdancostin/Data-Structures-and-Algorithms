#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
#include "../listaD.h"

/*
Intrare

4 1

9 2 7 3

Iesire

2 2 3 3

*/

int main() {
	int r, N;
	int i, val;
	listaD<int> l;

	N = 4; r = 1;
	//cin >> N >> r;

	int NN[] = { 9, 2, 7, 3};

	//int NN[] = { 23, 24, 12, 5, 2, -1, -2, -5, -3, 0, 3, 5};

	for (i = 0; i < N; i++) {
		val = NN[i]; //cin >> data;
		l.adauga(val);
	}

	NOD<int>* v = l.getHEAD(); int nv = 1 + r;
	int poz=0;
	while (poz < r) {
		nv++;
		// scriu min din cele 2 valori

		poz++;
	}

	//v = head; nv = 1 + 2 * r;
	while (poz < N - r) {
		listaD<int> lS;
		
		/*NOD<int>* x = v;
		/*int mn, mx; mn = mx = x->data; lS.adauga(x->data);  x = x->urm;
		for (int i = 1; i < nv; i++) {
			lS.adauga(x->data);
			
			if (x->data < mn)
				mn = x->data;
			else if (x->data > mx)
				mx = x->data;
			x = x->urm;
		}
		cout << l[poz] << "  " << floor((mn + mx) / 2) << "   " << lS << endl;
		//cout << floor ( (mn + mx) / 2 )  << "  ";*/

//		Spunem despre o valoare X din sirul V ca este K - neobisnuita daca este 
	//		de cel putin 2 ori mai mare decat mediana valorilor din K - vecinatatea ei.

//		9 ->[9, 2] -> 2  =   min(9,2)
//		2 ->[9, 2, 7] -> 7  = 9+2+7 = 18, media = 6, [2] comparat cu 6 nu e de 2 ori mai maire
//		7 ->[2, 7, 3] -> 3  = 9+2+7 = 18, media = 6, [2] comparat cu 6 nu e de 2 ori mai maire
//		3 ->[7, 3] -> 3 = min(7,3)

		NOD<int>* x = v;
		for (int i = 0; i < nv; i++) {
			lS.InsertSort(x->data);
			
			x = x->urm;
		}
		//cout << l[poz] << "  " << lS[r] << "  " << lS << endl;
		cout << lS[r] << "  ";

		v = v->urm; poz++;
	}

	while (poz < N) {
		nv--;
		// scriu min din cele 2 valori
		//// 
		v = v->urm; poz++;
	}

	//cout << l;
	cout << endl;
	return 0;
}
