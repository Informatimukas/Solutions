#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll Inf = 2000000000000000000ll;

struct matrix {
    vector<vector<ll>> m;
    matrix(int n): m(n, vector(n, Inf)) {}
    matrix operator*(const matrix& oth) const {
        matrix res(m.size());
        for (int i = 0; i < m.size(); i++)
            for (int j = 0; j < m.size(); j++)
                for (int k = 0; k < m.size(); k++)
                    res.m[i][j] = min(res.m[i][j], m[i][k] + oth.m[k][j]);
        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    matrix R(n), A(n);
    for (int i = 0; i < n; i++) {
        R.m[i][i] = 0;
        for (int j = 0; j < n; j++)
            cin >> A.m[i][j];
    }
    while (k) {
        if (k & 1)
            R = R * A;
        k >>= 1;
        A = A * A;
    }
    for (int i = 0; i < n; i++)
        cout << R.m[i][i] << "\n";
    return 0;
}
