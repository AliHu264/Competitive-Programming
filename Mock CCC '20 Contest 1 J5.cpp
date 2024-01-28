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
const ll MOD = 3e6 + 1;
const ll BASE = 131;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

bool isPrime(ll n) {
    if (n == 1) return false;
    int sqr = sqrt(n);
    for (int i = 2; i < sqr + 1; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int nextPrime(ll n) {
    while (!isPrime(n)) {
        n++;
    }
    return n;
}

ll po[14];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int d, n;
    cin >> d >> n;
    po[0] = 1;
    for (int i = 1; i < 15; i++) {
        po[i] = po[i - 1] * 10;
    }
    string Nstring = to_string(n);
    int lowestPrime = nextPrime(po[d - 1]);
    int ans = INT_MAX;

    if(d>Nstring.length()){
        cout << lowestPrime << lowestPrime << endl;
        return 0;
    }

    for (int i = 0; i + d <= Nstring.length(); i++) {
        ll prefix = i ? stoll(Nstring.substr(0, i)) : 0;
        ll suffix = 0;
        if (i < d) {
            prefix = lowestPrime;
            suffix = nextPrime(po[Nstring.length() - i - 1]);
        } else if (isPrime(prefix)) {
            suffix = stoll(Nstring.substr(i, Nstring.length() - i));
            suffix = max((ll)suffix, po[Nstring.length() - i - 1]);
            suffix = nextPrime(suffix);
            ans = min((ll)ans, stoll(to_string(prefix) + to_string(suffix)));
            prefix++;
        }
        if (i >= d) {
            prefix = nextPrime(prefix);
            suffix = nextPrime(po[Nstring.length() - i - 1]);
        }
        ans = min((ll)ans, stoll(to_string(prefix) + to_string(suffix)));
    }
    cout << ans << endl;
}
