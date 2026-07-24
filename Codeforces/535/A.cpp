#include <bits/stdc++.h>
using namespace std;

const vector numbs = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven",
    "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"
};

const vector tens = {"zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n <= 20)
        cout << numbs[n] << "\n";
    else {
        cout << tens[n / 10];
        if (n % 10)
            cout << "-" << numbs[n % 10];
        cout << "\n";
    }
    return 0;
}
