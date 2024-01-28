#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int MAXN = 1e6 + 5; // TODO change this for each problem
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll BASE = 131;
const int INF = 0x3f3f3f3f;
ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}

string operator*(const string &s, unsigned int n) {
    stringstream out;
    while (n--)
        out << s;
    return out.str();
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s; getline(cin,s);
    istringstream iss (s);
    string n;
    iss >> n;
    int ncount = 0;
    while (n == "not"){
        ncount++;
        iss >> n;
    }
    iss >> n;
    ncount = ncount%2;
    ncount += (n == "False" ? 0:1);
    cout << (ncount%2 ? "True": "False");
}