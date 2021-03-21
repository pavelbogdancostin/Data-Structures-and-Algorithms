#include <iostream>
#include <fstream>
using namespace std;

//#include "../listaD.h"
#include "../lista2D.h"
//#include "../coadaS.h"
//#include "../coadaD.h"
//#include "../stivaD.h"
#include <string>

bool nrPrim(int nr) {
	for (int i = 2; i <= nr / 2; i++) {
		if (nr % i == 0)
			return false;
	}
	return true;
}

class DATA {
	int a;
	float b;
public:
	DATA() {
		a = 0; b = 0;
	}
	DATA(int a1, float b1) {
		a = a1; b = b1;
	}
	void operator = (const DATA& d) {
		a = d.a; b = d.b;
	}
	bool operator == (const DATA& d) {
		return(a == d.a && b == d.b);
	}
	friend ostream& operator << (ostream&, DATA);
};

ostream& operator << (ostream& os, DATA d) {
	os << " [ " << d.a << " , " << d.b << " ] ";
	return os;
}
class carte {
public:
	string titlu;
	string autor;
	string editura;

	/*carte() {
		titlu = autor = editura = " ";
	}
	/*carte(string t, string a, string e) {
		titlu = t, autor = a, editura = e;
	}*/
	void operator = (const carte& d) {
		titlu = d.titlu, autor = d.autor, editura = d.editura;
	}
	bool operator == (const carte& d) {
		return(titlu == d.titlu, autor == d.autor, editura == d.editura);
	}
	friend ostream& operator << (ostream&, carte);
};

ostream& operator << (ostream& os, carte d) {
	os << " ( " << d.titlu <<" "<< d.autor<<" " << d.editura << " ) ";
	return os;
}

typedef struct {
	int a;
	//other fields
	string s1;
	string s2;
} strMyStruct;

class cMyStruct {
//public:
	string s1;
	string s2;
	string s3;
public:
	cMyStruct(string a,string b, string c) {
		s1 = a;
		s2 = b;
		s3 = c;
	}
};
class complex {
public:
	double re;
	double im;
public:
	complex() {
		re = im = 0;
	};
	complex(double a, double b) {
		re = a, im = b;
	} 
	
	complex operator + (complex const& obj) {
		return complex(re + obj.re, im + obj.im);
	}
	void operator = (const complex& d) {
		re = d.re, im = d.im;
	}
	bool operator == (const complex& d) {
		return(re == d.re && im == d.im);
	}

	double modul(void){
		return  sqrt(pow(re, 2) + pow(im, 2));
	}

	// (a+bi)(c+di) = ac + adi + bci + bdi2 = (ac - bd) + i(ad + bc)
	complex operator * (complex const& obj) {
		return complex(   re * obj.re - im * obj.im, re * obj.im  + im * obj.re);
	}
	friend ostream& operator << (ostream&, complex);
};

ostream& operator << (ostream& os, complex d) {
	os << " ( " << d.re << "|" << d.im << "i" << " ) ";
	return os;
}

struct Masina {
	string proprietar;
	string marca;
	int n;
	bool p;
public:
	Masina() {
		proprietar = marca = " ";
		n = 0; 
		p = false;
	}
	Masina(bool _n, bool _p,  string prop, string mas ) {
		n = _n, p = _p, proprietar = prop, marca = mas;
	}
	void operator = (const Masina& d) {
		n = d.n,p=d.p, proprietar = d.proprietar, marca = d.marca;
	}
	bool operator == (const Masina& d) {
		return(n == d.n && p==d.p && proprietar == d.proprietar && marca == d.marca);
	}
	friend ostream& operator << (ostream&, const Masina&);
	friend istream& operator >> (istream&, Masina&);
};

ostream& operator << (ostream& os, const Masina& d) {
	//os << " ( " << d.proprietar << " " << d.marca <<" "<< d.n<<" " <<d.p<< " ) "<<endl;
	os << d.proprietar << " " << d.marca << " " << d.n << " " << d.p;
	return os;
}

istream& operator >> (istream& os, Masina& d) {
	//os << " ( " << d.proprietar << " " << d.marca <<" "<< d.n<<" " <<d.p<< " ) "<<endl;
	os >> d.proprietar >> d.marca >> d.n >> d.p;
	return os;
}

