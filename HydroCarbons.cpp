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
const ll MOD = 1e9 + 7;
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
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int carbons = a+b+c+1;
    int hydrogens = d;

    if(!b&&a<c-1){//if there isn't enough single bonds since a must be at least c-1
        cout << "invalid" << endl;
        return 0;
    }
    if(b&&a<c){//if double bonds exist, that means there needs to be an extra single bond to bridge the gap for a double bond to bond with a carbon
        //obviously, double bonds cannot bond with triple bonds, so their only other choice is single bonds; hydrogen single bonds dont count because they can't be used to
        //build on more bonds, but single and double bonds can build on one another so there just needs to be one single covalent carbon bond that is equal to the number of triple bonds
        cout << "invalid" << endl;
        return 0;
    }
    int curtotal = 2*a+4*b+6*c;
    int required = 4*carbons-curtotal;

    if(required!=d){
        cout << "invalid" << endl;
    }
    else {
        cout << "C" << carbons << "H" << hydrogens << endl;
    }

}