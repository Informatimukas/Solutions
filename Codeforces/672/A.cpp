#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    for (int i = 1; i <= n; i++)
        s += to_string(i);
    cout << s[n - 1] << "\n";
    return 0;
}
