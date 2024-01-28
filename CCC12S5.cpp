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

string operator*(const string &s, int n) {
    stringstream out;
    while (n > 0) {
        n--;
        out << s;
    }
    return out.str();
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int r,c;
    cin >> r >> c;
    int dp[r+1][c+1];
    memset(dp,-1,sizeof dp);
    dp[1][1] = 1;
    for(int i=0; i<=r;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=c;i++){
        dp[0][i] = 0;
    }

    int cats; cin >> cats;
    for(int i=0;i<cats;i++){
        int r2,c2; cin >> r2 >> c2;
        dp[r2][c2] = 0;
    }

    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(i==1&&j==1){
                continue;
            }
            if(dp[i][j])
            dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
    }

    cout << dp[r][c];

}