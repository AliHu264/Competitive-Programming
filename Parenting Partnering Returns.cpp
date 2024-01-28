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

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    for (int loop = 1; loop <= t; loop++) {
        cout << "Case #" << loop << ": ";
        int n;
        cin >> n;
        pair<int, pair<int, int>> chores[n]; //<start time, <endtime, index>>
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            chores[i] = {a, {b, i}};
        }
        sort(&chores[0], &chores[n]);
        char output[n];
        int left = 0, right = 0;
        bool success = 1;
        for (int i = 0; i < n; i++) {
            if (left <= chores[i].first) {
                left = chores[i].second.first;
                output[chores[i].second.second] = 'C';
            } else if (right <= chores[i].first) {
                right = chores[i].second.first;
                output[chores[i].second.second] = 'J';
            } else {
                cout << "IMPOSSIBLE" << endl;
                success = 0;
                break;
            }
        }
        if (success) {
            for (int i = 0; i < n; i++) {
                cout << output[i];
            }
            cout << endl;
        }
    }