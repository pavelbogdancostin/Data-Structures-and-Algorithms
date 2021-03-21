#pragma once

// coada FIFO 

// stiva LIFO 



template<typename DT, int N=100>
struct coadaS{
	int n;
	DT l[N];
	coadaS() {
		n = 0;
	}
	bool push(const DT& d){
		if (n == N)
			return false;
		l[n++] = d;
		return true;
	}
	DT front(void){
		return l[0];
	}
	DT pop(void){
		DT rez = l[0]; 
		--n;
		for (int i = 0; i < n; i++)
			l[i] = l[i + 1];
		return rez;
	}
	int size(void){
		return n;
	}
	bool isEmpty(void) {
		return n ? true : false;
	}

	friend ostream& operator << <DT,N>(ostream&, const coadaS<DT,N>&);
};

template < typename DT, int N>
ostream& operator << (ostream& os, const coadaS<DT, N>& lst) {
	os << lst.n << " " << N << " { ";
	for (int p = 0; p < lst.n; p++)
		os << lst.l[p] << " ";
	os << "}";
	return os;
}

