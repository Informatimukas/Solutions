#include <bits/stdc++.h>
using namespace std;

void Digit()
{
    printf("digit\n");
    fflush(stdout);
    int res; scanf("%d", &res);
}

int Mult(int y)
{
    printf("mul %d\n", y);
    fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int Add(int y)
{
    printf("add %d\n", y);
    fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

void Answer()
{
    printf("!\n");
    fflush(stdout);
    int res; scanf("%d", &res);
}

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        Digit();
        Digit();
        for (int i = 3; i >= 0; i--)
            Add(-(1 << i));
        Mult(n);
        Answer();
    }
	return 0;
}
