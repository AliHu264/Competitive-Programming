#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <tuple>

using namespace std;

vector<string> ones{"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
vector<string> teens{"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
                     "nineteen"};
vector<string> tens{"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

string convert(long int number) {
    if (number < 10) {
        return ones[number];
    }
    else if(number < 20){
        return teens[number-10];
    }
    else if(number < 100){
        return tens[number/10] + convert(number%10);
    }
    else if(number < 1000){
        return convert(number/100)+"hundred"+convert(number%100);
    }
    else if(number < 1000000){
        return convert(number/1000)+"thousand"+convert(number%1000);
    }
    else if(number < 1000000000){
        return convert(number/1000000)+"million"+convert(number%1000000);
    }
    else if(number < 10000000000){
        return convert(number/1000000000)+"billion"+convert(number%1000000000);
    }
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    long int number;
    cin >> number;


    while(true){
        number = convert(number).size();
        cout << number << "\n";
        if(number == 4){
        break;}
    }

}