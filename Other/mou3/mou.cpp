#include <bits/stdc++.h>

#define K M.size()
#define int long long

using namespace std;

int N;
set<int> M;

struct instruct
{
	int a, b, d;
	char t;

	instruct(int _a, int _b, int _d)
	{
		t = 'I';
		a = _a;
		b = _b;
		d = _d;
	}

	instruct(int _d)
	{
		t = 'Q';
		d = _d;
	}
};

vector<instruct> v;

struct Node
{
	int l, s, v;
	Node(int _l, int _s, int _v)
	{
		l=_l;
		s=_s;
		v=_v;
	}
};

main()
{
	cin >> N;
	char c;
	while (true)
	{
		cin >> c;
		if (c == 'E')
			break;
		else if (c == 'I')
		{
			int a, b, d;
			cin >> a >> b >> d;
			v.push_back(instruct(a, b, d));
			M.insert(a);
			M.insert(b);
		} else
		{
			int h;
			cin >> h;
			v.push_back(instruct(h));
		}
	}
	// Node nd = Node(0, M.size()-1);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].t << endl;
		if (v[i].t == 'I')
			// nd.upd((*M.lower_bound(v[i].a)), *M.lower_bound(v[i].b)-1, v[i].d);
		else
		// cout << nd.query(v[i].d) << '\n';
	}
}