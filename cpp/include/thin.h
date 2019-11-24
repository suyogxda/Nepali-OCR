/**
 * Perform one thinning iteration.
 * Normally you wouldn't call this function directly from your code.
 *
 * Parameters:
 *              im    Binary image with range = [0,1]
 *              iter  0=even, 1=odd
 */
#pragma once
#include <opencv2/opencv.hpp>


void thinningIteration(cv::Mat& img, int iter);
void thinning(const cv::Mat& src, cv::Mat& dst);

