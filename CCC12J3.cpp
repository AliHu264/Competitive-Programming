#include <iostream>
using namespace std;

int main() {

    int N;
    cin >> N;
    string star = ("*");
    string x = ("x");

////    upper  screen
    for (int i = 0; i < N; i++) {
        for (int i = 0; i < N; i++)
            cout << star;
        for (int i = 0; i < N; i++)
            cout << x;
        for (int i = 0; i < N; i++)
            cout << star;
            cout << endl;
    }
////    middle screen
    for (int i = 0; i < N; i++) {
        for (int i = 0; i < N; i++)
            cout << " ";
        for (int i = 0; i < N; i++)
            cout << x;
        for (int i = 0; i < N; i++)
            cout << x;
        cout<< endl;
    }
////    bottom screen
    for (int i = 0; i < N; i++) {
        for (int i = 0; i < N; i++)
            cout<< star;
        for (int i = 0; i < N; i++)
            cout<< " ";
        for (int i = 0; i < N; i++)
            cout<< star;
        cout<<endl;
    }
    }
