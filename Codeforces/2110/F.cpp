#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1000006;

int T;
int n;
int a[Maxn];
map <int, int> M;
int nxt[Maxn];
int res[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        M.clear();
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (!M.count(a[i]))
                M.insert(make_pair(a[i], i));
            res[i] = 0;
        }
        priority_queue<ii, vector<ii>, greater<ii>> Q;
        for (auto &el: M) {
            while (!Q.empty() && nxt[Q.top().second] + a[Q.top().second] <= el.first) {
                int ind = Q.top().second;
                Q.pop();
                nxt[ind] = el.first / a[ind] * a[ind];
                Q.push({nxt[ind] - a[ind], ind});
            }
            if (!Q.empty()) {
                int lst = max(el.second, Q.top().second);
                res[lst] = max(res[lst], el.first - Q.top().first);
            }
            nxt[el.second] = a[el.second];
            Q.push({nxt[el.second] - a[el.second], el.second});
        }
        for (int i = 1; i <= n; i++) {
            res[i] = max(res[i], res[i - 1]);
            printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
        }
    }
	return 0;
}
