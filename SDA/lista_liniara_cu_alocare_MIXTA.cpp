#include<iostream>
#include<stdlib.h>
using namespace std;

class DATA {
	int a;
	float b;
	
public:
	DATA() {
		a = 0; b = 0;
		// b = a = 0;
	}
	DATA(int a1, float b1) {
		a = a1;
		b = b1;
	}

	DATA(DATA& x2) {
		a = x2.a;
		b = x2.b;
	}
	DATA& operator=(const DATA& x2) {
		a = x2.a;
		b = x2.b;
		return *this;
	}
	bool operator == (DATA x2) {
		return(a == x2.a && b == x2.b);
	}
	friend ostream& operator << (ostream&, DATA);
};

ostream & operator << (ostream & os, DATA d) {
	os << " ( " << d.a << " , " << d.b << " ) ";
	return os;
}

#define MAX 100

template < typename DT>
class ListaM {
	DT *elem[MAX];
	int p_crt;
	int p_sf;
public :
	ListaM() {
		for (int i = 0; i < MAX; i++)
			elem[i] = NULL;
		
		p_crt = p_sf = -1;
		
	}
	 ~ListaM();
	 
	 template < typename DT>
	 int addElemSf(DT &d) {

		 if (p_sf < MAX - 1) {
			 elem[p_sf + 1] = new DT(d); // alocare dinamica spatiu +folosire constructor copiere
			 if (elem[p_sf + 1] == NULL)
				 return 1; // eroare alocare memorie
			 p_sf++;
			 return 0; // operatie terminata cu succes
		 }
		 else
			 return 1; // eroare :listaera plina , operatia nu s−a efectuat
	 }

	 int operator++();
	int operator() (int);
	int SetCrtData(DT);
	int InsertCrt(DT);
	int DeleteCrt();
	DT& operator[](int);
	int getPozCrt() { return p_crt; }
	int Lungime();
	 int lookup(DT);
	friend ostream & operator << <DT>(ostream&, const ListaM<DT>&);
};
template < typename DT>
ostream & operator << (ostream & os, const ListaM<DT> &lst){
	os << " { ";
	int p = 0;
	while(p <= lst.p_sf) {
		
		os << *(lst.elem[p]) << " ";
		p++;
	}
	os << " } ";
	return os;
}

template < typename DT>
int ListaM<DT>::operator++(){
	if(p_crt < p_sf){
		p_crt++;
		return 0;
	}
	else
		return 1; //
}
template < typename DT>
int ListaM<DT>::operator() (int nr) {
   
	if(p_sf != -1 && nr <= p_sf+1 && nr>0 ){
		p_crt = nr - 1;
		return 0;
	}
	return 1;
}
template < typename DT>
int ListaM<DT>::SetCrtData(DT d){
	if(p_sf<0 || p_crt>p_sf || p_crt < 0)
		 return 1; // eroare
	 // operator de copiere
	*elem[p_crt] = d;
	return 0;
}
template < typename DT>
int ListaM<DT>::InsertCrt(DT d){
	int i;
	 DT* pd = new DT(d);
	
	 if(p_sf>MAX-2||p_crt>p_sf||p_crt<0)
	 return 1; // eroare
		if(pd == NULL)
	 return 1;
		
		for(i=p_sf;i>=p_crt;i--)
		elem[i + 1] = elem[i]; // translatareael ementelor cu o pozitie
		p_sf++;
	elem[p_crt] = pd;
	return 0;
}
template < typename DT>
int ListaM<DT>::DeleteCrt(){
	 int i;
	
	 if(p_sf<0 || p_crt>p_sf || p_crt <0)
		return 1; // eroare
		 delete elem[p_crt];
		for(i = p_crt; i < p_sf; i++)
		elem[i] = elem[i + 1]; // translatarea elementelor cu o pozitie
	
	 p_sf--;
	return 0;
}
template < typename DT>
DT& ListaM<DT>::operator[](int p){
	 return *elem[p];
}
template < typename DT>
ListaM<DT>::~ListaM() {
	 int p = 0;
	while(p < p_sf){
		delete elem[p];
		 p++;
	}
	
	 p_crt = p_sf = -1;
}
template < typename DT>
int ListaM<DT>::Lungime(){
	return p_sf + 1;
}
template < typename DT>
int ListaM<DT>::lookup(DT d){
	int p = 0;
	while(p < p_sf){
		if(*elem[p]==d){
			p_crt = p + 1;
			return 1;
		}
		p++;
	}
	return 0;
}
int main(){

	ListaM<DATA> lst;
	
	DATA  d(1, 2.5);

	 DATA dat;
	 cout << lst << endl;
		cout << endl << "Adaug 2 elemente la sfarsit " << endl;
	if(lst.addElemSf(d) == EXIT_FAILURE)
		exit(1);
	cout << lst << endl; DATA d2(4, 2.9);
	if(lst.addElemSf(d2) == EXIT_FAILURE)
		exit(1);
	cout << lst << endl;
	cout << endl << " Avansare pozitie curenta " << endl;
	if(++lst)
		exit(1);
	cout << " Pozitia curenta este: " << lst.getPozCrt() << endl;
	cout << endl << " Modifi care element curent " << endl;
	DATA d3(3, 5.7);
	if(lst.SetCrtData(d3))
		exit(1);
	cout << lst << endl;
	cout << endl << " Inserare element nou la pozitia curenta " << endl;
	DATA d4(9, 3.7);
	if(lst.InsertCrt(d4))
		exit(1);
	cout << lst << endl;
	cout << endl << " Stergere pozitie curenta " << endl;
	if(lst.DeleteCrt())
		exit(1);
	cout << lst << endl;
	cout << endl << " Afisare primul element " << endl;
	cout << lst[0] << endl;
	cout << endl << " Modificare primul element " << endl;
	
	lst[0]=DATA(4, 6.7);
	
	cout << lst << endl;
	   dat = DATA(4, 6.7);
	cout << endl << " Cautarea elementului " << dat<< endl;
	if(lst.lookup(dat))
		cout << " Elementul " << dat << " a fostgasit in lista pe pozitia" << lst.getPozCrt ( ) << endl;
		else
		cout << " Elementul " << dat << " nu a fost gasit in lista " <<endl;
		dat = DATA(14, 26.7);
	cout << endl << " Cautarea elementului " << dat<< endl;
	if(lst.lookup(dat))
		cout << " Elementul " << dat << " a fost gasit in lista pe pozitia" << lst.getPozCrt( ) << endl;
		else
		cout << " Elementul " << dat << " nu a fost gasit in lista" <<endl;
	return 0;
}
