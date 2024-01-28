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
struct s{
    int p,w,d;
};

vector<s> v;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, p, w, d; cin >> n;
    while(n--){
        cin >> p >> w >> d;
        v.pb({p,w,d});
    }
    ll best = LLONG_MAX;
    for(int i=0;i<= 1000000;i++){
       ll Res = 0;
       for(s student:v){
           Res += max(0,abs(i-student.p)-student.d)*student.w;
       }
        best = min(best,Res);
    }
    cout << best << endl;

}