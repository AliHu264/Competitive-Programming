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
const int MAXN = 100004; // TODO change this for each problem
const ll MOD = 3e6 + 1;
const ll BASE = 131;
const int INF = 0x3f3f3f3f;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

string operator*(const string &s, int n) {
    stringstream out;
    while (n > 0) {
        n--;
        out << s;
    }
    return out.str();
}

struct edge {
    int a, b, w;
    bool old;
};

vector<edge> edges;
vector<int> djset(MAXN);

int find(int n) {
    if (djset[n] != n) djset[n] = find(djset[n]);
    return djset[n];
}

bool merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    djset[find(a)] = find(b);
    return true;
}


int main() {
    iota(djset.begin(), djset.end(), 0);
    int n, m, d, a, b, w, days = 0, ecnt = 0, me = 0;
    cin >> n >> m >> d;
    edges.resize(m);
    for (int e = 0; e < m; e++) {
        cin >> a >> b >> w;
        edges[e] = {a, b, w, e + 1 < n};
    }
    sort(edges.begin(), edges.end(), [](edge &a, edge &b) {
        return (a.w < b.w) || (a.w == b.w && a.old);
        });
    for (auto &e : edges) {
        if (merge(e.a, e.b)) {
            ecnt++;
            me = e.w;
            if (!e.old) days++;
            if (ecnt == n - 1) {
                if (e.old) {
                    cout << days;
                    return 0;
                }
                break;
            }
        }
    }
    iota(djset.begin(), djset.end(), 0);
    for (auto &e :edges) {
        if (find(e.a) != find(e.b)) {
            if (e.w < me || (e.w == me && e.old))
                merge(e.a, e.b);
            else if (e.old && e.w <= d) {
                cout << days - 1;
                return 0;
            }
        }
    }
    cout << days;
}