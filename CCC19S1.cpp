#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <unordered_map>
#include <unordered_set>

#define mkp make_pair
typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAXN = 1e6 + 5; // TODO change this for each problem
const ll BASE = 131;
#define endl '\n'
using namespace std;

string operator*(const string &s, unsigned int n) {
    stringstream out;
    while (n--)
        out << s;
    return out.str();
}
int grid[3][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    grid[1][1] = 1;
    grid[1][2] = 2;
    grid[2][1] = 3;
    grid[2][2] = 4;

    string s;
    cin >> s;
    int tH, tV;

    for(char c:s){
        if (c == 'H'){
            tH++;
        }
        else tV++;
    }
    tH = tH%2;
    tV = tV%2;

    if(tV == 1){
        swap(grid[1][1],grid[1][2]);
        swap(grid[2][1],grid[2][2]);
    }
    if(tH == 1){
        swap(grid[1][1],grid[2][1]);
        swap(grid[1][2],grid[2][2]);
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(j==0||i==0){
                continue;
            }
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

}