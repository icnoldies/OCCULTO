
#include <iostream>
#include "Cipher.h"

//* Encryption method (Vigenere Cipher type of encryption)

std::string encrypt(std::string message, std::string key)                                                          //* this tells to encrypt the message and the key
    {
    std::string result = "";                                                                                    //* created empty character for result to go to
    for (int i =0; i <message.length(); i++)                                                                    //* Created for loop so that the program goes through every character of the message one by one
    {
        if (isalpha(toupper(message[i])))                                                                   // creates the condition that checks whether the message had upper or lower cases and if teh condition is met then carry on with the result
        {
            char encryptedChar = (toupper(message[i]) - 'A' + (key[i % key.length()] - 'A')) % 26 + 'A';       //* The logic for encryption - toupper converts message into capital letters, message[i] -gets the current in the message at position i. - A converting it from ASCII (65-90) to 0-26 range. key[i % key.length()] gets the corresponding key character and wrapping it around if the message is longer than the key.
            result += encryptedChar;                                                                            // appends the encryptedChar to a result 
        }
        else
        {
            result += message[i];                                                                                //  if the character is not a letter ( but have a space, number or punctuation), just add it to result unchanged without encrypting it
        }
    }
        return result;                                                                                      // It sends the encrypted string back to whoever called the function so they can use it
}

//* Decryption method

std::string decrypt(std::string message, std::string key)
{
    std::string result = "";                                                                                // created an empty string for result to go to
    for (int i =0; i <message.length(); i++)                                                                // created a loop, to start from position 0; i <message.length() keep looping as long as "i" is less than the length of the message; after each iteration, i++ move to the next position
    {
        if (isalpha(toupper(message[i]))) {                                                                 // is alpha checks whether a message is a letter
            char decryptedChar = (toupper(message[i]) - 'A' - (key[i % key.length()] - 'A') + 26) % 26 + 'A';       // we subtracting the shift to go backwards, we need to add 26 because subtracting can go negative and to prevent it, we need to add 26 (letter of the alphabet)
            result += decryptedChar;                                                                                // appends decryptedChart to the result
        }
        else
        {
            result += message[i];
        }


    }
    return result;
}