#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    int S, M , L;
    cin >> S >> M >> L;

    if(S+M*2+L*3>=10){
        cout << "happy";
    }
    else cout << "sad";

}