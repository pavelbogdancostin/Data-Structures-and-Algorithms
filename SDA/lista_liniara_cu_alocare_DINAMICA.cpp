#include<iostream>
#include<stdlib.h>
using namespace std;
class DATA{
	int a;
	float b;
	public:
	 DATA() {
	a = b = 0;
	 }
	 DATA(int a1, float b1){
		a = a1;
		b = b1;
	 }
	 DATA(DATA & x2) {
		a = x2.a;
		 b = x2.b;
	 }
	 void operator = (DATA & x2){
		a = x2.a;
		b = x2.b;
	 }
	 bool operator == (DATA x2){
		return(a == x2.a && b == x2.b);
	 }
	friend ostream & operator << (ostream&, DATA);
};
ostream & operator<< (ostream & os, DATA d){
	os<< " ( " << d.a << " , " << d.b << " ) ";
	 return os;
 }
template < typename DT>
class ListaD1;

template < typename DT>
class Nod;

template < typename DT>
ostream & operator<< (ostream & os, const ListaD1<DT> & lst){
	 Nod<DT>* tmp;
	 os << lst.inc << "  " << lst.crt << "  " << lst.sf << "  " << " { ";
	if(lst.inc){
		tmp = lst.inc->urm;
		 while(tmp){
			 os << tmp->info << " ";
			tmp = tmp->urm;
		 }
	}
	os << " } ";
	return os;
}

template < typename DT>
class Nod{
	 DT info;
	 Nod* urm;
	public:
	friend class ListaD1<DT>;
		Nod() {
		urm = NULL;
		}
		Nod(DT x){
		info = x;
		urm = NULL;
	 }
	
		 ~Nod() {
		if(urm) {
			DT d = urm->info;
			delete urm;
			cout << "S−a sters elementul cu info= " << d << endl;
		 }
		}
		friend ostream & operator << <DT>(ostream&, const ListaD1<DT>&);
};
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
template < typename DT>
int ListaD1<DT>::addElemSf(DT d){

	if((sf->urm = new Nod<DT>(d))) {
		 sf = sf->urm;
		return 0; // operatie terminata cu succes
	}
	else
		return 1; // eroare alocare memorie
}
template < typename DT>
int ListaD1<DT>::addElemInc(DT d) {
	Nod<DT>* tmp = new Nod<DT>(d);
	if(!tmp)
		return 1; // eroare alocare memorie
	 tmp->urm = inc->urm;
	inc-> urm = tmp;
	return 0; // operatie termina ta cu succes
}
template < typename DT>
int ListaD1<DT>::operator++(){
	if(crt-> urm){
		crt = crt-> urm;
		return 0;
	}
	 else
		return 1;
}
template < typename DT>
DT & ListaD1<DT>::operator() (int p){
	if(inc){
		crt = inc-> urm;
		while(crt){
			p--;
			if(p == 0)
				return crt-> info;
			crt = crt-> urm;
		}
	}
	crt = NULL;
}
template < typename DT>
DT& ListaD1<DT>::operator() () {
	return crt->info;
}
template < typename DT>
DT& ListaD1<DT>::operator[](int p) {
	operator() (p);
	return crt->info;
}
template < typename DT>
int ListaD1<DT>::setCrtData(DT d){
	if(!crt)
		return 1; // eroare
	crt-> info = d;
	return 0;
}



template < typename DT>
int ListaD1<DT>::getCrtData(DT & d){
	if(!crt)
		return 1; // eroare
	d = crt-> info;
	return 0;
}

template < typename DT>
int ListaD1<DT>::insertElemDupaCrt(DT d){
	 Nod<DT>* tmp = new Nod<DT>(d);
	if(!tmp)
		return 1; // eroare
	tmp-> urm = crt-> urm;
	if(crt == sf)
		sf= sf-> urm;
	crt-> urm = crt;
	return 0;
}

