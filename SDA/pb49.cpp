#include <iostream>
#include <fstream>
using namespace std;
//#include "../listaS.h"
#include "../listaD.h"
//#include "../lista2D.h"
//#include "../coadaS.h"
//#include "../coadaD.h"
//#include "../stivaD.h"
#include <string>
/* pb 49
http://info.mcip.ro/?cap=Liste%20inlantuite
#49. [2009-05-03 - 10:16:05]
In doua fisiere text f1.in si f2.in se gasesc 2 multimi A si respectiv B cu elemente numere naturale.
a) Sa se creeze cate o lista liniara simplu inlantuita pentru memorarea elementelor din fiecare dintre cele 2 multimi.
b) Sa se creeze o lista liniara simplu inlantuita care se memoreze reuniunea celor 2 multimi.
c) Sa se creeze o lista liniara simplu inlantuita care se memoreze intersectia celor 2 multimi.
*/


int main() {

	fstream fA("fA.txt", ios::in);
	fstream fB("fB.txt", ios::in);

	listaD<int> A, B, R, I;
	int el;
	while (fA >> el)
		A.adauga(el);
	while (fB >> el)
		B.adauga(el);

	cout << "A= " << A << endl;
	cout << "B= " << B << endl;

	//R = A;
	//citesc elem din B, daca nu exista in R il introduc in R

	A.resetCrt();
	while (A.getCRT(el)){
		R.adauga(el);
		++A;
	}	

	B.resetCrt();
	while (B.getCRT(el)) {
		if(R.lookup(el) == NULL)
			R.adauga(el);
		++B;
	}

	A.resetCrt();
	while (A.getCRT(el)) {
		if (B.lookup(el))
			I.adauga(el);
		++A;
	}

	cout << "R= " << R << endl;
	cout << "I= " << I << endl;

	return 0;
}