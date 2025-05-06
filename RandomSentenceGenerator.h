#pragma once
#include <sstream>
#include <regex>
#include "Grammar.h"

class RandomSentenceGenerator
{

private:
    Grammar grammar;

    /**
     * Given a file name ending with .g, it parses the grammar to be used in creating random sentences by utilizing
     * a map to map a nonterminal to a list of possible senences for the sentece.
     */
    void load(const std::string &fileName);

    /**
     * Utiizes recursion to replace a nonterminal with a desired sentence.
     */
    std::string generateSentence(const std::string &nonterm);

public:
    /**
     * A constructor that is passed the name of the file containing the grammar rules. This will parse the file, 
     * and create a Grammar instance, filling it with data from the file. To do so, you will call addProduction 
     * repeatedly, once for each possible production.
     */
    RandomSentenceGenerator(const std::string &fileName);

    /**
     * Returns a random sentence generated from the grammar. Call getRandomRHS("<start>") on the instance variable,
     * and then search the result for any non-terminals. If you find one, call getRandomRHS with that non-terminal,
     * and replace the non-terminal with the result. Then, repeat until there are no non-terminals remaining. 
     * Finally, return the string.
     */
    std::string randomSentence();

    /**
     * Prints the grammar rules in a readable format to the standard output. Call print() via the Grammar object
     */
    void printGrammar() { grammar.print(); }
};