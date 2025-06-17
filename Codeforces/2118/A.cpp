#include <bits/stdc++.h>
using namespace std;

int T;
int n, k;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        printf("%s%s\n", string(k, '1').c_str(), string(n - k, '0').c_str());
    }
    return 0;
}