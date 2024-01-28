#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

int main() {

    cin.tie(0);
    cin.sync_with_stdio(0);

    int totaldist, Clubnum;
    cin >> totaldist >> Clubnum;

    int val[Clubnum];
    int DP[totaldist + 1];

    fill_n(DP, totaldist + 1, INT_MAX);

    DP[0] = 0;

    for (int i = 0; i < Clubnum; i++) {
        cin >> val[i];
    }

    for (int i = 0; i < Clubnum; i++) {
        for (int j = 0; j < totaldist; j++) {
            if (DP[j] != INT_MAX && val[i] + j <= totaldist && DP[j + val[i]] > DP[j] + 1) {
                DP[j + val[i]] = DP[j] + 1;
            }

        }
    }
    if (DP[totaldist] == INT_MAX) {
        cout << "Roberta acknowledges defeat.";
    } else
        cout << "Roberta wins in " << DP[totaldist] << " strokes.";

}
