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
#define pb push_back
#define endl '\n'
const int MAXN = 1e6 + 5; // TODO change this for each problem
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll BASE = 131;
const int INF = 0x3f3f3f3f;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

string operator*(const string &s, unsigned int n) {
    stringstream out;
    while (n--)
        out << s;
    return out.str();
}

vector<int> adj[101];

void connect(int a, int b) {
    adj[a].pb(b);
    adj[b].pb(a);
}

int shortest(int st, int des) {
    bool vis[101] = {false};
    int dis[101];
    fill(dis, dis + 100, INT_MAX);
    dis[st] = 0;
    queue<int> q;
    q.push(st);
    vis[st] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int v:adj[cur]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
                if (dis[cur] + 1 < dis[v])
                    dis[v] = dis[cur] + 1;
                if (vis[des])
                    return dis[des];
            }
        }
    }
    return -1;
}

int FofF(int st) {
    vector<int> vSet;
    vector<int> fSet;
    fSet.pb(st);

    for (int v:adj[st])
        fSet.pb(v);

    queue<int> q;
    q.push(fSet[0]);

    int FFcount = 0;
    int iter = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int v:adj[cur]) {
            if (find(fSet.begin(), fSet.end(), v) == fSet.end()
                && find(vSet.begin(), vSet.end(), v) == vSet.end()) {
                vSet.pb(v);
                FFcount++;
            }
        }
        if (iter < fSet.size()) {
            q.push(fSet[iter]);
            iter++;
        }
    }
    return FFcount;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    connect(2, 6);
    connect(1, 6);
    connect(3, 6);
    connect(4, 6);
    connect(5, 6);
    connect(7, 6);
    connect(3, 5);
    connect(3, 4);
    connect(4, 5);
    connect(7, 8);
    connect(8, 9);
    connect(9, 10);
    connect(10, 11);
    connect(11, 12);
    connect(12, 9);
    connect(12, 13);
    connect(13, 14);
    connect(13, 15);
    connect(15, 3);
    connect(16, 17);
    connect(17, 18);
    connect(16,18);

    while (true) {
        string s;
        cin >> s;
        if (s == "q") {
            break;
        } else if (s == "i") {// form friends
            int a, b;
            cin >> a >> b;
            if (find(adj[a].begin(), adj[a].end(), b) == adj[a].end()) {
                connect(a, b);
            }
        } else if (s == "d") {//disconnect friends
            int a, b;
            cin >> a >> b;
            if (find(adj[a].begin(), adj[a].end(), b) != adj[a].end()) {
                adj[a].erase(find(adj[a].begin(), adj[a].end(), b));
                adj[b].erase(find(adj[b].begin(), adj[b].end(), a));
            }
        } else if (s == "n") {
            int a, count = 0;
            cin >> a;
            for (int f:adj[a]) {
                count++;
            }
            cout << count << endl;
        } else if (s == "s") {
            int a, b;
            cin >> a >> b;
            int c = shortest(a, b);
            if (c != -1) {
                cout << c << endl;
            } else cout << "Not connected" << endl;
        } else {
            int a;
            cin >> a;
            cout << FofF(a) << endl;
        }

    }
}