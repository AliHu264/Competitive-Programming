#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <iomanip>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int A, B, MAX;
    cin >> A >> B >> MAX;

    int arr[MAX];
    fill(arr, arr + MAX, 0);
    arr[0] = 1;

    for (int i = 0; i < MAX; i++) {
        if (arr[i] == 1) {
            if (i + A <= MAX) {
                arr[i + A] = 1;
            }
            if (i + B <= MAX) {
                arr[i + B] = 1;
            }
        }
    }
    for (int i = MAX-1; i >= 0; i--) {
        if (arr[i] == 1) {
            cout << i;
            break;
        }
    }
}