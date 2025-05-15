#include <bits/stdc++.h>
using namespace std;

int T;
int n;
string s;

int main()
{
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s;
        int res = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == '1')
                res += n - 1;
            else res++;
        cout << res << "\n";
    }
    return 0;
}
