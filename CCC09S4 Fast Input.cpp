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
const int MAXN = 5002; // TODO change this for each problem
const ll MOD = pow(2, 31);
const ll BASE = 131;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

struct edge {
    int node, weight;

    edge(int n, int w) {
        node = n;
        weight = w;
    }

    bool operator<(const edge &e) const {
        return e.weight < weight;
    }
};

struct SortSecond {
    bool operator()(pair<int, int> n1, pair<int, int> n2) {
        return n1.second > n2.second;
    }
};

int n, t, k, d, ans = INT_MAX;
int dis[MAXN], pencil[MAXN], cost[MAXN];
vector<edge> matrix[MAXN];
priority_queue<pair<int, int>, vector<pair<int, int>>, SortSecond> pq;
bool vis[MAXN];

void dijk() {
    fill(&dis[0], &dis[5002], INT_MAX);
    pq.push(mp(d, 0));
    dis[d] = 0;
    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        if(vis[cur.ff]){
            continue;
        }
        vis[cur.ff] = true;
        for (edge e:matrix[cur.ff]) {
            if (dis[e.node] > e.weight + cur.ss) {
                dis[e.node] = e.weight + cur.ss;
                pq.push(mp(e.node,dis[e.node]));
            }
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    scan(n); scan(t);
    int a, b, c;
    while (t--) {
        scan(a);scan(b);scan(c);
        matrix[a].eb(edge(b, c));
        matrix[b].eb(edge(a, c));
    }
    scan(k);
    for (int i = 0; i < k; i++) {
        scan(a);scan(b);
        pencil[i] = a;
        cost[i] = b;
    }
    scan(d);
    dijk();
    for (int i = 0; i < k; ++i)
        ans = min(ans, dis[pencil[i]] + cost[i]);
    cout << ans << endl;
}