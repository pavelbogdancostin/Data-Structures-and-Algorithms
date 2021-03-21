#include<iostream>
#include<stdlib.h>

using namespace std;

#define MAX 100

class DATA {
	 int a;
	 float b;
public :
	 DATA() {
		 a = 0; b = 0;
	 }
	 DATA(int a1, float b1) {
		a = a1;
	    b = b1;
	 }
	 bool operator == (DATA x2) {
		 return(a == x2.a && b == x2.b);
	 }
	friend ostream & operator << (ostream&, DATA);
};

ostream & operator << (ostream & os, DATA d) {
	 os << " ( " << d.a << " , " << d.b << " ) ";
	 return os;
}
template < typename DT>
class ListaS;

template < typename DT> // Data Type
class ListaS {
	 DT elem[MAX];
	 int p_crt;
	 int p_sf;
	 public :
	ListaS() {
		 p_crt = p_sf = -1;
	}
	int addElemSf(DT);
    int operator++();
	int operator() (int); // actualizeaza crt functie de nr
    int SetCrtData(DT);
	int InsertCrt(DT);
	int DeleteCrt();
	int getPozCrt() { 	return p_crt; }
	 void StergLista();
	 int Lungime();
	
		 DT & operator[](int);	// returneaza DATA de pe poz nr
	
		 int lookup(DT);
	
		friend ostream & operator << <DT>(ostream&, ListaS<DT>);
};

/*
template < typename DT>
class ListaD1{
	protected :
	 Nod<DT>* inc, * crt, * sf;
		public:
	ListaD1() {
		inc = sf = crt = new Nod<DT>;
	}
	 ~ListaD1();
	int addElemSf(DT);
	int addElemInc(DT);
	int operator++();

	int setCrtData(DT);
	int insertElemDupaCrt(DT);
	int insertElemCrt(DT);
	int deleteCrt(DT&);
	int lungime();

		bool lista_goala(){
		return !(inc->urm);
		}

	int getCrtData(DT&);
	DT &operator[](int);
	DT &operator() ();
	DT &operator()(int);
	int lookup(DT);
	friend ostream & operator << <DT>(ostream&, const ListaD1<DT>&);
};

*/


template < typename DT>
ostream & operator << (ostream & os, ListaS<DT> lst) {
	os << lst.p_sf << " : " << lst.p_crt << " " << " { ";
    for(int p = 0; p <= lst.p_sf; p++)
		os << lst.elem[p] << " ";
	os << "}";
	 return os;
	 }
