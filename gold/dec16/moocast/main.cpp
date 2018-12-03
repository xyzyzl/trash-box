#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

#define MAXN 1000
#define mp make_pair
#define vt vector
#define SQ(x) (x*x)
#define endl '\n'
#define ib ios_base::sync_with_stdio(false)

int N;
int p[MAXN], sz[MAXN];

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
#define f first
#define s second

pii locs[MAXN];
vt<piii> v;

int root(int u)
{

	while (u != p[u])
	{
		p[u] = p[p[u]];
		u = p[u];
	}

	return u;

}

int find(int u, int v)
{

	return root(u) == root(v);

}

bool merge(int u, int v)
{

	u = root(u);
	v = root(v);
	if (u == v)
		return false;
	p[u] = v;
	if (sz[u] >= sz[v])
	{
		p[v] = u;
		sz[u] += sz[v];
	} else
	{
		p[u] = v;
		sz[v] += sz[u];
	}

	return true;

}

int main()
{
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
	ib;
	cin >> N;
	// cout << SQ(2) << endl;
	fill(sz, sz+MAXN, 1);
	for(int i = 0; i < N; i++)
	{
		p[i] = i;
		cin >> locs[i].f >> locs[i].s;
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = i+1; j < N; j++)
		{
			v.push_back(mp(abs(pow(locs[i].f-locs[j].f,2) + pow(locs[i].s-locs[j].s, 2)), mp(i, j)));
			// cout << abs(pow(locs[i].f-locs[j].f,2) + pow(locs[i].s-locs[j].s, 2)) << " " << abs(SQ(locs[i].f-locs[j].f) + SQ(locs[i].s-locs[j].s)) << endl;
		}
	}
	sort(v.begin(), v.end());
	int sm = 0;
	int ct = N-1;
	for(int i = 0; i < v.size(); i++)
	{
		if(merge(v[i].s.f, v[i].s.s))
		{
			sm = v[i].f;
			if (--ct =- 0)
				break;
		}
	}
	cout << sm << endl;
}