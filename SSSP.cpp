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

vector<pair<int, int>> adj[1001];
int dis[1001];

struct SortSecond {
    bool operator()(pair<int, int> n1, pair<int, int> n2) {
        return n1.second > n2.second;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, SortSecond> pq;


void dijk() {
    fill(&dis[0], &dis[1001], INT_MAX);
    pq.push({1, 0});
    dis[1] = 0;
    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        for (auto &p:adj[cur.ff]) {
            if (dis[p.ff] > cur.ss + p.ss) {
                dis[p.ff] = cur.ss + p.ss;
                pq.push({p.ff, dis[p.ff]});
            }
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, a, b, w;
    cin >> n >> m;
    while (m--) {
        cin >> a >> b >> w;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }
    dijk();
    for (int i = 1; i <= n; i++) {
        cout << (dis[i] == INT_MAX ? -1 : dis[i]) << endl;
    }

}