#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 300005;

int T;
char str[Maxn];

bool Solve(string &s) {
    int l = 0, r = s.length() - 1;
    while (l <= r) {
        if (s[l] != 'a') {
            s.insert(s.begin() + r + 1, 'a');
            return true;
        }
        if (s[r] != 'a') {
            s.insert(s.begin() + l, 'a');
            return true;
        }
        l++;
        r--;
    }
    return false;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        string s = str;
        if (Solve(s)) {
            printf("YES\n");
            printf("%s\n", s.c_str());
        } else printf("NO\n");
    }
    return 0;
}
