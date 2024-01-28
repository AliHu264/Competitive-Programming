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


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    string s;
    getline(cin, s);
    while(n--){
        getline(cin,s);
        int lindex = 0, cnt = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == ' '){
                cnt=0;
                lindex = i+1;
                continue;
            }
            cnt++;
            if(cnt==4 && (s[lindex+4] == ' '||s[lindex+4] == '\0')){
                for(int j=lindex;j<lindex+4;j++){
                    s[j] = '*';
                }
            }
        }
        cout << s << endl;
    }
}