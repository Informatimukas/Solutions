#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

constexpr int Maxb = 64;
constexpr int Maxm = 19540;

ull reverseBits(ull x) noexcept
{
    x = ((x >> 1) & 0x5555'5555'5555'5555ULL) |
        ((x & 0x5555'5555'5555'5555ULL) << 1);
    x = ((x >> 2) & 0x3333'3333'3333'3333ULL) |
        ((x & 0x3333'3333'3333'3333ULL) << 2);
    x = ((x >> 4) & 0x0F0F'0F0F'0F0F'0F0FULL) |
        ((x & 0x0F0F'0F0F'0F0F'0F0FULL) << 4);
    x = ((x >> 8) & 0x00FF'00FF'00FF'00FFULL) |
        ((x & 0x00FF'00FF'00FF'00FFULL) << 8);
    x = ((x >> 16) & 0x0000'FFFF'0000'FFFFULL) |
        ((x & 0x0000'FFFF'0000'FFFFULL) << 16);
    x = (x >> 32) | (x << 32);
    return x;
}

bool Update(vector<ull>& masks, ull val, int lef) {
    int ind = lef < 0 ? -1 : lef / Maxb;
    if (ind >= static_cast<int>(masks.size()))
        return false;
    int mv = lef % Maxb;
    if (mv < 0)
        mv += Maxb;
    if (mv == 0) {
        masks[ind] |= val;
        return true;
    }
    int rem = Maxb - mv;
    if (ind >= 0)
        masks[ind] |= (val & ((1ull << rem) - 1)) << mv;
    if (ind + 1 < masks.size())
        masks[ind + 1] |= (val >> rem);
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int tot = 0;
    vector<int> a(2 * n);
    for (auto& x : a) {
        cin >> x;
        tot += x;
    }
    ranges::sort(a, greater());
    vector sam(2 * n + 1, vector(n + 1, vector(Maxm, 0ull)));
    vector dif(2 * n + 1, vector(n + 1, vector(Maxm, 0ull)));
    int curSum = 0;
    int best = 1000000006, wthi, wthj, wthj2;
    sam[0][0][0] = 1;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j <= i && j <= n; j++) {
            if (j < n)
                for (int k = 0; k < Maxm; k++) {
                    int lef = k * Maxb + a[i];
                    if (!Update(sam[i + 1][j + 1], sam[i][j][k], lef))
                        break;
                    if (!Update(sam[i + 1][j + 1], dif[i][j][k], lef))
                        break;
                }
            int nj = i - j;
            if (nj < n)
                for (int k = Maxm - 1; k >= 0; k--) {
                    int rig = curSum - k * Maxb + a[i];
                    if (rig < 0)
                        continue;
                    int lef = rig - (Maxb - 1);
                    if (!Update(dif[i + 1][nj + 1], reverseBits(sam[i][j][k]), lef))
                        break;
                    if (!Update(dif[i + 1][nj + 1], reverseBits(dif[i][j][k]), lef))
                        break;
                }
        }
        for (int k = 0; k < Maxm; k++)
            for (int j = 0; j < Maxb; j++)
                if ((sam[i][n][k] & 1ull << j) ||
                    (dif[i][n][k] & 1ull << j)) {
                    int sum1 = k * Maxb + j;
                    int sum2 = tot - sum1;
                    int cand = max(sum1 + a.back(), sum2 + a[i - 1]);
                    if (cand < best) {
                        best = cand;
                        wthi = i;
                        wthj = sum1;
                        wthj2 = curSum - sum1;
                    }
                }
        curSum += a[i];
    }
    array<vector<int>, 2> res{};
    for (int i = a.size() - 1; i >= wthi; i--)
        res[0].push_back(a[i]);
    int cur = 1, j = wthj, j2 = wthj2;
    for (int i = wthi; i > 0; i--) {
        if (sam[i][n - res[cur].size()][j / Maxb] & 1ull << j % Maxb) {
            res[cur].push_back(a[i - 1]);
            j -= a[i - 1];
        } else {
            res[cur].push_back(a[i - 1]);
            j -= a[i - 1];
            swap(j, j2);
            cur = 1 - cur;
        }
    }
    ranges::reverse(res[1]);
    for (auto& V : res)
        for (int i = 0; i < V.size(); i++)
            cout << V[i] << (i + 1 < V.size() ? ' ' : '\n');
    return 0;
}
