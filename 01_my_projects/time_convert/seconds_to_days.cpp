#include <iostream>
using namespace std;

int main()
{ 
  unsigned long duration;
  unsigned long days, hours, minutes, seconds;

  cout << "초 단위 시간을 입력: ";
  cin >> duration;

  days = duration / 86400;
  hours = (duration % 86400) / 3600;
  minutes = (duration % 3600) / 60;
  seconds = duration % 60;

  cout << days << "일 ";
  cout << hours << "시 ";
  cout << minutes << "분 ";
  cout << seconds << "초";

  return 0; 
}
