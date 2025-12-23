#include <bits/stdc++.h>
using namespace std;

vector<int> Merge(const vector<int>& A, const vector<int>& B) {
    vector<int> res(min(A.size(), B.size()));
    int pnt = 0;
    auto it1 = A.begin(), it2 = B.begin();
    while (it1 != A.end() && it2 != B.end())
        if (*it1 == *it2) {
            res[pnt++] = *it1++;
            ++it2;
        } else if (*it1 > *it2)
            it2 = lower_bound(it2, B.end(), *it1);
        else it1 = lower_bound(it1, A.end(), *it2);
    res.resize(pnt);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k, s, q;
        cin >> n >> k >> s >> q;

    }
    return 0;
}
