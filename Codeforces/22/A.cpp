#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        res.push_back(a);
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    if (res.size() >= 2)
        printf("%d\n", res[1]);
    else printf("NO\n");
    return 0;
}
