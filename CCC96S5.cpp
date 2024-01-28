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
#define f first
#define s second
#define pb push_back
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


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q; cin >> q;
    while (q) {
        int length;
        cin >> length;
        int arr[length], arr2[length];
        for(int &a:arr){
            cin >> a;
        }
        for(int &a:arr2){
            cin >> a;
        }
        int dis = 0;
        for(int i=0;i<length;i++){
            int low = 0, high = length-1, mid = 0;
            while(low<=high){
                mid = (low+high)/2;
                if(arr2[mid]>=arr[i])
                    low = mid+1;
                else
                    high = mid-1;
            }
            mid = (low+high)/2;
            dis = max(dis,mid-i);
        }
        cout << "The maximum distance is " << dis << endl;
        q--;
    }

}