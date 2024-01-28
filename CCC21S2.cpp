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

int r[5000001];
int c[5000001];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int m,n,k; cin >> m >> n >> k;

    for(int i=0;i<k;i++){
        char a; int b;
        cin >> a >> b;
        if(a == 'R'){
            r[b]++; r[b]%=2;
        }
        if(a == 'C'){
            c[b]++; c[b]%=2;
        }
    }

    ll ans = 0;
    int rowsBrushed = 0;
    for(int i=1;i<=m;i++){
        ans+=(ll)n*r[i];
        rowsBrushed+=r[i];
    }
    for(int i=1;i<=n;i++){
        ans+=(ll)m*c[i]-(ll)rowsBrushed*c[i]*2;
    }
}