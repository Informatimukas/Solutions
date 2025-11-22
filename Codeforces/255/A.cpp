#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    array<int, 3> cnt{};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[i % 3] += a;
    }
    if (cnt[0] > cnt[1] && cnt[0] > cnt[2])
        cout << "chest\n";
    else if (cnt[1] > cnt[2])
        cout << "biceps\n";
    else cout << "back\n";
    return 0;
}
