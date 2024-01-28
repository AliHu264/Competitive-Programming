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

vector<pair<string, string>> v;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    string direct = "", dest = "";
    while (dest != "SCHOOL") {
        cin >> direct;
        cin >> dest;
        v.eb(mp(direct, dest));
    }
    int ptr = v.size() - 1;
    while (ptr != -1) {
        string direction = (v[ptr].first == "R" ? "LEFT" : "RIGHT");
        string destination;
        if (ptr == 0) {
            destination = "HOME";
            cout << "Turn " << direction << " into your " << destination << "." << endl;
            return 0;
        }
        destination = v[ptr-1].second;
        cout << "Turn " << direction << " onto " << destination << " street." << endl;
        ptr--;
    }

}