#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>

using namespace std;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    int N[4];
    for(int i=0;i<4;i++){
        cin >> N[i];
    }
    if(N[0] == 8 || N[0] == 9)
        if(N[3] == 9 || N[3] ==8){
            if(N[1]==N[2]){
            cout << "ignore";
            return 0;
        }
    }

    cout << "answer";

}