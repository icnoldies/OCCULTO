#include "ImageHandler.h"
#include "Cipher.h"
#include "Steganography.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    cout << "Welcome to Project Occulto :)" << endl;                                      // simple console out to print out the name of the program onto the screen
    cout << "Option 1: Encode" << endl;                                                   // Printing out option 1
    cout << "Option 2: Decode" << endl;                                                   // Printing out option 2
    cout << "Option 3: Exit" << endl;                                                     // Printing out option 3
    cout << "Please select the option number:" << endl;
    int choice;
    cin >> choice;

    switch (choice) {
    case 1: {
            cout<<"Please type the file path of your selected image"<< endl;            // letting the user know what he needs to do
            string filepath;                                                            // creating a variable filepath
            cin>>filepath;                                                              // store the filepath in variable

            ImageHandler handler;                                                       // Creating the object
            if (handler.validateImage(filepath))                                     //  if statement checks the result of validateImage
            {
            // proceeds with encoding                                                    // if this is true then proceed with encoding
                cout<<"Please enter a text you would like to hide" << endl;
                string text;
                cin.ignore();
                getline(cin, text);


                cout<<"Please enter your key (word) to encrypt your message" << endl;
                string key;
                cin.ignore();
                getline(cin, key);
                for (char& c : key) c = toupper(c);

                string encryptedText = encrypt(text, key);
                if (handler.loadImage(filepath))
                {
                    Steganography hide;
                    hide.encode(handler.getImage(), encryptedText);
                    handler.saveImage(filepath);
                    cout <<"The encoding was successful" << endl;
                }
                else
                {
                    cout<<"Fail to load image" << endl;
                }
            }

            else
        {
            cout <<"Wrong file format" << endl;                                         // if this is not true then print out the message saying the image selected is in the wrong format


        }


        break;
    }

    case 2: {

        cout <<"Please specify the file path of your image" <<endl;
        string path;
        cin.ignore();
        getline(cin, path);

        cout <<"Please enter your key" <<endl;
        string key;
        cin.ignore();
        getline(cin, key);                                                                  // reads the entire line of the message within the program, including spaces
        for (char& c : key) c = toupper(c);                                                     // converts every character written in lower case to upper case

        ImageHandler next;
        if (next.validateImage(path))
        {
            if (next.loadImage(path))
            {
                Steganography back;
                string hiddenText = back.decode(next.getImage());
                string decryptedText = decrypt(hiddenText, key);
                cout <<"Your message has been decrypted successfully" << endl;
                cout << decryptedText << endl;

            }
            else
            {
                cout << "Failed to load image" << endl;
            }
        }
        else
        {
            cout << "Wrong file format" << endl;
        }
        break;
    }

    case 3:
        cout<<"Exit";
        break;
}
    system("pause");
    return 0;
}

