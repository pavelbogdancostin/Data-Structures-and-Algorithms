#pragma once

template<typename DT>
struct NOD {
	DT data;
	int nr_urm;		// HEAP
	NOD* st;
	NOD* dr;
	NOD(const DT& r) {
		data = r; nr_urm = 0;
		st = dr = NULL;
	}/*
	NOD(const DT&r, const DT &v1) {
		data = r;
		if (r == v1)
			cout << "root = st" << endl;
		if (v1 < r)
			st = new NOD<DT>(v1), dr = NULL;
		if (v1 > r)
			dr = new NOD<DT>(v1), st = NULL;
	}
	NOD(const DT& r, const DT &v1, const DT &v2) {
		data = r;
		if ( v1 >= r  ||  r >= v2)
			cout << "root = st || root = dr" << endl;
		if (v1 < r)
			st = new NOD<DT>(v1);
		if (v2 > r)
			dr = new NOD<DT>(v1);
	}*/
	~NOD(){
		if (st)
			delete st; // se apeleaza recursiv destructorul clasei NOD
		if (dr)
			delete dr; // se apeleaza recursiv destructorul clasei NOD
	}
	bool operator<(const DT& d)
	{
		return(data < d.data);
	}
	bool operator==(const DT& d)
	{
		return(data == d.data);
	}
	void operator = (const NOD& d) {
		data = d.data;
		st = d.st;
		d = d.dr;
	}
	/*bool operator == (const NOD& d) {
		return(data == d.data);
	}*/
	void insert(const DT& d){
		if (d < data)
			if (st)
				st->insert(d);
			else
				st = new NOD<DT>(d);
		else
			if (dr)
				dr->insert(d);
			else
				dr = new NOD<DT>(d);
	}
	/*
	int height(node* node) {
		if (node == NULL)
			return 0;

		int lHeight = height(node->left);
		int rHeight = height(node->right);

		return 1 + (lHeight > rHeight ? lHeight : rHeight);
	}*/

	int adancimea(void) {
		int sH = st ? st->adancimea() : 0;
		int dH = dr ? dr->adancimea() : 0;
		return 1 + (sH > dH ? sH : dH);
	}
	NOD* find(const DT& d){  // BST
		if (data == d)
			return this;
		if (d < data)
			if (st)
				return st->find(d);
			else
				return NULL;
		else
			if (dr)
				return dr->find(d);
			else
				return NULL;
	}
	bool erase(const DT& d){ //retuneaza true daca s-a gasit si sters
		NOD<DT>* t, * tmp; //retuneaza false daca NU s-a gasit d
		if (data == d) // s-a gasit nodul ce trebuie sters
		{
			if (st) // cautare cel mai mare nod din subarborele stang
			{
				t = st;
				if (!t->dr && !t->st) // t este frunza
				{
					data = t->data; // se muta st in nodul parinte
					delete t;
					st = NULL;
				}
				if (t->dr) // t are urmas pe dreapta
				{
					while (t->dr->dr) //parcurgere toti descendenti pe parte dr
						t = t->dr;
					data = t->dr->data;//schimb data nod crt cu nod cel mai dr
					tmp = t->dr;
					t->dr = t->dr->st;
					delete tmp; //sterg nod inlocuit
				}
				else // t NU are urmas pe dreapta, ARE pe stanga, inlantuit
				{
					data = t->data;
					st = t->st;
					delete t;
				}
			}
			else
				if (dr) //nodul (data=d) NU are urmas pe st, dar ARE urmas pe dr
				{
					t = dr; // inlantuit (lista)
					data = t->data;
					st = t->st;
					dr = t->dr;
					delete t;
				}
			return true; // s-a gasit d si s-a sters nodul
		}// end if(data==d)// nu s-a gasit nodul care continue d
		if (d < data) //avansare pe stanga
		{
			if (st)
				return st->erase(d);
		}
		else //d>data ; avansare pe dreapta
			if (dr)
				return dr->erase(d);
		return false; // NU s-a gasit nodul
	}

	//////////////////////////////////////////////////////////////
	//      HEAP
	//////////////////////////////////////////////////////////////

