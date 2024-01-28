#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int garden[N][N];
    int prevGarden[N][N];
    int corners[4];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> garden[i][j];
            prevGarden[i][j] = garden[i][j];
        }
    }

    corners[0] = garden[0][0];
    corners[1] = garden[0][N - 1];
    corners[2] = garden[N - 1][0];
    corners[3] = garden[N - 1][N - 1];
    sort(corners, corners + sizeof(corners) / sizeof(corners[0]));

    while (garden[0][0] != corners[0]) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                garden[i][j] = prevGarden[j][N - 1 - i];
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                prevGarden[i][j] = garden[i][j];
            }
        }

        }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << garden[i][j] << " ";
        }
        cout << "\n";
    }
}