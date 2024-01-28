#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    int quarters, firstM, secondM, thirdM;
    cin >> quarters >> firstM >> secondM >> thirdM;

    int played=0;
    while(quarters){
        if(quarters==0) break;
        firstM++; quarters--; played++;
        if(firstM==35){
            quarters+=30;
            firstM=0;
        }

        if(quarters==0) break;
        secondM++; quarters--;played++;
        if(secondM==100){
            quarters+=60;
            secondM=0;
        }

        if(quarters==0) break;
        thirdM++;quarters--;played++;
        if(thirdM==10){
            quarters+=9;
            thirdM=0;
        }
        if(quarters==0) break;
    }
    cout<<"Martha plays "<<played<<" times before going broke.";

}