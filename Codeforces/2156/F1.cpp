#include <bits/stdc++.h>
using namespace std;

void Solve(int i, vector<int>& seq) {
    if (i >= seq.size())
        return;
    if (find(seq.begin() + i + 1, seq.end(), seq[i] - 1) != seq.end() &&
        find(seq.begin() + i + 1, seq.end(), seq[i] - 2) != seq.end()) {
        for (int j = i + 1; j < seq.size(); j++)
            if (seq[j] > seq[i])
                seq[j]--;
        Solve(i + 1, seq);
        for (int j = i + 1; j < seq.size(); j++)
            if (seq[j] >= seq[i])
                seq[j]++;
        while (true) {
            auto it1 = find(seq.begin() + i + 1, seq.end(), seq[i] - 1);
            auto it2 = find(seq.begin() + i + 1, seq.end(), seq[i] - 2);
            if (it1 == seq.end() || it2 == seq.end())
                break;
            (*it1)++;
            (*it2)++;
            seq[i] -= 2;
        }
    } else Solve(i + 1, seq);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> seq(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> seq[i];
        Solve(1, seq);
        for (int i = 1; i <= n; i++)
            cout << seq[i] << (i + 1 <= n? ' ' : '\n');
    }
    return 0;
}
