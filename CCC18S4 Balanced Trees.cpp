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
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 30000001; // TODO change this for each problem
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

ull dp[MAXN];
map<int, ll> large;

ull recursion(ull n) {
    if (n < MAXN && dp[n]) return dp[n];
    else if (n >= MAXN && large.count(n)) return large[n];
    if (n == 1)return 1;
    ull sum = 0;
    for (ull i = 1; i <= n / 2;) {
        ull j1 = n / i, j2 = n / (i + 1);
        sum += (j1 - j2) * recursion(i);
        i = n / j2;
    }
    if (n < MAXN) return dp[n] = sum;
    else return large[n] = sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ull n;
    cin >> n;
    cout << recursion(n) << endl;
}