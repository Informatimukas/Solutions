// Next steps: I considered the elements that are not being pointed at, but it's still
// confusing which of them to pick as the smallest one.
// Need more thinking. Below is the test code for all permutations of given size.
#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

vector<int> Encode(const vector<int>& p) {
    vector<int> res(p.size());
    vector tk(p.size(), false);
    for (int i = 1; i < p.size(); i++) {
        res[i] = -1;
        for (int j = 1; j < p.size(); j++)
            if (!tk[j] && p[j] > p[i]) {
                tk[j] = true;
                res[i] = j;
                break;
            }
    }
    return res;
}

vector<int> Decode(vector<int> p) {
    int n = p.size() - 1;
    vector res(n + 1, -1);
    vector tk(n + 1, false);
    priority_queue<ii, vector<ii>, greater<>> Q;
    set<int> rem;
    for (int i = n; i > 0; i--)
        if (p[i] != -1)
            tk[p[i]] = true;
    for (int i = 1; i <= n; i++) {
        rem.insert(i);
        if (!tk[i] && p[i] != -1)
            Q.emplace(p[i], i);
    }
    int cur = 1;
    while (!Q.empty()) {
        int v = Q.top().second;
        Q.pop();
        if (res[v] != -1)
            continue;
        auto it = rem.lower_bound(p[v]);
        while (it != rem.begin()) {
            --it;
            if (*it <= v)
                break;
            res[*it] = cur++;
            int u = p[*it];
            if (u != -1 && p[u] != -1)
                Q.emplace(p[u], u);
            rem.erase(it++);
        }
        res[v] = cur++;
        int u = p[v];
        if (p[u] != -1)
            Q.emplace(p[u], u);
        rem.erase(v);
    }
    for (int i = n; i > 0; i--)
        if (res[i] == -1)
            res[i] = cur++;
    return res;
}

void Print(const string& label, const vector<int>& p) {
    cout << "-- " << label << endl;
    for (int i = 1; i < p.size(); i++)
        cout << " " << p[i];
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> t(n + 1);
    for (int i = 1; i <= n; i++)
        t[i] = i;
    do {
        vector<int> p = Encode(t);
        const vector<int> res = Decode(p);
        if (Encode(res) == p) ;
            /*cout << "Correct!\n";*/
        else {
            cout << "Incorrect\n";
            Print("p", p);
            Print("res", res);
            Print("got code", Encode(res));
        }
    } while (next_permutation(t.begin() + 1, t.end()));
    /*for (int i = 1; i <= n; i++)
        cout << res[i] << (i + 1 <= n ? ' ' : '\n');*/
    return 0;
}
