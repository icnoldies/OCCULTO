#include <gtest/gtest.h>
#include "Cipher.h"
#include "ImageHandler.h"
#include "Steganography.h"
#include <string>
using namespace std;

TEST(CipherTest, EncryptDecrypt) {
    string message = "HELLO";
    string key = "KEY";
    string encrypted = encrypt(message, key);
    string decrypted = decrypt(encrypted, key);
    EXPECT_EQ(decrypted, message);
}

TEST(CipherTest, EncryptChangesMessage) {
    string message = "HELLO";
    string key = "KEY";
    string encrypted = encrypt(message, key);
    EXPECT_NE(encrypted, message);
}

TEST(ImageHandlerTest, ValidPNG) {
    ImageHandler handler; EXPECT_TRUE(handler.validateImage(".png"));                                               // checking if the extension ends with .png, if it does the test is passed
}
TEST(ImageHandlerTest, InvalidPNG) {
    ImageHandler handler; EXPECT_FALSE(handler.validateImage(".jpg"));                                              // if the extension ends in .jpg the test should also pass as it expects false
}

TEST(ImageHandlerTest, LoadImage_InvalidFile) {
    ImageHandler handler; EXPECT_FALSE(handler.loadImage("empty.png"));                                             // if the file does not exist, then confirm it fails
}

TEST(ImageHandlerTest, LoadImage_ValidFile) {
    ImageHandler handler; EXPECT_TRUE(handler.loadImage("C:\\Users\\User\\Pictures\\mountains.png"));               // if the file does exist, then confirm success
}

TEST(ImageHandlerTest, SaveImage) {
    ImageHandler handler;
    handler.loadImage("C:\\Users\\User\\Pictures\\mountains.png");
    EXPECT_TRUE(handler.saveImage("C:\\Users\\User\\Pictures\\mountains.png"));
}

TEST(ImageHandlerTest, get_Image) {
    ImageHandler handler; handler.loadImage("C:\\Users\\User\\Pictures\\mountains.png");
    EXPECT_FALSE(handler.getImage().empty());
}

TEST(SteganographyTest, Encode) {
    ImageHandler handler; handler.loadImage("C:\\Users\\User\\Pictures\\mountains.png");                        // takes a real image
    Steganography encode; EXPECT_TRUE(encode.encode(handler.getImage(), "HELLO"));                          // creates a steganography object and calls the encode message, expects to return True
}


TEST(SteganographyTest, Decode) {
    ImageHandler handler; handler.loadImage("C:\\Users\\User\\Pictures\\mountains.png");
    Steganography steg; steg.encode(handler.getImage(),"HELLO");
    string result = steg.decode(handler.getImage()); EXPECT_EQ(result, "HELLO");                                        // checking if the result and "HELLO" are the same 
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

