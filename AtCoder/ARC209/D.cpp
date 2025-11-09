#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> A(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> A[i];
        if (A[1] == 1 || A[1] == -1) {
            for (int i = 1; i <= n; i++)
                if (A[i] == -1)
                    A[i] = 1;
            for (int i = 1; i <= n; i++)
                cout << A[A[i]] << (i + 1 <= n ? ' ' : '\n');
            continue;
        }
        set<int> rem;
        int best = n + 1;
        for (int i = 1; i <= n; i++)
            if (A[i] == -1) rem.insert(i);
            else if (A[i] == 1)
                best = min(best, i);
        vector<int> seq;
        for (int i = 1; i <= n; i++)
            if (A[i] != -1) {
                if (A[A[i]] == -1) {
                    if (A[i] < i) {
                        int cand = best;
                        auto it = rem.upper_bound(seq.back());
                        if (it != rem.end())
                            cand = min(cand, *it);
                        A[cand] = 1;
                        rem.erase(cand);
                        best = min(best, cand);
                        for (auto& ind : seq)
                            A[ind] = cand;
                        seq.clear();
                    } else {
                        A[A[i]] = 1;
                        rem.erase(A[i]);
                        best = min(best, A[i]);
                    }
                }
            } else {
                rem.erase(i);
                if (rem.empty()) {
                    if (best > n) {
                        A[i] = 1;
                        best = i;
                    } else A[i] = best;
                    for (auto& ind : seq)
                        A[ind] = best;
                    seq.clear();
                } else seq.push_back(i);
            }
        for (auto& ind : seq)
            A[ind] = best;
        for (int i = 1; i <= n; i++)
            cout << A[A[i]] << (i + 1 <= n ? ' ' : '\n');
    }
    return 0;
}
