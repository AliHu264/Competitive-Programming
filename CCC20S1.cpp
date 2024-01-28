#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define mp make_pair
#define pb push_back
#define endl '\n'
const int MAXN = 1e6 + 5; // TODO change this for each problem
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll MOD = 998244353;
const ll BASE = 131;
const int INF = 0x3f3f3f3f;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

string operator*(const string &s, unsigned int n) {
    stringstream out;
    while (n--)
        out << s;
    return out.str();
}

ll t, dis;
long double speed = 0;
vector<pair<ll,ll>> v;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> t >> dis;
        v.pb(mp(t,dis));
    }
    sort(v.begin(),v.end());
    for(int i=1;i<N;i++){
        speed = max(speed,(ld)abs(v[i].second-v[i-1].second)/abs(v[i].first-v[i-1].first));
    }

    cout << fixed << setprecision(6) << speed << endl;

}
