//Problema DFS - inforaena.ro - http://www.infoarena.ro/problema/dfs
//Tutorialul complet, explicat - http://tutoriale-pe.net/parcugerea-adancime-dfs/
#include    <fstream>
#include    <vector>
#include <iostream>
using namespace std;
 
ifstream fin("..//date//dfs.in");
//ofstream fout("dfs.out");

const int NLIM = 100005;

int sp[1000]; // alocare statica

int* g[];  1 - 50000

g[0] = sp; //  &sp[0];   0 -- N-1
g[1] = &sp[N];			// N -2*b-1
g[2] = &sp[N];			// 2*N -3*b-1

cin >> N;
for()


/*
Obs.: Cap_Graf = vector de pointeri catre NOD, cu alocare statica, de dimensiune fixa
egala cu numarul de noduri din graf
*/



int N, M;
vector < int > Edge  [NLIM];

Edge[0] vector<int>
Edge[1] vector<int>

int v[10];



bool beenThere[NLIM];
int answer;
 
void DFS(int Node)
{
    beenThere[Node] = true;
    for(unsigned int i = 0; i < Edge[Node].size(); i++)
    {
        int Next = Edge[Node][i];
        if(!beenThere[Next])
            DFS(Next);
    }
}
 
void Read()
{
    fin >> N >> M;
    for(int i = 1; i <= M; i++)
    {
        int x, y;
        fin >> x >> y;
        Edge[x].push_back(y);
        Edge[y].push_back(x);
    }

	1 3
	Edge[1].push_back(3);
	Edge[3].push_back(1);
	1 5
	Edge[1].push_back(5);
	Edge[5].push_back(1);
	4 1
	Edge[4].push_back(1);
	Edge[1].push_back(4);

	Edge[1] : 3, 5, 4
	Edge[3] : 1
	Edge[4] : 1
	Edge[5] : 1



    for(int i = 1; i <= N; i++)
    {
        if(!beenThere[i])
        {
            answer += 1;
            DFS(i);
        }
    }
    //fout << answer << "\n";
	cout << answer << "\n";
}
 
int main()
{
    Read();
    return 0;
}