#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int L; cin >> L;

    for(int i=0;i<L;i++){
        int times; string symbol;
        cin >> times >> symbol;
        for(int i=0;i<times;i++){
            cout<<symbol;
        }
        cout << "\n";
    }
}