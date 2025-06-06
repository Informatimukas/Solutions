#include <bits/stdc++.h>
using namespace std;

int n;
map <string, int> M;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int res = M[s]++;
        if (res == 0)
            cout << "OK\n";
        else cout << s << res << "\n";
    }
    return 0;
}
