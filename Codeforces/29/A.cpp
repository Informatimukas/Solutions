#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ii> a(n);
    for (auto& p : a)
        cin >> p.first >> p.second;
    for (int i = 0; i < a.size(); i++)
        for (int j = i + 1; j < a.size(); j++)
            if (a[i].first + a[i].second == a[j].first &&
                a[j].first + a[j].second == a[i].first) {
                cout << "YES\n";
                return 0;
            }
    cout << "NO\n";
    return 0;
}