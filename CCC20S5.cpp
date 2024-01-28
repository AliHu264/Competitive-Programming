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
const int MAXN = 4e5; // TODO change this for each problem
const ll MOD = 1e9 + 7;
const ll BASE = 131;
const int INF = 0x3f3f3f3f;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

int burg[1000002];
double dp[1000002];
unordered_map<int, int> visited;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> burg[i];
    }
    if (burg[0] == burg[n - 1])
        dp[n - 1] = 1;
    visited[burg[n - 1]] = n - 1;
    double sum = dp[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (visited.find(burg[i]) == visited.end()) {
            visited[burg[i]] = i;
            if (burg[i] == burg[0]) {
                dp[i] = 1;
            }
            else {
                dp[i] = (sum + 1) / (n - i);
            }
        }
        else {
            dp[i] = dp[visited[burg[i]]];
        }
        sum += dp[i];
    }
    cout << setprecision(9) << sum/n << endl;
}