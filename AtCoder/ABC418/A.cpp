#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    if (n >= 3 && s.substr(n - 3, 3) == "tea")
        cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
