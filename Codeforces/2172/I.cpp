#include <bits/stdc++.h>
using namespace std;

using ld = long double;
using ll = long long;

const ld pi = acos(-1.0l);

struct vec {
    ll x, y;
    ll operator^(const vec& oth) const {
        return x * oth.y - y * oth.x;
    }
    vec operator-(const vec& oth) const {
        return {x - oth.x, y - oth.y};
    }
    ld Distance() const {
        return sqrt(x * x + y * y);
    }
};

ld Area(ld h, ld r) {
    cout << h << " " << r << endl;
    ld alpha = acos(h / r);
    return r * r * alpha - h * r * sin(alpha);
}

ld getH(const vec& a, const vec& b, ld r) {
    ld d = (a - b).Distance();
    return sqrt(d * d / 4 - r * r);
}

ld Solve(const vector<vec>& hull, ld r) {
    for (auto& [x, y] : hull)
        cout << x << " " << y << endl;
    cout << "end\n";
    if (hull.size() < 3)
        return Area(0, r);
    vec origin = {0, 0};
    ld res = 0;
    for (int i = 0; i < hull.size(); i++) {
        int ni = (i + 1) % hull.size();
        if (((origin - hull[i]) ^ (origin - hull[ni])) >= 0)
            return Area(0, r);
        res = max(res, Area(getH(hull[i], hull[i + 1], r), r));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, r;
    cin >> n >> r;
    vector<vec> seq(n);
    for (auto& [x, y] : seq)
        cin >> x >> y;
    ranges::sort(seq, [](auto&& a, auto&& b) {
        if (a.x != b.x)
            return a.x < b.x;
        return a.y < b.y;
    });
    sort(seq.begin() + 1, seq.end(), [orig = seq[0]](auto&& a, auto&& b) {
        return atan2(static_cast<ld>(a.y - orig.y), static_cast<ld>(a.x - orig.x)) <
            atan2(static_cast<ld>(b.y - orig.y), static_cast<ld>(b.x - orig.x));
    });
    cout << "sorted" << endl;
    for (auto& [x, y] : seq)
        cout << x << " " << y << endl;
    cout << "end\n";
    vector hull = {seq[0]};
    for (int i = 1; i < seq.size(); i++) {
        while (hull.size() >= 2 && ((seq[i] - hull[hull.size() - 2]) ^ (seq[i] - hull.back())) >= 0)
            hull.pop_back();
        hull.push_back(seq[i]);
    }
    while (hull.size() >= 3 && ((hull[0] - hull[hull.size() - 2]) ^ (hull[0] - hull.back())) >= 0)
        hull.pop_back();
    cout << fixed << setprecision(10) << Solve(hull, r) << "\n";
    return 0;
}
