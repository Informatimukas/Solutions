#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector cnt(n + m + 1, 0);
        vector divs(n + m + 1, 0);
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            cnt[a]++;
        }
        for (int i = 1; i <= n + m; i++)
            if (cnt[i] > 0)
                for (int j = i; j <= n + m; j += i)
                    divs[j] += cnt[i];
        int A = 0, B = 0, both = 0;
        for (int i = 0; i < m; i++) {
            int b;
            cin >> b;
            if (divs[b] == 0)
                B++;
            else if (divs[b] == n)
                A++;
            else both++;
        }
        if (A + (both + 1) / 2 > B + both / 2)
            cout << "Alice\n";
        else cout << "Bob\n";
    }
    return 0;
}
