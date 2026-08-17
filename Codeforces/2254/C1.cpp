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
        string a;
        cin >> a;
        string b;
        cin >> b;
        array<int, 2> cnt0{};
        array<int, 2> cnt1{};
        for (int i = 0; i < n; i++) {
            if (a[i] == '1')
                cnt0[i % 2]++;
            if (b[i] == '1')
                cnt1[i % 2]++;
        }
        if (cnt0[0] == cnt1[0] && cnt0[1] == cnt1[1])
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
