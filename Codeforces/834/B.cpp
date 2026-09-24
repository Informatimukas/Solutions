#include <bits/stdc++.h>
using namespace std;

constexpr int Maxl = 26;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    array<vector<int>, Maxl> A{};
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
        A[s[i] - 'A'].push_back(i);
    vector<int> delt(n + 1);
    for (auto& V : A)
        if (!V.empty()) {
            delt[V[0]]++;
            delt[V.back() + 1]--;
        }
    int mx = 0, cur = 0;
    for (int i = 0; i <= n; i++) {
        cur += delt[i];
        mx = max(mx, cur);
    }
    cout << (mx > k ? "YES" : "NO") << "\n";
    return 0;
}
