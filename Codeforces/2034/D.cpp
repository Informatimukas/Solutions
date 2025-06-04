#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
int b[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        sort(b, b + n);
        deque <int> D[3] = {};
        for (int i = 0; i < n; i++)
            if (a[i] != b[i])
                D[a[i]].push_back(i);
        vector <ii> res;
        while (!D[0].empty() || !D[1].empty() || !D[2].empty()) {
            if (D[1].empty()) {
                int x = 0;
                while (a[x] != 1)
                    x++;
                res.push_back({x, D[0].front()});
                swap(a[x], a[D[0].front()]);
                D[0].push_back(x);
                D[1].push_back(D[0].front());
                D[0].pop_front();
            }
            while (!D[1].empty()) {
                int c = D[1].front();
                int d = D[b[c]].front();
                res.push_back({c, d});
                swap(a[c], a[d]);
                D[1].pop_front();
                D[b[c]].pop_front();
                if (b[d] != 1)
                    D[1].push_back(d);
            }
        }
        printf("%d\n", int(res.size()));
        for (int i = 0; i < res.size(); i++)
            printf("%d %d\n", res[i].first + 1, res[i].second + 1);
    }
	return 0;
}
