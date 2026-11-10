#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {

    Mat src = imread("image.jpg");  // 이미지 불러오기

    if (src.empty()) {
        cout << "이미지를 불러오지 못했습니다." << endl;
        return -1;
    }

    // 이미지 정보 출력
    cout << "이미지 가로 크기: " << src.cols << endl;
    cout << "이미지 세로 크기: " << src.rows << endl;
    cout << "채널 수: " << src.channels() << endl;

    // 흑백 변환
    Mat grayImg;
    cvtColor(src, grayImg, COLOR_BGR2GRAY);

    // 크기 줄이기 (50%)
    Mat smallImg;
    resize(src, smallImg, Size(), 0.5, 0.5);

    // 사각형 그리기
    rectangle(smallImg, Point(30, 30), Point(180, 180), Scalar(0, 255, 0), 2);

    // 텍스트 추가
    putText(smallImg, "2026-03-25", Point(30, 25),
            FONT_HERSHEY_SIMPLEX, 0.8, Scalar(255, 255, 255), 2);

    // 결과 출력
    imshow("원본 이미지", src);
    imshow("흑백 이미지", grayImg);
    imshow("결과 이미지", smallImg);

    waitKey(0);
    return 0;
}
