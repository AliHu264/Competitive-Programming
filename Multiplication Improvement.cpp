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

string operator*(const string &s, unsigned int n) {
    stringstream out;
    while (n--)
        out << s;
    return out.str();
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<ll> arr;
    ll product = 1;
    string s; cin >> s;

    string str;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == 'x')
        {
            arr.push_back(stoll(str));
            str = "";
        }
        else
            str += s[i];
    }
    arr.push_back(stoll(str));

    sort(arr.begin(),arr.end());
    for(int i = 0; i < arr.size()-1; i++){
        cout << arr[i] << "x";
    }
    cout << arr[arr.size()-1] << endl;

    for(auto a:arr){
        product*=a;
    }
    cout << product;
}