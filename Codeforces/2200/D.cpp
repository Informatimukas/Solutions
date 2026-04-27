#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> seq, mid;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (x <= i && i < y)
                mid.push_back(a);
            else seq.push_back(a);
        }
        ranges::rotate(mid.begin(), ranges::min_element(mid), mid.end());
        auto it = seq.begin();
        while (it != seq.end() && *it < mid[0])
            ++it;
        seq.insert(it, mid.begin(), mid.end());
        for (int i = 0; i < seq.size(); i++)
            cout << seq[i] << (i + 1 < seq.size() ? ' ' : '\n');
    }
    return 0;
}
