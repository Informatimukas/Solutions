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
        deque<int> D;
        vector<array<int, 2>> E;
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            if (D.empty() || D.back() > a)
                D.push_back(a);
            else {
                E.push_back({D.back(), a});
                while (D.size() > 1 && D.front() < a) {
                    E.push_back({D.front(), a});
                    D.pop_front();
                }
            }
        }
        if (D.size() == 1) {
            cout << "Yes\n";
            for (auto& e : E)
                cout << e[0] << " " << e[1] << "\n";
        } else cout << "No\n";
    }
    return 0;
}