/*
void l2D_1(void) {
	lista2D<DATA> lD; lD.adauga(DATA(1, 2.1f));
	cout << "lista D  " << lD << endl;

	int NR[] = { 1, 2, 4, 6, 7, 8, 9, 44, 66 };
	int max = sizeof(NR) / sizeof(NR[0]);

	lista2D<int> lNR, lP, lI;
	for (int i = 0; i < max; i++)
		lNR.adauga(NR[i]);
	cout << "lista NR  " << lNR << endl;

	for (int i = 0; i < max; i++) {
		if (lNR[i] % 2 == 0) // par
			lP.adauga(lNR[i]);
		else
			lI.adauga(lNR[i]);
	}

	cout << "pare" << lP << endl;

	cout << "impare" << lI << endl;
}
void l2D_2a(void) {
	lista2D<int> l;
	l.adauga(1);
	cout << "lista D  " << l << endl;

	l.resetCrt();
	l.DeleteCrt();

	l.adauga(0); l.adauga(1); l.adauga(2);
	cout << "lista D  " << l << endl;

	l[2]; cout << "sterge [1] " << l << endl;

	l.DeleteCrt();
	cout << "lista D  " << l << endl;

	l.DeleteCrt();
	cout << "lista D  " << l << endl;

	l.DeleteCrt();
	cout << "lista D  " << l << endl;
}

void l2D_2(void) {
	
	int NR[] = { 1, 2, 4, 6, 7, 8, 9, 44, 66 };
	//int NR[] = { 10, 2, 40, 26, 7, 11, 3, 9, 44, 66 };

	lista2D<int> l;
	for (int i = 0, max = sizeof(NR) / sizeof(NR[0]); i < max; i++)
		l.adauga(NR[i]);
	cout << "lista NR " << l << endl;

	int nr;
	while (true) {
		cout << "introduceti nr=";  cin >> nr;
		if (nr == 0)
			break;
		l.adauga(nr);
	}
	cout << "lista " << l << endl;
	
	l.resetCrt();
	while (l.getCRT(nr)) {
		if (nrPrim(nr))
			l.DeleteCrt();
		else ++l;
	}
	cout << "lista finala " << l << endl;
}
*/
void l2D_6(void) {
	int NR[] = { 10, 2, 40, 26, 7, 11, 3, 9, 44, 66 };

	lista2D<int> l, lS;
	for (int i = 0, max = sizeof(NR) / sizeof(NR[0]); i < max; i++) {
		cout << NR[i] << endl;
		cout << l << endl;
		l.adauga(NR[i]);
		cout << l << endl;
	}
//	if(l.test())
//		cout << endl << "eroare" << endl;
	cout << "lista NR" << l << endl;

	l.resetCrt();  int nr, ns;
	while (l.getCRT(nr)) {
		cout << nr << endl;
		lS.resetCrt();
		while (lS.getCRT(ns)) {
			if (nr < ns)
				break;
			++lS;
		}
		cout << lS << endl;
		lS.InsertCrt(nr);
		cout << lS << endl;
		++l;
		if(l.test())
			cout << endl << nr <<  "    eroare" << endl;
	}
	cout << "sortata " << lS << endl;
}

