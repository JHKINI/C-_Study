/**************************************************************
 * 0부터 n-1까지 for 반복문으로 출력하기                      *
 **************************************************************/
#include <iostream>
using namespace std;

int main()  
{
  // 선언
  int n;
  // 변수 n 입력받기
  cout << "출력할 정수를 입력하세요: ";
  cin >> n;
  // 반복문 (int counter 같이 선언과 사용을 동시에하는건 권장하지 않음)
  for(int counter = 0; counter < n; counter++)   
  { 
    cout << counter << " "; 
  }
  return 0; 
}
