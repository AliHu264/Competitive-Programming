#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>

#define endl '\n'


using namespace std;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    int input, curCell = 1;

    while (true) {
        cin >> input;
        if (input == 0) {
            cout << "You Quit!";
            break;
        } else if (curCell + input > 100) {
            input = 0;
        }
        curCell += input;

        //snakes and ladders
        if (curCell == 9)
            curCell = 34;
        else if (curCell == 40)
            curCell = 64;
        else if (curCell == 67)
            curCell = 86;
        else if (curCell == 54)
            curCell = 19;
        else if (curCell == 90)
            curCell = 48;
        else if (curCell == 99)
            curCell = 77;

        cout << "You are now on square " << curCell << endl;
        if (curCell == 100) {
            cout << "You Win!";
            break;
        }
    }
}