#include <bits/stdc++.h>
using namespace std;

string s1, s2;

int main()
{
    cin >> s1;
    cin >> s2;
    vector <string> res;
    while (s1 != s2) {
        string cur;
        if (s1[0] < s2[0]) {
            cur += "R";
            s1[0]++;
        } else if (s1[0] > s2[0]) {
            cur += "L";
            s1[0]--;
        }
        if (s1[1] < s2[1]) {
            cur += "U";
            s1[1]++;
        } else if (s1[1] > s2[1]) {
            cur += "D";
            s1[1]--;
        }
        res.push_back(cur);
    }
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << "\n";
    return 0;
}
