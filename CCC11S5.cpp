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

int lights[26];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> lights[i];
    }
    bool complete = false;
    int lindex = 0, rindex = 0;
    int tally = 0;
    while (!complete) {
        int lcnt = 0, rcnt = 0;
        for (int i = 0; i < k; i++) {
            if (i == k - 1) {
                lcnt = 999999;
                break;
            }
            if (lights[i]) {
                lcnt++;
                if (!lights[i + 1]) {
                    lindex = i + 1;
                    break;
                }
            }
        }
        if (lcnt == 0) {
            lcnt = 999999;
        }
        for (int i = k - 1; i > -1; i--) {
            if (i == 0) {
                rcnt = 999999;
                break;
            }
            if (lights[i]) {
                rcnt++;
                if (!lights[i - 1]) {
                    rindex = i - 1;
                    break;
                }
            }
        }
        if (rcnt == 0) {
            rcnt = 999999;
        }
        if (lcnt <= rcnt) {
            lights[lindex] = true;
        } else lights[rindex] = true;
        tally++;
        for (int i = 6; i >= 3; i--) {
            for (int j = 0; j < k - i; j++) {
                for (int n = 0; n <= i; n++) {
                    if (!lights[n + j]) {
                        goto skip;
                    }
                }
                for (int p = j; p <= j + i; p++) {
                    lights[p] = false;
                }
                skip:;
            }
        }
        complete = true;
        for (int i = 0; i < k; i++) {
            if (lights[i]) {
                complete = false;
                break;
            }
        }
    }
    cout << tally << endl;
}