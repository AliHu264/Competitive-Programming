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

map<string, string> dict;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    while (n--) {
        string a, b;
        cin >> a >> b;
        dict.insert(mp(a, b));
    }
    string binary;
    cin >> binary;
    string ans = "";
    while (binary.length()) {
        for (auto &p:dict) {
            if (binary.find(p.second) == 0) {
                ans += p.first;
                binary = binary.substr(p.second.length());
            }
        }
    }
    cout << ans << endl;
}