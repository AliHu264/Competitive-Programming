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

vector<int> adj[26];

bool bfs(int st, int dest);
set<pair<int,int>> Set;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    while (true) {
        string input;
        cin >> input;
        if (input == "**") break;
        int a = (input[0] - 'A');
        int b = (input[1] - 'A');
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int cnt = 0;
    for (int i = 0; i < 26; i++) {
        for (int j:adj[i]) {
            pair<int,int> temp = {i,j};
            pair<int,int> temp2 = {j,i};

            if(Set.find(temp)!=Set.end()||Set.find(temp2)!=Set.end())continue;

            int remem1 = i, remem2 = j;
            adj[i].erase(find(adj[i].begin(), adj[i].end(), j));
            adj[j].erase(find(adj[j].begin(), adj[j].end(), i));
            if (!bfs(0, 1)) {
                cnt++;
                char a = i + 'A', b = j + 'A';
                cout << a << b << endl;
            }
            adj[i].pb(remem2);
            adj[j].pb(remem1);
            Set.insert(mp(i,j));
            Set.insert(mp(j,i));
        }
    }
    cout << "There are " << cnt << " disconnecting roads." << endl;
}

bool bfs(int st, int dest) {
    queue<int> q;
    q.push(st);
    bool vis[27]{false};
    vis[st] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int n:adj[cur]) {
            if (!vis[n]) {
                q.push(n);
            }
        }
        vis[cur] = true;
    }
    return vis[dest];
}