#include <iostream>

class DATA
{
	int a;
	bool operator == (DATA d2)
	{
		return(a == d2.a);
	}
};


template<typename DT>
class NOD {
	DT info;
	NOD<DT>* st;
	NOD<DT>* dr;
	NOD(const DT& x){     //Construirea unui nod nou fără succesori; prin constructor
		info = x;
		st = dr = NULL;
	}
	NOD(NOD<DT>* n_st, NOD<DT>* n_dr, const DT& d)   //Construirea unui nod nou cu succesorii n_st, n_dr
	{
		info = d;
		st = n_st;
		dr = n_dr;
	}
	~NOD()   // abordare POO
	{
		if (st)
			delete st; // se apeleaza recursiv destructorul clasei NOD
		if (dr)
			delete dr; // se apeleaza recursiv destructorul clasei NOD
	}
};

template<typename DT>
class ArboreB{
	NOD<DT>* rad;
public:
	ArboreB()
	{
		rad = NULL;
	}
	constr_arb_tastatura(){
		DT s;
		if (rad) // verificare stare initiala a arborelui = arbore vid
			return 1; // eroare, arbore nevid
		cout << "Radacina: ";
		cin >> s;
		rad = new NOD<DT>(s);
		add_urmasi(rad);
		return 0;
	}
	add_urmasi(NOD<DT>* n_tata){
		DT s;
		cout << "Fii nodului " << n_tata->info << endl;
			cout << "stanga: ";
		cin >> s;
		if (s == 0)
			n_tata->st = NULL;
		else
			n_tata->st = new NOD<DT>(s);
		cout << "dreapta: ";
		cin >> s;
		if (s == 0)
			n_tata->dr = NULL;
		else
			n_tata->dr = new NOD<DT>(s);
		if (n_tata->st)
			add_urmasi(n_tata->st);
		if (n_tata->dr)
			add_urmasi(n_tata->dr);
	}
	distrug_subarb(NOD* nod)
	{
		if (nod)
		{
			distrug_subarb(nod->st);
			distrug_subarb(nod->dr);
			delete nod;
		}
	}
	~ArboreB()
	{
		if (rad)
		{
			distrug_subarb(rad->st);
			distrug_subarb(rad->dr);
			delete rad;
		}
	}
	/*~ArboreB()          //Abordare POO ; se foloseste destructorul clasei NOD
	{
		if (rad)
			delete rad; // se apeleaza destructorul clasei NOD
	}
	*/
};

int main()
{
	return 0;
}
