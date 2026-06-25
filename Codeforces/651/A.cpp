#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int Solve(map<ii, int>& M, int a, int b) {
    if (a > b)
        swap(a, b);
    if (a <= 0)
        return 0;
    auto it = M.find({a, b});
    if (it != M.end())
        return it->second;
    int cand1 = a >= 2 ? 1 + Solve(M, a - 2, b + 1) : 0;
    int cand2 = b >= 2 ? 1 + Solve(M, a + 1, b - 2) : 0;
    int res = max(cand1, cand2);
    M.insert({{a, b}, res});
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    map<ii, int> M;
    cout << Solve(M, a, b) << "\n";
    return 0;
}
