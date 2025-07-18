#include <bits/stdc++.h>
using namespace std;

bool Check(const vector<int> &seq) {
    for (int i = 2; i < seq.size(); i++)
        if ((seq[i - 1] + seq[i - 2]) % 26 != seq[i])
            return false;
    return true;
}

int main()
{
    string s;
    cin >> s;
    vector<int> seq;
    for (int i = 0; i < s.length(); i++)
        seq.push_back(s[i] - 'A');
    printf("%s\n", Check(seq)? "YES": "NO");
    return 0;
}