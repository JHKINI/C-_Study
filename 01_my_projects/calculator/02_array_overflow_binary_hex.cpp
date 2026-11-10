#include <iostream>
#include <bitset>
#include <climits> // INT_MAX, INT_MIN (원래 <limits>였는데 g++ 리눅스에서 INT_MAX를 못 찾아서 <climits>로 수정)
using namespace std;

int main() {
    int num[4];     // 숫자 4개
    char op[3];     // 연산자 3개
    int opCount = 3; // 연산자 개수 추적

    // 숫자와 연산자 입력
    for (int i = 0; i < 4; i++) {
        cout << i + 1 << "번째 숫자 입력: ";
        cin >> num[i];

        if (i < 3) {
            cout << i + 1 << "번째 연산자 입력 (+, -, *, /): ";
            cin >> op[i];
        }
    }

    // 1단계: 곱셈/나눗셈 먼저 계산
    for (int i = 0; i < opCount; i++) {
        if (op[i] == '*' || op[i] == '/') {
            int temp;
            if (op[i] == '*') {
                // 곱셈 오버플로우 체크
                if ((num[i] != 0 && num[i + 1] != 0) &&
                    (num[i] > INT_MAX / num[i + 1] || num[i] < INT_MIN / num[i + 1])) {
                    cout << "곱셈 오버플로우 발생!" << endl;
                    return 0;
                }
                temp = num[i] * num[i + 1];
            } else { // 나눗셈
                if (num[i + 1] == 0) {
                    cout << "0으로 나눌 수 없습니다!" << endl;
                    return 0;
                }
                temp = num[i] / num[i + 1];
            }
            num[i] = temp;

            // 배열 당기기
            for (int j = i + 1; j < opCount; j++) {
                num[j] = num[j + 1];
                op[j - 1] = op[j];
            }
            opCount--; // 연산자 개수 감소
            i--;       // 현재 위치 다시 검사
        }
    }

    // 2단계: 덧셈/뺄셈 계산
    int result = num[0];
    for (int i = 0; i < opCount; i++) {
        if (op[i] == '+') {
            // 덧셈 오버플로우/언더플로우 체크
            if ((num[i + 1] > 0 && result > INT_MAX - num[i + 1]) ||
                (num[i + 1] < 0 && result < INT_MIN - num[i + 1])) {
                cout << "덧셈 오버플로우/언더플로우 발생!" << endl;
                return 0;
            }
            result += num[i + 1];
        } else if (op[i] == '-') {
            // 뺄셈 오버플로우/언더플로우 체크
            if ((num[i + 1] < 0 && result > INT_MAX + num[i + 1]) ||
                (num[i + 1] > 0 && result < INT_MIN + num[i + 1])) {
                cout << "뺄셈 오버플로우/언더플로우 발생!" << endl;
                return 0;
            }
            result -= num[i + 1];
        } else {
            cout << "알 수 없는 연산자 발생!" << endl;
            return 0;
        }
    }

    // 결과 출력
    cout << "10진수: " << result << endl;
    cout << "2진수: " << bitset<32>(result) << endl;
    cout << "16진수: " << hex << result << endl;

    return 0;
}
