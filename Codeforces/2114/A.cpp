#include <bits/stdc++.h>
using namespace std;

int T;
int num;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &num);
        bool found = false;
        for (int i = 0; i <= 100 && !found; i++)
            for (int j = 0; j <= 100; j++)
                if ((i + j) * (i + j) == num) {
                    found = true;
                    printf("%d %d\n", i, j);
                    break;
                }
        if (!found)
            printf("-1\n");
    }
	return 0;
}
