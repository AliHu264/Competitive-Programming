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
const int MAXN = 3628802; // TODO change this for each problem
const ll MOD = 3e6 + 1;
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


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int q;
    cin >> q;

    while(q--){
        int n; cin>>n;
        deque<int> mountain;
        deque<int> branch;
        bool done = true;
        for(int i=0;i<n;i++){
            int next; cin>>next;
            //push it into the mountain
            mountain.push_back(next);
        }
        for(int i=1;i<=n;i++){

            if(!mountain.empty()&&mountain.back()==i){//mountain has the next val
                //pop mountain
                mountain.pop_back();
                // cout<<"top"<<endl;
            }
            else if(!branch.empty()&&branch.front()==i){//branch has the next val
                //pop branch
                branch.pop_front();
                // cout<<"side"<<endl;
            }
            else if(!mountain.empty()){//mountain still has elements
                //move mountain to branch
                branch.push_front(mountain.back());
                mountain.pop_back();
                // cout<<"switch"<<endl;
                i--;
            }
            else{
                done = false;
            }
        }
        cout<<"NY"[done]<<endl;
    }

}