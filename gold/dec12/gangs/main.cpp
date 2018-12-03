#include <bits/stdc++.h>

#define MAXN 105

using namespace std;
int N, M;
// only one cow can walk
void walk(int& gang, int& field, int cgang)
{
	if(field == 0)
		gang = cgang;
	if(gang == cgang)
		field++;
	else
		field--;
}
int func(int gang, int field, vector<int> sz)
{
	sort(sz.begin()+1, sz.end());
	while(sz.back())
	{
		for(int j = sz.size()-1; j > 0; j--)
		{
			walk(gang, field, j);
			sz[j]--;
			if(sz[j-1] <= sz[j])
				break;
		}
	}
	for(int i = 0; i < sz[0]; i++)
	{
		walk(gang, field, 0);
	}
	if(gang == 0)
		return field;
	return 0;
}

int main()
{
	freopen("gangs.in", "r", stdin);
	freopen("gangs.out", "w", stdout);
	cin >> N >> M;
	vector<int> sz(M);
	fill(sz.begin(), sz.end(), 0);
	for(int i = 0; i < M; i++)
	{
		cin >> sz[i];
	}

	// gang #, # on field, can you loop at all
	int gang = 0, field = 0;
	int can = func(gang, field, sz);
	if(can)
	{
		cout << "YES\n" << can << '\n';
		// try to find lexicographical order
		for(int i = 0; i < N; i++)
		{
			int pgang = gang;
			int pfield = field;
			for(int j = 0; ; j++)
			{
				if(sz[j] == 0)
				{
					continue; // gang is exhausted
				}
				sz[j]--;
				walk(gang, field, j);
				if(func(gang, field, sz) == can)
				{
					cout << j+1 << '\n';
					break;
				}
				// didn't work
				sz[j]++;
				gang = pgang;
				field = pfield;
			}
		}
	} else
	{
		cout << "NO\n";
	}

	return 0;
}