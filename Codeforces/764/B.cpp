#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    int i = 0, j = n - 1;
    while (i <= j) {
        swap(a[i], a[j]);
        i += 2;
        j -= 2;
    }
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << (i + 1 < a.size() ? ' ' : '\n');
    return 0;
}