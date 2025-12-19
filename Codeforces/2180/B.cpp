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
        vector<string> a(n);
        string cur;
        for (auto& x : a) {
            cin >> x;
            string w1 = x + cur;
            string w2 = cur + x;
            cur = min(w1, w2);
        }
        cout << cur << "\n";
    }
    return 0;
}
