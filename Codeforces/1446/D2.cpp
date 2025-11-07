#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int nextElement(const vector<int>& A, int i, const vector<int>& B, int j, int n) {
    int res = n + 1;
    if (i < A.size())
        res = min(res, A[i]);
    if (j < B.size())
        res = min(res, B[j]);
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector seq(n + 1, vector<int>());
    set<ii> S;
    for (int i = 0; i <= n; i++)
        S.insert({seq[i].size(), i});
    int best = 0, from = 0;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        S.erase({seq[a].size(), a});
        seq[a].push_back(i);
        S.insert({seq[a].size(), a});
        auto it = prev(S.end());
        auto it2 = prev(it);
        if (it->first == it2->first) {
            best = 0;
            res = max(res, i);
        } else if (best != it->second) {
            best = it->second;
            from = i;
        }
    }
    for (int z = 1; z <= n; z++)
        if (!seq[z].empty() && z != best) {
            auto& A = seq[best];
            auto& B = seq[z];
            int i = 0, j = 0;
            deque D = {0};
            int it = 0;
            while (i < A.size() || j < B.size())
                if (i < A.size() && (j >= B.size() || A[i] < B[j]))
                    if (it + 1 == D.size()) {
                        int rem = B.size() - j;
                        if (rem == 0) break;
                        int ni = distance(A.begin(), ranges::lower_bound(A, B[j]));
                        int got = ni - i;
                        if (got > rem)
                            i += got - rem - 1;
                        while (i < ni)
                            D.push_back(A[i++]);
                        it = D.size() - 1;
                    } else {
                        ++it;
                        i++;
                        int lst = nextElement(A, i, B, j, n) - 1;
                        if (lst >= from)
                            res = max(res, lst - D[it]);
                    }
                else if (it == 0)
                    D.push_front(B[j++]);
                else {
                    --it;
                    j++;
                    int lst = nextElement(A, i, B, j, n) - 1;
                    if (lst >= from)
                        res = max(res, lst - D[it]);
                }
        }
    cout << res << "\n";
    return 0;
}