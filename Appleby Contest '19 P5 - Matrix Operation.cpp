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
const int MAXN = 3e3 + 2; // TODO change this for each problem
const ll MOD = 3e6 + 1;
const ll BASE = 131;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

vector<pair<int, int>> makeAdj(int i, int j) {
    return {{i + 1, j},
            {i - 1, j},
            {i,     j + 1},
            {i,     j - 1}};
}

int arr[MAXN][MAXN], dp[MAXN][MAXN];
int n;

int dfs(int r, int c) {
    if (dp[r][c]) {
        return dp[r][c];
    }

    for (auto &p:makeAdj(r, c)) {
        if (p.ff < 0 || p.ff >= n || p.ss < 0 || p.ss >= n|| arr[p.ff][p.ss]<=arr[r][c]){
            continue;
        }
        dp[r][c] = max(dp[r][c],dfs(p.ff,p.ss)+1);
    }
    return dp[r][c];
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans << endl;
}