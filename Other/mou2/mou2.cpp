#include <bits/stdc++.h>

#define int long long

struct Node
{
	int l, r, m, s, lazy;
	bool on;
	int MAX, TOT;
	std::vector<Node> c;

	Node(int _l, int _r)
	{
		l = _l;
		r = _r;
		m = (l + r) / 2;
		s = r - l + 1;
		MAX = 0;
		TOT = 0;
		lazy = 0;
		on = 0;
	}

	void init()
	{
		if (c.empty() && l < r)
		{
			c.push_back(Node(l, m));
			c.push_back(Node(m + 1, r));
		}
		if (on)
		{
			if (l < r)
			{
				c[0].lazy = c[1].lazy = lazy;
				c[0].on = c[1].on = on;
			}
			TOT = MAX = s * lazy;
		}
		lazy = on = 0;
	}

	int query(int h)
	{
		init();
		if (l == r)
		{
			if (MAX > h)
				return l - 1;
			else
				return l;
		}
		c[0].init();
		if (c[0].MAX > h)
			return c[0].query(h);
		return c[1].query(h - c[0].TOT);
	}

	void upd(int a, int b, int D)
	{
		init();
		if (a > b || a > r || b < l)
			return;
		if (a <= l && b >= r)
		{
			lazy = D;
			on = 1;
			init();
			return;
		}
		c[0].upd(a, b, D);
		c[1].upd(a, b, D);
		TOT = c[0].TOT + c[1].TOT;
		MAX = std::max(c[0].MAX, c[0].TOT + c[1].MAX);
	}
};


int N;

main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin >> N;
	char c;
	Node root = Node(1, N);
	while (true)
	{
		std::cin >> c;
		if (c == 'E')
			break;
		else if (c == 'I')
		{
			int a, b, D;
			std::cin >> a >> b >> D;
			root.upd(a, b, D);
		} else
		{
			int h;
			std::cin >> h;
			std::cout << root.query(h) << '\n';
		}
	}
}
