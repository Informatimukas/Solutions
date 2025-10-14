#include <bits/stdc++.h>
using namespace std;

int Ask(auto& range, int val) {
    cout << "? " << val << " " << range.size();
    for (auto& x : range)
        cout << " " << x;
    cout << endl;
    int res;
    cin >> res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(2 * n - 1);
        iota(a.begin(), a.end(), 1);
        set<int> S, rS;
        for (int i = 1; i <= n; i++)
            S.insert(i);
        while (S.size() > 1) {
            ranges::shuffle(a, rng);
            vector r1(a.begin(), a.begin() + a.size() / 2);
            vector r2(a.begin() + a.size() / 2, a.end());
            int rem1 = a.size() / 2, rem2 = a.size() - rem1;
            set<int> A, B, rA, rB;
            for (auto& el : S) {
                int res1 = Ask(r1, el);
                int res2 = Ask(r2, el);
                if (res1 > res2) {
                    A.insert(el);
                    rem1 -= 2;
                } else if (res1 < res2) {
                    B.insert(el);
                    rem2 -= 2;
                }  else {
                    rem1--;
                    rem2--;
                    rA.insert(el);
                    rB.insert(el);
                }
            }
            for (auto& el : rS) {
                int res1 = Ask(r1, el);
                if (res1 == 1) {
                    rA.insert(el);
                    rem1--;
                } else {
                    rB.insert(el);
                    rem2--;
                }
            }
            if (rem1 % 2) {
                S = std::move(A);
                rS = std::move(rA);
                a = std::move(r1);
            } else {
                S = std::move(B);
                rS = std::move(rB);
                a = std::move(r2);
            }
        }
        cout << "! " << *S.begin() << endl;
    }
    return 0;
}
