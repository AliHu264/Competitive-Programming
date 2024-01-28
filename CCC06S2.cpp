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

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    string text, pair, cipher;
    map<char, char> key;
    getline(cin, text);
    getline(cin, pair);
    getline(cin, cipher);

    for (int i = 0; i < text.size(); i++) {
        if (key.find(pair[i]) == key.end()) {
            key.insert(mp(pair[i],text[i]));
        }
    }
    for(int i=0;i<cipher.size();i++){
        if (key.find(cipher[i]) != key.end()) {
            cipher[i] = key[cipher[i]];
        } else cipher [i] = '.';
    }
    cout << cipher << endl;
}