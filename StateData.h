#ifndef STATEDATA_H
#define STATEDATA_H

#include <string>
#include <map>
#include <iostream>

class StateData {
private:
    std::map<std::string, std::string> stateMap;
    // We'll add a helper function declaration here if needed later
    std::string normalizeState(const std::string& state) const;

public:
    // Declaration of functions
    StateData();
    void queryCapital();
};

#endif // STATEDATA_H
