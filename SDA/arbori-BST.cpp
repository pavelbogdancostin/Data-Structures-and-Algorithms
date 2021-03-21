#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


// fct de bool echilibrat
// diferenta inaltimilor subarborilor st / dr <=1 pt orice nod.
// Arbore ordonat = arbore la care ordinea fiilor săi este importan
//  BST st < dr
// afisare frunze !
// adancime
// arbore atributat ???? de gasit

// COZI - stive
// 09
// introducere perechi
// 2 elem adaugate una se elimina
// elementele ramase

#include "../arboreBST.h"
#include <string>

int isPostOrde(int* arr, int start, int end){
	
	cout << start << "  " << end << ": ";
	for (int a = start; a <= end; a++)
		cout << arr[a] << " ";
	cout << endl;
	
	if (start >= end) {
		return 1;
	}

	int r = arr[end];
	int ir = end - 1;
/*
// 3  9  8  7

	7
3		8
			9

			
// 3  8  9  7
	7
3		9
	  8
*/

	while (ir >= start && arr[ir] > r) {
		ir--;
	}

	int tmp = ir;
	while (ir >= start) {
		if (arr[ir] > r) {
			return -1;
		}

		ir--;
	}

	if (tmp == start) {
		cout << "1 " << start << " " << end - 1 << endl;
		return 1 + isPostOrde(arr, start, end - 1);
	}
	else {
		cout << "2 " << start << " " << tmp << " && " << tmp + 1 << " " << end-1 << endl;
		return 1 + (isPostOrde(arr, start, tmp) && isPostOrde(arr, tmp + 1, end - 1));
	}
}

int isPostOrder(int* arr, int start, int end)
{
	if (start >= end) {
		return 1;
	}

	int x = arr[end];
	int idx = end - 1;

	while (idx >= start && arr[idx] > x) {
		idx--;
	}

	int tmp = idx;
	while (idx >= start) {
		if (arr[idx] > x) {
			return -1;
		}

		idx--;
	}

	if (tmp == start) {
		return 1 + isPostOrder(arr, start, end - 1);
	}
	else {
		return 1 + (isPostOrder(arr, start, tmp) && isPostOrder(arr, tmp + 1, end - 1));
	}
}

string afis(int* A, int end) {
	stringstream s;
	int i = 0;
	while (i <= end) {
		if(i) s << ", " << A[i++];
		else s << A[i++];
	}
	return s.str();
}

stringstream V;

bool Order = true;

// arbori
// liste
int f() {
	int n, urm;
	bool cresc=true;
	cin >> n;
	if (cin >> urm) {
		return -2;
	}
	if (urm == n + 1)
		cresc = true;
	else if (urm == n - 1)
		cresc = false;
	else
		return -1;

	while (true) {
		if (cresc) {
			if (n == 5)
				cresc = false, urm = 0;
			else
				urm = n + 1;
		}
		else {
			if (n == 0)
				cresc = true, urm = 1;
			else
				urm = n - 1;
		}

		cin >> n;
		if (n != urm)
			return -1;
	}
	return urm;
}

int C[] = { 3 4 5 4 5 4 3 }; // [2]
int D[] = { 5 4 3 2 1 0 1 }; //  [3]
int C[] = { 3 4 5 4 5 4 3 }; // [2]
int I[] = { 5 };
int A[] = { 5 3 4 1 3 0 2 };


int verifPostOrdine(int *A, int start, int end) {
	if (Order == false || end - start < 1)  //   0 1 2
		return 0;

	//  17, 23, 52, 86, 75, 99, 45, 31, 29, 14		17 [14] [23, 52, 86, 75, 99, 45, 31, 29]     preOrdine
	//	17, 23, 52, 86, 75, 99, 45, 31, 29, 14		[] [17, 23, 52, 86, 75, 99, 45, 31, 29] 14   postOrdine
	cout << afis(&A[start], end-start) << "  |  ";

	int sm(start), dm(start), sx(-1), dx(-1); // int sm(start+1), dm(start+1), sx(-1), dx(-1);
	if (A[sm] < A[end]) {
		sx = sm;
		while (A[sx + 1] < A[end]) //  while (A[sx + 1] < A[start])     && sx < end
			sx++;
		dm = sx + 1;
	}
	if (A[dm] > A[end]) {
		dx = dm;
		while (A[dx + 1] > A[end])
			dx++;
	}

	if ((sm != start && dm != start) || (sx + 1 != end && dx + 1 != end)) {
		Order = false;
		return -1;
	}

	V << A[end] << ", ";
	if(sm == sx) V << A[sm] << ", ";
	if(dm == dx) V << A[dm] << ", ";

	cout << " [" << afis(&A[sm], sx - sm) << "] [" << afis(&A[dm], dx - dm) << "] "  << A[end] << endl;
	int sH = (sx != -1) ? verifPostOrdine(A, sm, sx) : 0;
	int dH = (dx != -1) ? verifPostOrdine(A, dm, dx) : 0;
	return 1 + (sH > dH ? sH : dH);
}

