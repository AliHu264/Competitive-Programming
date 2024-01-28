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
const ll MOD = pow(2, 32);
const ll BASE = 131;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

vector<pair<ll,ll>> countries;
ll shortest[3001];
bool vis[3001];

ll dist(ll a, ll b, ll c, ll d) {
    return abs(a - b) * abs(a - b) + abs(c - d) * abs(c - d);
}
int n;
void solve(){
    while (true) {
        ll cur = -1;
        for (int j = 0; j < n; j++) {
            if ((!vis[j]) && (cur == -1 || shortest[j] < shortest[cur])) {
                cur = j;
            }
        }
        if (cur == -1)break;
        vis[cur] = true;
        for (int j = 0; j < n; j++) {
            shortest[j] = min(shortest[j], shortest[cur] +
                                           dist(countries[cur].first, countries[j].first, countries[cur].second, countries[j].second));
        }
    }
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        countries.eb(mp(a,b));
    }
    fill(shortest, shortest + n, LLONG_MAX);
    ll start;
    cin >> start;
    start--;
    shortest[start] = 0;
    solve();

    sort(shortest, shortest + n);
    ll q;
    cin >> q;
    while (q--) {
        ll query;
        cin >> query;
        cout << upper_bound(shortest, shortest + n, query) - shortest << endl;
//        cout << shortest << endl;
    }
}