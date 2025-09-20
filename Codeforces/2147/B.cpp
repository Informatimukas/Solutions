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
        cin >> n;
        for (int i = n; i > 0; i--)
            cout << i << " ";
        cout << n;
        for (int i = 1; i < n; i++)
            cout << " " << i;
        cout << "\n";
    }
    return 0;
}