NOD<int>* g;
NOD<int>* x;
// parcurgere postOrdine, unde am calcul pentru fiecare nod
int difNivel(NOD<int>* n, int &max) {
	int iS = n->st ? difNivel(n->st, max) : 0;
	int iD = n->dr ? difNivel(n->dr, max) : 0;
	int dif = iS > iD ? iS - iD : iD - iS;
	if (dif > max)
		x = n, max = dif;
	return 1 + ( iS > iD ? iS : iD ); // intoarce andancimea
}


int main() {
	//int N[] = { 12,49,31,6,11,25,9,4,7,24,19}; // ex5 
	//int N[] = { 24,12,48,31,8,11,25,9,4,7,19 ,20,26}; // ex8
	//int N[] = { 17,19,2,7,9,3,11,49,31 }; // ex10
	//int N[] = { 12,49,31,6,11,25,9,4,7,24,19 }; // ex14
	//int N[] = { 17,16,33,19,34,2,7,9,3,12,11,49,31,23,1,18,5,80,62,71 }; // ex18
	//int N[] = { 12,49,31,6,11,25,9,4,7,24,19 ,20,26}; // ex37
	//int N[] = { 17,19,2,7,9,3,11,49,31,1,18 }; // ex44
	//int N[] = { 17,19,2,7,9,3,11,49,31 }; // ex47
	//int N[] = { 12,49,31,6,11,25,9,4,7,24,19 ,20,26}; // ex65
	//int N[] = { 17,19,2,7,9,3,11,49,31,1,18 }; // ex67
	//int N[] = { 17,19, 2,7,9,3,11,49,31,1,18,5,80,62}; // ex79
	//int N[] = { 17,19,2,7,9,3,11,49,31 }; // ex83
	//int N[] = { 12,48,31,8,11,25,9,4,7,24,19,20,26 }; //ex84
	//int N[] = { 17,19,2,7,9,3,49,31,1,18 }; // ex88
	//int N[] = { 12,46,31,8,11,25,9,4,7,24,19,21,26,15 }; // ex95

#define BST
//#define HEAP
//	r > s && r < d
//	postordine
//	s d r
	if (false) {
		int N[] = { 14, 29, 31, 45, 23, 99, 75, 52, 17, 86 };
		int n = sizeof(N) / sizeof(N[0]);

		NOD<int>* root = new NOD<int>(N[0]);
		for (int i = 1; i < n; i++) {
			root->insert(N[i]);
		}
		cout << "postordine:" << endl; root->postOrdine(); cout << endl << endl;
		// 17, 23, 52, 86, 75, 99, 45, 31, 29, 14,

		root->print();
		return 0;
	}

/*
_


17, [23, [ _ [52, 86, 75], 99, 45], 31, 29], 14]

14
                                                        29
                        23                                                              31
        17                              __                              __                              45
  __              __              __              __              __              __              __              99
    __      __      __      __      __      __      __      __      __      __      __      __      __      75      __
  __  __  __  __  __  __  __  __  __  __  __  __  __  __  __  __  __  __  __  __  __  __  __  __  __  __  52  86  __  __
*/
	
//	NOD :   s   d   r

	//int N[] = { 7, 3, 9, 8};
	//int P[] = { 3, 8, 9, 7};

	int R[] = {14, 29, 23, 17, 31, 45, 99, 75, 52, 86};

	int N[] = {14, 29, 31, 45, 23, 99, 75, 52, 17, 86}; // arbore initial, regasit in V.str()
	int P[] = {17, 23, 52, 86, 75, 99, 45, 31, 29, 14}; // arbore in postOrdine
	int s = sizeof(P) / sizeof(P[0]);

	int a = 1 + verifPostOrdine(P, 0, s - 1);
	cout << "adancimea = " << (Order ? a : -1)  << endl << endl;
	
	cout << "init = " << V.str() << endl << endl;

	NOD<int>* n = new NOD<int>(N[0]);
	for (int i = 1; i < s; i++) {
		n->insert(N[i]);
	}
	
	cout << "adancimea = "  << n->adancimea() << endl;
	
	n->inOrdine(); cout << endl << endl;

	n->print();
	g = n; s = 0;
	difNivel(n, s);
	cout << ( s <= 1 ? "arbore echilibrat" : "arbore neechilibrat" ) << endl;
	

	NOD<int>* r = new NOD<int>(R[0]);
	for (int i = 1; i < s; i++) {
		r->insert(R[i]);
	}

	cout << "adancimea = " << r->adancimea() << endl;
	r->print();

	return 0;

/*
    // [s] r [d] 
	
	[s] [d] r      10 1 2    10 2 1     st < r < dr

	10 1 2                        [10 1]  [] 2


	A start, end;
	end == A[end] == root
	s < r   &&   r < d
	//     [sm, sx]     [dm, dx]   r
	

	// subarbore st
	sm = dm = start;
	if(A[sm] < A[end]){ // exista subarbore st
		sx = sm;
		while(A[sx+1] < A[end])
			sx++;
		fn(A, sm, sx);	// [sm, sx]
		dm = sx + 1;
	}
	if(A[dm] > A[end]){	// exista subarbore dr
		dx = dm;
		while(A[dx+1] < A[end])
			dx++;
		fn(A, dm, dx);	// [dm, dx]
	}


	dm = dx = end - 1;
	if(A[dm] > A[end]){			// subarbore dr
		while(dm >= start && A[dm] > A[end])
			dm--;
	}
	if(A[start] > A[end]){		// subarbore st
		sm = start; sx = dm - 1;
	}

	17, 23, 52, 86, 75, 99, 45, 31, 29, 14   [] [17, 23, 52, 86, 75, 99, 45, 31, 29] 14
	17, 23, 52, 86, 75, 99, 45, 31, 29       [17, 23] [52, 86, 75, 99, 45, 31] 29
	        52, 86, 75, 99, 45, 31           [] [52, 86, 75, 99, 45] 31
			52, 86, 75, 99, 45               [] [52, 86, 75, 99] 45
			52, 86, 75, 99                   [52, 86, 75] [] 99
			52, 86, 75                       52 86 75


//  17, [23, [52, 86, 75], 99, 45, 31, 29], 14

	17, 23, 52, 86, 75, 99, 45, 31, 29, [14]  : last = R

	[st = 23], [52, 86, 75, 99, 45, 31], [29]

	52, 86, [75], 99, 45, [31]
	
	[52, 86, 75]

	//int N[] = { 17,16,33,19,34,2,7,9,3,12,11,49,31,23,1,18,5,80,62,71 }; // ex97
	//int N[] = { 14, 29, 31, 45, 23, 99, 75, 52, 17, 86}; // PDF
//	int N[] = { 14, 29, 31, 45, 23, 99, 75, 52, 17, 86, 61, 44, 3, 13, 84 }; // PDF
*/
	/*
	NOD<int>* root = new NOD<int>(N[0]);
	for (int i = 1; i < n ; i++) {
#ifdef BST
		root->insert(N[i]);
#endif
#ifdef HEAP
		root->push(N[i]);
#endif
	}

#ifdef BST
	cout << "rez = " << isPostOrde(P, 0, n -1)<< endl;
#endif

#ifdef HEAP
	cout << "initial" << endl;
	root->print();

	cout << "primul pop" << endl;
	root->pop();
	root->print();
	
	cout << "al doilea pop" << endl;
	root->pop();
	root->print();
#endif

	//cout << "adancime=" << endl;
	cout << "preordine:" << endl; root->preOrdine(); cout << endl << endl;
	cout << "postordine:" << endl; root->postOrdine(); cout << endl << endl;
	cout << "inordine:" << endl; root->inOrdine(); cout << endl << endl;

	root->print();
	*/
	return 0;
}