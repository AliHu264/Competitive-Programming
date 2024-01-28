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
const int MAXN = 1e5 + 1; // TODO change this for each problem
const ll MOD = 1e9 + 7;
const ll BASE = 131;
const int INF = 0x3f3f3f3f;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

int n, m;
vector<string> A, B;
vector<int> ans;
string s;

bool recurse(int k, string a, string b) {
    if (a == b && a.size()) {
        return true;
    }
    if (k == m - 1) {
        return false;
    }
    for (int i = 0; i < A.size(); i++) {
        if (recurse(k + 1, a + A[i], b + B[i])) {
            ans.pb(i);
            return true;
        }
    }
    return false;
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> m >> n;
    int n2 = n;
    while (n--) {
        cin >> s;
        A.pb(s);
    }
    while (n2--) {
        cin >> s;
        B.pb(s);
    }
    if (recurse(0, "", "")) {
        cout << ans.size() << endl;
        for (int i = ans.size() - 1; i >= 0; i--) {//in reverse since it's solved recursively
            cout << ans[i]+1 << endl;
        }
    }
    else {
        cout << "No solution." << endl;
    }

}