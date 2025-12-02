#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int sum = 0;
    while (n--) {
        int a;
        cin >> a;
        sum += a;
    }
    cout << (sum ? "HARD" : "EASY") << "\n";
    return 0;
}