#include <iostream>
#include "Grammar.h"

// Implement Grammar methods here
Grammar::Grammar() : rules{} {}

void Grammar::addProduction(const std::string &nonTerm, const std::string &rhs)
{
    rules[nonTerm].push_back(rhs);
}

std::string Grammar::getRandomRHS(const std::string &nonTerm)
{
    std::vector<std::string> &list = rules.at(nonTerm);
    return list[std::rand() % list.size()];
}

bool Grammar::containsNonTerminal(const std::string &nonTerm)
{
    return rules.find(nonTerm) != rules.end();
}

void Grammar::print()
{
    std::cout << "=========== Grammar Rules =================" << "\n";
    for (auto it = rules.begin(); it != rules.end(); it++)
    {
        printf("%s --->\n", it->first.c_str());
        std::vector<std::string> current_rule = it->second;
        for (int i = 0; i < (it->second).size(); i++)
        {
            printf("     %s\n", current_rule[i].c_str());
        }
        std::cout << "\n";
    }
    std::cout << "===========================================" << "\n\n";
}