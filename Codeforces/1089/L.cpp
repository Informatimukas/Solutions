#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> my(k + 1);
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        my[a[i]].push_back(b);
    }
    int need = 0;
    vector<int> seq;
    for (int i = 1; i <= k; i++)
        if (my[i].empty())
            need++;
        else {
            ranges::nth_element(my[i], my[i].end() - 1);
            seq.insert(seq.end(), my[i].begin(), my[i].end() - 1);
        }
    ranges::partial_sort(seq, seq.begin() + need);
    cout << accumulate(seq.begin(), seq.begin() + need, 0ll) << "\n";
    return 0;
}
