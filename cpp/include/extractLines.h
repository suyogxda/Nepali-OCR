#pragma once
#include <opencv2/opencv.hpp> 
#include <iostream> 

#define LINE_THRESHOLD 5

extern std::vector<std::vector<int>> linePoints;
 
std::vector<cv::Mat> segment_lines( cv::Mat& thin_image , cv::Mat& binary_image );