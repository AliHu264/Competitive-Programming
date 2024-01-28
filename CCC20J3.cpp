#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    string firstInt, secondInt;

    int comma;

    vector<int> X;
    vector<int> Y;
    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
        auto it = input.find(',');

        firstInt = input.substr(0, it);
        secondInt = input.substr(it + 1, input.size());

        int x = stoi(firstInt), y = stoi(secondInt);
        X.push_back(x);
        Y.push_back(y);
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    cout << X[0] - 1 << "," << Y[0] - 1 << "\n";

    cout << X[X.size() - 1] + 1 << "," << Y[Y.size() - 1] + 1;
}