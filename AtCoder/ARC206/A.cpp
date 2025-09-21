#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<int, int> M;
    int tot = 0;
    long long res = 0;
    int lst = 0;
    for (int i = 0; i < n; i++) {
       int a;
       cin >> a;
       res += tot - M[a];
       if (a != lst) {
          tot++;
          M[a]++;
          lst = a;
       }
    }
    res++;
    cout << res << "\n";
    return 0;
}