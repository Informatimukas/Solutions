#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int mn = 0, mx = 0;
        for (int i = 0; i < s.length(); )
            if (s[i] == '0')
                i++;
            else {
                int j = i;
                while (true)
                    if (j + 1 < s.length() && s[j + 1] == '1')
                        j++;
                    else if (j + 2 < s.length() && s[j + 2] == '1')
                        j += 2;
                    else break;
                int len = j - i + 1;
                mn += len - (len - 1) / 2;
                mx += len;
                i = j + 2;
            }
        cout << mn << " " << mx << "\n";
    }
    return 0;
}