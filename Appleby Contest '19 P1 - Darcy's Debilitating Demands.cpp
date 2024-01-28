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
const int MAXN = 1e5 + 2; // TODO change this for each problem
const ll MOD = 3e6 + 1;
const ll BASE = 131;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    while (q--) {
        vector<ll> v;
        ll n, a, b, c;
        cin >> n >> a >> b >> c;
        v.pb(c);
        v.pb(b);
        v.pb(a);
        vector<ll> v2(3);
        copy(v.begin(), v.end(), v2.begin());
        for (ll &x:v) {
            int diff = min(n, x);
            n -= x;
            x += diff;
            if (n < 1)
                break;
        }
        if (n > 0) {
            cout << -1 << endl;
            continue;
        }
        for (int i = 2; i >= 0; i--) {
            cout << v[i] - v2[i] << " ";
        }
        cout << endl;
    }
}
