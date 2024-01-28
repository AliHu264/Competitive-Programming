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

bool vis[9][9];

vector<pair<int, int>> makeAdj(int i, int j) {
    return {{i + 2, j + 1},
            {i + 2, j - 1},
            {i + 1, j + 2},
            {i + 1, j - 2},
            {i - 2, j + 1},
            {i - 2, j - 1},
            {i - 1, j + 2},
            {i - 1, j - 2}};
}

int bfs(pair<int,int> st, pair<int,int> end) {
    if(st == end){
        return 0;
    }
   int dis = 0;
   queue<pair<int,int>> q;
   q.push(st);
   while(!q.empty()){
       int size = q.size();
       for(int i=0;i<size;i++){
           pair<int,int> cur = q.front();
           q.pop();
           if (cur.ff < 1 || cur.ss < 1 || cur.ff > 8 || cur.ss > 8){
               continue;
           }
           for(auto &p:makeAdj(cur.ff,cur.ss)){
               if(!vis[p.ff][p.ss]){
                   vis[p.ff][p.ss] = true;
                   q.push(mp(p.ff,p.ss));
               }
           }
       }
       dis++;
       if(vis[end.ff][end.ss]){
           return dis;
       }
   }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans  = bfs(mp(a,b),mp(c,d));
    cout << ans << endl;
}