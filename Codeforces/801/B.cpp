#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string x, y;
    cin >> x >> y;
    for (int i = 0; i < x.length(); i++)
        if (x[i] < y[i]) {
            cout << "-1\n";
            return 0;
        }
    cout << y << "\n";
    return 0;
}
