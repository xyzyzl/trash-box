#include <bits/stdc++.h>

#define MAXN 100005
#define MAX (1 << 17)
#define INF 632632632

using namespace std;

int N, M, c[MAXN], bit[MAX * 2], lazy[MAX * 2];
typedef pair<int, int> pii;
#define f first
#define s second
pii que[MAXN]; // (end, beginning)

void up(int cur)
{
	if (cur >= MAX)
		return;
	bit[cur] = min(bit[2 * cur], bit[2 * cur + 1]);
}

void down(int cur)
{
	if (!lazy[cur])
		return;
	if (cur >= MAX)
		return;
	bit[2 * cur] -= lazy[cur];
	bit[2 * cur + 1] -= lazy[cur];
	lazy[2 * cur] += lazy[cur];
	lazy[2 * cur + 1] += lazy[cur];
	lazy[cur] = 0;
}

void init(int cur, int left, int right)
{
	if (cur >= 2 * MAX)
		return;
	down(cur);
	int mid = left + (right - left) / 2;
	init(2 * cur, left, mid);
	init(2 * cur + 1, mid, right);
	up(cur);
}

void add(int l, int r, int cur, int left, int right)
{
	if (left > r || right <= l)
		return;
	if (left >= l && right - 1 <= r)
	{
		lazy[cur]++;
		bit[cur]--;
		return;
	}
	down(cur);
	int mid = left + (right - left) / 2;
	add(l, r, 2 * cur, left, mid);
	add(l, r, 2 * cur + 1, mid, right);
	up(cur);
}

bool acc(int l, int r, int cur, int left, int right)
{
	if (left > r || right <= l)
	{
		cout << "phuc" << endl;
		return true;
	}
	if (left >= l || right <= r + 1)
	{
		cout << bit[cur] << endl;
		return (bit[cur] != 0);
	}
	down(cur);
	int mid = left + (right - left) / 2;
	bool fr = acc(l, r, 2 * cur, left, mid);
	bool bk = acc(l, r, 2 * cur + 1, mid, right);
	return fr && bk;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> c[i + MAX];
	}
	for (int i = N + MAX; i < MAX * 2; i++)
	{
		bit[i] = INF;
	}
	init(1, 0, MAX);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		que[i].f = b-1;
		que[i].s = a-1;
	}
	sort(que, que + M);
	// maintain a BIT that inserts the indices in this order
	int ct = 0;
	for (int i = 0; i < M; i++)
	{
		if (acc(que[i].s, que[i].f, 1, 0, MAX))
		{
			add(que[i].s, que[i].f, 1, 0, MAX);
			ct++;
		}
	}
	cout << ct << '\n';
	return 0;
}