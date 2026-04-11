#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int H, W;
    cin >> H >> W;
    vector<string> B(H);
    for (auto& x : B)
        cin >> x;
    vector nxt(H, vector(W, Inf));
    for (int i = H - 1; i >= 0; i--)
        for (int j = W - 1; j >= 0; j--)
            if (B[i][j] == '*')
                nxt[i][j] = 0;
            else {
                if (i + 1 < H)
                    nxt[i][j] = min(nxt[i][j], nxt[i + 1][j] + 1);
                if (j + 1 < W)
                    nxt[i][j] = min(nxt[i][j], nxt[i][j + 1] + 1);
            }
    int r = 0, c = 0;
    int res = B[0][0] == '*';
    while (r != H - 1 || c != W - 1) {
        if (r == H - 1 || c != W - 1 && nxt[r][c + 1] <= nxt[r + 1][c])
            c++;
        else r++;
        res += B[r][c] == '*';
    }
    cout << res << "\n";
    return 0;
}
