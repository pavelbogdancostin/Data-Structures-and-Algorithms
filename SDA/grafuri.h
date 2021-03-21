#pragma once


class Nod // nod pt constructie lista adiacenta
{
	int Nod_Ad;
	Nod* urm;
public:
	
};
struct Edge
{
	int src, dest;
};
class Graf
{
	int nNod; // numar de noduri
	Nod** CapGraf;
public:
	Graf(Edge edges[], int nArce, int nN)
	{
		capGraf = new Nod * [nN]; // alocare dinamica vector de nNod pointeri Nod*
		nNod = nN;
		for (int i = 0; i < nN; ++i)     //// TEMA: Sa se implementeze cu santinela
			capGraf[i] = nullptr; // se lucreaza fara santinela
		for (int i = 0; i < nArce; i++)
		{
			int src = edges[i].src;
			int dest = edges[i].dest;
			// inserare la inceputul listei
			Nod* newNod = new Nod(dest);
			newNod->urm = capGraf[src];
			capGraf[src] = newNod;
		}
		// Destructor
		~Graf()
		{
			for (int i = 0; i < nNod; i++)
				delete[] capGraf[i];
			delete[] capGraf;
		}
	};

