#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int w = 2 * n + 1;
    for (int i = 0; i < w; i++) {
        string B(w, ' ');
        int len = i <= n ? i : 2 * n - i;
        int lst = 0;
        for (int j = 0; j < 2 * len + 1; j++) {
            int val = j <= len ? j : 2 * len - j;
            int off = j <= len ? n - (len - j) : n + (j - len);
            lst = off;
            B[off] = val + '0';
        }
        for (int j = 0; j <= lst; j++)
            cout << B[j] << (j + 1 <= lst ? ' ' : '\n');
    }
    return 0;
}
