#pragma once

#include "Grammar.h"

class RandomSentenceGenerator {

private:
    Grammar grammar;

    void load( const std::string & fileName );

public:
    RandomSentenceGenerator( const std::string & fileName );

    std::string randomSentence();

    void printGrammar() { grammar.print(); }
    
};