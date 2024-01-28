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
const int MAXN = 1e5 + 1; // TODO change this for each problem
const ll MOD = 1e9 + 7;
const ll BASE = 131;
const int INF = 0x3f3f3f3f;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

bool find(int mag, int x, int y) {
    if(!mag){
        return false;
    }
    int p = pow(5,mag-1);
    int px = x/p, py = y/p;
    x%=p; y%=p;
    if(px && px != 4 && !py)// zero indexed: (1,0),(2,0),(3,0)
        return true;
    else if(px == 2 && py == 1) //(2,1)
        return true;
    else if ((px == 1 || px == 3) && py == 1)// (check in (1,1), (3,1)
        return find(mag-1,x,y);
    else if(px == 2 && py == 2){// check in (2,2)
        return find(mag-1,x,y);
    }
    return false;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int q, x, y, m;
    cin >> q;
    while (q--) {
        cin >> m >> x >> y;
        cout << (find(m, x, y)? "crystal":"empty") << endl;
    }
}