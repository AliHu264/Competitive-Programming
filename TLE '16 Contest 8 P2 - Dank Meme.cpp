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
    stack<int> Stack;
    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        if(!n){
            cout << "meme" << endl;
            continue;
        }
        while(n!=1) {
            Stack.push(n % 2);
            n /= 2;
        }
        Stack.push(n%2);

        while(!Stack.empty()){
            int b = Stack.top();
            Stack.pop();
            cout << (b==1?"dank":"meme") << " ";
        }
        cout << endl;
    }



}