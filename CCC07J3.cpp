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
    int arr[10] = {100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000};
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        arr[x - 1] = 0;
    }
    int a;
    double avg = 0, cnt = 0;
    cin >> a;

    for (auto i:arr) {
        cnt++;
        avg += i;
        if (!i) {
            cnt--;
        }
    }
    if (avg / cnt < a) {
        cout << "deal";
    } else cout << "no deal";

}