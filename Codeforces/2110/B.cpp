#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
char str[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        int slen = strlen(str);
        int cnt = 0, st = 0;
        for (int i = 0; i < slen; i++) {
            st += str[i] == '('? 1: -1;
            if (st == 0) cnt++;
        }
        printf("%s\n", cnt > 1? "YES": "NO");
    }
	return 0;
}
