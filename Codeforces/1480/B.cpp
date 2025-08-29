#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool Solve(int A, int B, const vector<int>& a, const vector<int>& b) {
    B += *ranges::max_element(a);
    for (int i = 0; i < a.size(); i++) {
        int tims = (b[i] + A - 1) / A;
        if (tims <= B / a[i]) {
            B -= tims * a[i];
        } else return false;
    }
    return B > 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int A, B, n;
        cin >> A >> B >> n;
        vector<int> a(n), b(n);
        for (auto& x : a)
            cin >> x;
        for (auto& x : b)
            cin >> x;
        cout << (Solve(A, B, a, b) ? "YES" : "NO") << "\n";
    }
    return 0;
}
