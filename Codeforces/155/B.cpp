#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int res = 0;
    vector<int> seq;
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (b > 0) {
            res += a;
            cnt += b - 1;
        } else seq.push_back(a);
    }
    ranges::sort(seq, greater());
    for (int i = 0; i < seq.size() && i < cnt; i++)
        res += seq[i];
    cout << res << "\n";
    return 0;
}