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

string operator*(const string &s, int n) {
    stringstream out;
    while (n > 0) {
        n--;
        out << s;
    }
    return out.str();
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        if(!n){
            cout << "0000" << endl;
            continue;
        }
        string s;
        bitset<32> output(n);
        bool check = false;
        for (int i = 31; i >= 0; i--) {
            if (output[i]) {
                check = true;
                s += to_string(output[i]);
            } else {
                if (check) {
                    s +=to_string(output[i]);
                }
            }
        }
        int rem = s.size() % 4;
        if (rem) {
            for (int i = 0; i < 4 - rem; i++) {
                s = '0'+s;
            }
        }
        for(int i=0;i<s.size();i++){
            if((i)%4==0&&i){
                cout << " ";
            }
            cout << s[i];
        }
        cout << endl;
    }
}