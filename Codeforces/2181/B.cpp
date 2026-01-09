#include <bits/stdc++.h>
using namespace std;

bool Solve(multiset<int>& A, multiset<int>& B) {
    auto el = *B.rbegin();
    B.erase(prev(B.end()));
    if (el <= *A.rbegin()) {
        if (B.empty())
            return true;
    } else B.insert(el - *A.rbegin());
    return !Solve(B, A);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        multiset<int> A, B;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            A.insert(x);
        }
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            B.insert(x);
        }
        cout << (Solve(A, B) ? "Alice" : "Bob") << "\n";
    }
    return 0;
}
