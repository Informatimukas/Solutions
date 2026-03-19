#include <bits/stdc++.h>
using namespace std;

int digitSum(int x) {
    int sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int x;
        cin >> x;
        int res = 0;
        for (int i = 1; i <= 100; i++)
            if (digitSum(x + i) == i)
                ++res;
        cout << res << "\n";
    }
    return 0;
}
