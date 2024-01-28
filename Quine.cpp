#include <iostream>
using namespace std;

int main() {
    char q = 34;
    string l[15]{
        "#include <iostream>",
        "using namespace std;",
        "",
        "int main() {",
        "    char q = 34;",
        "    string l[15]{",
        "    ",
        "    };",
        "    for(int i = 0; i < 6; i++)",
        "        cout<<(l[i])<<endl;",
        "    for(int i = 0; i < 15; i++)",
        "        cout<<(l[6] + l[6] + q + l[i] + q + ',')<<endl;",
        "    for(int i = 7; i < 15; i++)",
        "        cout<<(l[i])<<endl;",
        "}",
    };
    for(int i = 0; i < 6; i++)
        cout<<(l[i])<<endl;
    for(int i = 0; i < 15; i++)
        cout<<(l[6] + l[6] + q + l[i] + q + ',')<<endl;
    for(int i = 7; i < 15; i++)
        cout<<(l[i])<<endl;
}