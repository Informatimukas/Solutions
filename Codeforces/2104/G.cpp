#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

typedef struct snode *sn;
struct snode {         //////// VARIABLES
	sn p, c[2];        // parent, children
	bool flip = 0;     // subtree flipped or not
	int sz;            // # nodes in current splay tree
	ll sub, vsub = 0;  // vsub stores sum of virtual children
	ll val;            // value in node
	ll sum;
	ii extra = {-1, -1};
	int extraVal = 0;
	snode(int _val) : val(_val) {
		p = c[0] = c[1] = NULL;
		calc();
	}
	friend int getSz(sn x) { return x ? x->sz : 0; }
	friend ll getSub(sn x) { return x ? x->sub : 0; }
	friend ll getSum(sn x) { return x ? x->sum : 0; }
	void prop() {  // lazy prop
		if (!flip) return;
		swap(c[0], c[1]);
		flip = 0;
		for (int i = 0; i < 2; i++)
			if (c[i]) c[i]->flip ^= 1;
	}
	void calc() {  // recalc vals
		for (int i = 0; i < 2; i++)
			if (c[i]) c[i]->prop();
		sz = 1 + getSz(c[0]) + getSz(c[1]);
		sub = val + getSub(c[0]) + getSub(c[1]) + vsub;
		sum = val + getSum(c[0]) + getSum(c[1]);
	}
	//////// SPLAY TREE OPERATIONS
	int dir() {
		if (!p) return -2;
		for (int i = 0; i < 2; i++)
			if (p->c[i] == this) return i;
		return -1;  // p is path-parent pointer
	}  // -> not in current splay tree
	// test if root of current splay tree
	bool isRoot() { return dir() < 0; }
	friend void setLink(sn x, sn y, int d) {
		if (y) y->p = x;
		if (d >= 0) x->c[d] = y;
	}
	void rot() {  // assume p and p->p propagated
		assert(!isRoot());
		int x = dir();
		sn pa = p;
		setLink(pa->p, this, pa->dir());
		setLink(pa, c[x ^ 1], x);
		setLink(this, pa, x ^ 1);
		pa->calc();
	}
	void splay() {
		while (!isRoot() && !p->isRoot()) {
			p->p->prop(), p->prop(), prop();
			dir() == p->dir() ? p->rot() : rot();
			rot();
		}
		if (!isRoot()) p->prop(), prop(), rot();
		prop();
		calc();
	}
	sn fbo(int b) {  // find by order
		prop();
		int z = getSz(c[0]);  // of splay tree
		if (b == z) {
			splay();
			return this;
		}
		return b < z ? c[0]->fbo(b) : c[1]->fbo(b - z - 1);
	}
	//////// BASE OPERATIONS
	void access() {  // bring this to top of tree, propagate
		for (sn v = this, pre = NULL; v; v = v->p) {
			v->splay();  // now switch virtual children
			if (pre) v->vsub -= pre->sub;
			if (v->c[1]) v->vsub += v->c[1]->sub;
			v->c[1] = pre;
			v->calc();
			pre = v;
		}
		splay();
		assert(!c[1]);  // right subtree is empty
	}
	void makeRoot() {
		access();
		flip ^= 1;
		access();
		assert(!c[0] && !c[1]);
	}
	//////// QUERIES
	friend sn lca(sn x, sn y) {
		if (x == y) return x;
		x->access(), y->access();
		if (!x->p) return NULL;
		x->splay();
		return x->p ?: x;  // y was below x in latter case
	}  // access at y did not affect x -> not connected
	friend bool connected(sn x, sn y) { return lca(x, y); }
	// # nodes above
	int distRoot() {
		access();
		return getSz(c[0]);
	}
	sn getRoot() {  // get root of LCT component
		access();
		sn a = this;
		while (a->c[0]) a = a->c[0], a->prop();
		a->access();
		return a;
	}
	sn getPar(int b) {  // get b-th parent on path to root
		access();
		b = getSz(c[0]) - b;
		assert(b >= 0);
		return fbo(b);
	}  // can also get min, max on path to root, etc
	//////// MODIFICATIONS
	void set(int v) {
		access();
		val = v;
		calc();
	}
	friend void link(sn x, sn y, bool force = 0) {
		assert(!connected(x, y));
		if (force) y->makeRoot();  // make x par of y
		else {
			y->access();
			assert(!y->c[0]);
		}
		x->access();
		setLink(y, x, 0);
		y->calc();
	}
	friend void cut(sn y) {  // cut y from its parent
		y->access();
		assert(y->c[0]);
		y->c[0]->p = NULL;
		y->c[0] = NULL;
		y->calc();
	}
	friend void cut(sn x, sn y) {  // if x, y adj in tree
		x->makeRoot();
		y->access();
		assert(y->c[0] == x && !x->c[0] && !x->c[1]);
		cut(y);
	}
};

constexpr int Maxn = 200005;
sn LCT[Maxn];
int cur;
int n, q;
int g[Maxn];

void addEdge(int a, int b) {
	if (connected(LCT[a], LCT[b])) {
		LCT[a]->makeRoot();
		LCT[b]->access();
		LCT[a]->extra = {a, b};
		LCT[a]->extraVal = LCT[b]->sum % 2;
		cur += LCT[a]->extraVal;
	} else {
		link(LCT[b], LCT[a], true);
		cur--;
	}
}

void removeEdge(int a, int b) {
	auto const &root = LCT[a]->getRoot();
	ii got = root->extra;
	root->extra = {-1, -1};
	cur -= root->extraVal;
	root->extraVal = 0;
	if (ii{a, b} == got)
		return;
	cut(LCT[a], LCT[b]);
	cur++;
	if (got.first != -1)
		addEdge(got.first, got.second);
}

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++)
		LCT[i] = new snode(1);
	cur = n + n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &g[i]);
		g[i]--;
		addEdge(i, g[i]);
	}
	while (q--) {
		int x, y, k;
		scanf("%d %d %d", &x, &y, &k);
		x--; y--;
		removeEdge(x, g[x]);
		g[x] = y;
		addEdge(x, g[x]);
		if (k % 3 < 2) printf("%d\n", k % 3);
		else if (cur % 2) printf("2\n");
		else printf("1\n");
	}
    return 0;
}
