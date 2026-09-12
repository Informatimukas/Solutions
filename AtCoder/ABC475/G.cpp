#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxm = 24;
constexpr int Maxn = 1000;
constexpr ll Inf = 1000000000000000000ll;

vector<int> pr;
array<int, Maxm> marked;
int best;
ll wth;
ll D, N;

void Traverse(int lvl, bool follow, int allow, int divs, ll my) {
    if (my % D == 0)
        return;
    if (divs > best) {
        best = divs;
        wth = my;
    }
    if (lvl >= pr.size() || allow == 0)
        return;
    for (int i = 0; i <= allow; i++) {
        bool nfollow = follow && i >= marked[lvl];
        int nallow = follow && marked[lvl] > 0 ? allow : i;
        Traverse(lvl + 1, nfollow, nallow, divs * (i + 1), my);
        if (my <= N / pr[lvl])
            my *= pr[lvl];
        else break;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector prime(Maxn, true);
    for (int i = 2; i < Maxn; i++)
        if (prime[i]) {
            pr.push_back(i);
            for (int j = i + i; j < Maxn; j += i)
                prime[j] = false;
        }
    while (pr.size() > Maxm)
        pr.pop_back();
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> D;
        for (int i = 0; i < marked.size(); i++) {
            marked[i] = 0;
            ll num = D;
            while (num % pr[i] == 0) {
                num /= pr[i];
                marked[i]++;
            }
        }
        best = 0;
        Traverse(0, true, 64, 1, 1);
        cout << wth << "\n";
    }
    return 0;
}
