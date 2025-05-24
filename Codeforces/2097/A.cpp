#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
int a[Maxn];

bool Solve()
{
    map <int, int> M;
    for (int i = 0; i < n; i++)
        M[a[i]]++;
    int lst = -1;
    int cur = 0;
    for (auto el: M) {
        if (cur >= 2)
            return true;
        if (lst + 1 < el.first)
            cur = 0;
        if (cur == 1)
            cur = el.second;
        else cur = el.second / 2;
        lst = el.first;
    }
    return cur >= 2;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        printf("%s\n", Solve()? "Yes": "No");
    }
    return 0;
}
