#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%s\n", n % 4? "Alice": "Bob");
    }
    return 0;
}