	void push(DT d) {
		if (data < d) {   // switch radacina d
			DT t = data; data = d; d = t;
		}
		nr_urm++;
		if (!st) { // nu exista urmasi pe st; se adauga frunza
			st = new NOD<DT>(d);
			return;
		}
		if (!dr) { // nu exista urmasi pe dr; se adauga frunza
			dr = new NOD<DT>(d);
			return;
		}
		// exista urmasi pe st si dr
		// se avanseaza spre nodul cu mai putini mostenitori
		if (st->nr_urm <= dr->nr_urm)
			st->push(d);
		else
			dr->push(d);
	}

	void reordonare(){
		DT tmp = data;
		if (st && dr){ // există descendenti st + dr
			if (st->data > dr->data){ // switch parinte cu fiu stanga

				if (tmp < st->data){
					tmp = data; data = st->data; st->data = tmp;
					st->reordonare();
				}
				else
					return;
			}
			else{ // switch parinte cu fiu dr
				if (tmp < dr->data){
					tmp = data; data = dr->data; dr->data = tmp;
					dr->reordonare();
				}
				else
					return;
			}
		}
		else if (st){ //exista numai fiu pe stanga,
			if (tmp < st->data){ //se face direct switch cu parintele sau
				tmp = data; data = st->data; st->data = tmp;
				st->reordonare();
			}
			else
				return;
		}
	}
	DT stergUltimaFrunza() {
		DT tmp;
		nr_urm--;
		if (st && !dr) { // exista numai fiu stanga => frunza cautata => se sterge
			tmp = st->data;
			delete st;
			st = NULL;
			return tmp;
		}
		if (dr) {
			if (dr->nr_urm == 0) //fiu dreapta este frunza cautata => se sterge
			{
				tmp = dr->data;
				delete dr;
				dr = NULL;
				return tmp;
			}
			else // nodul crt. nu are fii frunze, se repeat pe subarb cu mai multe noduri
				if (st->nr_urm < dr->nr_urm)
					return dr->stergUltimaFrunza();
				else
					return st->stergUltimaFrunza();
		}
	}
	DT pop(){
		DT tmp = data;
		data = stergUltimaFrunza();
		
		//cout << "ininitial" << endl;
		//print();
		
		reordonare();
		return tmp;
	}
	
	//////////////////////////////////////////////////////////////
	//      HEAP   -----   END
	//////////////////////////////////////////////////////////////

	void inOrdine(){
		if (st)
			st->inOrdine();
		cout << data << ","; // info.prelucrare(); // prelucrare radacina, dupa st, inainte dr
		if (dr)
			dr->inOrdine();
	}

	void preOrdine(){
		cout << data << ","; // info.prelucrare(); // prelucrare radacina, dupa st, inainte dr
		if (st)
			st->preOrdine();
		if (dr)
			dr->preOrdine();
	}
	void postOrdine(){
		if (st)
			st->postOrdine();
		if (dr)
			dr->postOrdine();
		cout << data << ",";// info.prelucrare(); // prelucrare radacina, dupa st si dr
	}

	void print(void) {
		NOD<int>* l[256] = { NULL };
		int xl(1); l[xl] = this;
		for (int k = 1; k <= xl; k++) {
			if (l[k] == nullptr) continue;
			if (l[k]->st) l[xl = 2 * k] = l[k]->st;
			if (l[k]->dr) l[xl = 1 + 2 * k] = l[k]->dr;
		}
		int xn = 1, D;
		while (xl > int(pow(2, xn)))
			xn++;
		D = int(pow(2, xn - 1));
		for (int n = 1; n <= xn; n++) {
			int s = D / 2; if (s > 1) s += s - 1;
			if (s) cout << string(2 * s, ' ');
			s = D; if (s > 1) s += s - 1;
			for (int k = int(pow(2, n - 1)), xk = 2 * k; k < xk; k++) {
				if (l[k])
					printf("%2d", l[k]->data);
				else
					cout << string(2, '_');
				cout << string(2 * s, ' ');
			}
			D /= 2; cout << endl << endl;
		}
	}
};

