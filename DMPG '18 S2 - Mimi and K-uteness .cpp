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
const int MAXN = 2e5+5; // TODO change this for each problem
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

ll arr[MAXN];
ll psa[MAXN];
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for(int i=0;i<n;i++){
        ll a;
        cin >> a;
        arr[i]= a;
    }
    for(int i=1;i<n+1;i++){
        psa[i] = psa[i-1] + arr[i-1];
    }
    ull ans = 0;
    for(int i = 0;i<n;i++){
        ans+=psa[n-i]-psa[i];
        cout << ans << endl;
    }

}