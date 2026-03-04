#include <bits/stdc++.h>
using namespace std;

bool isPower2(int n) {
    while (n % 2 == 0)
        n /= 2;
    return n == 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (isPower2(n)) {
            cout << "-1\n";
            continue;
        }
        vector<int> a(n + 1);
        if (n % 2 == 0) {
            a[n] = n - 2;
            a[n - 1] = 1;
            for (int i = n - 2; i > 0; i--)
                a[i] = i ^ 1;
            int b = 0;
            while (!(n & 1 << b))
                ++b;
            a[1 << b] = n;
            a[1] = (1 << b) ^ 1;
        } else {
            set<int> S;
            for (int i = 2; i <= n; i++)
                S.insert(i);
            a[n] = 1;
            for (int i = n - 1; i > 1; i--) {
                a[i] = 1 ^ i;
                S.erase(a[i]);
            }
            a[1] = *S.begin();
        }
        for (int i = 1; i <= n; i++)
            cout << a[i] << (i + 1 <= n ? ' ' : '\n');
    }
    return 0;
}
