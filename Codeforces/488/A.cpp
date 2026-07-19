#include <bits/stdc++.h>
using namespace std;

bool Lucky(int x) {
    x = abs(x);
    while (x) {
        if (x % 10 == 8)
            return true;
        x /= 10;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a;
    cin >> a;
    for (int i = 1; ; i++)
        if (Lucky(a + i)) {
            cout << i << "\n";
            break;
        }
    return 0;
}
