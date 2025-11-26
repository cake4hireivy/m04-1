#include <iostream>
#include <string>
#include <algorithm> 
#include "TextAnalyzer.h" 
#include "StateData.h"    
#include <cctype>
#include <limits> 

using namespace std;

int main() {
    
    // --- PART 1: Unique Words ---
    cout << "=== PART 1: Unique Word Analyzer ===\n";
    TextAnalyzer analyzer; 
    string filename;
    
    cout << "Enter filename to process: ";
    cin >> filename;
    
    if (analyzer.loadFile(filename)) {
        analyzer.displayWords();
    }

    // Clear buffer after cin >> filename
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    // --- PART 2: State Capitals ---
    cout << "\n=== PART 2: State Capitals Lookup ===\n";
    StateData states;
    string inputStr;
    char choice; 
    
    do {
        states.queryCapital();
        
        // Input validation loop
        while (true) {
            cout << "Do you want to lookup another state? (y/n): ";
            
            // Read the entire line to check for "exact" matches
            if (!getline(cin, inputStr)) {
                break; // Handle edge case of stream closure
            }

            // Check if the input is exactly 1 character long
            if (inputStr.length() == 1) {
                char c = tolower(inputStr[0]);
                // Check if that single character is 'y' or 'n'
                if (c == 'y' || c == 'n') {
                    choice = c;
                    break; // Valid input found, break the validation loop
                }
            }

            // If string length isn't 1, or char isn't y/n, print error and repeat
            cout << "You must reply with y or n." << endl; 
        }

    } while (choice == 'y');

    cout << "\nProgram finished. Goodbye!\n";
    return 0;
}
