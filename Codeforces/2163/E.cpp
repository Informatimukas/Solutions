#include <bits/stdc++.h>
using namespace std;

string getRow(const vector<string>& B, int r) {
    return B[r];
}

string getCol(const vector<string>& B, int c) {
    string res;
    for (int i = 0; i < B.size(); i++)
        res += B[i][c];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string player;
    cin >> player;
    if (player == "first") {
        int T;
        cin >> T;
        while (T--) {
            int n, C;
            cin >> n >> C;
            vector<string> B(n);
            for (int i = 0; i < n; i++)
                cin >> B[i];
            string bestRow = getRow(B, 0), bestCol = getCol(B, 0);
            int wRow = 0, wCol = 0;
            for (int i = 1; i < n; i++) {
                string candRow = getRow(B, i);
                string candCol = getCol(B, i);
                if (C == 1) {
                    if (candRow > bestRow) {
                        bestRow = candRow;
                        wRow = i;
                    }
                    if (candCol < bestCol) {
                        bestCol = candCol;
                        wCol = i;
                    }
                } else {
                    if (candRow < bestRow) {
                        bestRow = candRow;
                        wRow = i;
                    }
                    if (candCol > bestCol) {
                        bestCol = candCol;
                        wCol = i;
                    }
                }
            }
            cout << wRow + 1 << " " << wCol + 1 << "\n";
        }
    } else {
        int T;
        cin >> T;
        while (T--) {
            int n;
            cin >> n;
            string row;
            cin >> row;
            string col;
            cin >> col;
            if (row >= col)
                cout << "1\n";
            else cout << "0\n";
        }
    }
    return 0;
}
