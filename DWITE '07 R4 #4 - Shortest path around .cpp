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

vector<pair<int,int>> makeAdj(int i, int j) {
    return {{i + 1, j}, {i - 1, j}, {i, j + 1}, {i, j - 1}};
}
char arr[10][10];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int q = 5;
    while (q--) {
        memset(arr, '.', sizeof arr);
        bool start = false;
        int endi, endj;
        queue<pair<int, int>> q;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                cin >> arr[i][j];
                if (arr[i][j] == 'X') {
                    if (start) {
                        endi = i;
                        endj = j;
                    } else {
                        q.push(mp(i, j));
                        start = true;
                    }
                }
            }
        }
        int dis = 0;
        while (!q.empty()) {
            bool found = false;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> cur = q.front();
                q.pop();
                if (cur.first < 0 || cur.second < 0 || cur.first >= 10 || cur.second >= 10 ||
                    arr[cur.first][cur.second] == '#') {
                    continue;
                }
                arr[cur.first][cur.second] = '#';
                if (cur.first == endi && cur.second == endj) {
                    cout << dis << endl;
                    found = true;
                    break;
                }

                q.push({cur.first + 1, cur.second});
                q.push({cur.first + 1, cur.second + 1});
                q.push({cur.first + 1, cur.second - 1});
                q.push({cur.first - 1, cur.second});
                q.push({cur.first - 1, cur.second + 1});
                q.push({cur.first - 1, cur.second - 1});
                q.push({cur.first, cur.second + 1});
                q.push({cur.first, cur.second - 1});
            }
            if(found){
                break;
            }
            dis++;
        }
        string sep; cin >> sep;
    }
}