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


int dp[10001];//min # of coins needed to reach n dollars
int coins[2001];
int solutions[100000];
vector<pair<int,pair<int,int>>> stores;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>coins[i];
    }
    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        stores.push_back({b,{a,i}});
    }
    sort(stores.begin(), stores.end());
    int ptr = 0;
    fill(&dp[0], &dp[10001], 1000000000);
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=coins[i];j<=10000;j++){
            dp[j] = min(dp[j], dp[j-coins[i]]+1);
        }
        while(stores[ptr].first==i){
            solutions[stores[ptr].second.second] = dp[stores[ptr].second.first];
            ptr++;
        }
    }
    for(int i=0;i<k;i++){
        cout<<((solutions[i]==1000000000)?-1:solutions[i])<<endl;
    }

}