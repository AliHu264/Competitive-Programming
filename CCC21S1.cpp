#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>

using namespace std;
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll BASE = 131;

vector<pair<double,double>> v;
vector<double> w;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    double l,r;
    cin >> l >> r;
    v.pb({l,r});
    for(int i=0;i<n-1;i++){
        l = r;
        cin >> r;
        v.pb({l,r});
    }
    for(int i=0;i<n;i++){
        double W; cin >> W;
        w.pb(W);
    }

    double area = 0;
    for(int i=0;i<n;i++){
        area += w[i]*min(v[i].first,v[i].second)+ abs(v[i].first - v[i].second)*w[i]/2;
    }
    cout << fixed << area << endl;
}