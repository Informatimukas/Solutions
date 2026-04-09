#include <bits/stdc++.h>
using namespace std;

constexpr int day = 24 * 60;

int toMinutes(const string& s) {
    int h = (s[0] - '0') * 10 + (s[1] - '0');
    int m = (s[3] - '0') * 10 + (s[4] - '0');
    return 60 * h + m;
}

string toString(int minutes) {
    int m = minutes % 60;
    int h = minutes / 60;
    return to_string(h / 10) + to_string(h % 10) + ":" +
           to_string(m / 10) + to_string(m % 10);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> s;
    cin >> t;
    int minutes = (toMinutes(s) - toMinutes(t) + day) % day;
    cout << toString(minutes) << endl;
    return 0;
}
