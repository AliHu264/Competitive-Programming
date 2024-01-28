#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    int m, n, c = 0;
    cin >> m >> n;


    for (; m <= n; m++) {
        string flip, sm = to_string(m);
        for (char i:sm) {

            if (i == '1' || i == '8' || i == '0') {
                flip = i + flip;
            } else if (i == '6') {
                flip = "9" + flip;
            } else if (i == '9') {
                flip = "6" + flip;
            }
        }


        if (flip == sm) {
            c++;
        }
    }
    cout << c;
    }
