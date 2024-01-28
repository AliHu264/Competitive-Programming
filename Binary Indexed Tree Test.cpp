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
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 1e5 + 1; // TODO change this for each problem
const ll MOD = 1e9 + 7;
const ll BASE = 131;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

int n, m, a, b;
char q;

struct bit {
    ll arr[MAXN];

    ll sum(int i) {
        ll ret = 0;
        for (; i > 0; i -= i & -i)
            ret += arr[i];
        return ret;
    }

    void add(int i, int k) {
        for (; i < MAXN; i += i & -i) {
            arr[i] += k;
        }
    }
};

struct Totaltree {
    bit a, cnt;
    int currVal[MAXN];

    void build(int i, int k) {
        a.add(i, k);
        currVal[i] = k;
        cnt.add(k, 1);
    }

    void update(int i, int k) {
        a.add(i, -currVal[i]);
        cnt.add(currVal[i], -1);
        cnt.add(k, 1);
        currVal[i] = k;
        a.add(i, k);
    }

    ll sum(int l, int r) {
        return a.sum(r) - a.sum(l - 1);
    }

    ll cntSum(int v) {
        return cnt.sum(v);
    }

};

Totaltree totaltree;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> a;
        totaltree.build(i, a);
    }
    while (m--) {
        cin >> q;
        if (q == 'C') {
            cin >> a >> b;
            totaltree.update(a, b);
        } else if (q == 'S') {
            cin >> a >> b;
            cout << totaltree.sum(a, b) << endl;
        } else if (q == 'Q') {
            cin >> a;
            cout << totaltree.cntSum(a) << endl;
        }
    }

}
