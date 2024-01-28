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

string operator*(const string &s, unsigned int n) {
    stringstream out;
    while (n--)
        out << s;
    return out.str();
}


int months[10000][4];
ll dp[10000][101];// best money we can get from having n cue balls on month n

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        cin>>months[i][0]>>months[i][1]>>months[i][2]>>months[i][3];
    }
    for(int i=0;i<=100;i++){//we sell all cue balls on the last month to get base case
        dp[n-1][i] = months[n-1][3]*min(i,months[n-1][1]);
    }
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<=5;j++){
            ll best = 0;
            for(int k=max(0,j-months[i][1]);k<=min(100,j+months[i][0]);k++){
                ll base = dp[i+1][k] - k*m;
                if(months[i][2]<months[i][3]){
                    int left = max(0,max(j-months[i][1], k-months[i][0]));
                    base+= max(0,j-left)*months[i][3] - max(0,k-left)*months[i][2];
                }
                else{
                    if(k<j){//sell
                        base += (j-k)*months[i][3];
                    }
                    else{//buy
                        base -= (k-j)*months[i][2];
                    }
                }
                best = max(base,best);
            }
            dp[i][j] = best;

        }
    }
    cout<<dp[0][0]<<endl;
}