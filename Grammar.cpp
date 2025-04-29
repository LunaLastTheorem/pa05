#include <iostream>
#include "Grammar.h"

// Implement Grammar methods here
Grammar::Grammar() : rules{} {}


void Grammar::addProduction(const std::string &nonTerm, const std::string &rhs)
{
}


std::string Grammar::getRandomRHS(const std::string &nonTerm)
{
    return "test";
}


bool Grammar::containsNonTerminal(const std::string &nonTerm)
{
    return true;
}

void Grammar::print()
{
    std::cout << "=========== Grammar Rules =================" << "\n";
    for (auto it = rules.begin(); it != rules.end(); it++)
    {
        printf("<%s> --->\n", it->first);
        std::vector<std::string> current_rule = it->second;
        for (int i = 0; i < (it->second).size(); i++)
        {
            printf("     %s\n", current_rule[i]);
        }
        std::cout << "\n";
    }
    std::cout << "===========================================" << "\n";
}