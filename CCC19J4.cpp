#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    int grid[2][2];

    grid[0][0] = 1; grid[1][0] = 3; grid[0][1] = 2;grid[1][1]=4;

    string in; cin >> in;
    for(int i=0;i<in.size();i++){
        if(in[i]=='H'){
            swap(grid[0][0],grid[1][0]);
            swap(grid[0][1],grid[1][1]);
        }
        else{
            swap(grid[0][0],grid[0][1]);
            swap(grid[1][0],grid[1][1]);
        }
    }

    for (int i = 0; i < 2; ++i) {
        cout<< grid[0][i] << " ";
    }
    cout << endl;
    for(int j=0; j<2 ; j++){
        cout<<grid[1][j] << " ";
    }
    cout << endl;
}
