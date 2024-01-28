#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        char symbol;
        int count = 1;

        for (int j=0; j < S.size(); j++) {
            symbol = S[j];
            if (S[j + 1] == S[j]) {
                count++;
            } else {
                cout << count << " " << symbol << " ";
                count = 1;
            }
        }
        cout<< "\n";

    }
}







