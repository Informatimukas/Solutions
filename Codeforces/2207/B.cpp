#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m, l;
        cin >> n >> m >> l;
        multiset<int> S;
        for (int i = 0; i < m; i++)
            S.insert(0);
        deque<int> a(n);
        for (auto& x : a)
            cin >> x;
        while (S.size() > n + 1)
            S.erase(S.begin());
        for (int i = 1; i <= l; i++) {
            int got = *S.begin() + 1;
            S.erase(S.begin());
            S.insert(got);
            if (!a.empty() && a.front() == i) {
                S.erase(prev(S.end()));
                S.insert(0);
                a.pop_front();
            }
            while (S.size() > a.size() + 1)
                S.erase(S.begin());
        }
        cout << *S.rbegin() << "\n";
    }
    return 0;
}
