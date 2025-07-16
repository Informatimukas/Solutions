#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, vector<ll>> iv;

constexpr int Maxb = 62;
constexpr int Maxn = 1000006;

int T;
int n;
char A[Maxn];
char B[Maxn];

iv Express(const map<int, vector<ll>> &M, vector<ll> &V) {
    for (int i = 0, b = 0; i < V.size(); i++, b += Maxb)
        if (V[i])
            for (int j = 0; j < Maxb; j++)
                if (V[i] & 1ll << j) {
                    auto it = M.find(b + j);
                    if (it == M.end())
                        return {b + j, V};
                    for (int k = i; k < V.size(); k++)
                        V[k] ^= it->second[k];
                }
    return {-1, V};
}

map<int, vector<ll>> Get(char A[]) {
    int len = n;
    while (len % 2 == 0) len /= 2;
    int blen = (len - 1) / Maxb + 1;
    map<int, vector<ll>> M;
    for (int i = 0; i < n; i += len) {
        vector V(blen, 0ll);
        for (int j = 0; j < len; j++)
            if (A[i + j] == '1')
                V[j / Maxb] |= 1ll << j % Maxb;
        iv got = Express(M, V);
        if (got.first >= 0)
            M.insert(got);
    }
    return M;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", A);
        scanf("%s", B);
        auto MA = Get(A);
        auto MB = Get(B);
        if (MA.size() != MB.size()) {
            printf("No\n");
            continue;
        }
        bool ok = true;
        for (auto &p: MB)
            if (Express(MA, p.second).first != -1) {
                ok = false;
                break;
            }
        printf("%s\n", ok? "Yes": "No");
    }
    return 0;
}
