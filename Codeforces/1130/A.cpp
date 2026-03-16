#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int pos = 0, neg = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a < 0)
            neg++;
        else if (a > 0)
            pos++;
    }
    if (2 * pos >= n)
        cout << "1\n";
    else if (2 * neg >= n)
        cout << "-1\n";
    else cout << "0\n";
    return 0;
}
