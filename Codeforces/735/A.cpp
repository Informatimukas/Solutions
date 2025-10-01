#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int g = s.find('G');
    int t = s.find('T');
    if ((g - t) % k) {
        cout << "NO\n";
        return 0;
    }
    while (g < t) {
        g += k;
        if (s[g] == '#')
            break;
    }
    while (g > t) {
        g -= k;
        if (s[g] == '#')
            break;
    }
    cout << (g == t ? "YES" : "NO") << "\n";
    return 0;
}