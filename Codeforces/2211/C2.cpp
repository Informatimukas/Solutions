#include <bits/stdc++.h>
using namespace std;

bool Match(const vector<int>& a, vector<int>& b, int k) {
    for (int i = 0; i < k; i++) {
        int fir = i;
        while (fir < a.size()) {
            int cur = fir;
            while (cur + k < a.size() && a[cur] == a[cur + k])
                cur += k;
            if (cur + k < a.size()) {
                if (b[cur] != -1 && a[cur] != b[cur])
                    return false;
                b[cur] = a[cur];
                if (b[cur + k] != -1 && a[cur + k] != b[cur + k])
                    return false;
                b[cur + k] = a[cur + k];
            }
            set<int> S;
            for (int tmp = fir; tmp <= cur; tmp += k)
                if (b[tmp] != -1)
                    S.insert(b[tmp]);
            if (S.size() >= 2)
                return false;
            if (S.size() == 1)
                for (int tmp = fir; tmp <= cur; tmp += k)
                    b[tmp] = *S.begin();
            fir = cur + k;
        }
    }
    map<int, int> M;
    for (int i = 0; i < k; i++) {
        M[a[i]]++;
        if (b[i] != -1)
            M[b[i]]--;
    }
    return ranges::all_of(M, [](auto&& x) {
        return x.second >= 0;
    });
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector<int> b(n);
        for (auto& x : b)
            cin >> x;
        cout << (Match(a, b, k) ? "YES" : "NO") << "\n";
    }
    return 0;
}
