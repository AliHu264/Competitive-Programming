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
const ll MOD = pow(2, 31);
const ll BASE = 131;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

/// N = 5, representing how many elements are in the array
int arr[5] = {1, 3, -2, 8, -7};

/// t is the segtree array that will be used to store precomputed results
/// to handle the worst case complexity, the size of t should be 4 times the size of the input array
int t[5 * 4];

/// build function to initialize the segtree at the start
/// parameters are: input array, current index value (which is always 1 when calling build), left boundary (0), right boundary (N-1)
void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

//// sum function to calculate the sum of a subarray, such as the sum of arr[l....r] with l and r being the respective left and right boundaries of the query
/// the algorithm takes O(logN) time to calculate the sum
int sum(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v * 2, tl, tm, l, min(r, tm))
      + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

//// update function to update an element in the array and subsequently the segtree precomputed results in O(logN) time
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    build(arr, 1, 0, 4);
    update(1,0,4,4,100);
    cout << sum(1, 0, 4, 2, 4);
}