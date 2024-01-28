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

vector<int> adj[10000];

int bfs(int st, int end) {
    int deg = 0;
    queue<int> q;
    bool vis[10000]{false};
    q.push(st);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int cur = q.front();
            q.pop();
            if (cur == end) {
                return deg-1;
            }
            if (vis[cur]) {
                continue;
            }
            vis[cur] = true;
            for (int v:adj[cur]) {
                q.push(v);
            }
        }
        deg++;
    }
    return -1;
}


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    int a, b;
    cin >> a >> b;
    while (a) {
        int result = bfs(a,b);
        if(result<0){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << " " << result << endl;
        }
        cin >> a >> b;
    }


}