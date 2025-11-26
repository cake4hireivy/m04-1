#include "TextAnalyzer.h"
// Best practice is to not use 'using namespace std;' in .cpp files

bool TextAnalyzer::loadFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return false;
    }

    std::string word;
    while (inputFile >> word) {
        uniqueWords.insert(word);
    }
    inputFile.close();
    return true;
}

void TextAnalyzer::displayWords() const {
    std::cout << "\nNon-duplicate words in ascending order:\n";
    std::cout << "---------------------------------------\n";
    for (const auto& word : uniqueWords) {
        std::cout << word << std::endl;
    }
}
