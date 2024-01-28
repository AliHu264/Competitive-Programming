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

int n;
int diff[21];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    int first, second;
    while (n) {
        cin >> first;
        if (n == 1) {
            cout << 0 << endl;
        } else {
            for (int i = 1; i < n; i++) {
                cin >> second;
                diff[i] = second - first;
                first = second;
            }
            int length = 1;
            while (true) {
                int curindex = 1;
                while (curindex + length < n && diff[curindex] == diff[curindex + length]) {
                    curindex++;
                }
                if (curindex + length >= n) {
                    break;
                }
                length++;
            }
            cout << length << endl;
            memset(diff, 0, sizeof diff);
        }
        cin >> n;
    }
}

