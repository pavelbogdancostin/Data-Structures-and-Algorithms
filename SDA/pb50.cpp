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
/*
http://info.mcip.ro/?cap=Liste%20inlantuite
a) Sa se creeze o lista liniara simplu inlantuita care sa memoreze urmatoarele informatii despre elevii unei clase formata din n elevi :
-numele(sir de maxim 20 de caractere)
- prenumele(sir de maxim 20 de caractere)
- 3 note intr - un vector cu 3 componente reale
b) Sa se afiseze numele, prenumele si media fiecarui elev.
c) Sa se scrie o functie care calculeaza si returneaza media clasei.
*/

#define NOTE_NR  3
#define NOTE_SIZE  ( NOTE_NR * sizeof(double) )

struct elev {

	char nume[21];
	char prenume[21];
	double note[NOTE_NR];
	double med;

	elev() {
		// cout << NOTE_SIZE << endl;
		nume[0] = prenume[0] = 0;
		memset(note, 0, NOTE_SIZE); med = 0;
	}
	elev(const char* n, const char* p, const double& n1, const double& n2, const double& n3) {
		strcpy_s(nume, n); strcpy_s(prenume, p);
		note[0] = n1; note[1] = n2; note[2] = n3;
		med = (note[0] + note[1] + note[2]) / NOTE_NR; // media();
	}
	void operator = (const elev & e) {
		strcpy_s(nume, e.nume); strcpy_s(prenume, e.prenume);
		memcpy(note, e.note, NOTE_SIZE); med = e.med;
	}
	bool operator == (const elev & e) {
	/*		if (strcmp(nume, e.nume) == 0 && strcmp(prenume, e.prenume) == 0 && \
				nota[0] == e.note[0] && nota[1] == e.note[1] && nota[2] == e.note[2] && media == e.media)
			return true;
		return false;
	*/
		if (strcmp(nume, e.nume) || strcmp(prenume, e.prenume))
			return false;
		for (int i = 0; i < NOTE_NR; i++)
			if (note[i] != e.note[i])
				return false;
		if (med != e.med)
			return false;
		return true;
	}
	void media(void) {
		med = (note[0] + note[1] + note[2]) / NOTE_NR;
		cout << "media = " << med;
	}
};

ostream& operator << (ostream& os, elev d) {
	os << " [ " << d.nume << "  " << d.prenume << ", note: " << d.note[0] << " " << d.note[1] << " " << d.note[2] << ", media=" << d.med << " ] " << endl;
	return os;
}

//strcpy_s
//strcmp
//strlen

int main() {

	listaD<elev> l;
	l.adauga(elev("nume1", "prenum1", 7, 7, 7));
	l.adauga(elev("nume2", "prenum2", 7, 8, 9));
	l.adauga(elev("nume3", "prenum3", 5, 6, 7));
	l.adauga(elev("nume4", "prenum4", 7, 3, 10));
	l.adauga(elev("nume5", "prenum5", 4, 7, 9));

	cout << l << endl;

	double m = 0; int nr = 0;
	l.resetCrt(); elev el;
	while (l.getCRT(el)) {
		m += el.med; nr++;
		++l;
	}
	m /= nr;

	cout << "media clasei = " << m << endl;
	return 0;
}