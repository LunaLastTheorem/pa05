#pragma once

#include <string>
#include <map>
#include <vector>

class Grammar
{

private:
    std::map<std::string, std::vector<std::string>> rules;

public:
    /**
     * Initializes the rules map with as an empty map
     */
    Grammar();

    /**
     * Takes the non-terminal (the left side of the production) and one of the right hand sides of the 
     * production and adds it to your data structure. If the non-terminal doesn’t exist in the map,
     * create it. If it does exist, add the right hand side to the list corresponding to that non-terminal. 
     * This will be used when loading the data from the file by the RandomSentenceGenerator constructor
     */
    void addProduction(const std::string &nonTerm, const std::string &rhs);

    /**
     * Takes a non-terminal and returns one of the right hand sides of the appropriate production chosen 
     * at random (see below for how to generate random numbers).
     */
    std::string getRandomRHS(const std::string &nonTerm);

    /**
     * Returns whether or not the grammar has a rule with the given non-terminal as its left hand side.
     */
    bool containsNonTerminal(const std::string &nonTerm);

    /**
     * Prints the grammar rules in a readable format to the standard output
     */
    void print();
};