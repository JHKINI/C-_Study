# ⚙️ C++ Study

한국폴리텍대학 **AI소프트웨어과 하이테크과정** C++ 수업(금요일, Computer Vision·Linux와 함께 진행)에서 작성한 코드를 정리한 저장소입니다.
교재 예제를 장(chapter)별로 직접 입력하고 빌드해 본 코드와, 과제를 받아 **직접 설계한 코드**를 나눠서 정리했습니다.

| 항목 | 내용 |
|---|---|
| 기간 | 2026년 3월 ~ |
| 환경 | VS Code · MSYS2 MinGW-w64 `g++` · `-std=c++17` |
| 분량 | `.cpp` / `.h` 파일 154개 (교재 예제 3장 ~ 9장 + 직접 만든 실습) |
| 함께 본 것 | 파이썬으로 같은 과제를 푼 기록: [python-learning](https://github.com/JHKINI/python-learning) |

---

## 🗺 학습 로드맵

| 단계 | 주제 | 핵심 내용 |
|---|---|---|
| [00](00_getting_started) | 시작하기 | Hello World, VS Code 빌드 설정, `chcp 65001` |
| [03장](ch03_expressions_types) | 표현식과 자료형 | 연산자 우선순위, 형변환, 오버플로우, 진법 출력 |
| [04장](ch04_selection) | 조건문 | `if`, `switch`, 조건부 표현식 |
| [05장](ch05_repetition) | 반복문 | 센티넬·EOF 제어 반복, `do-while` 입력 검사, 중첩 반복 |
| [06장](ch06_functions) | 함수 | 값 전달 vs **참조 전달**, 오버로딩, 기본 매개변수, 변수의 범위와 `static` |
| [07장](ch07_classes) | 클래스 | 생성자, 접근자, `static` 멤버, **헤더/구현 파일 분리 + makefile** |
| [08장](ch08_arrays) | 배열 | 파일 → 배열, 배열을 함수에 전달, 객체 배열, 2차원 배열 |
| [09장](ch09_references_pointers) | 참조 · 포인터 | 포인터 연산, 포인터로 배열 다루기, **`new`/`delete` 동적 메모리**, 래기드 배열 |

📝 **손필기 정리**: [`notes/cpp.md`](notes/cpp.md) (빌드 방법, C++ 코드 3단 구성, 형변환, 이중 for문, 헤더 분리)

---

## 🔍 직접 만든 실습 ([`01_my_projects`](01_my_projects))

### 📋 성장 비전 리포트 (3/20 과제)
이름·목표·현재 수치를 입력받아 달성률과 운영 상태를 출력합니다. 목표가 0이면 나누지 않도록 처리했습니다.

### 🧮 사칙연산 계산기: 변수 버전 → 배열 버전
숫자 4개와 연산자 3개를 받아 **곱셈·나눗셈을 먼저** 계산합니다.
처음에는 변수 7개로 풀고, 다음에는 배열로 바꿔서 "곱셈·나눗셈 계산 → 배열 당기기 → 덧셈·뺄셈 계산" 2단계로 정리했습니다.
여기에 **0으로 나누기와 `int` 오버플로우 검사**를 넣고, 결과를 10진수·2진수·16진수로 출력합니다.

```text
입력: 3 + 4 * 5 - 6   →   10진수: 17 / 2진수: 0000...00010001 / 16진수: 11
입력: 2147483647 * 2 ...   →   곱셈 오버플로우 발생!
```

### ⏱ 초 단위 시간 변환 확장
교재 예제(초 → 시·분·초)를 **일 단위까지** 나누고, 곱해서 빼던 계산을 `%` 연산으로 바꿨습니다.

### 🖼 OpenCV 이미지 처리 (C++)
이미지 정보 출력 → 흑백 변환 → 축소 → 도형·텍스트 그리기. 같은 과제를 파이썬으로도 구현했습니다.

---

## ✍️ 이렇게 공부했습니다

- **교재 예제는 빠짐없이 직접 입력하고 빌드**: 3장 ~ 9장 예제 130개 이상
- **한 파일 → 여러 파일로 나누기**: 클래스 예제를 `.h` / `.cpp` / `app.cpp`로 나누고, `makefile`을 직접 작성해서 `.o` 파일 단위로 빌드 ([`circle_project`](ch07_classes/circle_project))
- **예제를 그대로 두지 않고 고쳐 보기**: 시간 변환 예제를 일 단위로 확장하고, 계산기는 변수 → 배열 → 예외 검사 순서로 발전
- **진법 감각 익히기**: 필기에 "2·10·16진수를 자연스럽게 계산할 정도로 연습하기"라고 적고, 계산기 출력에 2진수·16진수를 넣음

---

## 📂 폴더 구조

```text
C-_Study/
├── 00_getting_started/        Hello World, 자기소개
├── 01_my_projects/            직접 만든 실습 (vision_report, calculator, time_convert, opencv_image)
├── ch03_expressions_types/    Prg3-1 ~ 3-31
├── ch04_selection/            Prg4-1 ~ 4-17
├── ch05_repetition/           Prg5-1 ~ 5-22 (+ numbers.dat)
├── ch06_functions/            Prg6-1 ~ 6-27
├── ch07_classes/              Prg7-1 ~ 7-6, circle_project/ fraction_project/ time_project/
├── ch08_arrays/               Prg8-1 ~ 8-15, student_project/
├── ch09_references_pointers/  Prg9-1 ~ 9-15, course_project/ matrix_project/
├── notes/                     손필기 정리 + 사진
└── .vscode/tasks.json         VS Code 빌드 설정 (MSYS2 g++)
```

`Prg3-1`처럼 교재 예제 번호를 그대로 파일명으로 썼습니다. 각 폴더 README에 예제별 내용이 정리되어 있습니다.

## ▶️ 빌드

```bash
# 파일 하나
g++ -std=c++17 ch06_functions/Prg6-15.cpp -o app && ./app

# 여러 파일로 나눈 프로젝트
cd ch07_classes/circle_project && make
```
