#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<string, string> M = {{"red", "SSS"}, {"blue", "FFF"}, {"green", "MMM"}};
    string s;
    cin >> s;
    auto it = M.find(s);
    cout << (it == M.end()? "Unknown": it->second) << "\n";
    return 0;
}
