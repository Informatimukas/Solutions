#include <bits/stdc++.h>
using namespace std;

constexpr int Maxd = 3;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    array<array<int, Maxd>, Maxd> B{};
    for (auto& i : B)
        for (auto& j : i)
            cin >> j;
    const vector<pair<int, int>> dirs =
        {{0, 0}, {0, -1}, {0, 1}, {1, 0 }, {-1, 0}};
    for (int i = 0; i < Maxd; i++) {
        for (int j = 0; j < Maxd; j++) {
            int state = 1;
            for (auto& d : dirs) {
                int ni = i + d.first, nj = j + d.second;
                if (0 <= ni && ni < Maxd && 0 <= nj && nj < Maxd && B[ni][nj] % 2)
                    state = !state;
            }
            cout << state;
        }
        cout << "\n";
    }
    return 0;
}
