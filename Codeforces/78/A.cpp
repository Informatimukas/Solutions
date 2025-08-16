#include <bits/stdc++.h>
using namespace std;

constexpr string vowel = "aeiou";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    auto isVowel = [](char ch) {
        return vowel.find(ch) != string::npos;
    };
    string a, b, c;
    getline(cin, a);
    getline(cin, b);
    getline(cin, c);
    if (ranges::count_if(a, isVowel) == 5 &&
        ranges::count_if(b, isVowel) == 7 &&
        ranges::count_if(c, isVowel) == 5)
        cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
