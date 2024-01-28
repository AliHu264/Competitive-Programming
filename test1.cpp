#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll BASE = 131;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    vector<int> a = {1,2,3,4};
    vector<int> b = {1,2,3};

    b = a;
    a[3] = 50;

    cout << b[3] << endl << a[3];







}