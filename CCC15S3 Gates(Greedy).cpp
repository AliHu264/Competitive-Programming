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
const int MAXN = 1e6 + 2; // TODO change this for each problem
const ll MOD = 3e6 + 1;
const ll BASE = 131;

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

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int g, p;
    cin >> g >> p;
    set<int> s;
    for (int i = 1; i <= g; i++) {
        s.insert(-i);
    }
    int gateNum, ans = 0;
    while (p--) {
        cin >> gateNum;
        auto val = s.lower_bound(-gateNum);
        if (val == s.end()) {
            cout << ans << endl;
            return 0;
        }
        ans++;
        s.erase(val);
    }
    cout << ans << endl;

}

