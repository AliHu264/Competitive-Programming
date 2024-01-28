#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>

#define endl '\n'
using namespace std;

bool visited[4];
vector<int> adj[4];


bool dfs(int n, int parent) {


    visited[n] = true;
    for (int j:adj[n]) {
        if (visited[j]) {
            if (j == parent) continue;
            else return false;
        } else {
            if (!dfs(j, n))
                return false;
        }
    }
    return true;
}

bool check() {
    int count = 0;
    for (bool i : visited) {
        if (i) {
            count++;
        }
    }

    return count == 4;
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    fill(visited, visited + 4, false);
    //// (vector<int> i: adj) also works
    for (auto &i : adj) {
        for (int j = 0; j < 4; j++) {
            int input;
            cin >> input;
            if (input == 1) {
                i.push_back(j);
            }
        }
    }


    if (!dfs(0, -1)) {
        cout << "No";
    } else if (!check()) {
        cout << "No";
    } else cout << "Yes";

////     figuring out how to use range based loops to iterate an array of vectors
//        for (auto & i : adj) {
//            for (int j:i) {
//            cout << j << " ";
//        }
}