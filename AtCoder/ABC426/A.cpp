#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string osl = "OSL";
    string x, y;
    cin >> x >> y;
    cout << (osl.find(x[0]) >= osl.find(y[0]) ? "Yes" : "No") << "\n";
    return 0;
}