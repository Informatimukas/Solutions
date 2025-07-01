#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main() {
    scanf("%d", &T);
    while (T--) {
        vector<int> res;
        scanf("%d", &n);
        res.push_back(2);
        if (n % 2) res.push_back(3);
        res.push_back(1);
        int pnt = n % 2? 4: 3;
        while (pnt < n) {
            res.push_back(pnt + 1);
            res.push_back(pnt);
            pnt += 2;
        }
        for (int i = 0; i < res.size(); i++) {
            printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
        }
    }
    return 0;
}