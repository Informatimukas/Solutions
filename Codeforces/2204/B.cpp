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
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector<int> seq;
        for (auto x : a | views::reverse) {
            while (!seq.empty() && seq.back() < x)
                seq.pop_back();
            seq.push_back(x);
        }
        cout << seq.size() << "\n";
    }
    return 0;
}
