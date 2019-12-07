#include <opencv2/opencv.hpp>
#include "thin.h"
#include "extractLines.h"

int main(int argc, char** argv){
  cv::Mat input_image = cv::imread( argv[1], 0 );
  cv::Mat thinned_image, binary_image;
  
  // We use inverse binary because what we want to pass...
  // white characters on black background to the thinning function
  cv::threshold( input_image, binary_image, 0, 255, cv::THRESH_BINARY_INV + cv::THRESH_OTSU );

  // This function makes sure that the characters are reduced to pixels
  thinning( binary_image, thinned_image );

  // The line below returns vector of lines extracted
  auto vector_of_images = segment_lines( thinned_image, binary_image );

  // For loop to show the seperated lines.
  // This line extraction method is not limited just to devnagari scripts
  // Just make sure that the images of texts you pass are clean, and not connected vertically
  cv::namedWindow( "Lines", cv::WINDOW_NORMAL );
  for( size_t i = 0; i < vector_of_images.size(); ++i ){
    cv::imshow( "Lines", vector_of_images[i] );
    auto key = cv::waitKey();
    if( key == 27 )
      break;
  }
}
