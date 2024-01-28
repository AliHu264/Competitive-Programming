#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>

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
const ll BASE2 = 239;
const int INF = 0x3f3f3f3f;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

struct hash1 {
    vector <ll> h, p;
    hash1(string s) {
        int n = (int) s.size();
        h.resize(n); p.resize(n);
        h[0] = s[0];
        p[0] = 1;
        for (int i = 1; i < n; i++) {
            h[i] = (h[i - 1] * BASE + s[i]) % MOD;
            p[i] = (p[i - 1] * BASE) % MOD;
        }
    }
    int get_hash(int l, int r) {
        if (!l) return h[r];
        else {
            int ret = h[r] - (h[l - 1]%MOD * p[r - l + 1]%MOD) % MOD;
            if (ret < 0) ret += MOD;
            return ret;
        }
    }
};

struct hash2 {
    vector <ll> h, p;
    hash2(string s) {
        int n = (int) s.size();
        h.resize(n), p.resize(n);
        h[0] = s[0];
        p[0] = 1;
        for (int i = 1; i < n; i++) {
            h[i] = (h[i - 1] * BASE2 + s[i]) % MOD;
            p[i] = (p[i - 1] * BASE2) % MOD;
        }
    }
    int get_hash(int l, int r) {
        if (!l) return h[r];
        else {
            int ret = h[r] - (h[l - 1]%MOD * p[r - l + 1]%MOD) % MOD;
            if (ret < 0) ret += MOD;
            return ret;
        }
    }
};

mt19937_64 rnd(228);

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    vector<int> r(26);
    for (int i = 0; i < 26; i++)
        r[i] = rnd();
    string s, t;
    cin >> s >> t;
    int m = s.size();
    int n = t.size();
    if(m>n){
        cout << 0 << endl;
        return 0;
    };
    ll nval = 0;
    ll curval = 0;
    for (int i = 0; i < m; i++) {
        nval += r[s[i] - 'a'];
    }
    for (int i = 0; i < m && i < n; i++)
        curval += r[t[i] - 'a'];
    hash1 h(t);
    hash2 g(t);
    set<pair<int, int>> ans;
    for (int i = 0; i+m-1 < n;i++){
        if(nval==curval){
            ans.insert({h.get_hash(i,i+m-1),g.get_hash(i,i+m-1)});
        }
        curval-=r[t[i]-'a'];
        curval += r[t[i + m] - 'a'];
    }
    cout << ans.size() << endl;
}