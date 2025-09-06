#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < n && k; i++) {
        char nd = i == 0 && n > 1 ? '1' : '0';
        if (s[i] != nd) {
            s[i] = nd;
            k--;
        }
    }
    cout << s << "\n";
    return 0;
}
