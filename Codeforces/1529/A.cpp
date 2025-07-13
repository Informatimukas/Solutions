#include <bits/stdc++.h>
using namespace std;

int T;
int n;
map<int, int> M;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        M.clear();
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            M[a]++;
        }
        printf("%d\n", n - M.begin()->second);
    }
    return 0;
}
