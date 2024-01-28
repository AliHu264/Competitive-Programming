#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int MAXN = 1e6 + 5; // TODO change this for each problem
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9 + 7;
const ll BASE = 131;
const int INF = 0x3f3f3f3f;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

string operator*(const string &s, unsigned int n) {
    stringstream out;
    while (n--)
        out << s;
    return out.str();
}

vector<int> adj[10002];
bool vis[10002];
bool cycle = false;

void dfs(int start, int end) {
    if (vis[start]) return;
    if (start == end) {
        cycle = true;
        return;
    }
    vis[start] = true;
    for (int i:adj[start]) {
        dfs(i, end);
    }
}

int main() {

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if (find(adj[a].begin(), adj[a].end(), b) == adj[a].end())
            adj[a].pb(b);
    }
    for (int i = 1; i <= N; i++) {
        memset(vis, false, sizeof(vis));
        cycle = false;
        for (int y:adj[i]) {
            dfs(y, i);
        }
        if (cycle) break;
    }
    cout << (cycle ? "N" : "Y");
}
