#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <functional>

using namespace std;
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 1e5 + 1; // TODO change this for each problem
const ll MOD = 1e9 + 7;
const ll BASE = 131;
const int INF = 0x3f3f3f3f;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<pair<long double, long double>> sheeps;

    while (n--) {
        long double x, y;
        cin >> x >> y;
        sheeps.pb({x, y});
    }

    for (int i = 0; i < sheeps.size(); i++) {
        long double l = 0, r = 1000;//lower and upper bound of x-intercept
        for (int j = 0; j < sheeps.size(); j++) {
            if (i == j) continue;

            if (sheeps[i].first == sheeps[j].first) {//same x coord
                if (sheeps[i].second < sheeps[j].second) {//perpendicular bisect. doesnt touch x-axis
                    continue;
                } else {//else will never be eaten so skip to next
                    goto skip;
                }
            }
            long double x_int = 0;
            long double xavg = (sheeps[i].first + sheeps[j].first) / 2;
            long double yavg = (sheeps[i].second + sheeps[j].second) / 2;
            if (sheeps[i].second == sheeps[j].second) {// if on the same y axis
                x_int = xavg;//simplified to equalling xavg
            } else {//else calculate it normally
                long double slope = -(sheeps[j].first - sheeps[i].first) /
                                    (sheeps[j].second - sheeps[i].second);//neg. reciprocal slope
                x_int = -(yavg - slope * xavg) / slope;// b=y-mx
                // x=-b/m when y=0
            }
            if (sheeps[i].first < sheeps[j].first) {//upper bound if x1<x2
                r = min(r, x_int);
            } else {
                l = max(l, x_int);//else lower bound
            }
        }
        if (l <= r)//if the lower and upper bounds dont intersect, it will be eaten
            cout << fixed << setprecision(2) << "The sheep at (" << sheeps[i].first << ", " << sheeps[i].second
                 << ") might be eaten." << endl;
        skip:;
    }

}