#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    char op1, op2, op3;

    cin >> a >> b >> c >> d;
    cin >> op1 >> op2 >> op3;

    int result = 0;
    int temp = a;

    // op1 처리
    if (op1 == '*') temp *= b;
    else if (op1 == '/') temp /= b;
    else {
        result += temp;
        temp = (op1 == '+') ? b : -b;
    }

    // op2 처리
    if (op2 == '*') temp *= c;
    else if (op2 == '/') temp /= c;
    else {
        result += temp;
        temp = (op2 == '+') ? c : -c;
    }

    // op3 처리
    if (op3 == '*') temp *= d;
    else if (op3 == '/') temp /= d;
    else {
        result += temp;
        temp = (op3 == '+') ? d : -d;
    }

    result += temp;

    cout << result << endl;

    return 0;
}
