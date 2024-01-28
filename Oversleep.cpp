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

vector<pair<int, int>> makeAdj(int i, int j) {
    return {{i + 1, j},
            {i - 1, j},
            {i,     j + 1},
            {i,     j - 1}};
}

int r, c;
char grid[1001][1001];

int bfs(pair<int, int> st, pair<int, int> end) {
    queue<pair<int, int>> q;
    int dis = 0;
    q.push(st);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            pair<int, int> cur = q.front();
            q.pop();
            if (cur.ff < 0 || cur.ss < 0 || cur.ff >= r || cur.ss >= c ||
                grid[cur.ff][cur.ss] == 'X') {
                continue;
            }
            grid[cur.ff][cur.ss] = 'X';

            if (cur.ff == end.ff && cur.ss == end.ss) {
                return dis-1;
            }
            for (auto &p:makeAdj(cur.ff, cur.ss)) {
                q.push(p);
            }
        }
        dis++;
    }
    return -1;
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> r >> c;
    pair<int, int> st, end;
    for (int i = 0; i < r; i++) {
        string in;
        cin >> in;
        for (int j = 0; j < c; j++) {
            grid[i][j] = in[j];
            if (grid[i][j] == 's') {
                st.ff = i;
                st.ss = j;
            } else if (grid[i][j] == 'e') {
                end.ff = i;
                end.ss = j;
            }
        }
    }
    cout << bfs(st, end) << endl;
}


