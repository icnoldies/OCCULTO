#include "Steganography.h"


bool Steganography::encode(cv::Mat & image, std:: string message)                   // encodes a message into an image using LSB (least significant bit) steganography
{
    message += '\0';                                                                // adding a special marker to the end of the message so the program knows where the message ends
    int row = 0;                                                                    // a variable that tracks which row of pixels we're currently on
    int col = 0;                                                                    // a variable that tracks which pixel in that row we're on
    int channel = 0;                                                                // a variable that tracks which color channel (R, G, or B) we're putting the next bit into


    for (int i = 0; i < message.length(); i++)                                      // it loops through every character in the message one by one
    {
        for (int a = 7; a >= 0; a--)                                                // it counts down from 7 to 0 to process all 8 bits of the current character
        {
            int bit = (message[i] >> a) & 1;                                        // slide the bits of the current character right by a positions, then look at the last bit and store it in variable bit, & 1 tells the program to read the last bit
            image.at<cv::Vec3b>(row, col)[channel] = (image.at<cv::Vec3b>(row, col)[channel] & 0xFE) | bit;         // go to pixel at (row, col), channel R/G/B, force the last bit to be 0, then set it to our hidden bit

            channel++;                                          // simply moves to the next channel
            if (channel == 3)                                   //When channel hits 3, reset it and move to the next col
            {
                channel = 0;                                    // All 3 channels of the current pixel are full, so reset to channel 0 and move to the next pixel (col++)
                col++;

                if (col == image.cols)                          // When we reach the end of a row, we reset col to 0 and move down to the next row
                {
                    col = 0;
                    row++;

                }
            }
        }
    }
    return true;                                                //  It returns true when the encoding is complete
}


std::string Steganography::decode(cv::Mat& image)
{
    int row = 0;
    int col = 0;
    int channel = 0;
    std::string result = "";
    int currentByte = 0;
    int bitCount = 0;


    while(true)
    {
        int bit = image.at<cv::Vec3b>(row, col)[channel] & 1;
        currentByte = (currentByte << 1) | bit;

        channel++;
        if (channel == 3) { channel = 0; col++; if (col == image.cols) { col = 0; row++; } }
        bitCount++;

        if (bitCount == 8)
{
        bitCount = 0;
        if (currentByte == '\0')
        {
        break;
        }
        else
        {
            result += (char)currentByte;
        }
        currentByte = 0;
        }

}

return result;
}


