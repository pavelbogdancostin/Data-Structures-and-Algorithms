#pragma once

template<typename DT>
struct NOD { 
	DT data;
	NOD* urm;
	NOD(const DT& d) {
		data = d;
		urm = NULL;
	}

	void operator = (const NOD& d) {
		data = d.data;
		urm = d.urm;
	}
	bool operator == (const NOD& d) {
		return(data==d.data);
	}

	friend ostream& operator << <DT>(ostream&, NOD<DT>&);
};

template<typename DT>
ostream& operator << (ostream& os, NOD<DT>& d) {
	os << " ( " << d.data <<" "<< d.urm << " ) " << endl;
	return os;
}

template<typename DT>
struct coadaD {
	int _size;
	NOD<DT> *inc, *sf;

	coadaD() {
		_size = 0;  inc = sf = NULL;
	}

	void push(const DT& data) {
		_size++;
		NOD<DT>*  n = new NOD<DT>(data);
		if (sf != NULL)
			sf->urm = n;
		sf = n;
		if (inc == NULL) inc = n;
	}
	DT pop(void) {
		_size--;
		DT rez;
		if (inc) {
			NOD<DT>* n = inc;
			inc = inc->urm;
			rez = n->data;
			delete n;
		}
		return rez;
	}
	DT front(NOD<DT>* inc){
		if (inc)
			return inc->data;
		return DT(0);
	}
	bool isEmpty(NOD<DT>* inc){
		return inc == NULL;
	}
	int size(void) {
		/*NOD<DT>* n = inc; int s = 0;
		while (n) {
			s++;
			n = n->urm;
		}*/
		return _size;
	}
	friend ostream& operator << <DT>(ostream&, const coadaD<DT>&);
	friend istream& operator >> <DT>(istream&, coadaD<DT>&);
};

template < typename DT>
ostream& operator << (ostream& os, const coadaD<DT>& lst) {
	os << lst._size << endl;
	NOD<DT>* n = lst.inc;
	while (n) {
		os << n->data << endl;
		n = n->urm;
	}
	return os;
}

template < typename DT>
istream& operator >> (istream& os, coadaD<DT>& lst) {
	int size;
	os >> size;

	DT m;
	for (int i = 0; i < size; i++) {
		os >> m;
		lst.push(m);
	}
	return os;
}

template<typename DT>
struct coadaDP {
	int _size;
	NOD<DT>* inc, * sf;

	coadaDP() {
		_size = 0;  inc = sf = NULL;
	}

	void push(const DT& data) {
		_size++;
		NOD<DT>* n = new NOD<DT>(data);
		if (sf != NULL)
			sf->urm = n;
		sf = n;
		if (inc == NULL) inc = n;
	}
	DT pop(void) {
		_size--;
		DT rez;
		if (inc) {
			NOD<DT>* n = inc;
			inc = inc->urm;
			rez = n->data;
			delete n;
		}
		return rez;
	}
	DT front(NOD<DT>* inc) {
		if (inc)
			return inc->data;
		return DT(0);
	}
	bool isEmpty(NOD<DT>* inc) {
		return inc == NULL;
	}
	int size(void) {
		/*NOD<DT>* n = inc; int s = 0;
		while (n) {
			s++;
			n = n->urm;
		}*/
		return _size;
	}
	friend ostream& operator << <DT>(ostream&, const coadaD<DT>&);
	friend istream& operator >> <DT>(istream&, coadaD<DT>&);
};

template < typename DT>
ostream& operator << (ostream& os, const coadaD<DT>& lst) {
	os << lst._size << endl;
	NOD<DT>* n = lst.inc;
	while (n) {
		os << n->data << endl;
		n = n->urm;
	}
	return os;
}





/*

template < typename DT>
ostream& operator << (ostream& os, const coadaD<DT>& lst) {
	os << lst.inc << " " << lst.sf << " { ";
	NOD<DT>* n = lst.inc;
	while (n) {
		os << n->data << " ";
		n = n->urm;
	}
	os << "}";
	return os;
}

*/


/*
int main()
{ 
	NOD* inc = NULL;
	NOD* sf = NULL;
	push(inc, sf, 2);
	push(inc, sf, 4); 
	push(inc, sf, 6); 
	push(inc, sf, 7);
	push(inc, sf, 8);
	cout << pop(inc); 
	cout << pop(inc); 
	cout << pop(inc); 
	return 0;
}

	coadaD<int> c;
	c.push(2);
	c.push(4); 
	c.push(6); 
	c.push(7);
	c.push(8);
	cout << c.pop(); 
	cout << c.pop(); 
	cout << c.pop();

*/