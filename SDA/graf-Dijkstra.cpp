//Problema DFS - inforaena.ro - http://www.infoarena.ro/problema/dfs
//Tutorialul complet, explicat - http://tutoriale-pe.net/parcugerea-adancime-dfs/

#include <iomanip>
#include <iostream>
#include <fstream>
//#include <vector>
#include <string>

using namespace std;

#include "../listaS.h"
#include "../listaD.h"

int v[100]; int nv = 10;
int b[100]; int nb = 20;

/*

head S = [ S | urm ]  .... [S | urm};

template<typename DT>
functie_sortare(DT &a, DT &b) { // a > b ==> return 1, a==b return 0, a<b ==> -1
	if (a.val > b.val)
		return true;
	return false;
}

qsort(v, nv, sizeof(v[0]), functie_sortare);
*/

struct VF {
	char  nume[8];
	VF() { nume[0] = 0; }
	VF(const char* n) {
		strcpy_s(nume, 8, n);
	}
	bool operator==(const VF& d){
		return (0 == (strcmp(nume, d.nume)));
	}
	friend ostream& operator << (ostream& os, const VF& d) {
		os << d.nume << ' ';
		return os;
	}
};

int N, M;
int cost[10][10];
listaS<VF> lv;

ifstream fin("..//date//dijkstra.in");
//ofstream fout("dfs.out");


int Read(){
    fin >> N >> M; int c;
    for(int m = 0; m < M; m++){
		VF a, b;
        fin >> a.nume >> b.nume >> c;
		cout << a << ' ' << b << ' ' << c << endl;
		int i, j;
		
		if (lv.lookup(a) == 0)
			lv.adauga(a);
		i = lv.getCrt();
		if (lv.lookup(b) == 0)
			lv.adauga(b);
		j = lv.getCrt();

		cost[i][j] = cost[j][i] = c;
	}
	return N;
}

struct V_C {
	int v;
	int *cost;
	V_C() { v = 0; cost = NULL; }
	V_C(int a, int *b) {
		v = a;  cost = b;
	}
	void operator = (const V_C& e) {
		v = e.v; cost = e.cost;
	}
};

void sort_VC(V_C* a, int n) {
	for (int i = 1; i < n; i++) {
		V_C x = a[i];
		int p = i - 1;
		while (p >= 0 && *a[p].cost > *x.cost)
			a[p + 1] = a[p], p--;
		a[p + 1] = x;
	}
}

void dijkstra(int is, int *R) {
	int v[12] = { 0 };
	// coadaD
	//NOD<V_C> *aH = new NOD<V_C>(V_C(is, &R[is]));
	//aH.push(V_C(is, &R[is]));

	V_C cp[12] = { V_C(0, NULL) }; int ncp = 0; cp[ncp++] = V_C(is, &R[is]);
	while (ncp) {
		for (int va = 0; va < N; va++) {
			if (v[va]) continue;
			//if (cost[cp[0].v][va] == 0)
			//	continue;

			if (R[va] == 0) {
				R[va] = R[cp[0].v] + cost[cp[0].v][va];
				cp[ncp++] = V_C(va, &R[va]);
			}
			else
				if(R[cp[0].v] + cost[cp[0].v][va] < R[va]){
					R[va] = R[cp[0].v] + cost[cp[0].v][va];
				}
		}
		v[cp[0].v] = true;
		sort_VC(cp, ncp);
		memcpy(&cp[0], &cp[1], --ncp*sizeof(V_C));
	}
}

int main(){
    int N = Read();
	cout << setw(4) << " ";
	for (int i = 0; i < N; i++)
		cout << setw(5) << lv[i];
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << lv[i];
		for (int j = 0; j < N; j++)
			cout << setw(6) << cost[i][j];
		cout << endl;
	}
	cout << "===========================================" << endl;
	VF s("BWI");
	if (lv.lookup(s)) {
		int R[12] = { 0 }; int is = lv.getCrt();
		dijkstra(is, R);
		
		cout << s << endl;
		for (int n = 0; n < N; n++) {
			if (n == is) continue;
			cout << lv[n] << ' ' << R[n] << endl;
		}
	}
	return 0;
}