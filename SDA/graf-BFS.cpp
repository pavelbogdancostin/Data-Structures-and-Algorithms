#include    <iostream>
#include    <fstream>
#include    <vector>
#include    <queue>

using namespace std;

struct E {
	int x, y;
	E(int a, int b) {
		x = a; y = b;
	}
};


ifstream fin("..//date//bfs.in");
//ofstream fout("bfs.out");

const int NLIM = 100005;

int N, M, S;
int Distance[NLIM];

vector <int> Edge[NLIM];
queue <int> Q;

void BFS()
{
	int Node, Next;
	while (!Q.empty())
	{
		Node = Q.front();
		Q.pop();
		for (unsigned int i = 0; i < Edge[Node].size(); i++)
		{
			Next = Edge[Node][i];
			if (Distance[Next] == -1)
			{
				Q.push(Next);
				Distance[Next] = Distance[Node] + 1;
			}
		}
	}
}

void Read()
{
	fin >> N >> M >> S;
	for (int i = 1; i <= M; i++)
	{
		int x, y;
		fin >> x >> y;
		Edge[x].push_back(y);
	}
	for (int i = 1; i <= N; i++)
		Distance[i] = -1;
	Distance[S] = 0;

	Q.push(S);

	BFS();

	for (int i = 1; i <= N; i++)
		cout << Distance[i] << " ";
		//fout << Distance[i] << " ";
}

int main()
{
	struct E e[] = { {1,2}, {2,3}, {3, 4} };



	Read();
	return 0;
}