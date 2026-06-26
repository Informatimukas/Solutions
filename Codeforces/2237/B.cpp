#include <bits/stdc++.h>
using namespace std;

int Solve(vector<int> a, vector<int> b) {
    int res = 0;
    for (int j = 0; j < b.size(); j++) {
        int i = j;
        while (i < a.size() && b[j] < a[i])
            i++;
        if (i >= a.size())
            return -1;
        while (i > j) {
            swap(a[i], a[i - 1]);
            i--;
            res++;
        }
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
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector<int> b(n);
        for (auto& x : b)
            cin >> x;
        cout << Solve(a, b) << "\n";
    }
    return 0;
}
