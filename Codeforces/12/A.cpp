#include <bits/stdc++.h>
using namespace std;

string B[3];

int main()
{
    for (int i = 0; i < 3; i++)
        cin >> B[i];
    if (B[0][0] == B[2][2] &&
        B[0][1] == B[2][1] &&
        B[0][2] == B[2][0] &&
        B[1][0] == B[1][2])
        printf("YES\n");
    else printf("NO\n");
    return 0;
}
