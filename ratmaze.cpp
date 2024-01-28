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

int n;
int grid[502][502];
bool vis[502][502];

bool dfs(int r, int c) {
    if (r == n && c == n) return true;
    if(grid[r][c]==1||vis[r][c]){
        return false;
    }
    vis[r][c] = true;

    bool left = dfs(r,c+1);
    bool right = dfs(r,c-1);
    bool down = dfs(r-1,c);
    bool up = dfs(r+1,c);

    return (left || right || down || up);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;

    for (int i = 0; i < n+1; i++) {
        grid[0][i] = 1;
        grid[n+1][i] = 1;
    }
    for (int i = 0; i < n+1; i++) {
        grid[i][0] = 1;
        grid[i][n+1] = 1;
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            cin >> grid[i][j];
        }
    }
    if (dfs(1, 1))
        cout << "yes" << endl;
    else cout << "no" << endl;

}