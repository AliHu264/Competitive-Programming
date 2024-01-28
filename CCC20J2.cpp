#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    int P = 0, Nstart = 0, Rate = 0, day = 0;
    cin >> P >> Nstart >> Rate;

    int NstartO = Nstart;

    while (NstartO < P) {
        Nstart *= Rate;
        NstartO += Nstart;
        day++;
    }
    cout << day;


}