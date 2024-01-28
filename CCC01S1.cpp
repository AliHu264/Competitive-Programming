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
const int MAXN = 1e5 + 2; // TODO change this for each problem
const ll MOD = pow(2, 32);
const ll BASE = 131;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

struct suit {
    vector<char> contains;
    int points = 0;
};

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    suit suits[4];
    int cur = -1;
    for (char i : s) {
        if (i == 'D' || i == 'H' || i == 'S' || i == 'C') {
            cur++;
            continue;
        }
        suits[cur].contains.push_back(i);
        if (isdigit(i) || i == 'T') {
            continue;
        } else {
            suits[cur].points += i == 'A' ? 4 : i == 'K' ? 3 : i == 'Q' ? 2 : 1;
        }
    }
    for (suit &su:suits) {
        su.points += su.contains.empty() ? 3 : su.contains.size() == 1 ? 2 : su.contains.size() == 2 ? 1 : 0;
    }
    int total = 0;
    cout << "Cards Dealt              Points" << endl;
    for (int i = 0; i < 4; i++) {
        if (i == 0)
            cout << "Clubs ";
        else if (i == 1)
            cout << "Diamonds ";
        else if (i == 2)
            cout << "Hearts ";
        else cout << "Spades ";
        for (char c:suits[i].contains) {
            cout << c << " ";
        }
        total += suits[i].points;
        cout << "              " << suits[i].points << endl;
    }
    cout << "                    Total " << total << endl;
}


