// C++ implementation for Mini Interpreter
#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> vars;

int eval(string expr) {
    stringstream ss(expr);
    string token;
    while (ss >> token) {
        if (token == "let") continue;
        else if (token.find('=') != string::npos) {
            auto pos = token.find('=');
            string var = token.substr(0, pos);
            int val = stoi(token.substr(pos + 1));
            vars[var] = val;
        } else if (token == "if") {
            string var, op; int val;
            ss >> var >> op >> val;
            if (op == "==") return vars[var] == val;
            if (op == "!=") return vars[var] != val;
        }
    }
    return -1;
}

int main() {
    cout << eval("let x=10 y=20") << endl;       // Output: -1
    cout << eval("let x=5 if x == 5") << endl;   // Output: 1
    cout << eval("let z=8 if z != 5") << endl;   // Output: 1
    return 0;
}
