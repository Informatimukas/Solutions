#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int Send(int m1, int m2) {
    cout << m1 << " " << m2 << endl;
    int res;
    cin >> res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int mid = (1 << 15) - 1;
        cout << mid << endl;
        int got;
        cin >> got;
        if (got > mid) {
            int b = 0;
            for (int i = 15; i < 30; i++)
                if (got & 1 << i) {
                    b = i;
                    break;
                }
            got = Send(1 << b, 0);
            if (got & 1 << b)
                cout << "1";
            else cout << "0";
            cout << endl;
            continue;
        }
        if (got < mid) {
            int b = 0;
            for (int i = 0; i < 15; i++)
                if (!(got & 1 << i)) {
                    b = i;
                    break;
                }
            got = Send(0, 1 << b);
            if (got & 1 << b)
                cout << "1";
            else cout << "0";
            cout << endl;
            continue;
        }
        int pat1, pat2;
        do {
            pat1 = uniform_int_distribution(1, (1 << 15) - 1)(rng);
            pat2 = uniform_int_distribution(1, (1 << 15) - 1)(rng);
        } while (pat1 == pat2);
        int opat1 = ((1 << 15) - 1) ^ pat1;
        int off1 = (pat1 << 15) | opat1;
        int opat2 = ((1 << 15) - 1) ^ pat2;
        int off2 = (pat2 << 15) | opat2;
        got = Send(off2, off1);
        int ogot = got ^ off1 ^ off2;
        int p1 = (got >> 15);
        int p2 = ((1 << 15) - 1) & got;
        int p3 = ogot >> 15;
        int p4 = ((1 << 15) - 1) & ogot;
        if (p1 == pat1 && p3 == pat2 || p2 == pat1 && p4 == pat2)
            cout << "1";
        else cout << "0";
        cout << endl;
    }
    return 0;
}
