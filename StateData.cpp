#include "StateData.h"
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>
#include <limits>

// Best practice is to not use 'using namespace std;' in .cpp files

// Constructor implementation: Initializing the map with all 50 U.S. states and capitals.
StateData::StateData() {
    // This uses C++11 initializer list syntax for std::map insertion, 
    // which is the clearest way to populate the map.
    stateMap["Alabama"] = "Montgomery";
    stateMap["Alaska"] = "Juneau";
    stateMap["Arizona"] = "Phoenix";
    stateMap["Arkansas"] = "Little Rock";
    stateMap["California"] = "Sacramento";
    stateMap["Colorado"] = "Denver";
    stateMap["Connecticut"] = "Hartford";
    stateMap["Delaware"] = "Dover";
    stateMap["Florida"] = "Tallahassee";
    stateMap["Georgia"] = "Atlanta";
    stateMap["Hawaii"] = "Honolulu";
    stateMap["Idaho"] = "Boise";
    stateMap["Illinois"] = "Springfield";
    stateMap["Indiana"] = "Indianapolis";
    stateMap["Iowa"] = "Des Moines";
    stateMap["Kansas"] = "Topeka";
    stateMap["Kentucky"] = "Frankfort";
    stateMap["Louisiana"] = "Baton Rouge";
    stateMap["Maine"] = "Augusta";
    stateMap["Maryland"] = "Annapolis";
    stateMap["Massachusetts"] = "Boston";
    stateMap["Michigan"] = "Lansing";
    stateMap["Minnesota"] = "St. Paul";
    stateMap["Mississippi"] = "Jackson";
    stateMap["Missouri"] = "Jefferson City";
    stateMap["Montana"] = "Helena";
    stateMap["Nebraska"] = "Lincoln";
    stateMap["Nevada"] = "Carson City";
    stateMap["New Hampshire"] = "Concord";
    stateMap["New Jersey"] = "Trenton";
    stateMap["New Mexico"] = "Santa Fe";
    stateMap["New York"] = "Albany";
    stateMap["North Carolina"] = "Raleigh";
    stateMap["North Dakota"] = "Bismarck";
    stateMap["Ohio"] = "Columbus";
    stateMap["Oklahoma"] = "Oklahoma City";
    stateMap["Oregon"] = "Salem";
    stateMap["Pennsylvania"] = "Harrisburg";
    stateMap["Rhode Island"] = "Providence";
    stateMap["South Carolina"] = "Columbia";
    stateMap["South Dakota"] = "Pierre";
    stateMap["Tennessee"] = "Nashville";
    stateMap["Texas"] = "Austin";
    stateMap["Utah"] = "Salt Lake City";
    stateMap["Vermont"] = "Montpelier";
    stateMap["Virginia"] = "Richmond";
    stateMap["Washington"] = "Olympia";
    stateMap["West Virginia"] = "Charleston";
    stateMap["Wisconsin"] = "Madison";
    stateMap["Wyoming"] = "Cheyenne";
}

// Helper function implementation
std::string StateData::normalizeState(const std::string& state) const {
    // Trim leading/trailing whitespace
    std::string normalized = state;
    normalized.erase(0, normalized.find_first_not_of(" \t\n\r"));
    normalized.erase(normalized.find_last_not_of(" \t\n\r") + 1);

    // Apply Title Case conversion for proper lookup (e.g., "new york" -> "New York")
    if (!normalized.empty()) {
        bool capitalizeNext = true;
        for (char& c : normalized) {
            if (std::isspace(c)) {
                capitalizeNext = true;
            } else if (capitalizeNext) {
                c = std::toupper(c);
                capitalizeNext = false;
            } else {
                c = std::tolower(c);
            }
        }
    }
    return normalized;
}


// queryCapital function implementation
void StateData::queryCapital() {
    std::string inputState;

    // Use std::cout/std::cin without 'using namespace std;'
    std::cout << "Enter state name: ";
    if (!std::getline(std::cin, inputState)) {
        // Handle input failure (e.g., Ctrl+D/Ctrl+Z)
        return;
    }

    // Normalize input to match map keys (e.g., "nevada" -> "Nevada")
    std::string normalizedState = normalizeState(inputState);
    
    // std::map::find provides fast lookup (O(log N))
    auto it = stateMap.find(normalizedState);

    if (it != stateMap.end()) {
        std::cout << "The capital of " << it->first << " is: " << it->second << std::endl;
    } else {
        std::cout << "Error: State '" << inputState << "' not found. (Tried searching for '" << normalizedState << "')." << std::endl;
    }
}