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
const ll MOD = pow(2,32);
const ll BASE = 131;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    ull factorial [35];
    fill_n(factorial,35,1);
    for(ull i=1;i<35;i++){
        factorial[i] = (factorial[i-1]*i)%MOD;
    }
    ull n, a;
    cin >> n;
    while(n--){
        cin >> a;
        if(a>33){
            cout << 0 << endl;
        }
        else{
            cout << factorial[a] << endl;
        }
    }
}