#include "input_parser_manager.h"

vector<Command*> InputParserManager::GetCommandList(vector<string> inputstrings) {
	vector<Command*> result;

	for (auto astring : inputstrings) {
		vector <string> parsedstring = GetEachLineParsedStrings(astring);

		auto commandtype = parsedstring[0];
		result.emplace_back(GetCommand_[command_to_index_[commandtype]](parsedstring));
	}

	return result;
}

vector <string> InputParserManager::GetEachLineParsedStrings(string astring) {
	vector<string> result;
	string::size_type fpos, lpos;

	fpos = astring.find_first_not_of(',', 0);
	lpos = astring.find_first_of(',', fpos);

	while (string::npos != fpos || string::npos != lpos) {
		result.emplace_back(astring.substr(fpos, lpos - fpos));
		fpos = astring.find_first_not_of(',', lpos);
		lpos = astring.find_first_of(',', fpos);
	}
	return result;
}

