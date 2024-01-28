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
const int MAXN = 100000; // TODO change this for each problem
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


ll money[2][101];

int main() {
    ll N, M, X, Y, b, s;
    scanf("%lld %lld", &N, &M);

    fill_n(money[0], 101, -1e15);
    money[0][0] = 0;

    while(N--) {
        scanf("%lld %lld %lld %lld", &X, &Y, &b, &s);

        copy_n(money[0], 101, money[1]);

        for(ll count = 1; count <= 5; count++) {
            for(ll sell = 1; sell <= min(Y, count); sell++) {
                money[1][count - sell] = max(money[1][count - sell], money[0][count] + sell * s);
            }
        }

        copy_n(money[1], 101, money[0]);

        for(ll count = 0; count < 5; count++) {
            for(ll buy = 1; buy <= min(5 - count, X); buy++) {
                money[1][count + buy] = max(money[1][count + buy], money[0][count] - buy * b);
            }
        }

        copy_n(money[1], 101, money[0]);

        for(ll count = 1; count <= 100; count++)
            money[0][count] -= M * count;

//		for(int i = 0; i < 101; i++)
//			cout << money[0][i] << " ";
//		cout << endl;
    }

    printf("%lld", money[0][0]);
}