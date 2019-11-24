#include <opencv2/opencv.hpp>
#include "thin.h"

int main(int argc, char** argv){
  cv::Mat input_image = cv::imread(argv[1], 0);
  cv::Mat thinned_image;
  thinning(input_image, thinned_image);

  cv::namedWindow("Thinned", cv::WINDOW_NORMAL);
  cv::imshow("Thinned", thinned_image);
  cv::waitKey(0);
}
