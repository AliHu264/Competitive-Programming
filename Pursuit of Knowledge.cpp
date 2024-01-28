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

vector<int> adj[1001];
int dis[1001][1001];
int n, m, t;

void bfs(int a) {
    bool vis[1001]{false};
    queue<int> q;
    q.push(a);
    int curDist = 0;
    vis[a]=true;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int cur = q.front();
            q.pop();
            dis[a][cur] = curDist;
            for (int v:adj[cur]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        curDist += t;
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> t;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    for (int i = 0; i <= n; i++) {
        bfs(i);
    }

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (dis[a][b]) {
            cout << dis[a][b] << endl;
        } else {
            cout << "Not enough hallways!" << endl;
        }
    }
}


