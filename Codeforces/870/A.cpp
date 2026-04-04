#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    set<int> A, B;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        A.insert(a);
    }
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        B.insert(b);
    }
    for (int i = 1; i <= 9; i++)
        if (A.contains(i) && B.contains(i)) {
            cout << i << "\n";
            return 0;
        }
    int a = *A.begin(), b = *B.begin();
    if (a > b)
        swap(a, b);
    cout << 10 * a + b << "\n";
    return 0;
}
