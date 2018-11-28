#include <bits/stdc++.h>

#define LEFT(x) 2*x
#define RIGHT(x) 2*x+1

#define EMPTY 1
#define FULL 2
#define OTHER 0

using namespace std;

struct Node {
  int l, r, mx, sz;
};

int N, M;
vector<Node> tree;
vector<int> lazy;

void build(int node, int a, int b) {
  tree[node].l=tree[node].r=tree[node].mx=tree[node].sz=b-a+1;
  if(a != b) {
    int mid = (a+b)/2;
    build(LEFT(node), a, mid);
    build(RIGHT(node), mid+1, b);
  }
}

void prop(int node) {
  lazy[LEFT(node)] = lazy[RIGHT(node)] = lazy[node];
  if(lazy[node] == FULL) {
    tree[LEFT(node)].l = tree[LEFT(node)].r = tree[LEFT(node)].mx = 0;
    tree[RIGHT(node)].l = tree[RIGHT(node)].r = tree[RIGHT(node)].mx = 0;
  }
  else {
    tree[LEFT(node)].l = tree[LEFT(node)].r = tree[LEFT(node)].mx = tree[LEFT(node)].sz;
    tree[RIGHT(node)].l = tree[RIGHT(node)].r = tree[RIGHT(node)].mx = tree[RIGHT(node)].sz;
  }
  lazy[node] = OTHER;
}

void upd(int node, int a, int b, int i, int j, bool fl) {
  if(b < i || j < a)
    return;
  if(a >= i && b <= j) {
    tree[node].l = tree[node].r = tree[node].mx = fl ? (b-a+1) : 0;
    lazy[node] = fl ? EMPTY : FULL;
    return;
  }
  if(lazy[node] != OTHER)
    prop(node);

  int mid = (a+b)/2;
  upd(LEFT(node), a, mid, i, j, fl);
  upd(RIGHT(node), mid+1, b, i, j, fl);

  tree[node].mx = max(max(tree[LEFT(node)].mx, tree[RIGHT(node)].mx), tree[LEFT(node)].r + tree[RIGHT(node)].l);
  if(tree[LEFT(node)].l == tree[LEFT(node)].sz)
    tree[node].l = tree[LEFT(node)].l + tree[RIGHT(node)].l;
  else
    tree[node].l = tree[LEFT(node)].l;
  
  if(tree[RIGHT(node)].l == tree[RIGHT(node)].sz)
    tree[node].r = tree[LEFT(node)].r + tree[RIGHT(node)].r;
  else
    tree[node].r = tree[RIGHT(node)].r;
}

int seat(int node, int a, int b, int p) {
  if (lazy[node] != OTHER)
    prop(node);
  if (tree[node].l >= p)
    return a;
  int mid = (a+b)/2;
  if (tree[LEFT(node)].mx >= p)
    return seat(LEFT(node), a, mid, p);
  if (tree[LEFT(node)].r + tree[RIGHT(node)].l >= p)
    return mid-tree[LEFT(node)].r+1;
  return seat(RIGHT(node), mid+1, b, p);
}

int turnaway(int p) {
  if (tree[1].mx < p)
    return 0;
  int st = seat(1, 1, N, p);
  upd(1, 1, N, st, st + p - 1, false);
  return st;
}

int main() {
  cin >> N >> M;
  tree.resize(4*N);
  lazy.assign(4*N, OTHER);
  build(1, 1, N);
  int ct = 0;
  for(int i = 0; i < M; i++) {
    char c;
    cin >> c;
    if(c == '1') {
      int x;

      cin >> x;
      cout << turnaway(x) << endl;
	}
    else {
      int a, b;
      cin >> a >> b;
      upd(1, 1, N, a, a+b, true);
    }
  }
}
