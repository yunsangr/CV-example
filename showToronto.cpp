#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"


int main( int argc, char** argv)
{
  cv::Mat dog, toronto, torontoGray;

  dog = cv::imread("images/dog.jpg", cv::ImreadModes::IMREAD_UNCHANGED);
  toronto = cv::imread("images/toronto.jpeg", cv::ImreadModes::IMREAD_UNCHANGED);
  torontoGray = cv::imread("images/toronto.jpeg", cv::ImreadModes::IMREAD_GRAYSCALE);

  cv::imshow("dog", dog);
  cv::imshow("toronto", toronto);
  cv::imshow("torontoGray", torontoGray);

  cv::waitKey(0);

  return 0;
}
