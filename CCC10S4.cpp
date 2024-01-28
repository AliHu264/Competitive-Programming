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
const int MAXN = 100000; // TODO change this for each problem
const ll MOD = 1e9 + 7;
const ll BASE = 131;
const int INF = 0x3f3f3f3f;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

int disjoint[102];

int disjointF(int n){
    if(disjoint[n]!= n) disjoint[n] = disjointF(disjoint[n]);
    return disjoint[n];
}

void merge(int a, int b){
    disjoint[disjointF(a)] = disjointF(b);
}

struct edge {// node, dest, weight
    int a, b, w;
    edge(int a, int b, int w) {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

struct Wall {
    int node, cost;

    Wall(int node, int cost) {
        this->node = node;
        this->cost = cost;
    }
};

vector<edge> edges;
map<pair<int, int>, Wall> Map;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    for (int i = 0; i < 102; i++)
        disjoint[i] = i;
    int m, n;
    cin >> m;

    set<pair<int, int>> s;
    for (int i = 0; i < m; i++) {
        cin >> n;
        int walls[n + 1];
        for (int j = 0; j < n; j++) {
            cin >> walls[j];
        }
        for (int j = 0; j < n; j++) {
            int w;
            cin >> w;
            pair<int, int> p;

            if (j == n - 1) {//last input
                p = mp(max(walls[j], walls[0]), min(walls[j], walls[0]));
            } else
                p = mp(max(walls[j], walls[j + 1]), min(walls[j], walls[j + 1]));
            auto ifOutWall = s.find(p);
            if (ifOutWall == s.end()) {//if it hasn't been mentioned
                Map.insert(mp(p, Wall(i + 1, w)));
                s.insert(p);
            } else {// if its mentioned twice
                auto k = Map.find(p);
                int wallCost = (*k).second.cost, wallNode = (*k).second.node;
                edges.eb(edge(i + 1, wallNode, wallCost));
                edges.eb(edge(wallNode, i + 1, wallCost));
                s.erase(ifOutWall);//erase it since it doesn't connect out
            }
        }
    }
    sort(edges.begin(),edges.end(),[] (edge a, edge b){
        return a.w<b.w;
    });

    int MST = 0, MST2 = 0;
    for(auto e: edges){
        if(disjointF(e.a)!=disjointF(e.b)){
            merge(e.a,e.b);
            MST+=e.w;
        }
    }

    for(int i=0;i<102;i++){
        disjoint[i] = i;
    }

    for(auto p:s){
        auto k = Map.find(p);
        int cost = (*k).second.cost, node = (*k).second.node;
        edges.eb(node,0,cost);
        edges.eb(0,node,cost);
    }
    sort(edges.begin(),edges.end(),[] (edge a, edge b){
        return a.w<b.w;
    });
    for(auto e: edges){
        if(disjointF(e.a)!=disjointF(e.b)){
            merge(e.a,e.b);
            MST2+=e.w;
        }
    }
    cout << min(MST,MST2);
}
