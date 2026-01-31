#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int Maxc = 9;
constexpr int Maxs = 4;
const string cards = "6789TJQKA";
const string suits = "CDSH";

ii parseCard(const string& s) {
    return {cards.find(s[0]), suits.find(s[1])};
}

int Win(int p, const vector<int>& cur, const vector<vector<vector<bool>>>& has, const vector<vector<vector<bool>>>& good,
    const vector<ii>& states, const vector<vector<int>>& inStates, vector<vector<vector<vector<vector<int>>>>>& win) {
    auto& myWin = win[p][cur[0]][cur[1]][cur[2]][cur[3]];
    if (myWin)
        return myWin;
    bool allGood = true;
    for (int i = 0; i < cur.size() && allGood; i++)
        allGood = good[p][i][cur[i]];
    if (allGood)
        return myWin = 1;
    bool was = false;
    for (int i = 0; i < cur.size(); i++) {
        ii s = states[cur[i]];
        if (s.first == -1 && has[p][i][3]) {
            vector u = cur;
            u[i] = inStates[3][3];
            was = true;
            if (Win(1 - p, u, has, good, states, inStates, win) == -1)
                return myWin = 1;
        }
        if (s.first - 1 >= 0 && has[p][i][s.first - 1]) {
            vector u = cur;
            u[i] = inStates[s.first - 1][s.second];
            was = true;
            if (Win(1 - p, u, has, good, states, inStates, win) == -1)
                return myWin = 1;
        }
        if (s.second != -1 && s.second + 1 < Maxc && has[p][i][s.second + 1]) {
            vector u = cur;
            u[i] = inStates[s.first][s.second + 1];
            was = true;
            if (Win(1 - p, u, has, good, states, inStates, win) == -1)
                return myWin = 1;
        }
    }
    if (was)
        return myWin = -1;
    return myWin = -Win(1 - p, cur, has, good, states, inStates, win);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ii> states = {{-1, -1}};
    vector inStates(Maxc, vector<int>(Maxc));
    for (int i = 0; i < Maxc; ++i)
        for (int j = i; j < Maxc; ++j) {
            inStates[i][j] = states.size();
            states.emplace_back(i, j);
        }
    vector has(2, vector(Maxs, vector(Maxc, false)));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 18; j++) {
            string s;
            cin >> s;
            ii card = parseCard(s);
            has[i][card.first][card.second] = true;
        }
    vector good(2, vector(Maxs, vector(states.size(), false)));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < Maxs; j++) {
            int lef = 0;
            while (lef < Maxc && !has[i][j][lef])
                ++lef;
            if (lef >= Maxc) {
                ranges::fill(good[i][j], true);
                continue;
            }
            int rig = Maxc - 1;
            while (!has[i][j][rig])
                --rig;
            for (int k = 0; k < states.size(); ++k)
                good[i][j][k] = states[k].first <= lef && rig <= states[k].second;
        }
    vector win(2, vector(states.size(), vector(states.size(), vector(states.size(), vector(states.size(), 0)))));
    if (Win(0, {0, 0, 0, 0}, has, good, states, inStates, win) == 1)
        cout << "Alice\n";
    else cout << "Bob\n";
    return 0;
}
