#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int res = 0;
    for (auto ch : s)
        if (ch == 'i' || ch == 'j')
            res++;
    cout << res << "\n";
    return 0;
}
