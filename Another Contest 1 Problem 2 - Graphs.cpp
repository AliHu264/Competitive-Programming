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

vector<int> djs(100002);
vector<int> adj[100002];
int ranks[100002];

int findRoot(int a) {
    if (djs[a] == a) {
        return a;
    }
    return findRoot(djs[a]);
}

void merge(int v1, int v2) {
    v1 = findRoot(v1);
    v2 = findRoot(v2);

    if (ranks[v1] < ranks[v2]) {
        djs[v1] = v2;
    } else if (ranks[v1] > ranks[v2]) {
        djs[v2] = v1;
    } else {
        djs[v2] = v1;
        ranks[v1]++;
    }
}

bool same(int a, int b) {
    return findRoot(a) == findRoot(b);
}

int dis1[MAXN], dis2[MAXN];
int n, m, q;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    iota(djs.begin(), djs.end(), 0);
    cin >> n >> m >> q;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        merge(a, b);
    }

    while (q--) {
        cin >> a >> b;
        if (a == b) {
            cout << 0 << endl;
            continue;
        }

        if (!same(a, b)) {
            cout << -1 << endl;
            continue;
        }

        deque<pair<int, int>> dq;//node id, bfs id
        memset(dis1, -1, sizeof dis1);
        memset(dis2, -1, sizeof dis2);
        dis1[a] = 0;
        dis2[b] = 0;

        dq.eb(a, 0);
        dq.eb(b, 1);

        int meetAt = -1;

        while (!dq.empty()) {
            pair<int, int> cur = dq.front();
            dq.pop_front();

            bool found = false;

            for (int v:adj[cur.ff]) {
                if (cur.ss) {
                    if (dis2[v] != -1) {//second
                        continue;
                    }
                } else {// else first
                    if (dis1[v] != -1) {
                        continue;
                    }
                }

                if(cur.ss){ //second
                    dis2[v] = dis2[cur.ff] + 1;

                    if(dis1[v] != -1){
                        meetAt = v;
                        found = true;
                        break;
                    }
                }
                else{
                    dis1[v] = dis1[cur.ff] + 1;

                    if(dis2[v] != -1){
                        meetAt = v;
                        found = true;
                        break;
                    }
                }
                dq.eb(v,cur.ss);
            }
            if(found){
                break;
            }
        }
        cout << dis1[meetAt] + dis2[meetAt] << endl;
    }
}