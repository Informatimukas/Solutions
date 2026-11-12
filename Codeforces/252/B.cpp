#include <bits/stdc++.h>
using namespace std;

bool Ok(vector<int> a, vector<int> b) {
    ranges::sort(a);
    ranges::sort(b);
    return !(a.back() < b[0] || b.back() < a[0]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<int, vector<int>> M;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        M[a].push_back(i);
    }
    if (M.size() == 1) {
        cout << "-1\n";
        return 0;
    }
    if (M.size() == 2) {
        auto A = M.begin()->second;
        auto B = M.rbegin()->second;
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < B.size(); j++) {
                swap(A[i], B[j]);
                if (Ok(A, B)) {
                    cout << A[i] << " " << B[j] << "\n";
                    return 0;
                }
                swap(A[i], B[j]);
            }
        cout << "-1\n";
        return 0;
    }
    auto it = M.begin();
    int a = it->second[0];
    ++it;
    int b = it->second[0];
    ++it;
    int c = it->second[0];
    vector V = {a, b, c};
    ranges::sort(V);
    if (a != V[1]) {
        cout << a << " " << V[1] << "\n";
        return 0;
    }
    cout << c << " " << V[1] << "\n";
    return 0;
}
