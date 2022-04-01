#pragma once

#include "../Command/Command.h"
#include <string>
#include <vector>

using namespace std;

class InputParserManager {
public:
    InputParserManager() {
    }

    ~InputParserManager() {
    }

    vector <string> GetEachLineParsedStrings(string astring);
    vector<Command*> GetCommandList(vector<string> inputstrings);

};
