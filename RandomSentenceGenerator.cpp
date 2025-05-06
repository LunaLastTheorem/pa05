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
        return;
    }
    else
    {
        std::string line;
        std::string terminal;
        while (inStream.good())
        {
            while (std::getline(inStream, line))
            {
                line.erase(line.find_last_not_of(" \r\n\t") + 1);
                if (line == "{")
                {
                    break;
                }
            }
            std::getline(inStream, line);
            line.erase(line.find_last_not_of(" \r\n\t") + 1);
            terminal = line;

            while (std::getline(inStream, line))
            {
                line.erase(line.find_last_not_of(" \r\n\t") + 1);
                if (line == "}")
                {
                    break;
                }
                grammar.addProduction(terminal, line);
            }
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
    return generateSentence("<start>");
}

std::string RandomSentenceGenerator::generateSentence(const std::string &nonterm)
{
    std::stringstream ss;

    std::vector<std::string> tokens;
    std::stringstream tokenize(grammar.getRandomRHS(nonterm));
    std::string token;

    while (getline(tokenize, token, ' '))
    {
        tokens.push_back(token);
    }

    for (int i = 0; i < tokens.size(); i++)
    {
        std::string currToken = tokens[i];

        if(currToken[0] != '<'){
            ss << currToken << " ";
        }else{
            std::stringstream currTerm;
            int j = 0;
            for(; j < currToken.size(); j++){
                currTerm << currToken[j];
                if(currToken[j] == '>'){
                    j++;
                    break;
                }
            }
            ss << generateSentence(currTerm.str());
            for(; j < currToken.size(); j++){
                ss << currToken[j];
            }
            ss << " "; 
        }
    }
    std::string finalSentence = ss.str();
    
    finalSentence = std::regex_replace(finalSentence, std::regex(R"(\s+([.,!?;:]))"), "$1");
    finalSentence.erase(finalSentence.find_last_not_of(" \n\r\t") + 1);

    return finalSentence;
}