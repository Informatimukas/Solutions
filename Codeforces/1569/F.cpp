#include <bits/stdc++.h>
using namespace std;

int res = 0;

void Gen(int lvl, vector<int> &seq) {
    if (lvl >= 12) {
        res += ranges::count_if(seq, [](int x) {
            return x % 2 == 0;
        }) == seq.size();
        return;
    }
    for (int i = 0; i < seq.size(); i++) {
        seq[i]++;
        Gen(lvl + 1, seq);
        seq[i]--;
    }
    seq.push_back(1);
    Gen(lvl + 1, seq);
    seq.pop_back();
}

int main() {
    vector<int> seq;
    Gen(0, seq);
    cout << res << endl;
    return 0;
}