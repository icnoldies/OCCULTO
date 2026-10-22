#ifndef INC_12418688_IPA_A1_IMAGEHANDLER_H
#define INC_12418688_IPA_A1_IMAGEHANDLER_H

#include <string>
#include <opencv2/opencv.hpp>



class ImageHandler {
public:
    bool loadImage(std::string filepath);
    bool validateImage(std::string filepath);
    bool saveImage(std::string filepath);
    cv::Mat& getImage();
private:
    cv::Mat image;

};

#endif //INC_12418688_IPA_A1_IMAGEHANDLER_H
