#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int a, b, c, d;

    cin >> a >> b >> c >> d;
    int D[5][5];


    D[0][0] = 0;
    D[1][0] = a;
    D[2][0] = a + b;
    D[3][0] = D[2][0] + c;
    D[4][0] = D[3][0] + d;
    D[0][1] = a;
    D[0][2] = a + b;
    D[0][3] = D[0][2] + c;
    D[0][4] = D[0][3] + d;

    for (int i = 0; i <= 4; i++) {
        for (int j = 0; j <= 4; j++)
            D[i][j] = abs(D[i][0] - D[0][j]);
    }

    for (int i = 0; i <= 4; i++) {
        int a;
        for (int j = 0; j <= 3; j++){
            cout << D[i][j] << " ";
            a = j;
        } cout << D[i][a+1];

        cout << endl;
    }
}

