#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr int Maxn = 8;
    vector<string> B(Maxn);
    for (auto& el : B)
        cin >> el;
    vector<bool> rows(Maxn), cols(Maxn);
    for (int i = 0; i < Maxn; i++)
        rows[i] = ranges::all_of(B[i], [](char ch) {
            return ch == 'B';
        });
    if (ranges::all_of(rows, [](bool b) { return b; })) {
        cout << Maxn << "\n";
        return 0;
    }
    for (int i = 0; i < Maxn; i++)
        for (int j = i + 1; j < Maxn; j++)
            swap(B[i][j], B[j][i]);
    for (int i = 0; i < Maxn; i++)
        cols[i] = ranges::all_of(B[i], [](char ch) {
            return ch == 'B';
        });
    cout << ranges::count(cols, true) + ranges::count(rows, true) << "\n";
    return 0;
}
