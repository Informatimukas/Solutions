#include <bits/stdc++.h>
using namespace std;

bool Palindrome(int r, int g, int b, int w) {
    return r % 2 + g % 2 + b % 2 + w % 2 <= 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int r, g, b, w;
        cin >> r >> g >> b >> w;
        int mn = min({r, g, b});
        bool res = Palindrome(r - mn, g - mn, b - mn, w + mn);
        if (mn > 0)
            res |= Palindrome(r - mn + 1, g - mn + 1, b - mn + 1, w + mn - 1);
        cout << (res ? "Yes" : "No") << "\n";
    }
    return 0;
}
