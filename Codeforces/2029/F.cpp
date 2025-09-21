#include <bits/stdc++.h>
using namespace std;

vector<int> getDist(const vector<int> &V, int n)
{
    vector <int> res;
    for (int i = 0; i < V.size(); i++) {
        int ni = (i + 1) % V.size();
        int dif = (V[ni] - 1 - V[i] + n) % n;
        res.push_back(dif);
    }
    return res;
}

string Solve(const vector<int> &V)
{
    if (V.size() <= 1) return "YES";
    return ranges::count_if(V, [](int x) {
        return x % 2 == 0;
    }) == 1 ? "YES" : "NO";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> R, B;
        for (int i = 0; i < s.length(); i++)
            if (s[i] == 'R')
                R.push_back(i);
            else B.push_back(i);
        vector<int> VR = getDist(R, n), VB = getDist(B, n);
        if (ranges::find(VR, 0) == VR.end())
            cout << Solve(VR) << "\n";
        else if (ranges::find(VB, 0) == VB.end())
            cout << Solve(VB) << "\n";
        else cout << "NO\n";
    }
    return 0;
}