#include <bits/stdc++.h>
using namespace std;

int T;
string l, r;

int main() {
    cin >> T;
    while (T--) {
        cin >> l >> r;
        int res = 0;
        for (int i = 0; i < l.size(); i++)
            if (l[i] == r[i]) res += 2;
            else if (l[i] + 1 == r[i]) {
                res++;
                for (int j = i + 1; j < l.size(); j++)
                    if (l[j] == '9' && r[j] == '0') {
                        res++;
                    } else break;
                break;
            } else break;
        printf("%d\n", res);
    }
    return 0;
}