int main() {
	
	//l2D_1();
	//l2D_2();
	l2D_6();

	/*
	stivaD<Masina> c, c2;
	Masina m; string s; int P = 0;
	
	// citim din fisier lista de ieri
	ifstream fr; fr.open("stiva.txt");
	fr >> c;
	fr.close();
	cout << "coada citita"  << endl << c << endl;

	// citim de la tastatura lista de azi
	while (true) {
		int w;
		cout << "introduceti masina ? "; cin >> w;
		if (w == 0)
			break;

		cout << "propietar= "; cin >> m.proprietar;
		cout << "marca= "; cin >> m.marca;
		cout << "preferential [da/nu]= ";
		
		cin >> s;
		m.p = s == "da" ? true : false; if (m.p) P++;
		m.n = 0;

		c.push(m);
		if (c.size() == 10) {
			cout << " s'au introdus deja 10 masini !" << endl;
			break;
		}
	}
	cout << "coada introdusa " << c << endl;

	while (c.size()) {
		int w;
		cout << "prelucrati un dosar ? "; cin >> w;
		if (w == 0)
			break;

		c.pop();
	}
	cout << "coada ramasa pentru a doua zi" << endl << c << endl;

	// a cree o noua coadaD
	NOD<Masina>* n = c.inc;
	while (n) {
		
		Masina m = n->data;
		m.n++;
		c2.push(m);

		n = n->urm;
	}
	cout << "c2  " << c2 << endl;

	// scriere in fisier coada ramasa

	ofstream fw; fw.open("coada.txt");
	fw << c2;
	fw.close();

	cout << "nr masini preferentiale=" << P << endl;


	/*
	cout << " c  " << c << endl;
	// b
	n = c.inc;
	while (n) {
		n->data.n++;
		n = n->urm;
	}
	cout << c << endl;
	*/
	//    sf coada - stiva 



	/*
	int v[]{1,2,3,4,5,6,7,8,9,10};
	coada<int, 10> c;
	for (int i = 0; i < sizeof(v) / sizeof(v[0]); i++) {
		c.push(v[i]);
		cout << c << endl;
	}

	cout << c.front() << endl;
	c.pop();
	c.pop();
	c.push(11);
	c.push(12);
	cout << c << endl;
	*/

	/*listaD<DATA> lD; lD.adauga(DATA(1, 2.1f));
	cout << "lista D" << lD << endl;

	int NR[] = { 1, 2, 4, 6, 7, 8, 9, 44, 66 };
	int max = sizeof(NR) / sizeof(NR[0]);

	listaD<int> lNR, lP, lI;
	for (int i = 0; i < max; i++)
		lNR.adauga(NR[i]);
	cout << "lista NR" << lNR << endl;

	for (int i = 0; i < max; i++){
		if (lNR[i] % 2 == 0) // par
			lP.adauga(lNR[i]);
		else
			lI.adauga(lNR[i]);
	}
	
	cout << "pare" << lP << endl;

	cout << "impare" << lI << endl;
	*/
	
	// sda_lab4 ex2
	/*{
		int s;
		listaD<int> ls;
		while (true) {
			cin >> s;
			if (s == 0)
				break;

			ls.adauga(s);
			cout << ls << endl;
			int i = 0;
			while (s != 0) {
				i = i * 10 + s % 10;
				s = s / 10;
			}
			ls.adauga(i);
			cout << ls << endl;
		}
	}*/
	//ex3 lab4_sda
	/*{	
		listaD<int> ex3;
		int nr;
		while (true) {
			cout << "introduceti nr=";  cin >> nr;
			if (nr == 0)
				break;
			ex3.adauga(nr);
		}
		cout << "lista " << ex3 << endl;
		ex3.resetCrt();
		while (ex3.getCRT(nr)) {
			if (nrPrim(nr))
				ex3.DeleteCrt();
			else ++ex3;
		}
		cout << "lista finala " << ex3 << endl;
	}*/
	
	/*{
		carte v[]{ {"Baltagul","MS","Corint"}, {"Luceafarul","ME","Art"}, {"Ion","LR","Printech"}, {"Testament","TA","Edu"}, {"Plumb","GB","Printech"} };
		listaD<carte> l;
		for (int i = 0, max = sizeof(v) / sizeof(v[0]); i < max; i++) {
			l.adauga(v[i]);
		}
		cout << l << endl;

		carte c;
		l.resetCrt();
		while (l.getCRT(c)) {
			if (c.editura == "Printech")
				cout << c << endl;
			++l;
		}
	}*/
	//ex5
	/*{
		complex v[]{ {1, 1}, {2,2}, {3,3} };

		listaD<complex> l;
		for (int i = 0, max = sizeof(v) / sizeof(v[0]); i < max; i++)
			l.adauga(v[i]);
		cout << l << endl;

		//cout <<l[0].modul() << endl;
		l.resetCrt(); complex c, cX, suma{ 0,0 }, produs{ 1,0 };

		int xm = 0;

		while (l.getCRT(c)) {
			suma = suma + c;
			cout << produs << "  " << c << " " << produs * c;
			produs = produs * c;
			cout << " produs=" << produs << endl;

			if (c.modul() > xm)
				xm = c.modul(), cX = c;

			++l;
		}

		cout << cX << " " << xm << endl;
		cout << "suma=" << suma << "  produs=" << produs << endl;
	}*/
		//ex6
	/*{int NR[] = { 10, 2, 40, 26, 7, 11, 3, 9, 44, 66 };

	listaD<int> l, lS;
	for (int i = 0, max = sizeof(NR) / sizeof(NR[0]); i < max; i++)
		l.adauga(NR[i]);
	cout << "lista NR" << l << endl;

	l.resetCrt();  int nr, ns;
	while (l.getCRT(nr)) {
		lS.resetCrt();
		while (lS.getCRT(ns)) {
			if (nr < ns)
				break;
			++lS;
		}
		lS.InsertCrt(nr);
		// cout << lS << endl;
		++l;
	}
	cout << "sortata " << lS << endl;
	}*/
	//ListaS<DATA> lst;
	/*listaD< DATA > lst;
	
	DATA d[] = { DATA(1, 0), DATA(2, 0), DATA(3, 0), DATA(4, 0), DATA(5, 0) };

	cout << lst << endl;

	if (lst.adauga(d[0]) == EXIT_FAILURE)
		exit(1);

	cout << lst << endl;
	
	lst.adauga(d[1]);  cout << lst << endl;
	lst.adauga(d[2]);  cout << lst << endl;

	cout << lst[2] << endl;
	cout << lst << endl;

	lst.InsertCrt(d[3]); cout << lst << endl;
	lst.InsertCrt(d[4]); cout << lst << endl;
	
	lst.DeleteCrt();  cout << lst << endl;
	lst.DeleteCrt();  cout << lst << endl;


	/*
	cout << lst.lookup(d[0]) << endl;
	cout << lst.lookup(d[1]) << endl;
	cout << lst.lookup(d[2]) << endl;
	
	cout << lst[1] << endl;
	lst[1]; cout << lst << endl;
	lst[2]; cout << lst << endl;
	lst[3]; cout << lst << endl;
	
	lst[0]; cout << lst << endl;
	lst[4]; cout << lst << endl;

/*
	lst.InsertCrt(DATA(1, 1));

	lst.InsertCrt(DATA(2, 2));

	lst.InsertCrt(DATA(3, 3));

	cout << lst << endl;



	// lst.SetCrt = 0; lst.SetCrt(DATA(1, 1));
	lst[0] = DATA(1, 1); cout << lst << endl;
	++lst; cout << lst << endl;
	lst.InsertCrt(DATA(2, 2));
	cout << lst << endl;
	
	while (lst.lookup(DATA(2, 2)) == true) {
		cout << "element gasit pe pozitia " << lst.getCrt() << endl;
		lst.DeleteCrt();
	}
	// cout << "elementul nu s'a gasit !" << endl;
	
	cout << lst << endl;

	*/
	
	/* program laborator nr3-4
	
	listaD<DATA> lst;
	DATA data;
	
	cout << " Lista iniliala:" << endl << lst << endl;
	cout << endl << "Adaug succesiv 2 elemente la sfarsitul listei" << endl;
	DATA d1(1, 2.5f);

	if (lst.adauga(d1) == EXIT_FAILURE)
		exit(1);
	
	lst.lookup(d1);
	
	cout << lst << endl;
	DATA d2(4, 2.9f);
	if (lst.adauga(d2) == EXIT_FAILURE)
		exit(1);
	cout << lst << endl;
	DATA d3(112, 333.999f);
	lst.InsertCrt(d3);
	cout << endl << " Lista dupa inserare pe pozitia 1 " << lst << endl;
	DATA d4(666, 999.1f);
	lst.InsertCrt(d4);
	cout << endl << " Lista dupa inserare pe pozitia 1 " << lst << endl;
	cout << endl << " Modifi care valoare pe pozitia crt ( primul element )" << endl;
	DATA d5(3, 5.7f);
	if (lst.SetCrt(d4))
		exit(1);
	cout << lst << endl;
	lst.SetCrt(data);
	cout << endl << " Citire element crt:" << data << endl;
	cout << endl << " Modificare valoare pe pozitia crt ( primul element), Metoda 2 = operator" << endl;
	
	lst[0] = DATA(27, 10.3f);
	cout << lst << endl;
	cout << endl << " Citire element crt , Metoda 2 = operator:" << endl;
	cout << lst[0] << endl;
	cout << endl << " Avansare in lista " << endl;
	++lst;
	cout << endl << " Inserare element nou pe pozitia crt ( al doilea)" << endl;
	DATA d7(9, 3.7f);
	if (lst.InsertCrt(d7))
		exit(1);
	cout << lst << endl;
	cout << endl << " Avansare in lista" << endl;
	++lst;
	cout << endl << " Eliminare element de pe pozitia crt (al treilea)" << endl;
	if (lst.DeleteCrt())
		exit(1);
	cout << lst << endl;
	cout << endl << " Afisare element sters:" << endl;
	cout << data << endl;
	cout << endl << " Citire element de pe o anumita pozitie(ex.:2)folosind op indexare" << endl;
	cout << lst[2] << endl;
	cout << endl << " Modificare element de pe o anumita pozitie(ex.:2),folosind op indexare" << endl;
	DATA d8(17, 6.7f);
	lst[2] = d8;
	cout << lst << endl;
	data = d8;
	cout << endl << " Se cauta elementul " << data << " in lista" << endl;
	if (lst.lookup(data))
		cout << endl << " Elementul " << data << " a fost gasit in lista" << endl;
	else
		cout << endl << " Elementul " << data << " nu a fost gasit in lista" << endl;
	DATA d9(4, 9.1f);
	data = d9;
	cout << endl << " Se cauta elementul " << data << " in lista " << endl;
	if (lst.lookup(data))
		cout << endl << " Elementul " << data << " a fost gasit in lista" << endl;
	else
		cout << endl << " Elementul " << data << " nu a fost gasit in lista" << endl;
	cout << endl;

	*/
	return 0;
}








// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
