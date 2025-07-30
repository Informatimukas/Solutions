#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const vector<int>& V, int mx, int rem) {
    int l = 0, r = static_cast<int>(V.size()) - 1;
    while (l < r) {
        if (V[l] != V[r]) {
            if (rem && V[l] == mx) {
                rem--;
                l++;
                continue;
            }
            if (rem && V[r] == mx) {
                rem--;
                r--;
                continue;
            }
            return false;
        }
        l++;
        r--;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> cnt(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        int sum = 0, nxt = 1;
        while (nxt <= n && sum + cnt[nxt] < k) {
            sum += cnt[nxt];
            nxt++;
        }
        int rem = cnt[nxt] + 1 - (k - sum);
        vector<int> cand;
        for (int i = 0; i < n; i++)
            if (a[i] <= nxt)
                cand.push_back(a[i]);
        printf("%s\n", isPalindrome(cand, nxt, rem)? "YES": "NO");
    }
    return 0;
}