template < typename DT>
int ListaS<DT>::addElemSf(DT d) {
		if(p_sf<MAX-1){
		 p_sf++;
		 elem[p_sf] = d;
		 return EXIT_SUCCESS;
	}
	 else
		 return EXIT_FAILURE;
}
template < typename DT>
int ListaS<DT>::operator++(){
	 if(p_crt < p_sf) {
		p_crt++;
		return 0;
	 }
	else
	 return 1;
}
template < typename DT>
int ListaS<DT>::operator() (int nr) {
	if(p_sf!=-1 && nr<=p_sf+1 && nr>0){
		 p_crt = nr - 1;
		 return 0;
	}
	return 1;
}
template < typename DT>
int ListaS<DT>::SetCrtData(DT d) {
	 if(p_sf<0 || p_crt>p_sf || p_crt < 0)
		 return 1; // e r o a r e
	elem[p_crt] = d;
	 return 0;
}
template < typename DT>
int ListaS<DT>::InsertCrt(DT d) {
	int i;
	if(p_sf > MAX - 2 || p_crt > p_sf || p_crt < 0)
		return 1; // e r o a r e
		 for(i= p_sf; i>=p_crt; i-- )
		 elem[i + 1] = elem[i];
	     elem[p_crt] = d;
	     p_sf++;
		 return 0;
}
template < typename DT>
int ListaS<DT>::DeleteCrt(){
	int i;
	 if(p_sf<0 || p_crt>p_sf || p_crt < 0)
	 return 1; // e r o a r e
		 for(i = p_crt; i < p_sf; i++)
		elem[i] = elem[i + 1]; // translatarea elementelor cu o pozitie
	 p_sf--;
	 return 0;
}
template < typename DT>
DT & ListaS<DT>::operator[](int p) {
	 return elem[p];
}
template < typename DT>
void ListaS<DT>::StergLista(){
	 p_crt = p_sf = -1;
}
template < typename DT>
int ListaS<DT>::Lungime() {
	 return p_sf + 1;
}
template < typename DT>
int ListaS<DT>::lookup(DT d) {
	int p = 0;
	while(p <= p_sf) {
		if(elem[p] == d) {
			 p_crt = p + 1;
			return 1;
		}
		 p++;
	}
	return 0;
}
int main() {
	ListaS<DATA> lst;
	DATA data;
	cout << " Lista iniliala:" << endl << lst << endl;
	cout << endl << "Adaug succesiv 2 elemente la sfarsitul listei" << endl;
	DATA d1(1, 2.5);

	if (lst.addElemSf(d1) == EXIT_FAILURE)
		exit(1);
	cout << lst << endl;
	DATA d2(4, 2.9);
	if (lst.addElemSf(d2) == EXIT_FAILURE)
		exit(1);
	cout << lst << endl;
	DATA d3(112, 333.999);
	lst.InsertCrt(d3);
	cout << endl << " Lista dupa inserare pe pozitia 1 " << lst << endl;
	DATA d4(666, 999.1);
	lst.InsertCrt(d4);
	cout << endl << " Lista dupa inserare pe pozitia 1 " << lst << endl;
	cout << endl << " Modifi care valoare pe pozitia crt ( primul element )" << endl;
	DATA d5(3, 5.7);
	if (lst.SetCrtData(d5))
		exit(1);
	cout << lst << endl;
	lst.getCrtData(data);
	cout << endl << " Citire element crt:" << data << endl;
	cout << endl << " Modifi care valoare pe pozitia crt ( primul element), Metoda 2 = operator" << endl;
	DATA d6(27, 10.3);
	lst() = d6;
	cout << lst << endl;
	cout << endl << " Citire element crt , Metoda 2 = operator:" << endl;
	cout << lst() << endl;
	cout << endl << " Avansare in lista " << endl;
	++lst;
	cout << endl << " Inserare element nou pe pozitia crt ( al doilea)" << endl;
	DATA d7(9, 3.7);
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
	DATA d8(17, 6.7);
	lst[2] = d8;
	cout << lst << endl;
	data = d8;
	cout << endl << " Se cauta elementul " << data << " in lista" << endl;
	if (lst.lookup(data))
		cout << endl << " Elementul " << data << " a fost gasit in lista" << endl;
	else
		cout << endl << " Elementul " << data << " nu a fost gasit in lista" << endl;
	DATA d9(4, 9.1);
	data = d9;
	cout << endl << " Se cauta elementul " << data << " in lista " << endl;
	if (lst.lookup(data))
		cout << endl << " Elementul " << data << " a fost gasit in lista" << endl;
	else
		cout << endl << " Elementul " << data << " nu a fost gasit in lista" << endl;
	cout << endl;
	
	
	/*ListaS<DATA> lst;
	DATA data;
	cout << lst << endl;
	 cout << "Adaug 2 elemente la sfarsit " << endl;
	 DATA d1(1, 2.5);
	if(lst.addElemSf(d1) == EXIT_FAILURE)
		 exit(1);
	cout << lst << endl;
	DATA d2(4, 2.9f);  //??? nu apare
	if(lst.addElemSf(d2) == EXIT_FAILURE)
		exit(1);
	 cout << lst << endl;
		cout << " Avansare pozitie curenta de 2 ori " << endl;
	 if(++lst)
		 exit(1);
		if(lst(2))
		exit(1);
		 cout << " Modificare element curent " << endl;
	DATA d3(3, 5.7f);
	 if(lst.SetCrtData(d3))
		exit(1);
	cout << lst << endl;
	cout << " Inserare element nou" << endl;
	DATA d4(9, 3.7f);
	 if(lst.InsertCrt(d4))
		exit(1);
	cout << lst << endl;
	cout << " Sterge nodul curent " << endl;
	if ( lst.DeleteCrt() )
	 exit ( 1 ) ;
	cout << lst << endl ;
	
	cout << " Afisare primul element " << endl;
	 cout << lst[0] << endl;
	lst[0] = DATA(4, 6.7f);
	cout << " Modificare primul element " << endl;
	cout << lst[0] << endl;
	cout << lst << endl;
	data = DATA(4, 6.7f);
	cout << " Cautarea unui element " << endl;
	if(lst.lookup(data))
		cout << " Elementul " << data << " afost gasit in lista pe pozitia " << lst.getPozCrt ( ) << endl ;
	 else
		cout << " Elementul " << data << " nu a fost gasit in lista " <<endl;
	*/
	return 0;
}