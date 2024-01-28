#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#define mkp make_pair

#define endl '\n'
using namespace std;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    int starcount = 1;
    int spacecount = 0;
    if(n%2!=0) {
        spacecount = (n - 1) * 2;
    }
    else spacecount = (n-2)*2;

    for (int i = 0; i < n; ++i) {
        if(i+1<=ceil(n/2.0)){
            string spaces(spacecount,' ');
            string stars(starcount,'*');
            cout << stars << spaces << stars;
            starcount+=2;
            spacecount-=4;
            if(i+1==ceil(n/2.0)){
                starcount-=2;
                spacecount+=4;
            }
        }
        else if(i+1>ceil(n/2.0)){
            starcount-=2;
            spacecount+=4;
            if(ceil(n/2.0)==floor(n/2.0)&&i+1==ceil(n/2.0)+1){//even
                starcount+=2;
                spacecount=0;
                string stars(starcount,'*');
                cout << stars << stars << endl;
                continue;
            }
            string spaces(spacecount,' ');
            string stars(starcount,'*');
            cout << stars << spaces << stars;
        }
        cout << endl;
    }

}