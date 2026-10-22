#ifndef INC_12418688_IPA_A1_STEGANOGRAPHY_H
#define INC_12418688_IPA_A1_STEGANOGRAPHY_H
#include <string>
#include <opencv2/opencv.hpp>



class Steganography {
    public:
    bool encode(cv::Mat & image, std::string message);
    std:: string decode(cv::Mat & image);
};

#endif //INC_12418688_IPA_A1_STEGANOGRAPHY_H
