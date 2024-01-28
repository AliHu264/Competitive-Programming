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
const int MAXN = 500002; // TODO change this for each problem
const ll MOD = pow(2, 32);
const ll BASE = 131;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
gp_hash_table<int, bool> ht[MAXN];

int n, m, k, a, b;
queue<pair<int, int>> q;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    while (k--) {
        cin >> a >> b;
        ht[a][b] = true;
    }
    for (int i = 0; i < m; i++) {
        if (ht[1][i]) q.emplace(1, i), ht[1][i] = false;
    }
    for (int i = 0; i < n; i++) {
        if (ht[i][m]) q.emplace(i, m), ht[i][m] = false;
    }
    while (q.size()) {
        tie(a, b) = q.front();
        q.pop();
        if (a == n || b == 1) {
            cout << "NO" << endl;
            return 0;
        }
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if(ht[a+i][b+j]){
                    q.emplace(a+i,b+j);
                    ht[a+i][b+j]=false;
                }
            }
        }
    }
    cout << "YES" << endl;
}