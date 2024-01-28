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

int tally[1000001], data[100000];
int main() {
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    int max;cin>>max;
    int diverse; cin>>diverse;

    for(int count=0;count<max;count++) {
        cin>>data[count];
    }
    int bot=0;
    int top=0;
    tally[data[bot]]++;

    int diverseNum=1;
    ll total=0;
    while(top<max) {

        if(diverseNum>=diverse) {
            total+=max-top;
            tally[data[bot]]--;
            if(tally[data[bot]]<=0) {
                diverseNum--;
            }
            bot++;
            if(bot>top) {
                top=bot;
                if(top==max) {
                    break;
                }
                if(tally[data[top]]==0) {
                    diverseNum++;
                }
                tally[data[top]]++;

            }
        }
        else {
            top++;
            if(top==max) {
                break;
            }
            if(tally[data[top]]==0) {
                diverseNum++;
            }
            tally[data[top]]++;
        }
    }
    cout<<total<<'\n';
}
