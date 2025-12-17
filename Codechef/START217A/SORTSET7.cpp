#include <bits/stdc++.h>
using namespace std;

int getCost(const vector<int>& p) {
    int res = 0;
    vector taken(p.size(), false);
    for (int i = 0; i < p.size(); i++)
        if (!taken[i]) {
            int cur = i;
            vector<int> seq;
            while (!taken[cur]) {
                taken[cur] = true;
                seq.push_back(cur);
                cur = p[cur];
            }
            int mn = *ranges::min_element(seq);
            for (auto& x : seq)
                if (x != mn)
                    res += x + 2 + mn;
        }
    return res;
}

int Solve(int n) {
    vector<int> seq(n);
    iota(seq.begin(), seq.end(), 0);
    int res = 0;
    do res += getCost(seq);
    while (ranges::next_permutation(seq).found);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i <= 10; i++)
        cout << i << " " << Solve(i) << endl;
    return 0;
}
