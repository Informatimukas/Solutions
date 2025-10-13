#include <bits/stdc++.h>
using namespace std;

int Solve(const vector<int>& a, int ad) {
    vector<int> R(a.size());
    for (int i = 1; i < a.size(); i++) {
        R[i] = R[i - 1];
        if ((i + ad - a[i]) % 2)
            R[i]++;
    }
    int n = a.size() - 1;
    for (int i = 1; i < a.size(); i++)
        if (i - R[i] + R[n] - R[i - 1] != a[i])
            return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        cout << Solve(a, 0) + Solve(a, 1) << "\n";
    }
    return 0;
}
