#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int x;
    fin >> x;
    int a, b;
    while (fin >> a >> b) {
        if (x == a) x = b;
        else if (x == b) x = a;
    }
    fout << x << "\n";
    return 0;
}
