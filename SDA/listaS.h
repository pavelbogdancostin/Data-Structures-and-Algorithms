#pragma once

using namespace std;

// coada
/*
N				dimensiunea

l [ 0, ....... N-1 ]

inc = 0 ..... N - 1

inc = 5 ..... N-1, 0, 1, 2, 3, 4



push inc ++;




*/


template < typename DT, uint8_t MAX = 100> // Data Type
class listaS {
	DT elem[MAX]; // 0 : 99; 100 == MAX eroare
	int crt;
	int sf;
public:
	listaS() {
		crt = sf = -1;
	}
	int getCrt() { return crt; }
	int getSize() { return 1+sf; }
	int adauga(const DT& d) {
		if (sf == MAX)
			return EXIT_FAILURE;
		elem[crt = ++sf] = d;
		return EXIT_SUCCESS;
	}

	int InsertCrt(const DT& d) {
		if (sf == MAX || crt > sf || crt < 0)
			return EXIT_FAILURE;
		for (int i = sf++; i >= crt; i--)
			elem[i + 1] = elem[i];
		elem[crt] = d;
		return EXIT_SUCCESS;
	}

	int SetCrt(const DT& d) {
		if (sf<0 || crt>sf || crt < 0)
			return EXIT_FAILURE;
		elem[crt] = d;
		return EXIT_SUCCESS;
	}
	int DeleteCrt() {
		if (sf<0 || crt>sf || crt < 0)
			return EXIT_FAILURE;
		for (int i = crt; i < sf; i++)
			elem[i] = elem[i + 1]; // translatarea elementelor cu o pozitie
		sf--;
		return EXIT_SUCCESS;
	}
	DT& operator[](int i) {
		return elem[crt = i];
	}
	int operator++() {
		if (crt < sf) {
			crt++;
			return EXIT_SUCCESS;
		}
		return EXIT_FAILURE;
	}
	bool lookup(const DT& d) {
		int p = 0;
		while (p <= sf) {
			if (elem[p] == d) {
				crt = p;
				return true;
			}
			p++;
		}
		return false;
	}

	friend ostream& operator << <DT>(ostream&, const listaS<DT>&);
};
template < typename DT>
ostream& operator << (ostream& os, const listaS<DT>& lst) {
	os << lst.sf << " : " << lst.crt << " " << " { ";
	for (int p = 0; p <= lst.sf; p++)
		os << lst.elem[p] << " ";
	os << "}";
	return os;
}
