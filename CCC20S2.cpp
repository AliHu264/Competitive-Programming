#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <unordered_map>
#include <unordered_set>

#define mkp make_pair
typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAXN = 1e6 + 5; // TODO change this for each problem
const ll BASE = 131;
#define endl '\n'
using namespace std;

string operator*(const string &s, unsigned int n) {
    stringstream out;
    while (n--)
        out << s;
    return out.str();
}

int grid[1000][1000];
bool vis[1000][1000];
unordered_map <int, vector<pair<int,int>>> graph;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int M, N;
    cin >> M >> N;

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> grid[i-1][j-1];
            graph[i*j].emplace_back(mkp(i,j));
        }
    }

    queue<pair<int,int>> q;
    vis[0][0] = true;
    q.push(mkp(1,1));
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        int gridCur = grid[cur.first-1][cur.second-1];
        for(auto & v:graph[gridCur]){
            if(!vis[v.first-1][v.second-1]){
                vis[v.first-1][v.second-1] = true;
                q.push(mkp(v.first,v.second));
            }
        }
    }
    if (vis[M-1][N-1]){
        cout << "yes";
    }
    else cout << "no";
}