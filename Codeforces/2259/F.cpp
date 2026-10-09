#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main() {
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
        int allzers = 0, allones = 0;
        ll invs = 0;
        deque<ii> Q;
        for (int i = 0, j; i < n; i = j) {
            j = i;
            while (j < n && a[i] == a[j])
                j++;
            if (a[i] == 0) {
                allzers += j - i;
                invs += static_cast<ll>(allones) * (j - i);
            } else allones += j - i;
            Q.emplace_back(j - i, a[i]);
        }
        if (!Q.empty() && Q.front().second == 0) {
            allzers -= Q.front().first;
            Q.pop_front();
        }
        if (!Q.empty() && Q.back().second == 1) {
            allones -= Q.back().first;
            Q.pop_back();
        }
        cout << invs;
        string s;
        cin >> s;
        for (auto ch : s) {
            if (ch == '1') {
                if (!Q.empty()) {
                    invs -= allzers;
                    Q.front().first--;
                    allones--;
                    if (Q.front().first == 0) {
                        Q.pop_front();
                        if (!Q.empty()) {
                            allzers -= Q.front().first;
                            Q.pop_front();
                        }
                    }
                }
            } else {
                if (!Q.empty()) {
                    invs -= allones;
                    Q.back().first--;
                    allzers--;
                    if (Q.back().first == 0) {
                        Q.pop_back();
                        if (!Q.empty()) {
                            allones -= Q.back().first;
                            Q.pop_back();
                        }
                    }
                }
            }
            cout << " " << invs;
        }
        cout << "\n";
    }
    return 0;
}
