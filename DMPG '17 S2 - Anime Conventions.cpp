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

int ranks[MAXN];
int djs[MAXN];

int findRoot(int a) {
    if (djs[a] != a) {
        djs[a] = findRoot(djs[a]);
    }
    return djs[a];
}

void merge(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);
    if (ranks[a] < ranks[b]) {
        djs[a] = b;
    } else if (ranks[a] > ranks[b]) {
        djs[b] = a;
    } else {
        djs[a] = b;
        ranks[b]++;
    }
}

void check(int a, int b) {
    if (findRoot(a) == findRoot(b)) {
        cout << "Y" << endl;
    } else {
        cout << "N" << endl;
    }
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    iota(&djs[0], &djs[MAXN], 0);
    int n, q;
    cin >> n >> q;
    while (q--) {
        char query;
        int a, b;
        cin >> query >> a >> b;
        query == 'A' ? merge(a, b) : check(a, b);
    }
}