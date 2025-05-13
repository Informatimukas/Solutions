#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int sum = 0;
        int l = 0, r = n - 1;
        while (l < r) {
            sum += r - l;
            l++; r--;
        }
        printf("%d\n", sum + 1);
    }
    return 0;
}
