#include <bits/stdc++.h>
using namespace std;

int getMin(int n) {
    return n - 2;
}

int getMax(int n) {
    multiset<int> S;
    for (int i = 0; i < n; i++)
        S.insert(0);
    int res = 0;
    while (S.size() > 1) {
        int a = *S.begin();
        S.erase(S.begin());
        int b = *S.rbegin();
        S.erase(prev(S.end()));
        res += a + b;
        S.insert(b + 1);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << getMin(n) << " " << getMax(n) << "\n";
    }
    return 0;
}