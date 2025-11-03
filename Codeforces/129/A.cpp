#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    array<int, 2> cnt{};
    cin >> n;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a %= 2;
        cur = (cur + a) % 2;
        cnt[a]++;
    }
    cout << cnt[cur] << "\n";
    return 0;
}
