#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

constexpr int Maxn = 50;

int T;
int n;
int a[Maxn];
int b[Maxn];
vector<ii> res;

void Swap(int ind) {
    swap(a[ind], b[ind]);
    res.emplace_back(3, ind);
}

void MoveA(int ind) {
    swap(a[ind], a[ind + 1]);
    res.emplace_back(1, ind);
}

void MoveB(int ind) {
    swap(b[ind], b[ind + 1]);
    res.emplace_back(2, ind);
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &b[i]);
        res.clear();
        for (int i = 0; i < n; i++) {
            // a
            int nd = 2 * i + 1, p;
            for (int j = 0; j < n; j++) {
                if (a[j] == nd) {
                    p = j;
                    break;
                }
                if (b[j] == nd) {
                    p = j;
                    Swap(j);
                    break;
                }
            }
            while (p > i)
                MoveA(--p);
            nd = 2 * i + 2;
            for (int j = 0; j < n; j++) {
                if (b[j] == nd) {
                    p = j;
                    break;
                }
                if (a[j] == nd) {
                    p = j;
                    Swap(j);
                    break;
                }
            }
            while (p > i)
                MoveB(--p);
        }
        printf("%d\n", res.size());
        for (auto el: res)
            printf("%d %d\n", el.first, el.second + 1);
    }
    return 0;
}
