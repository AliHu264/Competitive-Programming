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

vector<int> adj[100001];
int ranks [100001];
int n,m;

vector<int> djs(100001);

int findRoot(int a){
    if(djs[a]!= a) djs[a] = findRoot(djs[a]);
    return djs[a];
}

void merge(int v1, int v2){
    v1 = findRoot(v1);
    v2 = findRoot(v2);

    if(ranks[v1] < ranks[v2]){
        djs[v1] = v2;
    }
    else if(ranks[v1] > ranks[v2]){
        djs[v2] = v1;
    }
    else{
        djs[v2] = v1;
        ranks[v1]++;
    }
}
bool same(int a, int b){
    return findRoot(a)==findRoot(b);
}

vector<int> mst;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    iota(djs.begin(), djs.end(), 0);
    cin >> n >> m;
    memset(ranks,1,n);
    int edgeCnt = 0;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;

        if(!same(a,b)){
            mst.pb(i+1);
            merge(a,b);
            edgeCnt++;
        }
    }
    if(edgeCnt>=n-1){
        for(int a:mst){
            cout << a << endl;
        }
    }
    else cout << "Disconnected Graph" << endl;
}