
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"


using namespace std;

int main( int argc, char** argv )
{

  cv::Mat unchaged;
  cv::Mat grayscale;
  cv::Mat color;
  cv::Mat anydepth;
  cv::Mat load_gdal;
  cv::Mat reduced_gray_scale_2;
  cv::Mat reduced_color_2;
  cv::Mat reduced_grayscale_8;
  cv::Mat reduced_color_8;
  cv::Mat reduced_ignore_orientation;



  unchaged = cv::imread("dog.jpg", cv::ImreadModes::IMREAD_UNCHANGED );
  grayscale = cv::imread("dog.jpg", cv::ImreadModes::IMREAD_GRAYSCALE );
  color = cv::imread("dog.jpg", cv::ImreadModes::IMREAD_COLOR );
  anydepth = cv::imread("dog.jpg", cv::ImreadModes::IMREAD_ANYDEPTH );
  load_gdal = cv::imread("dog.jpg", cv::ImreadModes::IMREAD_LOAD_GDAL );
  reduced_gray_scale_2 = cv::imread("dog.jpg", cv::ImreadModes::IMREAD_REDUCED_GRAYSCALE_2 );
  reduced_color_2 = cv::imread("dog.jpg", cv::ImreadModes::IMREAD_REDUCED_COLOR_2 );
  reduced_grayscale_8 = cv::imread("dog.jpg", cv::ImreadModes::IMREAD_REDUCED_GRAYSCALE_8 );
  reduced_color_8 = cv::imread("dog.jpg", cv::ImreadModes::IMREAD_REDUCED_COLOR_8 );
  reduced_ignore_orientation = cv::imread("dog.jpg", cv::ImreadModes::IMREAD_IGNORE_ORIENTATION );


  cv::imshow("unchaged", unchaged);
  cv::imshow("grayscale", grayscale);
  cv::imshow("color", color);
  cv::imshow("anydepth", anydepth);
  cv::imshow("load_gdal", load_gdal);

  cv::imshow("reduced_gray_scale_2", reduced_gray_scale_2);
  cv::imshow("reduced_color_2", reduced_color_2);
  cv::imshow("reduced_grayscale_8", reduced_grayscale_8);
  cv::imshow("reduced_color_8", reduced_color_8);
  cv::imshow("reduced_ignore_orientation", reduced_ignore_orientation);



  cv::waitKey(0);



  return 0;
}
