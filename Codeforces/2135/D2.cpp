#include <bits/stdc++.h>
using namespace std;

constexpr int Maxw = 123;
constexpr int Maxp1 = 10000;
constexpr int Maxp2 = 15000;
constexpr int lim = 100001;

int Ask(const vector<int>& words) {
    cout << "? " << words.size();
    for (auto& x : words)
        cout << " " << x;
    cout << endl;
    int res;
    cin >> res;
    return res;
}

void Print(int x) {
    cout << "! " << x << endl;
}

int getOther(int n, int a) {
    return (n + a - 1) / a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int res1 = Ask(vector(Maxp1, Maxw));
        if (res1 == 0) {
            int lines = Ask(vector(Maxp2, 1));
            Print(getOther(Maxp2, lines));
            continue;
        }
        int lef = getOther(Maxp1, res1), rig = getOther(Maxp1, res1 - 1);
        lef *= Maxw;
        rig = min(lim, rig * Maxw);
        vector<int> seq;
        for (int i = rig - 1; i >= lef; i--) {
            seq.push_back(lef);
            if (i > lef)
                seq.push_back(i - lef);
        }
        Print(2 * rig - 1 - lef - Ask(seq));
    }
    return 0;
}
