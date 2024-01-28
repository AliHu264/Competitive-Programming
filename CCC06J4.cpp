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

vector<int> adj[9];
int indegree[9];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    adj[1].pb(7);
    adj[1].pb(4);
    adj[2].pb(1);
    adj[3].pb(4);
    adj[3].pb(5);
    indegree[7]++;
    indegree[4] = 2;
    indegree[1]++;
    indegree[5]++;

    while (true) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        indegree[b]++;
        if (!a || !b)
            break;
    }
    int ind = 0;
    int precedence[8];
    for (int p=0;p<7;p++) {
        for (int i = 1; i < 8; i++) {
            if (indegree[i] == 0) {
                precedence[ind++] = i;
                indegree[i] = -1;//so it doesn't check it more than once
                for (int j:adj[i]) {
                    indegree[j]--;
                }
                adj[i].erase(adj[i].begin(), adj[i].end());
                break;
            }
        }
    }
    if(ind<7){
        cout << "Cannot complete these tasks. Going to bed.";
    } else {
        for(int i=0;i<7;i++){
            cout << precedence[i] << " ";
        }
    }
}