#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string.h>

//#define MAX_N 1000001

#define MAX_N 16

using namespace std;

ifstream f("..//date//darb-geek.in");
ofstream g("..//date//darb.out");

/*
// arbori binari
int diameterOpt(struct node* root, int& height) {
	// lh --> Height of left subtree
	//   rh --> Height of right subtree
	int lh = 0, rh = 0;

	if (root == NULL){
		height = 0;
		return 0; // diameter is also 0
	}

	// ldiameter  --> diameter of left subtree
	//   rdiameter  --> Diameter of right subtree
	//  Get the heights of left and right subtrees in lh and rh
	//  And store the returned values in ldiameter and ldiameter
	int ldiameter = diameterOpt(root->left, lh);
	int rdiameter = diameterOpt(root->right, rh);

	// Height of current node is max of heights of left and
	//   right subtrees plus 1
	height = 1 + max(lh, rh);

	return max(1 + lh + rh, max(ldiameter, rdiameter));
}
*/
// arbori parcurgere latime - adancime
vector<int> nod[MAX_N];
queue<int> coada;
int n, contor[MAX_N], viz[MAX_N], last, diametru;

/*
[0]:
[1]: 2, 3, 4
[2]: 5
[3]: 6
[4]: 7
[5]: 8
[5]: 9
[6]: 10
[8]: 
[10]: 11
[11]:
*/

//[2, 3, 4], height
int diameterOpt(int n, int& height) { // [8] 0 0
	/*if (nod[n].size() == 0) {
	//if ( n == 0 ) {
		height = 1;
		cout << "[" << n << "]=" << 1 << ": " << 1 << " " << 0 << endl;
		return 1;
	}*/
	int sH = 0, mD = 0, mH = 0;
	for (int i = 0; i < nod[n].size(); i++) {
		int h;
		int d = diameterOpt(nod[n][i], h);
		sH += h;
		mH = max(mH, h);
		mD = max(mD, d);
		//if (h > mH) mH = h;
		//if (d > mD) mD = d;
	}
	height = 1 + mH;
	cout << "[" << n << "] h=" << height << "  d=" << max(1 + sH, mD) << " : " << 1 + sH << " " << mD << endl;
	return max(1 + sH, mD);
}
/* geek -- corect
D  = max(1 + suma Inaltimilor subarborilor, maxim diametrelor subarborilor);
[8] h=1  d=1 : 1 0
[9] h=1  d=1 : 1 0
[5] h=2  d=3 : 3 1
[2] h=3  d=3 : 3 3
[11] h=1  d=1 : 1 0
[11] h=1  d=1 : 1 0
[11] h=1  d=1 : 1 0
[10] h=2  d=4 : 4 1
[6] h=3  d=4 : 3 4
[3] h=4  d=4 : 4 4
[1] h=5  d=8 : 8 4
height=5, d=8

corect geek
[8]=1: 1 0
[9]=1: 1 0
[5]=3: 3 1
[2]=3: 3 3
[11]=1: 1 0
[10]=2: 2 1
[6]=3: 3 2
[3]=4: 4 3
[1]=8: 8 4
Diameter of the given binary tree is 8 h=5
*/

void bfs(int plecare) {
	memset(contor, 0, sizeof(contor));
	memset(viz, 0, sizeof(viz));
	coada.push(plecare);
	contor[plecare] = 1;
	viz[plecare] = 1;
	int i, el;
	while (!coada.empty()) {
		el = coada.front();
		for (i = 0; i < nod[el].size(); i++) {
			if (viz[nod[el][i]] == 0) {
				coada.push(nod[el][i]);
				contor[nod[el][i]] = contor[el] + 1;
				viz[nod[el][i]] = 1;

				diametru = contor[nod[el][i]];
				last = nod[el][i];
			}
		}
		coada.pop();
	}
}

void citire() {
	int i, a, b;
	f >> n;
	for (i = 0; i < n; i++) {
		f >> a >> b;
		nod[a].push_back(b);
		//nod[b].push_back(a);
	}
}

int main(){
	citire();
	//bfs(1);
	//bfs(last);
	//g << diametru;
	//cout << "diametru =" << diametru << endl;

	int height, d = diameterOpt(1, height);
	cout << "height=" << height << ", d=" << d << endl;
	return 0;
}
/*
11
1 2
1 3
1 4
2 5
3 6
4 7
5 8
5 9
6 10
10 11

          1
	 2    3    4
	 5    6    7
   8  9  10
	     11
*/

/*//#include <bits/stdc++.h>
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("..//date//planeta.in");
ofstream fout("..//date//planeta.out");

//#define int long long

const int DIM = 33;

int dp[DIM][DIM];
int cnt[DIM];

void solve(int n, int k, int add = 0)
{
	if (n == 0)
		return;

	if (n == 1)
	{
		fout << add + 1 << ' ';
		return;
	}

	for (int i = 1; i <= n; ++i)
	{
		if (dp[n][i] < k)
		{
			k -= dp[n][i];
			continue;
		}

		fout << i + add << ' ';
		solve(i - 1, (k - 1) / cnt[n - i] + 1, add);
		solve(n - i, (k - 1) % cnt[n - i] + 1, add + i);
		return;
	}
}

int main(){
	int n, k;
	fin >> n >> k;

	dp[0][0] = 1;
	cnt[0] = 1;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j)
		{
			dp[i][j] = cnt[i - j] * cnt[j - 1];
			cnt[i] += dp[i][j];
		}

	solve(n, k);
	return 0;
}*/