#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int h = (s[0] - '0') * 10 + (s[1] - '0');
    int m = (s[3] - '0') * 10 + (s[4] - '0');
    do {
        if (++m >= 60) {
            m = 0;
            if (++h >= 24)
                h = 0;
        }
    } while (h / 10 != m % 10 || h % 10 != m / 10);
    cout << h / 10 << h % 10 << ":" << m / 10 << m % 10 << "\n";
    return 0;
}