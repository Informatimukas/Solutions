#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector<int> seq;
        for (int i = 0, j; i < n; i = j) {
            j = i;
            while (j < n && a[i] == a[j])
                j++;
            seq.push_back(j - i);
        }
        ranges::sort(seq, greater());
        while (n > k)
            for (int i = seq.size() - 1; i >= 0; i--) {
                n--;
                if (--seq[i] == 0)
                    seq.pop_back();
            }
        int res = 0;
        while (n > 0) {
            if (n <= k && (k - n) % seq.size() == 0)
                res++;
            int rem = seq.back();
            for (int i = seq.size() - 1; i >= 0; i--) {
                n -= rem;
                seq[i] -= rem;
                if (seq[i] == 0)
                    seq.pop_back();
            }
        }
        cout << res << "\n";
    }
    return 0;
}
