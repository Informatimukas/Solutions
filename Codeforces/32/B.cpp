#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    cin >> s;
    int pnt = 0;
    while (pnt < s.length())
        if (s[pnt] == '.') {
            printf("0");
            pnt++;
        } else if (s[pnt + 1] == '.') {
            printf("1");
            pnt += 2;
        } else {
            printf("2");
            pnt += 2;
        }
    printf("\n");
    return 0;
}