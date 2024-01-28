#include <iostream>
using namespace std;

int main() {

    int first; int second; int third; int fourth;

    cin >> first>>second>>third>>fourth;

    if (first < second && second < third && third < fourth)
        cout << "Fish Rising";
    else if (first > second && second > third && third > fourth)
        cout << "Fish Diving";
    else if (first==second&&second==third&&third==fourth){
        cout << "Fish At Constant Depth";
    }
    else {
        cout << "No Fish";
    }
}
