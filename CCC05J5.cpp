#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <functional>

using namespace std;
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 3628802; // TODO change this for each problem
const ll MOD = 3e6 + 1;
const ll BASE = 131;
const int INF = 0x3f3f3f3f;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

string operator*(const string &s, int n) {
    stringstream out;
    while (n > 0) {
        n--;
        out << s;
    }
    return out.str();
}
bool Aword(string word);

bool monkeyW(string word){
    int IndexN = word.find('N');
    if(IndexN!=string::npos){
        bool flag = false;
        for(int i=0;i<word.length();i++){
            if(word[i] == 'N'){
                flag = (Aword(word.substr(0,i)) && monkeyW(word.substr(i+1)));
                if(flag) break;
            }
        }
        if(!flag){
            return Aword(word);
        }
        return flag;
    }
    else return Aword(word);

}

bool Aword(string word){
    if(word.length()>0){
        int IndexS = word.find_last_of('S');
        if(word == "A"){
            return true;
        }
        if(word[0] == 'B' && word[word.length()-1]=='S'){
            return monkeyW(word.substr(1,word.length()-2));
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    string s;
    for (cin>>s; s != "X"; cin>>s){
        cout << (monkeyW(s)?"YES":"NO") << endl;
    }
}
