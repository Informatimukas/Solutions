#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int Maxc = 9;
constexpr int Maxs = 4;

ii parseCard(const string& s) {
    const static string cards = "6789TJQKA";
    const static string suits = "CDSH";
    return {cards.find(s[0]), suits.find(s[1])};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ii> states = {{-1, -1}};
    for (int i = 0; i < Maxc; ++i)
        for (int j = i; j < Maxc; ++j)
            states.emplace_back(i, j);
    vector has(2, vector(Maxs, vector(Maxc, false)));

    return 0;
}
