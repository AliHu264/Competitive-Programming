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
const int MAXN = 100002; // TODO change this for each problem
const ll MOD = pow(2, 31);
const ll BASE = 131;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

int n;
string s;
set<string> st;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    while (n--) {
        cin >> s;
        st.insert(s);
    }
    for (int q = 0; q < 10; q++) {
        vector<int> dp;
        cin >> s;
        dp.resize(s.length() + 1);
        fill(dp.begin(), dp.end(), INT_MAX - 1);
        dp[0] = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j <= s.length(); j++) {
                if (st.find(s.substr(i, j - i)) != st.end()) {
                    dp[j] = min(dp[i] + 1, dp[j]);
                }
            }
        }
        cout << dp[s.length()] - 1 << endl;
    }
}