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
const int MAXN = 100004; // TODO change this for each problem
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

vector<pair<int, int>> makeAdj(int i, int j) {
    return {{i + 1, j},
            {i - 1, j},
            {i,j + 1},
            {i,j - 1}};
}

int tally = 1;

void solve(int a, int b) {
    cout << "Case #" << tally++ << ": ";
    bool one = a > 0;
    bool two = b > 0;
    a = abs(a);
    b = abs(b);
    if ((a & 1) == (b & 1)) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    string out = "";
    bool prevFlip = false;
    while (a != 0 || b != 0) {
        //check for evens while either side hasn't seen a 0
        int check = 0;
        int comp = 1;
        if ((a & 1) == 1) {
            if ((a > 1 || b > 1) && (a & 2) == (b & 2)) {
                out += (one) ? "W" : "E";
                a++;
            } else {
                out += (one) ? "E" : "W";
                a--;
            }
        } else if ((b & 1) == 1) {
            if ((a > 1 || b > 1) && (a & 2) == (b & 2)) {
                out += (two) ? "S" : "N";
                b++;
            } else {

                out += (two) ? "N" : "S";
                b--;
            }
        }
        a >>= 1;
        b >>= 1;
    }
    cout << out << endl;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int t = 0; t < n; t++) {
        ll a, b;
        cin >> a >> b;
        solve(a, b);
    }
}