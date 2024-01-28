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
#define pb push_back
#define endl '\n'
const int MAXN = 1e6 + 5; // TODO change this for each problem
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll MOD = 998244353;
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

set<pair<int, int>> Set;
set<int> dupSet;
int freq[1000002];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    fill(freq, freq + 1000002, 0);

    for (int i = 0; i < N; i++) {
        freq[arr[i]]++;
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (arr[i] + arr[j] > 1000000)
                continue;
            if (freq[arr[i] + arr[j]]) {
                if(arr[i] == arr[j]){
                    dupSet.insert(arr[i]);
                    continue;
                }
                Set.insert(mp(arr[i], arr[j]));
                Set.insert(mp(arr[j], arr[i]));
            }
        }
    }
    ull size = Set.size()/2+dupSet.size();

    if (Set.empty() && dupSet.empty()) {
        cout << -1;
        return 0;
    }
    cout << size;
}
