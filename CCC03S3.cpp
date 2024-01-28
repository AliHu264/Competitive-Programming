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
const int MAXN = 1e6 + 2; // TODO change this for each problem
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

int grid[26][26];
int n, r, c;

vector<int> areas;

int dfs(int r2, int c2) {
    if (r2 < 0 || r2 >= r || c2 < 0 || c2 >= c) return 0;

    if(!grid[r2][c2]) return 0;

    grid[r2][c2] = 0;

    return dfs(r2 + 1, c2) + dfs(r2 - 1, c2) + dfs(r2, c2 + 1) + dfs(r2, c2 - 1) + 1;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n >> r >> c;

    for (int i = 0; i < r; i++) {
        string in;
        cin >> in;
        for (int j = 0; j < c; j++) {
            if (in[j] == '.') {
                grid[i][j] = 1;
            }
        }
    }
    int total = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 1) {
                int cur = dfs(i, j);
                total += cur;
                areas.push_back(cur);
            }
        }
    }
    sort(areas.begin(),areas.end(),[] (int a, int b){
        return a>b;
    });
    int roomCount = 0;

    while(true){
        if (n < areas[roomCount]||roomCount==areas.size()){
            if (roomCount == 1)
                cout << roomCount << " room, " << n << " square metre(s) left over" << endl;
            else
                cout << roomCount << " rooms, " << n << " square metre(s) left over" << endl;
            return 0;
        }
        roomCount++;
        n -= areas[roomCount - 1];
    }
}

