#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, c;
    cin >> n >> c;
    vector<int> p(n);
    for (auto& x : p)
        cin >> x;
    vector<int> t(n);
    for (auto& x : t)
        cin >> x;
    int A = 0, tim = 0;
    for (int i = 0; i < n; i++) {
        tim += t[i];
        A += max(0, p[i] - c * tim);
    }
    int B = 0;
    tim = 0;
    for (int i = n - 1; i >= 0; i--) {
        tim += t[i];
        B += max(0, p[i] - c * tim);
    }
    if (A > B)
        cout << "Limak\n";
    else if (A < B)
        cout << "Radewoosh\n";
    else cout << "Tie\n";
    return 0;
}
