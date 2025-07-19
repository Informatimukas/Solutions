#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

constexpr int Maxn = 200005;

int T;
int n;
int X[Maxn], Y[Maxn];
ii byX[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &X[i], &Y[i]);
            byX[i] = {X[i], i};
        }
        sort(byX, byX + n);
        vector<ii> A, B;
        for (int i = 0; i < n / 2; i++) {
            int ind = byX[i].second;
            A.emplace_back(Y[ind], ind);
        }
        for (int i = n / 2; i < n; i++) {
            int ind = byX[i].second;
            B.emplace_back(Y[ind], ind);
        }
        ranges::sort(A);
        ranges::sort(B);
        for (int i = 0; i < A.size(); i++)
            printf("%d %d\n", A[i].second + 1, B[A.size() - 1 - i].second + 1);
    }
    return 0;
}