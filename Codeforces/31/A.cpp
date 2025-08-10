#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& num : a)
        cin >> num;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) if (i != j)
            for (int k = j + 1; k < n; k++) if (i != k)
                if (a[i] == a[j] + a[k]) {
                    cout << i + 1 << " " << j + 1 << " " << k + 1 << "\n";
                    return 0;
                }
    cout << "-1\n";
    return 0;
}
