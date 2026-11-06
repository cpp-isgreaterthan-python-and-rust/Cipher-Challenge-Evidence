// This file's purpose is convert a punctuated, spaced Project Gutenburg novel into a format where 
// everything is lowercase characters
#include <iostream> // Able to output text
#include <fstream> // Able to read and output files
#include <cctype> // Includes tolower() and isalpha()

int main() // Define the function main(). The C++ compiler executes this function when running the code.
{
    std::ifstream Reading_File("Documented_Decryption/Data/Text.txt"); // Define the file we are reading from as Reading_File from Documented_Decryption/Data/Text.txt
    if(!Reading_File.is_open()) // If the file fails to open, we alert the user.
    {
        std::cout << "Failed to open Reading_File from: Documented_Decryption/Data/Text.txt\n"; // Alert the user
        return 1; // Exit int main() immediately, we return 1 instead of return 0, as it is good practice and this is a programming project
    } 
    std::cout << "Reading_File has opened successfully\n"; // Confirm to the user that the file has opened successfully
    std::ofstream Output_File("Documented_Decryption/Data/Converted.txt"); // Define the output file we convert to
    char Character{}; // In the conversion part of the program, we loop through the characters. This is the character we use for this defined outside of the while loop due to scope
    while(Reading_File.get(Character)) // We set Character to each character of Reading_File in order. A while loop is used for simplicity and that this part's speed is not in any way needed to be optimized
    {
        if(std::isalpha(static_cast<unsigned char>(Character))) // we use static_cast<unsigned char> because we wish to avoid special characters messing everything up
        {
            Output_File << static_cast<char>(std::tolower(static_cast<unsigned char>(Character))); // Add this to the end of Output_File
        }
        else if((Character == -15547) || (Character == -15546) || (Character == -15548)) // Accented e's used in café
        {
            Output_File << 'e'; // Just in case of café or the likes
        }
    }
    std::cout << "Finished Converting!"; // Tell the user we have finished converting the text into this format.
}
