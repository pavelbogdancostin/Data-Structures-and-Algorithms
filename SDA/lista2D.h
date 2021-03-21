#pragma once

template<typename DT>
struct NOD {
	DT data;
	NOD* ant;
	NOD* urm;
	NOD(const DT& d) {
		data = d;
		ant = urm = NULL;
	}

	void operator = (const NOD& d) {
		data = d.data;
		ant = d.ant;
		urm = d.urm;
	}
	bool operator == (const NOD& d) {
		return(data == d.data);
	}

	friend ostream& operator << <DT>(ostream&, NOD<DT>&);
};

template<typename DT>
ostream& operator << (ostream& os, NOD<DT>& d) {
	os << " ( " << d.data << " " << d.ant  << " - " << d.urm << " ) ";
	return os;
}


template<typename DT>
struct lista2D {
	int _size;
	NOD<DT>* inc, * crt, *sf;

	lista2D() {
		_size = 0;  inc = crt = sf = NULL;
	}

	int adauga(const DT& d) {
		NOD<DT>* n = new NOD<DT>(d);
		if (n == NULL)
			return EXIT_FAILURE; // eroare alocare memorie
		
		if (inc == NULL)
			inc = n;
		else
			n->ant = sf, sf->urm = n;
		sf = n;  _size++;
		return EXIT_SUCCESS;
	}

	DT& operator[](int i) {
		crt = inc;
		while (i && crt->urm)   // pcrt->urm || pcrt != psf
			if (i--)
				crt = crt->urm;
		return crt->data;
	}
	void resetCrt(void) {
		crt = inc;
	}

	int InsertCrt(const DT& d) {
		NOD<DT>* n = new NOD<DT>(d);
		if (n == NULL)
return EXIT_FAILURE; // eroare alocare memorie
if (crt == NULL) {
	if (inc)
		return adauga(d);
	inc = sf = crt = n;
	return EXIT_SUCCESS;
}

n->ant = crt->ant;
if (crt->ant)
(crt->ant)->urm = n;
else
inc = n;
n->urm = crt; crt->ant = n;
crt = n;
if (crt->urm == NULL)
sf = n;
return EXIT_SUCCESS;

/*
n1 = 10  // pi = pf = pc = NULL
pi = pf = pc = n;        return;

n2 = 2      pc = n1;

n2->ant = pc->ant;
if(pc->ant)
	(pc -> ant)->urm = n2;
else
	pi=n2;
n2->urm = pc; pc->ant = n2;

if (pc->urm == NULL)
	pf = n;
pc = n;			return;
*/
if (crt == NULL) {
	//if (crt->ant == sf)
	//	sf->ant = sf;
	inc = sf = crt = n;
	return EXIT_SUCCESS;
}
n->urm = crt;
if (crt == sf)
sf = n;
crt = n;
return EXIT_SUCCESS;



// inc != NULL, sf != NULL, crt = NULL
if (crt == NULL)
crt = inc;
if (inc) {
	if (inc == crt)
		inc = n;
	else
		if (sf == crt)
			sf = n;
}
else
inc = sf = n;
if (crt)
crt->ant = n;
n->urm = crt; crt = n;  _size++;
return EXIT_SUCCESS;
	}

	bool test(void) {
		if (inc) {
			if (inc->ant || sf->urm)
				return EXIT_FAILURE;

			NOD<DT>* n = inc;
			while (n) {
				if (n->ant)
					if (n->ant->urm != n)
						return EXIT_FAILURE;
				if (n->urm)
					if (n->urm->ant != n)
						return EXIT_FAILURE;
				n = n->urm;
			}
			return EXIT_SUCCESS;
		}
		return sf ? EXIT_FAILURE : EXIT_SUCCESS;
	}

	int SetCrt(const DT& d) {
		crt = inc;
		while (crt) {
			if (crt->data == d)
				return EXIT_SUCCESS;
			crt = crt->urm;
		}
		return EXIT_FAILURE;
	}

	/*struct key {
		int val;
		int p;
		operator > (& v){
			if (p > v.p)
				return 1;
			if (p < v.p)
				rerurn 0;
			if (val > v.val)
				return 1;
			return 0;
		}
	};

	template<typename T>
	struct coadaPr<T> {
		listaD<T> l;
		coadaPr() {

		}

               29
//		45, 30, 28, 10

		push(const T& t) {
			T* n = l.inc;
			while (l.getCRT(v) {
				if (t < n->data)
					++l() // creste CRT
				break;
			}
			l.insertCRT(t);
		}

		T pop() {
			if (l.inc) {
				NOD<T>* n= l.inc;
				l.inc = n->urm;
				T t = n->data;
				delete n;
			}
		}


		insertCRT(const T & t) {
			l.insertCRT(t);
		}
	}
	coadaProp<key> cp; 
	cin v, val >> v.p
		cp.resetcrt();
		while(cp.getcrt(v))


	*/
	int DeleteCrt() {
		if (crt == NULL)
			return EXIT_FAILURE;
		NOD<DT>* n = crt;  _size--;

		if (crt->ant)
			(crt->ant)->urm = crt->urm;
		else
			inc = crt->urm;

		if(crt->urm)
			(crt->urm)->ant = crt->ant, crt = crt->urm;
		else {
			sf = crt->ant;
			crt = crt->urm ? crt->urm : crt->ant;
		}

		delete n;
		return EXIT_SUCCESS;
	}
	
	int operator++() { // ++lista;
		if (crt) {
			crt = crt->urm;
			return EXIT_SUCCESS;
		}
		return EXIT_FAILURE;
	}

	NOD<DT>* lookup(const DT& d) {
		NOD<DT>* n = inc;
		while (n) {
			if (n->data == d) {
				//pcrt = n;
				return n;
			}
			n = n->urm;
		}
		return NULL;
	}

	NOD<DT>* getCRT(DT& el) {
		if (crt == NULL)
			return NULL;
		el = crt->data;
		return crt;
	}

	friend ostream& operator << <DT>(ostream&, const lista2D<DT>&);
};

template < typename DT>
ostream& operator<< (ostream& os, const lista2D<DT>& lst) {
	os << lst.inc << "  " << lst.crt << "  " << lst.sf << "  " << " { ";
	if (lst.inc) {
		NOD<DT>* n = lst.inc;
		while (n) {
			os << n << ":" << *n;
			n = n->urm;
			if (n) os << ", ";
		}
	}
	os << " } ";
	return os;
}
