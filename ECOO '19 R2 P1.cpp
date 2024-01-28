#include <iostream>
#include <set>

using namespace std;

int main() {
    long long ind = 10;
    while(ind-->0){
        int N;
        cin >> N;
        set<string> op;

        while(N --> 0){
            string e;
            cin >> e;
            string ema;
            int i = 0;
            while(i < e.length() && e[i] != '+' && e[i] != '@'){
                if(e[i] != '.'){
                    ema += tolower(e[i]);
                }
                i++;
            }
            int as = e.find('@');
            while(as < e.length()){
                ema += tolower(e[as]);
                as++;
            }
            op.insert(ema);
        }
        cout << op.size() << endl;
    }
}