#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    if (all_of(s.begin() + 1, s.end(), [](auto&& x) { return isupper(x); }))
        ranges::for_each(s, [](auto&& x) {
            x = isupper(x) ? tolower(x) : toupper(x);
        });
    cout << s << "\n";
    return 0;
}
