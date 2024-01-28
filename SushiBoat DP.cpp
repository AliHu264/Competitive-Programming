#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define mp make_pair
#define pb push_back
#define endl '\n'
const int MAXN = 1e6 + 5; // TODO change this for each problem
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll MOD = 998244353;
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

vector<int> pieces;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K, F;
    cin >> N >> K;
    pieces.assign(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> F;
        pieces[F-1]++;
    }

    vector<int> dp(K + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = min(i, K - 1); j >= 0; j--) {
            dp[j + 1] = (dp[j + 1] + (ll) pieces[i] * dp[j]) % MOD;
        }
    }
    cout << dp[K] << endl;
}
