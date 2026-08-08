#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        cnt[c]++;
    }
    cout << n - *ranges::max_element(cnt) << "\n";
    return 0;
}
