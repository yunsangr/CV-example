#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

void lineDivider(){
  std::cout << "\n\n\n";
}


/***
 *
 *  CV_[ 데이터 비트 수] [S: signed, U: unsigned] C [ 데이터 개수(채널 수)]
 *
 */

int main( int argc, char** argv)
{

  cv::Mat M1(3, 4, CV_32SC1);
  cv::Mat M2(cv::Size(3, 4), CV_32SC1);
  cv::Mat M3;
  M3.create(3, 4, CV_32SC1);


  std::cout << "M1: \n" << M1 << std::endl;
  std::cout << "M2: \n" << M2 << std::endl;
  std::cout << "M3: \n" << M3 << std::endl;

  lineDivider();

  /***
   *  create 3 x 4 x 5 x 6 matrix (4-dimension)
   */
  int sizes[] = {3, 4, 5, 6};
  cv::Mat M_4_d(4, sizes, CV_32SC1);



  /***
   *   Zero && Ones && Identical(Eyes) Metrics.
   */
  cv::Mat O = cv::Mat::zeros(2, 2, CV_32SC1);

  cv::Mat N = cv::Mat::ones(2, 2, CV_32SC1);

  cv::Mat E = cv::Mat::eye(2, 2, CV_32SC1);

  std::cout << "O: \n" << O << std::endl;
  std::cout << "N: \n" << N << std::endl;
  std::cout << "E: \n" << E << std::endl;


  lineDivider();

  /***
   *  cv::Mat.data 데이터 주소.
   *  Data(Pointer Varialbe) type = uchar *
   */

  cv::Mat M4(3, 3, CV_8UC1);
  cv::Mat M5 = M4;
  cv::Mat M6(M4);
  cv::Mat M7, M8;
  M4.copyTo(M7);
  M8 = M4.clone();

  std::cout << "M4 데이터 주소: " << (void *)M4.data << std::endl;
  std::cout << "M5 데이터 주소: " << (void *)M5.data << std::endl;
  std::cout << "M6 데이터 주소: " << (void *)M6.data << std::endl;
  std::cout << "M7 데이터 주소: " << (void *)M7.data << std::endl;
  std::cout << "M8 데이터 주소: " << (void *)M8.data << std::endl;


  lineDivider();

  cv::Mat Mat0 = cv::Mat::zeros(2, 2, CV_32SC1);

  Mat0.at<int>(0, 0) = 1;
  Mat0.at<int>(0, 1) = 2;
  Mat0.at<int>(1, 0) = 3;
  Mat0.at<int>(1, 1) = 4;

  std::cout << "Mat0: \n" << Mat0 << std::endl;

  /***
   *    Vec [채널 수] [ b: byte, s : short, i : int, f : float, d: double ]
   */


  cv::Mat Mat1 = cv::Mat::zeros(2, 2, CV_8UC3);

  Mat1.at<cv::Vec3b>(0, 0)[0] = 1;
  Mat1.at<cv::Vec3b>(0, 0)[1] = 2;
  Mat1.at<cv::Vec3b>(0, 0)[2] = 3;
//  Mat1.at<cv::Vec3b>(1, 1)[0] = 4;

  std::cout << "Mat1: \n" << Mat1 << std::endl;

  lineDivider();

  /***
   *    operator 활용
   *    cv::Mat 값 생성 시 작은 크기의 경우 Mat_ 클래스의
   *    "operator <<" 를 사용하여 값을 쉽게 초기화할 수 있다.
   */

  cv::Mat M_0 = (cv::Mat_<int>(2, 2) << 1, 2, 3, 4);
  std::cout <<  "M_0 = \n" << M_0 << std::endl;
  lineDivider();

  /***
   *    Iterator 활용
   *    MatIterator_<type> 을 통해 matrix의 모든 요소에 접근 가능하며,
   *    사용 방법은 일반적인 Iterator 사용 방법과 비슷하다.
   */
  cv:: Mat M_iter = cv::Mat::zeros(2, 2, CV_8UC3);
  std::cout << "M_iter = \n" << M_iter << std::endl;
//
  int sequence = 0;
  cv::MatIterator_<cv::Vec3b> it, end;

//  for (auto p : M_iter){
//    std::cout << "p = " << p << std::endl;
//  }



  for (it = M_iter.begin<cv::Vec3b>(), end = M_iter.end<cv::Vec3b>(); it != end; ++it){
//    std::cout << "sequence = " << sequence << std::endl;
//    std::cout << "M_iter = \n" << M_iter << std::endl;
    (*it)[0] = sequence++;
    (*it)[1] = sequence++;
    (*it)[2] = sequence++;
  }
  std::cout << "M_iter = \n" << M_iter << std::endl;
//  cv::imshow("M_iter",  M_iter);

  lineDivider();


  /***
   *    Mat_ class 활용
   *
   *    at<type> 메소드를 사용할 경우 메소드를 사용할 때마다 at<int> 처럼 type을 선언해줘야 되는
   *    번거로움이 있는데 이를 해결하기 위해서 Mat_ class를 활용할 수 있다.
   */

  {
    cv::Mat M = cv::Mat::zeros(2, 2, CV_8SC3);
    cv::Mat_<cv::Vec3b> _M = M;

    _M(0, 0)[0] = 1;
    _M(0, 0)[1] = 2;
    _M(0, 0)[2] = 3;
    M = _M;

    /***
     *  Mat_ 클래스는 깊은 복사(deep  copy)를 하기 때문에 기존 matrix에 대입해야 한다.
     *  (160줄 참고.)
     */
    std::cout << "M = \n" << M << std::endl;
  }

  return 0;
}
