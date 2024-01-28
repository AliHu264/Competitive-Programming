#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <tuple>
using namespace std;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    vector<string> Permutations;
    string T, S;
    cin >> T >> S;

    for (int i = 0; i < S.size(); i++) {
        Permutations.push_back(S);
        string endstr = S.substr(S.size() - 1, S.size());
        S.erase(S.size() - 1);
        S.insert(0, endstr);
    }

    for (string i:Permutations) {
        auto found = T.find(i);
        if (found != std::string::npos) {
            cout << "yes";
            return 0;
        }
    }
    cout << "no";
}