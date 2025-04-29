#include <fstream>
#include <iostream>
#include "RandomSentenceGenerator.h"

// Implement RandomSentenceGenerator methods here
void RandomSentenceGenerator::load(const std::string &fileName)
{
    std::string curr_file = fileName;
    std::ifstream inStream(curr_file, std::ios::in);
    if (!inStream.is_open())
    {
        std::cout << "Failed to open: " << curr_file << "\n";
    }
    else
    {
        std::string line;
        while (inStream.good())
        {
            std::getline(inStream, line);
            line.erase(line.find_last_not_of(" \r\n\t") + 1); // Remove whitespace at the end of the string
            std::cout << line << "\n";
        }
    }
    inStream.close();
}

RandomSentenceGenerator::RandomSentenceGenerator(const std::string &fileName) : grammar()
{
    
    load(fileName);
}

std::string RandomSentenceGenerator::randomSentence()
{
    return "hello world";
}