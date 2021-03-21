#include<iostream>
using namespace std;

struct nod {
	int val;
	nod* next;
};

struct lista{
	nod* head;		// inceput lista
	nod* crt;		// nodul curent dupa inserare

	lista() { head = NULL; crt = NULL; }

	void add(int val) {
		nod* n = new nod; n->val = val; n->next = NULL;
		if (head == NULL)
			head = n;
		else crt->next = n;
		crt = n;
	}
	void add(int val) {
		nod* n = new nod; n->val = val; n->next = NULL;
		if (head == NULL)
			head = n;
		else crt->next = n;
		crt = n;
	}

	void del(int val) {		 // 200
		if (head == NULL) return;
		nod* d = head;
		if(head->val == val) { // 10, 20, 30, ... 40
			head = d->next;
			delete d;
			return;
		}
		nod* n = head; d = n->next;
		while (d) {
			if (d->val == val) {
				n->next = d->next ? d->next : NULL;
				delete d;
				break;
			}
			n = d; d = d->next;
		}
	}
	void cout(void) {
		if (head == NULL) {
			std::cout << " lista vida !" << endl;
			return;
		}
		nod* n = head;
		while (n) {
			std::cout << n->val << "  ";
			n = n->next;
		}
		std::cout << endl;
	}
};

int main() {
	{
		lista l;
		l.add(10);
		l.add(20);
		l.add(30);
		l.add(40);
		l.cout();

		l.del(30); l.cout();
		l.del(40); l.cout();
		l.del(10); l.cout();
		l.del(20); l.cout();

	}
	system("pause");
	return 0;
}


/*    0       1       2      3      4
     0x10    0x20   0x30   0x40   0x50
val   20      30     40     50     60      
next  &1      &2     &3     &4     NULL

nod *lista=NULL; // nu are nici un nod

lista->add(55);
	 0x10
val   55 
next  NULL

lista->add(75);
	 0x10    0x20
val   55      75
next  0x20   NULL

lista->add(90);
	 0x10    0x20    0x30
val   55      75      90
next  0x20   0x30    NULL

add(val) => insereze un nod new cu valoarea data
*nod = new nod; nod->val = val; nod->next=NULL;

nod *lista=NULL; // nu are nici un nod

if(lista == NULL){
	lista->add(val);
	lista = new nod; nod->val = val; nod->next=NULL;
}

lista = new nod; nod->val = 0; nod->next=NULL;

lista->add(10);
lista->afis(){ // val + next
	nod *n = next;
	while(n){
		cout << n->val << endl;
		n = n->next;
	}
}

definesc o lista
si prin metoda a listei sa adaug noduri

// nod *lista;
lista->add(20); // adauga la sfarsitul listei
lista->cout();

nod *n = lista->getNod(int pos);		// nod *n2 = lista->getPos(2);
int pos = lista->getPos(nod *n);

lista->delete(int pos);					// lista->delete(2);
lista->delete(nod *n);					// lista->delete(n2);

*/