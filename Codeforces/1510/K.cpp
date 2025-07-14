#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> cur, seq;
map<vector<int>, int> M;
queue<vector<int>> Q;

int main()
{
    scanf("%d",&n);
    seq.resize(2 * n);
    cur.resize(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        scanf("%d", &seq[i]);
        cur[i] = i + 1;
    }
    Q.push(cur);
    while (!Q.empty()) {
        cur = Q.front(); Q.pop();
        int d = M[cur];
        if (cur == seq) {
            printf("%d\n", d);
            return 0;
        }
        vector<int> nxt = cur;
        for (int i = 0; i < 2 * n; i += 2)
            swap(nxt[i], nxt[i + 1]);
        if (M.insert({nxt, d + 1}).second) {
            Q.push(nxt);
        }
        nxt = cur;
        for (int i = 0; i < n; i++)
            swap(nxt[i], nxt[n + i]);
        if (M.insert({nxt, d + 1}).second) {
            Q.push(nxt);
        }
    }
    printf("-1\n");
    return 0;
}