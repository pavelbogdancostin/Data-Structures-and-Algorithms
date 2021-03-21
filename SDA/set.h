#pragma once

template <class T>
struct Node {
	T data;
	Node<T>* left, * right;

	explicit Node(T _data) {
		data = _data;
		left = right = nullptr;
	}
	void insert(const T& key) {
		if (key < data) {
			if (left)
				left->insert(key);
			else
				left = new Node<T>(key);
		}
		else {
			if (right)
				right->insert(key);
			else
				right = new Node<T>(key);
		}
	}
	bool find(const T& key) {
		if (data == key)
			return true;
		if (key < data)
			if (left)
				return left->find(key);
			else
				return false;
		else
			if (right)
				return right->find(key);
			else
				return false;
	}
	void remove(const T& key) {
		Node<T>* t, * tmp; //retuneaza false daca NU s-a gasit key
		if (data == key) // s-a gasit nodul ce trebuie sters
		{
			if (left) // cautare cel mai mare nod din subarborele stang
			{
				t = left;
				if (!t->right && !t->left) // t este frunza
				{
					data = t->data; // se muta left in nodul parinte
					delete t;
					left = NULL;
				}
				else if (t->right) // t are urmas pe dreapta
				{
					while (t->right->right) //parcurgere toti descendenti pe parte right
						t = t->right;
					data = t->right->data;//schimb data nod crt cu nod cel mai right
					tmp = t->right;
					t->right = t->right->left;
					delete tmp; //sterg nod inlocuit
				}
				else // t NU are urmas pe dreapta, ARE pe stanga, inlantuit
				{
					data = t->data;
					left = t->left;
					delete t;
				}
			}
			else
				if (right) //nodul (data=key) NU are urmas pe left, dar ARE urmas pe right
				{
					t = right; // inlantuit (lista)
					data = t->data;
					left = t->left;
					right = t->right;
					delete t;
				}
			return;// true; // s-a gasit key si s-a sters nodul
		}// end if(data==key)// nu s-a gasit nodul care continue key
		if (key < data) //avansare pe stanga
		{
			if (left)
				return left->remove(key);
		}
		else //key>data ; avansare pe dreapta
			if (right)
				return right->remove(key);
		return;// false; // NU s-a gasit nodul
	}
};

template <class T>
struct Set {
	Node<T>* root;
	Set() {
		root = nullptr;
	}
};

template <class T>
void InsertSet(Set<T>& s, T key) {
	if (s.root == nullptr)
		s.root = new Node<T>(key);
	else
		if(s.root->find(key) == false)
			s.root->insert(key);

	if (s.root) {
		if (s.root->find(key) == false)
			s.root->insert(key);
	}
	else
		s.root = new Node<T>(key);
}

template <class T>
bool findSet(Set<T>& s, T key) {
	return s.root ? s.root->find(key) : false;
}
template <class T>
void removeSet(Set<T>& s, T key) {
	if(s.root)
		s.root->remove(key);
}
