#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 10; i++) {
        map<int, int> M;
        for (int a = 0; a < i; a++)
            for (int b = 0; a + b < i; b++)
                M[a ^ b]++;
        cout << "i = " << i << endl;
        for (auto& [key, value] : M)
            cout << key << " " << value << endl;
    }
    return 0;
}
