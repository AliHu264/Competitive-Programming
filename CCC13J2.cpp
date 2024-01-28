#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    bool flag = true;
    for (char i:str) {
        if (i == 'I' || i == 'O' || i == 'S' || i == 'H' || i == 'Z' || i == 'X' || i == 'N') {
            continue;
        }
        else flag = false; break;
    }
    if (flag){
        cout << "YES";
    }
    else cout << "NO";
}