#include <bits/stdc++.h>

using namespace std;

int N, M, c[100000];
typedef pair<int, int> pii;
#define f first
#define s second
pii que[100000]; // (end, beginning)
int main()
{
	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		cin >> c[i];
	}
	for(int i = 0; i < M; i++)
	{
		cin >> que[i].s >> que[i].f;
	}

	return 0;
}