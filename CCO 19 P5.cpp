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

vector<pair<int, int>> makeAdj(int i, int j) {
    return {{i + 1, j},
            {i - 1, j},
            {i,j + 1},
            {i,j - 1}};
}

set<int> * graph;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n,k;cin>>n>>k;
    graph = new set<int>[n];
    for(int i=0;i<k;i++){
        int from, to; cin>>from>>to;
        graph[min(from,to)].insert(max(from,to));

    }
    ll tally = 0;
    for(int i=0;i<n;i++){
        tally += graph[i].size();
        if(graph[i].size()==0)continue;
        int next=*graph[i].begin();
        graph[i].erase(graph[i].begin());
        if(graph[i].size()>graph[next].size())swap(graph[i], graph[next]);
        for(int nextNode: graph[i]){
            graph[next].insert(nextNode);
        }
    }
    cout<<tally<<endl;
}