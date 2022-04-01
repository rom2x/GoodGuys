#include <iostream>
#include <string>

#include "file_input_manager.h"

using namespace std;

int main(int argc, char* argv[])
{
	const char* inputfilename = argv[1];
	const char* outputfilename = argv[2];

	FileInputManager* inputmanager = new FileInputManager(inputfilename);

	if (inputmanager->IsFileValid()) {
		vector<string> inputstrings = inputmanager->GetInputStringsFromFile();
	}

	return 0;
}

