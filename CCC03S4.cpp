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
const ll MOD = 3e6 + 1;
const ll BASE = 131;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        vector<string> substrings;
        for (int i = 0; i < s.length(); i++) {
            substrings.pb(s.substr(i, s.length() - i));
        }
        sort(substrings.begin(), substrings.end());
        int cnt = substrings[0].length() + 1;
        for (int i = 1; i < s.length(); i++) {
            int longest = min(substrings[i].length(), substrings[i - 1].length());
            for (int j = 0; j < longest; j++) {
                if (substrings[i][j] != substrings[i - 1][j]) {
                    longest = j;
                    break;
                }
            }
            cnt += substrings[i].length() - longest;
        }
        cout << cnt /*+ 1 */ << endl;
    }
}


