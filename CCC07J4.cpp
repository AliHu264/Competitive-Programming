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

int cnt1[26],cnt2[26];
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s; getline(cin,s);
    string s2; getline(cin,s2);

    s.erase(remove(s.begin(),s.end(),' '),s.end());
    s2.erase(remove(s2.begin(),s2.end(),' '),s2.end());

    for(char c:s){
        cnt1[c-'A']++;
    }
    for(char c:s2){
        cnt2[c-'A']++;
    }

    for(int i=0;i<26;i++){
        if(cnt1[i]!=cnt2[i]){
            cout << "Is not an anagram." << endl;
            return 0;
        }
    }
    cout << "Is an anagram." << endl;
}