#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

constexpr int Maxn = 100005;

int T;
int n;
int k;
int A[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        vector<ii> seq;
        for (int i = 0; i < n; i++) {
            scanf("%d", &k);
            for (int j = 0; j < k; j++)
                scanf("%d", &A[j]);
            int lst = 0;
            for (int j = k - 1; j >= 0; j--)
                lst = max(lst - 1, A[j] + 1);
            seq.push_back({lst, k});
        }
        ranges::sort(seq);
        int cur = 0, res = 0;
        for (int i = 0; i < n; i++) {
            if (cur < seq[i].first) {
                res += seq[i].first - cur;
                cur = seq[i].first;
            }
            cur += seq[i].second;
        }
        printf("%d\n", res);
    }
    return 0;
}