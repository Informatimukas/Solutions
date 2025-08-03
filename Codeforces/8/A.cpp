#include <bits/stdc++.h>
using namespace std;

bool Contains(const string& s, const string& a, const string& b) {
    auto ind = s.find(a);
    if (ind == string::npos)
        return false;
    return s.find(b, ind + a.length()) != string::npos;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, a, b;
    cin >> s >> a >> b;
    bool ab = Contains(s, a, b);
    ranges::reverse(s);
    bool ba = Contains(s, a, b);
    if (ab)
        cout << (ba? "both": "forward");
    else cout << (ba? "backward": "fantasy");
    cout << "\n";
    return 0;
}
