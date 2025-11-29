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
    ld alpha = acos(h / r);
    return r * r * alpha - h * r * sin(alpha);
}

ld getH(const vec& a, const vec& b) {
    ld d = (a - b).Distance();
    ld r1 = a.Distance();
    ld r2 = b.Distance();
    ld alpha = acos((r1 * r1 + r2 * r2 - d * d) / (2 * r1 * r2));
    return sin(alpha) * r1 * r2 / d;
}

ld Solve(const vector<vec>& hull, ld r) {
    if (hull.size() < 3)
        return Area(0, r);
    vec origin = {0, 0};
    ld res = 0;
    for (int i = 0; i < hull.size(); i++) {
        int ni = (i + 1) % hull.size();
        if (((origin - hull[i]) ^ (hull[ni] - hull[i])) >= 0)
            return Area(0, r);
        res = max(res, Area(getH(hull[i], hull[ni]), r));
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
    vector hull = {seq[0]};
    for (int i = 1; i < seq.size(); i++) {
        while (hull.size() >= 2 && ((seq[i] - hull.back()) ^
            (hull.back() - hull[hull.size() - 2])) >= 0)
            hull.pop_back();
        hull.push_back(seq[i]);
    }
    while (hull.size() >= 3 && ((hull[0] - hull.back()) ^
        (hull.back() - hull[hull.size() - 2])) >= 0)
        hull.pop_back();
    cout << fixed << setprecision(10) << Solve(hull, r) << "\n";
    return 0;
}
