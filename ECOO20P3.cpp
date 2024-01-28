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
        int m;
        cin >> m;
        while (m--) {
            int w, h;
            cin >> w >> h;
            bool grid[w][h];
            pair<int, int> smaller = {1000, 1000};
            pair<int, int> bigger = {-1, -1};
            for (int i = 0; i < w; i++) {
                string next;
                cin >> next;
                for (int j = 0; j < h; j++) {
                    grid[i][j] = next[j] == '*';
                    if (grid[i][j]) {
                        smaller = {min(smaller.first, i), min(smaller.second, j)};
                        bigger = {max(bigger.first, i), max(bigger.second, j)};
                    }
                }
            }

            //hard coded logic
            if (smaller.second == bigger.second) {
                cout << "1";
            } else if (grid[smaller.first][smaller.second] && grid[smaller.first][bigger.second]) {
                cout << "4";
            } else if (grid[bigger.first][bigger.second]) {
                cout << "7";
            } else if (!grid[(smaller.first + bigger.first) / 2][bigger.second - 1]) {
                cout << "0";
            } else {
                bool pres[4];
                pres[0] = grid[smaller.first + 1][smaller.second];
                pres[1] = grid[smaller.first + 1][bigger.second];
                pres[2] = grid[bigger.first - 1][smaller.second];
                pres[3] = grid[bigger.first - 1][bigger.second];
                if (pres[0] && pres[1] && pres[2] && pres[3]) {
                    cout << "8";
                } else if (pres[0] && pres[1] && pres[3]) {
                    cout << "9";
                } else if (pres[0] && pres[2] && pres[3]) {
                    cout << "6";
                } else if (pres[0] && pres[3]) {
                    cout << "5";
                } else if (pres[1] && pres[3]) {
                    cout << "3";
                } else {
                    cout << "2";
                }
            }
        }
        cout << "\n";
    }
}

