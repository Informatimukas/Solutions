#include <bits/stdc++.h>
using namespace std;

int T;
int n;
char str[52];

bool Wins(int a, int b)
{
    if (a == 0 && b == n - 1) return true;
    if (a == n - 1 && b == 0) return false;
    return a > b;
}

bool winAlice(int x)
{
    for (int i = 0; i < n; i++)
        if (str[i] == 'B')
            if (!Wins(x, i))
                return false;
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", str);
        bool alice = false;
        for (int i = 0; i < n; i++)
            if (str[i] == 'A' && winAlice(i)) {
                alice = true;
                break;
            }
        printf("%s\n", alice? "Alice": "Bob");
    }
    return 0;
}
