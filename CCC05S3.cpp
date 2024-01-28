#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>

using namespace std;
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 1e5 + 1; // TODO change this for each problem
const ll MOD = 1e9 + 7;
const ll BASE = 131;
const int INF = 0x3f3f3f3f;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

using matrix = vector<vector<int>>;

matrix multiply(matrix &a, matrix &b) {
    matrix ret;
    ret.resize(a.size() * b.size(), vector<int>(a[0].size() * b[0].size()));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            for (int k = 0; k < b.size(); k++) {
                for (int l = 0; l < b[0].size(); l++) {
                    ret[i*b.size()+k][j*b[0].size()+l] = a[i][j]*b[k][l];
                }
            }
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int r, c;
    cin >> r >> c;
    matrix M(r, vector<int>(c));

    for (auto &v: M) {
        for (auto &i: v) {
            cin >> i;
        }
    }
    n--;
    while (n--) {
        cin >> r >> c;
        matrix M2(r, vector<int>(c));
        for (auto &v: M2) {
            for (auto &i: v) {
                cin >> i;
            }
        }
        M = multiply(M, M2);
    }
    int maxr = INT_MIN; int minr = INT_MAX;
    int maxc = INT_MIN; int minc = INT_MAX;
    int maximum = INT_MIN; int minimum = INT_MAX;

    for (auto &v: M) {
        int sum = 0;
        for (auto &i:v) {
            sum += i;
            maximum = max(maximum, i);
            minimum = min(minimum, i);
        }
        maxr = max(maxr, sum);
        minr = min(minr, sum);
    }
    for (int i = 0; i < M[0].size(); i++) {
        int sum = 0;
        for (int j = 0; j < M.size(); j++) {
            sum += M[j][i];
        }
        maxc = max(maxc, sum);
        minc = min(minc, sum);
    }

    cout << maximum << endl << minimum << endl;
    cout << maxr << endl << minr << endl;
    cout << maxc << endl << minc << endl;
}