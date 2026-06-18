#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    if (s.length() <= 1) {
        cout << "0\n";
        return 0;
    }
    int sum = accumulate(s.begin(), s.end(), 0, [](auto&& s, auto&& c) { return s + (c - '0'); });
    int res = 1;
    while (sum >= 10) {
        int nsum = 0;
        while (sum) {
            nsum += sum % 10;
            sum /= 10;
        }
        sum = nsum;
        res++;
    }
    cout << res << "\n";
    return 0;
}
