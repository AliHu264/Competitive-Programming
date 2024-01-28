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

int main() {
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    int n; ll m; cin>>n>>m;
    ll val[n];
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    int l = 0;
    int r = 0;
    ll comp = val[0];
    int best = 0;
    while(true){
        if(comp<m){
            best = max(best, r-l+1);
            r++;
            if(r>=n)break;
            comp += val[r];
        }
        else{
            comp-=val[l];
            l++;
        }
    }
    cout<<best<<"\n";
}
