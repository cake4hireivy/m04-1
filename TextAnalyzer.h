#ifndef TEXTANALYZER_H
#define TEXTANALYZER_H

#include <string>
#include <set>
#include <fstream>
#include <iostream>

class TextAnalyzer {
private:
    std::set<std::string> uniqueWords; 

public:
    // Declaration of functions
    bool loadFile(const std::string& filename);
    void displayWords() const;
};

#endif // TEXTANALYZER_H
