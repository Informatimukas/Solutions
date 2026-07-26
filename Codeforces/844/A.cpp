#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int k;
    cin >> k;
    if (s.length() < k) {
        cout << "impossible\n";
        return 0;
    }
    cout << max(0, k - static_cast<int>(set(s.begin(), s.end()).size())) << "\n";
    return 0;
}
