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
const int MAXN = 100000; // TODO change this for each problem
const ll MOD = 1e9 + 7;
const ll BASE = 131;
const int INF = 0x3f3f3f3f;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    vector<pair<int,int>> v;
    int n,m; cin >> n >> m;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        v.eb(a,b);
    }
    sort(v.begin(),v.end());

    ll cost = 0;
    for(auto &p:v){
        ll b = min(m,p.ss);
        cost += b*p.ff;
        m -= b;
    }
    cout << cost << endl;
}