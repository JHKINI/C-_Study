# 01. 직접 만든 실습

교재 예제를 따라 친 코드(`ch03` ~ `ch09`)와 따로, **과제를 받아 직접 설계한 코드**입니다.

## 📋 성장 비전 리포트 (`vision_report/`)

`0320_growth_vision_report.cpp`: 3/20 C++ 과제. 이름, 나이, 비전(한 단어), 목표 수치와 현재 수치, 활성화 여부(`bool`)를 입력받아 리포트로 출력합니다.
`string`, `int`, `bool`, `double` 자료형과 `cin`/`cout`, 그리고 목표가 0일 때 나누지 않도록 하는 조건 처리를 연습했습니다.

```text
--- 나의 성장 비전 리포트 ---
목표비전: 반도체
진행도: 40/100
현재달성률: 0.4
운영상태: 진행중
```

## 🧮 사칙연산 계산기 (`calculator/`)

숫자 4개와 연산자 3개를 입력받아 **곱셈·나눗셈을 먼저** 계산하는 계산기입니다.

| 단계 | 파일 | 내용 |
|---|---|---|
| 1 | `01_four_numbers_precedence.cpp` | 변수 `a, b, c, d`와 `op1, op2, op3`로 처리. `*`, `/`는 바로 곱하고, `+`, `-`가 나오면 그때까지의 값을 결과에 더하는 방식으로 우선순위를 처리 |
| 2 | `02_array_overflow_binary_hex.cpp` | 숫자와 연산자를 **배열**로 바꿈. 1단계에서 곱셈·나눗셈을 계산하고 배열을 앞으로 당긴 뒤, 2단계에서 덧셈·뺄셈 계산. **0으로 나누기, `int` 오버플로우·언더플로우 검사** 추가. 결과를 10진수 / 2진수(`bitset<32>`) / 16진수(`hex`)로 출력 |

```text
입력: 3 + 4 * 5 - 6
10진수: 17
2진수: 00000000000000000000000000010001
16진수: 11

입력: 2147483647 * 2 + 1 - 1
곱셈 오버플로우 발생!
```

> 2단계 파일은 처음에 `#include <limits>`만 있어서 리눅스 g++에서는 `INT_MAX`를 찾지 못했습니다. `INT_MAX`가 정의된 `<climits>`로 바꿨습니다.

## ⏱ 초 → 일·시·분·초 변환 (`time_convert/`)

`seconds_to_days.cpp`: 교재 [`Prg3-30`](../ch03_expressions_types/Prg3-30.cpp)은 초를 시·분·초로만 나눕니다. 이 파일은 **일(day) 단위**까지 나누고, `duration - (hours * 3600)`처럼 곱해서 빼던 계산을 `%`(나머지) 연산으로 바꿨습니다.

```text
100000초 → 교재: 27시 46분 40초 / 수정본: 1일 3시 46분 40초
```

## 🖼 OpenCV 이미지 처리 (`opencv_image/`)

`0320_image_info_gray_resize.cpp`: 이미지 크기·채널 수 출력 → 흑백 변환 → 50% 축소 → 사각형과 날짜 텍스트 그리기.
같은 과제를 파이썬으로도 풀었습니다. ([python-learning/06_computer_vision](https://github.com/JHKINI/python-learning/tree/main/06_computer_vision))

```bash
g++ 0320_image_info_gray_resize.cpp -o app `pkg-config --cflags --libs opencv4`   # OpenCV 설치 필요, image.jpg 필요
```
