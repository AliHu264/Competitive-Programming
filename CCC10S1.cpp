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


struct computer {
    string name;
    int R, S, D;

    computer(string &name, int R, int S, int D) {
        this->name = name;
        this->R = R;
        this->S = S;
        this->D = D;
    }
    int value() const{
        return R*2+S*3+D;
    }
};

bool cmp(const computer& a,const computer& b){
    return a.value() > b.value();
}

vector<computer> v;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    if(!n){
        return 0;
    }
    while (n--) {
        string n;
        int R,S,D;
        cin >> n >> R >> S >> D;
        v.eb(computer(n,R,S,D));
    }
    sort(v.begin(),v.end(),cmp);
    if(v.size()==1){
        cout << v[0].name << endl;
        return 0;
    }

    if(v[0].value()==v[1].value()){
        if(v[0].name.compare(v[1].name)>0){
            cout << v[1].name << endl;
            cout << v[0].name << endl;
            return 0;
        }
    }

    cout << v[0].name << endl;
    cout << v[1].name << endl;
}