#include <iostream>
#include <string>
using namespace std;

int main()
{
string name;
int age;
string vision;
int goal;
int current;
bool active;

cout << "이름을 입력하세요: ";
cin >> name;

cout << "나이를 입력하세요: ";
cin >> age;

cout << "나의 비전(한 단어)을 입력하세요: ";
cin >> vision;

cout << "목표수치를 입력하세요 (0~100): ";
cin >> goal;

cout<< "현재 진행 수치를 입력하세요 (0~100): ";
cin >> current;

cout << "비전활성화 여부 (1: 시작, 0: 대기): ";
cin>> active;
double progress = 0;
    if (goal != 0) {
 progress = (double)current / goal;
    }
cout << "\n--- 나의 성장 비전 리포트 ---\n" << endl;
cout << "성함: " << name << "("<< age << "세)" << endl;

cout << "목표비전: " << vision << endl;
cout << "진행도: " << current << "/" << goal << endl;
cout << "현재달성률: " << progress << endl;

if (active)
cout << "운영상태: 진행중" << endl;
else 
cout << "운영상태: 준비중" << endl;

return 0;
}


