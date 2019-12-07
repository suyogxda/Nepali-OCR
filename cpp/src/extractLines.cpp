#include "../include/extractLines.h"


std::vector<int> singleLine;
std::vector<std::vector<int>> linePoints;

std::vector<cv::Mat> segment_lines( cv::Mat& thin_image , cv::Mat& binary_image ){

    int checkpoint = 0;
    std::vector<cv::Mat> vector_of_lines;
    cv::Mat1i black_pixels(thin_image.rows, 1);
    linePoints.clear();
    singleLine.clear();

    for( int i = 0; i < thin_image.rows; i++ ){
        cv::Mat row = thin_image.row( i );
        black_pixels( i, 0 ) = cv::countNonZero( row );

        if( checkpoint == 0 ){
            if( black_pixels(i, 0) > LINE_THRESHOLD ){
                checkpoint++;
                singleLine.clear();
                singleLine.push_back(i);
            }
        }
        else if( checkpoint != 0 && black_pixels(i, 0) > LINE_THRESHOLD ){
            ++checkpoint;
        }
        else{
            if( checkpoint > 10 ){
                cv::Rect toCrop;
                toCrop = cv::Rect( 0, i - checkpoint, thin_image.cols, checkpoint );
                vector_of_lines.push_back( binary_image( toCrop ) );
                checkpoint = 0;
                singleLine.push_back( i );
                linePoints.push_back( singleLine );
            }
            else{
                singleLine.clear();
                checkpoint = 0;
            }
        }
    }
    return( vector_of_lines );
}