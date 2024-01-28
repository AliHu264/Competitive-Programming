#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>

using namespace std;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);


    int n; cin >> n;
    int countL = n;
    int countR = 0;

    int count = 0;
    for(int i=0;i<n;i++){
        if(countR-countL==1||countR-countL==2) {
            break;
        }


        if(countL>5||countR-countL==1||countR-countL==2){
            countL--;
            countR++;
            continue;
        }
        else {
            countL--;
            countR++;
            count++;
        }
    }

    cout << count;








}