#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    map<string, string> M;
    for (int i = 0; i < n; i++) {
        string nam, ip;
        cin >> nam >> ip;
        M.emplace(ip, nam);
    }
    while (m--) {
        string nam, ip;
        cin >> nam >> ip;
        cout << nam << " " << ip << " #" << M[ip.substr(0, ip.length() - 1)] << "\n";
    }
    return 0;
}
