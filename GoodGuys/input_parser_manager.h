#pragma once

#include "../Command/Command.h"
#include <string>
#include <vector>
#include <map>
#include <functional>

using namespace std;

const unsigned int MAX_COMMAND_TYPE = 4;

class InputParserManager {
public:
    InputParserManager() {
        command_to_index_["ADD"] = 0;
        command_to_index_["DEL"] = 1;
        command_to_index_["SCH"] = 2;
        command_to_index_["MOD"] = 3;
    }

    ~InputParserManager() {
    }

    vector <string> GetEachLineParsedStrings(string astring);
    vector<Command*> GetCommandList(vector<string> inputstrings);

private:
    function< Command* (vector<string>)> GetCommand_[MAX_COMMAND_TYPE] = { GetAddCommand , GetDelCommand , GetSchCommand , GetModCommand };
    map<string, int> command_to_index_;
};

