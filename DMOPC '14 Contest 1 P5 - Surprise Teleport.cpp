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

char grid[1001][1001];
set<int> teleDistance;

vector<pair<int, int>> makeAdj(int i, int j) {
    return {{i + 1, j},
            {i - 1, j},
            {i,     j + 1},
            {i,     j - 1}};
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int r, c, rr, cc, endr, endc;
    cin >> r >> c >> rr >> cc >> endr >> endc;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        grid[a][b] = 'T';
    }
    grid[endr][endc] = 'F';

    queue<pair<int, int>> q;
    q.push(mp(rr, cc));
    int dis = 0;
    int office = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            pair<int, int> cur = q.front();
            q.pop();
            switch (grid[cur.ff][cur.ss]) {
                case 'X':
                    goto skipAdj;
                case 'T':
                    teleDistance.insert(dis);
                    break;
                case 'F':
                    office = dis;
                    break;
                default:
                    break;
            }
            grid[cur.ff][cur.ss] = 'X';
            for (auto &p:makeAdj(cur.ff, cur.ss)) {
                if (p.ff >= r || p.ss >= c || p.ff < 0 || p.ss < 0)
                    continue;
                q.push(p);
            }
            skipAdj:;
        }
        dis++;
    }
    if (teleDistance.empty()) {
        cout << 0;
        return 0;
    }
    cout << max(0, office - (*teleDistance.begin()));
}