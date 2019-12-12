#include "../include/extractWords.h"

std::vector< int > getWords( cv::Mat image ){
    cv::Mat1i whitePixelOfColumn( image.cols, 1 );

    int previousPixelValue = 0;
    bool isBetweenCharacters = false;
    std::vector < int > characterPoints;

    for( int x = 0; x < image.cols; x++ ){
        cv::Mat singleColumn = image.col( x );
        whitePixelOfColumn( x,0 ) = cv::countNonZero( singleColumn );

        if( previousPixelValue == 0 && whitePixelOfColumn( x,0 ) != 0 && !isBetweenCharacters ){
            isBetweenCharacters = true;
            characterPoints.push_back( x );
        }
        else if( isBetweenCharacters && whitePixelOfColumn( x,0 ) == 0 ){
            isBetweenCharacters = false;
            characterPoints.push_back( x );
        }
        else{
            previousPixelValue = whitePixelOfColumn( x, 0 );
        }
        previousPixelValue = whitePixelOfColumn( x, 0 );
    }

    if( ( characterPoints.size() % 2 != 0 ) ){
        characterPoints.push_back( image.cols );
    }

    bool checker = false;
    double aspectRatio = 0;
    std::vector< int > wordPoints;

    for( size_t i = 0; i < characterPoints.size(); i++ ){
        if( i != 0 ){
            aspectRatio = characterPoints[i] - characterPoints[i - 1];
        }
        else{
            wordPoints.push_back( characterPoints[i] );
            checker = true;
        }
        if( ( aspectRatio / image.rows > WORD_THRESHOLD ) && checker ){
            wordPoints.push_back( characterPoints[i - 1] );
            checker = false;
        }
        else if( !checker ){
            wordPoints.push_back( characterPoints[i - 2] );
            checker = true;
        }
        i++;
    }
    if( ( wordPoints.size() % 2 != 0 ) ){
        wordPoints.push_back( characterPoints[characterPoints.size() - 1] );
    }

    for( size_t i = 0; i < wordPoints.size(); i++ ){
        if( ( wordPoints[i] - 5 ) >= 0 ){
            wordPoints[i] = wordPoints[i] - 5;
        }
        if( ( wordPoints[i + 1] + 5 ) <= image.cols ){
            wordPoints[i + 1] = wordPoints[i + 1] + 5;
        }
        i++;
    }
    return characterPoints;

}