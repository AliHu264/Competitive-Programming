#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <unordered_map>
#include <unordered_set>

#define mkp make_pair
typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAXN = 1e6 + 5; // TODO change this for each problem
const ll BASE = 131;
#define endl '\n'
using namespace std;

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

    vector<pair<int, string>> v;

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        v.emplace_back(s.size(), s);
    }
    string w;
    cin >> w;

    int charReplaced = w.size();
    int diff = INT_MAX;

    for (auto x:v) {
        if ((signed)(charReplaced - x.second.size()) >= 0) {
            int curDiff = charReplaced - x.second.size();
            diff = min(diff, curDiff);
        }
    }
    for(auto x:v){
        if(x.first == charReplaced-diff){
            cout << x.second;
        }
    }
}