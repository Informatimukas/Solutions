#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    string s;
    for (int i = 1; s.length() < k; i++)
        s += to_string(i);
    cout << s[k - 1] << "\n";
    return 0;
}
