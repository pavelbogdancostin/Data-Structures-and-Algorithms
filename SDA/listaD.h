#pragma once
// cea cu S este statica !
// D este simpla inalnatuita

template < typename DT>
struct NOD {
	DT	data;
	NOD* urm;
	NOD() : urm(NULL) { /*urm = NULL;*/ }
	NOD(const DT& d) : data(d) { urm = NULL; }
};

#define INC		(pinc->urm)
#define CRT		(pcrt->urm)
#define SF		(psf->urm)

template < typename DT> // Data Type
class listaD {
	/*	struct NOD : public DT {
			DT* urm;
			NOD() { urm = NULL; }
			NOD(const DT& d) : DT(d) { urm = NULL; }
		}*/
	NOD<DT>* pinc, * psf;
public:
	NOD<DT> *pcrt;
	listaD() {
		pinc = psf = new NOD<DT>; pcrt = NULL;
	}

	~listaD() {
		while (pinc) {
			NOD<DT>* n = pinc;
			pinc = pinc->urm;
			delete n;
		}
		pinc = psf = pcrt = NULL;
	}


	void resetCrt(void) {
		pcrt = pinc;
	}

	int adauga(const DT& d) {
		NOD<DT>* n = new NOD<DT>(d);
		if (n == NULL)
			return EXIT_FAILURE; // eroare alocare memorie
		if (SF)
			psf = SF;
		SF = n;
		// psf = n;
		return EXIT_SUCCESS;
	}
	//    inc       p1      p2        sf
	// (0, p1)   (1, p2)  (2, p3)  (3, NULL)


	// datele pinc, pcrt, psf, datele urm;

	//             crt
	//    inc       p1       p4         p2        sf
	// (0, p1)   (1, p2)    (4, p2)    (2, p3)  (3, NULL)

	//             crt
	//    inc       p1       p4         p2        sf
	// (0, p1)   (1, p4)  (4, p2)    (2, p3)  (3, NULL)


	int InsertCrt(const DT& d) {
		//		inc(0, urm)      crt         sf: sf->urm = NULL;
		// inc, sf, crt
		NOD<DT>* n = new NOD<DT>(d);
		if (n == NULL)
			return EXIT_FAILURE; // eroare alocare memorie
		if (pcrt == NULL)
			pcrt = pinc;
		if (CRT == NULL) {
			if (pcrt == SF)
				psf = SF;
			CRT = n;
			return EXIT_SUCCESS;
		}
		n->urm = CRT;
		if (pcrt == psf)
			psf = n;
		CRT = n;
		return EXIT_SUCCESS;
/*		
		pi urm
		pf urm
		pc urm

		pi->urm NULL
		pf->urm NULL
		pc->urm NULL

		n1=10,    pc->urm=NULL; // pi = pf = pc = fantoma
		pc->urm = n;        return;

		n2=2      pc->urm=n1;
		n2->urm = pc->urm;
		if(pc == pf)
			pf = n; 
		pc->urm = n;			return;
*/
	}
	bool test(void){
		if (INC) {
			NOD<DT>* n = pinc->urm;
			while (n) {
				n = n->urm;
			}
			return n == psf ? true : false;
		}
		return  SF ? false : true;
	}


	/*
	int InsertCrt(const DT& d) {
		if (sf == MAX || crt > sf || crt < 0)
			return EXIT_FAILURE;
		for (int i = sf++; i >= crt; i--)
			elem[i + 1] = elem[i];
		elem[crt] = d;
		return EXIT_SUCCESS;
	}*/

	int SetCrt(const DT& d) {
		pcrt = pinc;
		while (pcrt->urm) {
			if (pcrt->urm->data == d)
				return EXIT_SUCCESS;
			pcrt = pcrt->urm;
		}
		return EXIT_FAILURE;
	}

	//             crt
	//    inc       p1       p4         p2        sf
	// (0, p1)   (1, p2)    (4, p2)    (2, p3)  (3, NULL)

	//                      crt 
	//    inc       p1       p4         p2        sf
	// (0, p1)   (1, p4)  (4, p2)    (2, p3)  (3, NULL)

	//				INC               SF            
	//    inc       p1       psf        p3
	// (0, p1)   (1, p2)  (2, p3)  (3, NULL)


	int DeleteCrt() {
		if (pcrt == NULL || CRT == NULL)
			return EXIT_FAILURE;
		NOD<DT>* n = CRT;
		CRT = n->urm;
		delete n;
		return EXIT_SUCCESS;
	}
	DT& operator[](int i) {
		pcrt = INC;
		while (i && CRT)   // pcrt->urm || pcrt != psf
			if (--i)
				pcrt = pcrt->urm;
		return CRT->data;
	}
	/*
	DT& operator(int a){
		if (pcrt == NULL)
			pcrt = pinc;
		return *CRT;
	}*/

	int operator++() { // ++lista;
		if (pcrt){
			pcrt = pcrt->urm;
			return EXIT_SUCCESS;
		}
		return EXIT_FAILURE;
	}

	// inc are sens urm
// crt are sens this
//  sf are sens this

//             crt
//    inc       p1      p2        sf
// (0, p1)   (1, p2)  (2, p3)  (3, NULL)

	NOD<DT>* lookup(const DT& d) {
		NOD<DT>* n = pinc->urm;
		while (n) {
			if (n->data == d) {
				//pcrt = n;
				return n;
			}
			n = n->urm;
		}
		return NULL;
	}
	NOD<DT>* getHEAD(void) {
		return INC;
	}
	NOD<DT>* getCRT(DT& el) {
		if (CRT == NULL)
			return NULL;
		el = CRT->data;
		return CRT;
	}
	void InsertSort(const DT& d){
		NOD<DT>* n = new NOD<DT>(d);

		/*
		pinc = NULL;
		pinc[100,NULL]
		pinc[100, &b] ... [200, NULL]

		n = &;
		sterg(n);
		p = pinc;
		while(p->urm != n)
			p = p->urm;
		*/

		// if(last == null){
		//     pinc->urm = n;
		//     return;
		// }
		// else if{d < last->data){
		//     n->urm = pinc->urm;
		//     pinc->urm = n;
		//     return
		// }
/*
		pinc[, NULL]
		pinc[, &a] .. a[100, NULL]
		pinc[, &a] .. a[100, &b] ... b[200, NULL]
		pinc[, &a] .. a[100, &c] ... c[150, &b] ... b[200, NULL]
		pinc[, &d] .. d[50, &a] ... a[100, &c] ... c[150, &b] ... b[200, NULL]
*/

		NOD<DT>* last = INC;
		if (last == NULL || d < last->data) {
			n->urm = INC;
			INC = n;
			return;
		}
		while (last->urm != NULL && last->urm->data < d)
			last = last->urm;
		n->urm = last->urm;
		last->urm = n;
	}
	friend ostream& operator << <DT>(ostream&, const listaD<DT>&);
};

template < typename DT>
ostream& operator<< (ostream& os, const listaD<DT>& lst) {
	os << lst.pinc->urm << "  " << (lst.pcrt ? lst.pcrt->urm : NULL) << "  " << lst.psf->urm << "  " << " { ";
	if (lst.pinc) {
		NOD<DT>* n = lst.pinc->urm;
		while (n) {
			os << n << ":" << n->data << " ";
			n = n->urm;
		}
	}
	os << " } ";
	return os;
}

#undef INC
#undef SF
#undef CRT