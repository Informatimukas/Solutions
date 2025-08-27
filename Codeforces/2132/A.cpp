#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string a;
        int m;
        string b;
        string players;
        cin >> n >> a >> m >> b >> players;
        for (int i = 0; i < m; i++)
            if (players[i] == 'D')
                a += b[i];
            else a = b[i] + a;
        cout << a << "\n";
    }
    return 0;
}
