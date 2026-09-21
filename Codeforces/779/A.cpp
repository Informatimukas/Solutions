#include <bits/stdc++.h>
using namespace std;

constexpr int Maxd = 6;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    array<int, Maxd> cnt{};
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a]--;
    }
    int A = 0;
    for (auto x : cnt) {
        if (x % 2) {
            cout << "-1\n";
            return 0;
        }
        if (x >= 0)
            A += x;
    }
    cout << A / 2 << "\n";
    return 0;
}
