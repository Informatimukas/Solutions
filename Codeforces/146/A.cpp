#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool bad = false;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int dig = s[i] - '0';
        if (dig != 4 && dig != 7)
            bad = true;
        if (i < n / 2)
            sum += dig;
        else sum -= dig;
    }
    cout << (sum == 0 && !bad ? "YES" : "NO") << "\n";
    return 0;
}