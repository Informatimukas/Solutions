#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<string, string> M;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;
        string c = a.length() <= b.length() ? a : b;
        M.emplace(a, c);
        M.emplace(b, c);
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cout << M[s] << (i + 1 < n ? ' ' : '\n');
    }
    return 0;
}
