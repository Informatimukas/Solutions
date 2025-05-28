#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int n, m, k;
map <int, int> M[Maxn];

int Solve(int r, int c)
{
    auto it = M[c].lower_bound(r);
    if (it == M[c].end()) return c;
    int nr = it->first;
    int nc = it->second == 1? c + 1: c - 1;
    M[c].erase(it);
    return Solve(nr, nc);
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            int a; scanf("%d", &a);
            if (a != 2)
                M[j][i] = a;
        }
    for (int i = 0; i < k; i++) {
        int c; scanf("%d", &c);
        printf("%d%c", Solve(0, c), i + 1 < k? ' ': '\n');
    }
	return 0;
}
