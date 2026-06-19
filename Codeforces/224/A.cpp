#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int sum = 0;
    for (int i = 1; i <= s1 && i <= s2; i++)
        if (s1 % i == 0 && s2 % i == 0) {
            int b = s1 / i, c = s2 / i;
            if (b * c == s3) {
                sum = 4 * (i + b + c);
                break;
            }
        }
    cout << sum << "\n";
    return 0;
}
