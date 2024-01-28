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
const int MAXN = 3628802; // TODO change this for each problem
const ll MOD = 3e6 + 1;
const ll BASE = 131;
const int INF = 0x3f3f3f3f;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

string operator*(const string &s, int n) {
    stringstream out;
    while (n > 0) {
        n--;
        out << s;
    }
    return out.str();
}
int n,m, ans; vector<int> adj[22]; bool vis[22];

void dfs(int N){
    if(N>n){
        ans++; return;
    }
    dfs(N+1);
    bool flag = true;
    for(int v:adj[N]){
        if(vis[v]) flag = false;
    }
    if(flag){
        vis[N] = true;
        dfs(N+1);
        vis[N] = false;
    }


}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }
    dfs(1);
    cout << ans << endl;
}