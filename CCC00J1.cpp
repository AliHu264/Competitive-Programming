#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int start, end;
    cin >> start >> end;
    int weekcount = start;

    cout << "Sun Mon Tue Wed Thr Fri Sat\n";

    for(int i=0;i<start-1;i++){
        cout << "    ";
    } start=1;
    while(start <= end){
        if(start<10){
            cout << "  " << start;
        }
        else{
            cout <<  " " << start;
        }

        if(weekcount<7 && start != end)
            cout << " ";

        else {cout << "\n";
            weekcount = 0;}

        start++;
        weekcount ++;
    }
}