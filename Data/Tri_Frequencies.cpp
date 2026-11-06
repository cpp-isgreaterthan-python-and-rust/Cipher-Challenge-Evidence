// This file's purpose is to count the frequencies of triples.
// This is for future tri-gram evaluation function: a function to gauge how similar a piece of text
// looks like English. This evaluation function is used often during the main search function, at the 
// moment of writing, planned to be mcts for reasons which will be specified
#include <iostream> // This allows the program to output text to the terminal
#include <fstream> // This allows the program to write and read text to other files, used in this case to make it much easier and systematic
#include <cstdint> // This allows the program to have integer type variables, such as uint8_t and size_t
#include <iostream> // Allows it to output to the user
#include <fstream> // Allows it to output to a file
#include <cstdint> // Lets the file use things like uint8_t
#include "Copied_Triples.h" // Includes a copy of Copied_Triples.h so that we can get information from more than one Project Gutenburg novel

int main()
{
    std::ofstream Write_File("Documented_Decryption/Data/Triples.h");

    if (!Write_File.is_open())
    {
        std::cout << "Failed to open Triples.h\n";
        return 1;
    }
    std::ifstream Reading_File("Documented_Decryption/Data/Converted.txt"); // Define the file we are reading from as Reading_File from Documented_Decryption/Data/Text.txt
    if(!Reading_File.is_open()) // If the file fails to open, we alert the user.
    {
        std::cout << "Failed to open Reading_File from: Documented_Decryption/Data/Text.txt\n"; // Alert the user
        return 1; // Exit int main() immediately, we return 1 instead of return 0, as it is good practice and this is a programming project
    }
    std::string Input_String{}; // Create the string to store characters. The entire contents of reading file should be on one line as "\n" characters are removed during Conversion.cpp
    std::getline(Reading_File,Input_String); // Get the input string, using getline()


    for(size_t Position{}; Position + 2 < Input_String.length(); Position++) // We loop over all the possible starts of triples to guarantee we select every triple. Position + 2 < Input_String.length() is used because if it was just Position < Input_String.length() then Input_String[Position + 2] would cause undefined behaviour
    {
        char A = Input_String[Position] - 'a', B = Input_String[Position + 1] - 'a', C = Input_String[Position + 2] - 'a'; // A is first character, B is second character, C is second character.
        Triples[A][B][C]++; // Increment the triple.
    }

    Write_File << "#pragma once\n"; // Useful for .h files like the one we are building.
    Write_File << "double Triples[26][26][26] =\n{\n"; // Create the Triples array. The Triples array is built in the following way because that is the style I like my arrays. This is *

    for(uint8_t First = 0; First < 26; First++)   // Loop over all the values of the first character in the array.
    {
        Write_File << "    {\n"; // Output "    {" followed by a new line. This is **

        for(uint8_t Second = 0; Second < 26; Second++) // Loop over all the values of the second character in the array
        {
            Write_File << "        {"; // Output "        {" This is ***

            for(uint8_t Third = 0; Third < 26; Third++) // Loop over all the values of the third and final character in the array
            {
                Write_File << Triples[First][Second][Third]; // Output the abundance of those triples occuring

                if(Third != 25) // If Third == 25, (meaning 'z') then if we output a comma, it will end in ",}" which is a syntax error, so if(Third != 25) is used to prevent that
                {    
                    Write_File << ","; // Output a comma
                }
            }

            Write_File << "}"; // Output a closing output corresponding to ***

            if(Second != 25) // Same thing as what we did with Third
            {
                Write_File << ","; // Output a comma
            }
            Write_File << "\n"; // Output a newline character
        }

        Write_File << "    }"; // Output a bracket corresponding to **

        if(First != 25) // Same thing as what we did with Second and Third
        {
            Write_File << ","; // Output a comma
        }
        Write_File << "\n"; // Write a newline
    }

    Write_File << "};\n"; // Output a bracket corresponding to *

    return 0; // End the program
}
