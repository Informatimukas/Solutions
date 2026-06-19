#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<ii, int> M;
    int n;
    cin >> n;
    while (n--) {
        int h, m;
        cin >> h >> m;
        M[{h, m}]++;
    }
    cout << ranges::max_element(M, {}, [](auto&& x) { return x.second; })->second << "\n";
    return 0;
}
