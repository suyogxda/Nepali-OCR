#include "../include/extractWords.h"

std::vector< int > getWords( cv::Mat image ){
    cv::Mat1i whitePixelOfColumn(image.cols, 1);

    int previousPixelValue = 0;
    bool isBetweenCharacters = false;
    std::vector <int> characterPoints;

    for(int x = 0; x < image.cols; x++){
        cv::Mat singleColumn = image.col(x);
        whitePixelOfColumn(x,0) = cv::countNonZero(singleColumn);

        if( previousPixelValue == 0 && whitePixelOfColumn(x,0) != 0 && !isBetweenCharacters ){
            isBetweenCharacters = true;
            characterPoints.push_back( x );
        }
        else if( isBetweenCharacters && whitePixelOfColumn(x,0) == 0 ){
            isBetweenCharacters = false;
            characterPoints.push_back( x );
        }
        else{
            previousPixelValue = whitePixelOfColumn(x, 0);
        }
        previousPixelValue = whitePixelOfColumn(x, 0);
    }

    if( ( characterPoints.size() % 2 != 0 ) ){
        characterPoints.push_back( image.cols );
    }
    return characterPoints;

}