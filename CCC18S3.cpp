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
const int MAXN = 100002; // TODO change this for each problem
const ll MOD = pow(2, 31);
const ll BASE = 131;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

int r, c, rr, cc;

vector<vector<char>> arr(101, vector<char>(101));
bool camSees[101][101];
vector<pair<int, int>> cams;
int dis[101][101];

bool isConv(int r, int c) {
    return (arr[r][c] == 'L' || arr[r][c] == 'R' || arr[r][c] == 'U' || arr[r][c] == 'D');
}

bool valid(int r, int c) {
    return (!camSees[r][c] && arr[r][c] != 'W') || isConv(r, c);
}

vector<pair<int, int>> makeAdj(int i, int j) {
    return {{i + 1, j},
            {i - 1, j},
            {i,     j + 1},
            {i,     j - 1}};
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'S') {
                rr = i, cc = j;
            }
            if (arr[i][j] == 'C') {
                cams.eb(mp(i, j));
            }
        }
    }
    for (auto &cam:cams) {
        for (int left = cam.ss - 1; left > 0; left--) {
            if (arr[cam.ff][left] == 'W') {
                break;
            } else if (!isConv(cam.ff, left)) {
                camSees[cam.ff][left] = true;
            }
        }
        for (int right = cam.ss + 1; right < c; right++) {
            if (arr[cam.ff][right] == 'W') {
                break;
            } else if (!isConv(cam.ff, right)) {
                camSees[cam.ff][right] = true;
            }
        }
        for (int down = cam.ff + 1; down < r; down++) {
            if (arr[down][cam.ss] == 'W') {
                break;
            } else if (!isConv(down, cam.ss)) {
                camSees[down][cam.ss] = true;
            }
        }
        for (int up = cam.ff - 1; up > 0; up--) {
            if (arr[up][cam.ss] == 'W') {
                break;
            } else if (!isConv(up, cam.ss)) {
                camSees[up][cam.ss] = true;
            }
        }
    }
    queue<pair<int, int>> q;
    q.push(mp(rr, cc));
    fill(&dis[0][0], &dis[100][101], INT_MAX);

    if (!camSees[rr][cc]) {//checks if robot immediately spawns in front of camera
        while (!q.empty()) {
            dis[rr][cc] = 0;
            pair<int, int> cur = q.front(), next;
            q.pop();
            switch (arr[cur.ff][cur.ss]) {
                case 'U':
                    next = mp(cur.ff - 1, cur.ss);
                    break;
                case 'D':
                    next = mp(cur.ff + 1, cur.ss);
                    break;
                case 'L':
                    next = mp(cur.ff, cur.ss - 1);
                    break;
                case 'R':
                    next = mp(cur.ff, cur.ss + 1);
                    break;
                default:
                    for (auto &p:makeAdj(cur.ff, cur.ss)) {
                        if (valid(p.ff, p.ss) && dis[p.ff][p.ss] > dis[cur.ff][cur.ss] + 1) {
                            dis[p.ff][p.ss] = dis[cur.ff][cur.ss] + 1;
                            q.push(mp(p.ff, p.ss));
                        }
                    }
                    goto skipConv;
            }
            if (valid(next.ff, next.ss) && dis[next.ff][next.ss] > dis[cur.ff][cur.ss]) {
                dis[next.ff][next.ss] = dis[cur.ff][cur.ss];
                q.push(next);
            }
            skipConv:;
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] == '.') {
                cout << (dis[i][j] == INT_MAX ? -1 : dis[i][j]) << endl;
            }
        }
    }

}