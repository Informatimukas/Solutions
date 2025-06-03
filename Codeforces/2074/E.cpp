#include <bits/stdc++.h>
using namespace std;

int T;
int n;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int Ask(int seq[])
{
    printf("? %d %d %d\n", seq[0], seq[1], seq[2]);
    fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int seq[3] = {1, 2, 3};
        int nxt;
        while ((nxt = Ask(seq)) != 0)
            seq[uniform_int_distribution<int>(0, 2)(rng)] = nxt;
        printf("! %d %d %d\n", seq[0], seq[1], seq[2]);
        fflush(stdout);
    }
	return 0;
}
