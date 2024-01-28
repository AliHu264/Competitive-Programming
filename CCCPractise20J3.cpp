#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>

using namespace std;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    int Acid [N];
    int mode [1001];
    for(int i=0;i<1001;i++){
        mode[i] = 0;
    }

    for(int i=0;i<N;i++){
        cin >> Acid[i];
        mode[Acid[i]]++;
    }


    int largest, SecondLargest;
    largest = 0; SecondLargest = 0;

    for(int i = 1;i<1001; i++)
    {
        if(mode[largest] < mode[i] || mode[largest] == mode[i])
            largest = i;
    }
    mode[largest] = 0;

    for (int i = 1; i < 1001; ++i){
        if(mode[SecondLargest]<mode[i])
            SecondLargest = i;
        if(mode[SecondLargest]==mode[i] && abs(largest-i)>abs(largest-SecondLargest))
            SecondLargest = i;
    }

    cout << abs(largest - SecondLargest);
}