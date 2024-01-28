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
const int MAXN = 500002; // TODO change this for each problem
const ll MOD = pow(2, 32);
const ll BASE = 131;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

int n, m;
vector<int>adj[100002];
int dp[100002];

int dfs(int v){
    if(dp[v]) return dp[v];
    for (int e :adj[v]) {
        dp[v] = max(dp[v],dfs(e)+1);
    }
    return dp[v];
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;

    while(m--){
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans,dfs(i));
    }
    cout << ans << endl;
}