#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n, m, d;
        cin >> n >> m >> d;
        int all = 1 + d / m;
        cout << (n + all - 1) / all << "\n";
    }
    return 0;
}