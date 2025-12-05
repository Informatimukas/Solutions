#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "I ";
        cout << (i % 2 ? "hate" : "love") << " ";
        cout << (i < n ? "that " : "it\n");
    }
    return 0;
}