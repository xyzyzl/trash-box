#include <bits/stdc++.h>

#define MAXN 1005

using namespace std;

int H, G;

typedef pair<int, int> pii;
#define f first
#define s second

pii ho[MAXN];
pii gu[MAXN];

int dph[MAXN][MAXN];
int dpg[MAXN][MAXN];
int dist(pii a, pii b)
{
	return (a.s-b.s)*(a.s-b.s) + (a.f-b.f)*(a.f-b.f);
}
int main()
{
	freopen("checklist.in", "r", stdin);
	freopen("checklist.out", "w", stdout);
	cin >> H >> G;
	for(int i = 1; i <= H; i++)
	{
		cin >> ho[i].f >> ho[i].s;
	}
	for(int i = 1; i <= G; i++)
	{
		cin >> gu[i].f >> gu[i].s;
	}
	for(int i = 0; i < MAXN; i++)
	{
		for (int j = 0; j < MAXN; j++)
			dph[i][j] = dpg[i][j] = 2147483647;
	}

	dph[1][0] = 0;
	for(int i = 1; i <= H; i++)
	{
		for(int j = 0; j <= G; j++)
		{
			if(i > 0)
			{
				// H-->H
				if(dph[i-1][j] != 2147483647)
					dph[i][j] = dph[i - 1][j] + dist(ho[i - 1], ho[i]);
				// G-->H
				if(dpg[i-1][j] != 2147483647)
					dph[i][j] = min(dph[i][j], dpg[i - 1][j] + dist(gu[j], ho[i]));
			}
			if(j > 0)
			{
				// H-->G
				if(dph[i][j-1] != 2147483647)
					dpg[i][j] = dph[i][j - 1] + dist(ho[i], gu[j]);
				// G-->G
				if(dpg[i][j-1] != 2147483647)
					dpg[i][j] = min(dpg[i][j], dpg[i][j - 1] + dist(gu[j - 1], gu[j]));
			}
		}
	}
	cout << dph[H][G] << endl;
	return 0;
}