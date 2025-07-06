#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 100005;

int T;
int n;
char str[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", str);
        set<char> S;
        S.insert(str[0]);
        S.insert(str[n - 1]);
        bool found = false;
        for (int i = 1; i < n - 1; i++)
            if (!S.insert(str[i]).second) {
                found = true;
                break;
            }
        printf("%s\n", found? "Yes": "No");
    }
    return 0;
}