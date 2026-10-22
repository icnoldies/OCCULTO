#include "ImageHandler.h"                           //imports everything from ImageHandler.h therefore I do not need to include libraries such as <string> or <opencv2/opencv.hpp> because they have been included already in the file I am already importing.



bool ImageHandler::loadImage(std::string filepath) {                    //it tells the compiler that this loadImage function belongs to the ImageHandler class. the expected outcome from filepath is string.
    image = cv::imread(filepath);                                       // calling private variable from a class I created earlier. Loads the image from the filepath and stores it into image
    if (image.empty()) {                                                // checks if the file has been successfully uploaded and if it is not corrupted or the filepath does not exist. In this case it becomes unreadable
        return false;
    }
    else
    {
        return true;
    }
}

bool ImageHandler::validateImage(std::string filepath) {
    if (filepath.substr (filepath.length() - 4) == ".png") {
        return true;
    }
    else {
        return false;
    }
}

bool ImageHandler::saveImage(std::string filepath) {
    std::string newFilepath = filepath.substr(0, filepath.length() - 4) + "_encoded.png";                   // takes everything except the last 4. So it removes .png from the end, then adds _encoded.png back
    return cv::imwrite(newFilepath, image);                                                                        // return the image — it saves the image to disk and returns true if it saved successfully, false if it failed
}

cv::Mat& ImageHandler::getImage()
{
    return image;
}