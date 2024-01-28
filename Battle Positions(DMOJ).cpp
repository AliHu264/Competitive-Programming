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
const int MAXN = 1e5+5; // TODO change this for each problem
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
int psa[MAXN];
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int minimumT; cin >> minimumT;
    int wave; cin >> wave;
    for(int i=0;i<wave;i++){
        int l, r, k;
        cin >> l >> r >> k;
        psa[l]+=k;
        psa[r+1]-=k;
    }

    int ans = 0;
    for(int i=1;i<n+1;i++){
        psa[i] += psa[i-1];
    }
    for(int i=1;i<n+1;i++){
        if(psa[i]<minimumT){
            ans++;
        }
    }
    cout << ans << endl;

}