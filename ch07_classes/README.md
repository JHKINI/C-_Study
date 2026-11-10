# 7장. 클래스

> 교재 예제를 직접 입력하고 VS Code + MinGW g++로 빌드·실행하며 익힌 코드입니다.

**다룬 내용**: 클래스 선언·정의·사용, 생성자, 접근자/설정자, 객체 개수 세기(`static` 멤버), **인터페이스 파일(.h)과 구현 파일(.cpp) 분리**

## 예제 목록

| 파일 | 내용 |
|---|---|
| `Prg7-1.cpp` | 객체 지향 프로그래밍에서 클래스를 사용하는 프로그램 |
| `Prg7-2.cpp` | 객체 지향 프로그래밍에서 클래스를 사용하는 예 |
| `Prg7-3.cpp` | 주어진 범위의 랜덤한 숫자를 생성하는 클래스를 선언, 정의하고 사용하는 프로그램 |
| `Prg7-4.cpp` | Rectangle 클래스를 선언, 정의, 사용하는 프로그램 |
| `Prg7-5.cpp` | 객체를 만들고, 만들어진 객체의 수를 세는 프로그램 |
| `Prg7-6.cpp` | Account(은행 계좌) 클래스를 선언, 정의, 사용하는 프로그램 |

## 여러 파일로 나눈 프로젝트

교재 예제(Prg7-7 ~ Prg7-15)를 **헤더 / 구현 / 실행 파일로 직접 나눠서** 빌드했습니다.

| 폴더 | 파일 | 교재 번호 | 빌드 |
|---|---|---|---|
| `circle_project/` | `circle.h`, `circle.cpp`, `app.cpp`, `makefile` | 7-7, 7-8, 7-9 | `make` (직접 작성한 makefile) |
| `fraction_project/` | `fraction.h`, `fraction.cpp`, `app.cpp` | 7-10, 7-11, 7-12 | `g++ fraction.cpp app.cpp -o app` |
| `time_project/` | `time.h`, `time.cpp`, `app.cpp` | 7-13, 7-14, 7-15 | `g++ time.cpp app.cpp -o app` |

- 원래 `Prg7-7.cpp`에는 헤더 안에서 자기 자신(`circle.h`)을 `#include`하는 줄이 있었는데, `circle.h`로 옮기면서 그 줄을 지웠습니다.
- `circle_project/app.cpp`는 출력 문구가 영어(Radius, Area 등)입니다. Windows 터미널에서 한글이 깨질 때는 `chcp 65001`(UTF-8)을 먼저 입력하면 됩니다. (필기)
- `makefile`은 `g++ -Wall -Wextra -std=c++17`로 `.o` 파일을 따로 만든 뒤 링크합니다. 헤더가 바뀌면 그 헤더를 쓰는 파일만 다시 컴파일됩니다.

```makefile
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
app.o: app.cpp circle.h
	$(CXX) $(CXXFLAGS) -c app.cpp
```

## 빌드

```bash
g++ -std=c++17 Prg파일.cpp -o app && ./app
```
