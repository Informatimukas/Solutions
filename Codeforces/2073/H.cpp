#include <bits/stdc++.h>
using namespace std;

string getType(int ind) {
    cout << "type " << ind << endl;
    string res;
    cin >> res;
    return res;
}

int getMulti(int ind) {
    cout << "multi " << ind << endl;
    int res;
    cin >> res;
    return res;
}

void Answer(int ind) {
    cout << "answer " << ind << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int lef = 1, rig = n;
        while (lef <= rig) {
            int mid = (lef + rig) / 2;
            if (getType(mid) == "rose")
                lef = mid + 1;
            else rig = mid - 1;
        }
        int pnt = rig;
        if (pnt == 0) {
            Answer(getMulti(1));
            continue;
        }
        if (pnt == n) {
            Answer(n - getMulti(n - 1));
            continue;
        }
        Answer(pnt + getMulti(pnt + 1) - getMulti(pnt - 1));
    }
    return 0;
}
