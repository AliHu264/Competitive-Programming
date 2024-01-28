#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>

using namespace std;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int SW[N];
    int SE[N];

    for (int i = 0; i < N; i++)
        cin >> SW[i];
    for (int i = 0; i < N; i++)
        cin >> SE[i];

    int K = 0;
    for(int i=0;i<sizeof(SW) / sizeof(SW[0]);i++) {
        if (i != 0) {
        SW[i] += SW[i - 1];
        SE[i] += SE[i - 1];
    }

        if (SW[i] == SE[i]){
            K = i+1;
        }
    }
    cout << K;

}