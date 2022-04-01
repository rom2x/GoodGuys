#include "file_input_manager.h"

vector <string> FileInputManager::GetInputStringsFromFile() {
	vector<string> result;
	string eachline;
	string::size_type fpos, lpos;

	while (IsEndOfFile() == false) {
		getline(input_file_stream_, eachline);
		fpos = eachline.find_first_not_of(',', 0);
		lpos = eachline.find_first_of(',', fpos);

		while (string::npos != fpos || string::npos != lpos) {
			result.push_back(eachline.substr(fpos, lpos - fpos));
			fpos = eachline.find_first_not_of(',', lpos);
			lpos = eachline.find_first_of(',', fpos);
		}
	}
	return result;
}

