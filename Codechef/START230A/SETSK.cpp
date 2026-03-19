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
        int lst = -1000000000;
        vector<int> seq;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a == 1) {
                seq.push_back(i);
                if (i - lst <= k)
                    ok = false;
                lst = i;
            }
        }
        if (ok) {
            if (seq.empty())
                ok = false;
            else if (seq[0] > k)
                ok = false;
            else if (seq.back() + 1 + k < n)
                ok = false;
            else for (int i = 0; i + 1 < seq.size(); i++)
                if (seq[i] + k + 1 + k + 1 <= seq[i + 1])
                    ok = false;
        }
        cout << (ok? "Yes" : "No") << "\n";
    }
    return 0;
}
