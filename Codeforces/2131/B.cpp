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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            a[i] = i % 2 ? 3: -1;
        if (a[n - 1] == 3)
            a[n - 1] = 2;
        for (int i = 0; i < n; i++)
            cout << a[i] << (i + 1 < n? ' ': '\n');
    }
    return 0;
}
