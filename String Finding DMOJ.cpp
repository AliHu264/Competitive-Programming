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
const ll MOD = pow(2, 32);
const ll BASE = 131;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

ll MODULUS = (ll) (827873739);
int length;
ll power = 1;

void init() {
    for (int i = 0; i < length; i++) {
        power = (power * 26) % MODULUS;
    }
}

ll createValue(string in) {
    ll start = 0;
    for (int i = 0; i < in.length(); i++) {
        start = (start * 26 + in[i] - 'a') % MODULUS;
    }
    return start;
}

ll roll(ll hash, char prev, char next) {
    hash = (hash * 26 + next - 'a') % MODULUS;
    hash = (hash + MODULUS - ((prev - 'a') * power) % MODULUS) % MODULUS;
    return hash;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    string a, b;
    cin >> a >> b;
    length = b.length();
    init();
    ll compare = createValue(b);
    ll start = createValue(a.substr(0, length));
    for (int i = 0; i + length < a.length(); i++) {
        // cout<<start<<" "<<compare<<endl;
        if (start == compare) {
            cout << i << "\n";
            return 0;
        }
        start = roll(start, a[i], a[i + length]);
    }
    if (start == compare) {
        cout << a.length() - length << "\n";
        return 0;
    }
    cout << "-1" << "\n";
}