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
const int MAXN = 4*100000+1; // TODO change this for each problem
const ll MOD = 1e9 + 7;
const ll BASE = 131;
const int INF = 0x3f3f3f3f;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

struct Node {
    int min,gcd,cnt;
};

Node segTree[400001];
int arr[100001];

Node merge(const Node L, const Node R) {
    int minimum = min(L.min, R.min);
    int gcd = __gcd(L.gcd, R.gcd);
    int cnt = (L.gcd == gcd) * L.cnt + (R.gcd == gcd) * R.cnt;
    return {minimum, gcd, cnt};
}

Node build(int i, int l, int r) {
    if (l == r) {
        return segTree[i] = {arr[l], arr[l], 1};
    }
    int mid = (l + r) / 2;
    return segTree[i] = merge(build(i*2,l,mid),build(i*2+1,mid+1,r));
}

Node Query(int i, int l, int r, int ql, int qr){
    if(l>qr||r<ql) return {INT_MAX,0,0};
    if(l>=ql&&r<=qr) return segTree[i];
    int mid = (l+r)/2;
    return merge(Query(i*2,l,mid,ql,qr),Query(i*2+1,mid+1,r,ql,qr));
}

Node update(int i, int l, int r, int node, int value) {
    if (l > node || r < node) return segTree[i];
    if (l == r)return segTree[i] = {value, value, 1};
    int mid = (l + r) / 2;
    return segTree[i] = merge(update(i*2,l,mid,node,value),update(i*2+1,mid+1,r,node,value));
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    build(1,1,n);
    char query;
    int a, b;
    while (q--) {
        cin >> query >> a >> b;
        switch (query) {
            case 'C':
                update(1,1,n,a,b);
                break;
            case 'M':
                cout << Query(1,1,n,a,b).min << endl;
                break;
            case 'G':
                cout << Query(1,1,n,a,b).gcd << endl;
                break;
            default:
                cout << Query(1,1,n,a,b).cnt << endl;
                break;
        }

    }


}