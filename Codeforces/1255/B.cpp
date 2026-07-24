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
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            sum += 2 * tmp;
        }
        if (m < n || n == 2) {
            cout << "-1\n";
            continue;
        }
        cout << sum << "\n";
        for (int i = 1; i < n; i++)
            cout << i << " " << i + 1 << "\n";
        cout << "1 " << n << "\n";
    }
    return 0;
}
