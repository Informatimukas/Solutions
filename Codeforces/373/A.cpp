#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    array<int, 10> cnt{};
    int x;
    cin >> x;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            char ch;
            cin >> ch;
            if (ch != '.')
                ++cnt[ch - '0'];
        }
    cout << (*ranges::max_element(cnt) <= 2 * x ? "YES" : "NO") << "\n";
    return 0;
}
