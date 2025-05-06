#include <iostream>

#include "RandomSentenceGenerator.h"

int main(int argc, char** argv) {
    if( argc != 3 ) {
        std::cout << "Please provide input file name and random seed.\n";
        std::cout << argv[0] << " file_name seed\n";
        return 1;
    }

    int seed = std::stoi( std::string{argv[2]} );
    std::string fileName = std::string{argv[1]};
    std::srand( seed );

    // Instantiate RandomSentenceGenerator, print the grammar, then print a random sentence.
    RandomSentenceGenerator rand(fileName);
    rand.printGrammar();
    printf("Random sentence (seed = %d)\n\n", seed);
    printf("%s\n", rand.randomSentence().c_str());
    return 0;
}