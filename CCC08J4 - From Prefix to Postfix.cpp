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
const int MAXN = 100004; // TODO change this for each problem
const ll MOD = 3e6 + 1;
const ll BASE = 131;

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

vector<pair<int, int>> makeAdj(int i, int j) {
    return {{i + 1, j},
            {i - 1, j},
            {i,     j + 1},
            {i,     j - 1}};
}

bool isOperator(string &s) {
    return (s == "+" || s == "-");
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    string s;
    getline(cin, s);
    while (s != "0") {
        vector<string> v;
        deque<string> dq;
        istringstream iss(s);
        string w;
        while (iss >> w) {
            v.push_back(w);
        }
        reverse(v.begin(), v.end());
        string ans = "";
        int i = 0;
        while (i < v.size()) {
            if (!isOperator(v[i])) {
                dq.push_front(v[i]);
            }
            else {
                string s1 = dq.front(); dq.pop_front();
                string s2 = dq.front(); dq.pop_front();
                ans = s1 + " " + s2 + " " + v[i];
                dq.push_front(ans);
            }
            i++;
        }
        cout << ans << endl;
        getline(cin,s);
    }

}