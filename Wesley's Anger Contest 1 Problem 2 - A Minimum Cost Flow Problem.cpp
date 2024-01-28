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
const ll MOD = pow(2, 31);
const ll BASE = 131;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

vector<int> ranks(MAXN), djs(MAXN);

int findRoot(int a) {
    if (djs[a] != a) djs[a] = findRoot(djs[a]);
    return djs[a];
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

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    iota(djs.begin(), djs.end(), 0);

    int n, m, k, a, b;
    cin >> n >> m >> k;

    int movable = 0;
    while (m--) {
        cin >> a >> b;
        if (findRoot(a) == findRoot(b)) {
            movable++;
        } else {
            merge(a, b);
        }
    }
    set<int> sets;
    for (int i = 1; i <= n; i++) {
        sets.insert(findRoot(i));
    }
    int pipes = sets.size() - 1;
    cout << max(0, pipes - min(k, movable)) << endl;
}