#include <bits/stdc++.h>
using namespace std;

int digitSum(int a, int bas) {
    int res = 0;
    while (a) {
        res += a % bas;
        a /= bas;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a;
    cin >> a;
    int sum = 0, cnt = 0;
    for (int i = 2; i < a; i++) {
        sum += digitSum(a, i);
        cnt++;
    }
    int g = __gcd(sum, cnt);
    cout << sum / g << "/" << cnt / g << "\n";
    return 0;
}
