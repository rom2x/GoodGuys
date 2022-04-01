#include "file_input_manager.h"

vector <string> FileInputManager::GetInputStringsFromFile() {
	vector<string> result;
	string eachline;

	while (IsEndOfFile() == false) {
		getline(input_file_stream_, eachline);
		if (!eachline.empty()) {
			result.push_back(eachline);
		}
	}
	return result;
}

