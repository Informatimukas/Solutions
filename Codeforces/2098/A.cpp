#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10;

int T;
string s;

int main()
{
    cin >> T;
    while (T--) {
        cin >> s;
        multiset<int> S;
        for (int i = 0; i < s.length(); i++)
            S.insert(s[i] - '0');
        for (int i = 9; i >= 0; i--) {
            auto it = S.lower_bound(i);
            printf("%d", *it);
            S.erase(it);
        }
        printf("\n");
    }
    return 0;
}
