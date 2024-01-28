#include <iostream>
using namespace std;

int main() {

    int N;
    cin >> N;

    string Y; string T;
    cin >> Y >> T;

    int space = 0;

    for(int i=0; i<N;i++){
            if(Y[i] == 'C' && T[i] == 'C')
            space ++;
    }
    cout << space;


}