template < typename DT>
int ListaD1<DT>::insertElemCrt(DT d){
	if(inc-> urm == NULL){
		if(!(crt-> urm = new Nod<DT>(d)))
			return 1;
		crt = crt-> urm;
		crt-> urm = NULL;
		return 0;
	}
		if(crt == inc)
		crt = crt-> urm;
		Nod<DT>* tmp = new Nod<DT>(crt->info);

	if(!tmp)
		return 1;
		crt-> info = d;
	tmp-> urm = crt-> urm;
	if(crt == sf)
		sf = sf-> urm;
		crt-> urm = tmp;
		return 0;
}
template < typename DT>
int ListaD1<DT>::deleteCrt(DT & d){
	Nod<DT> * tmp;
	if(crt == inc)
		crt = inc-> urm;
	if(!crt)
	 return 1;
	if(crt == sf){
		crt = inc;
		 while(crt-> urm != sf) // pozitionare inainte de sf
			crt = crt-> urm;
		d = crt-> urm-> info;
	}
	else{
		 d = crt-> info;
		 crt->info=crt->urm->info;
	}
	tmp = crt-> urm;
	crt-> urm = tmp-> urm;
	tmp-> urm = NULL;
	delete tmp;
	return 0;
}


template < typename DT>
ListaD1<DT>::~ListaD1(){
	 if(inc)
		delete inc;
}

template < typename DT>
int ListaD1<DT>::lungime(){
	int lung = 0;
	if(inc){
		crt = inc-> urm;
		while(crt){
			crt = crt-> urm;
			 lung++;
		 }
	 }
	 return lung;
}
template < typename DT>
int ListaD1<DT>::lookup(DT d) {
	if(inc){
		crt = inc-> urm;
		while(crt){
			if(crt-> info == d)
				return 1;
			crt = crt-> urm;
		}
	}
	return 0;
}
int main(){
	ListaD1<DATA> lst;
	DATA data;
	cout << " Lista iniliala:" << endl << lst << endl;
	cout << endl << "Adaug succesiv 2 elemente la sfarsitul listei"<< endl;
	DATA d1(1, 2.5);
	
	if(lst.addElemSf(d1) == EXIT_FAILURE)
		exit(1);
	cout << lst << endl; 
	DATA d2(4, 2.9);
	if(lst.addElemSf(d2) == EXIT_FAILURE)
		exit(1);
	cout << lst << endl; 
	DATA d3(112, 333.999);
	lst.insertElemCrt(d3);
	cout << endl << " Lista dupa inserare pe pozitia 1 " << lst <<endl;
	DATA d4(666, 999.1);
	lst.insertElemCrt(d4);
	cout << endl << " Lista dupa inserare pe pozitia 1 " << lst <<endl;
	cout << endl << " Modifi care valoare pe pozitia crt ( primul element )" << endl;
	DATA d5(3, 5.7);
		if(lst.setCrtData(d5))
		exit(1);
	cout << lst << endl;
	
	//data = lst[];
	
	lst.getCrtData(data);

	cout << endl << " Citire element crt:" << data << endl;
	cout << endl << " Modifi care valoare pe pozitia crt ( primul element), Metoda 2 = operator" << endl;
	DATA d6(27, 10.3);
		lst() = d6;
	cout << lst << endl;
	cout << endl << " Citire element crt , Metoda 2 = operator:" <<endl;
	cout << lst() << endl;
	cout << endl << " Avansare in lista " << endl;
	++lst;
	cout << endl << " Inserare element nou pe pozitia crt ( al doilea)"<< endl;
	DATA d7(9, 3.7);
	if(lst.insertElemCrt(d7))
		exit(1);
	cout << lst << endl;
	cout << endl << " Avansare in lista" << endl;
	++lst;
	cout << endl << " Eliminare element de pe pozitia crt (al treilea)" << endl ;
		if(lst.deleteCrt(data))
		exit(1);
	cout << lst << endl;
	cout << endl << " Afisare element sters:" << endl;
	cout << data << endl;
	cout << endl << " Citire element de pe o anumita pozitie(ex.:2)folosind op indexare" << endl ;
	cout << lst[2] << endl;
	cout << endl << " Modificare element de pe o anumita pozitie(ex.:2),folosind op indexare" << endl;
	DATA d8(17, 6.7);
		lst[2] = d8;
	cout << lst << endl;
	data = d8;
	cout << endl << " Se cauta elementul " << data << " in lista" <<endl;
	if(lst.lookup(data))
		cout << endl << " Elementul " << data << " a fost gasit in lista" << endl ;
		else
		cout << endl << " Elementul " << data << " nu a fost gasit in lista" << endl ;
	DATA d9(4, 9.1);
		data = d9;
	cout << endl << " Se cauta elementul " << data << " in lista " <<endl;
	 if(lst.lookup(data))
		cout << endl << " Elementul " << data << " a fost gasit in lista" << endl;
		else
		cout << endl << " Elementul " << data << " nu a fost gasit in lista" << endl ;
		cout << endl;
	return 0;
}