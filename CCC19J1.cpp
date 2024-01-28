#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){

    cin.sync_with_stdio(0);
    cin.tie(0);

    int A3,A2,A1,B3,B2,B1;
    cin >> A3 >> A2 >> A1 >> B3 >> B2 >> B1;
    if(A3*3+A2*2+A1 < B3*3+B2*2+B1){
        cout<< "B";
    }
    else if(A3*3+A2*2+A1 > B3*3+B2*2+B1){
    cout<<"A";}
    else cout << "T";
}