#include <iostream>
#include <string>

#include "file_input_manager.h"
#include "input_parser_manager.h"
#include "../Command/Command.h"
#include "../Employees/Employees.h"

using namespace std;

int main(int argc, char* argv[])
{
	const char* inputfilename = argv[1];
	const char* outputfilename = argv[2];

	FileInputManager* inputmanager = new FileInputManager(inputfilename);
	InputParserManager* parsermanager = new InputParserManager();

	if (!inputmanager->IsFileValid()) return 0;

	vector<string> inputstrings = inputmanager->GetInputStringsFromFile();
	vector<Command*> command_list = parsermanager->GetCommandList(inputstrings);

	//Employees* employees = CreateEmployees();
	for (auto a_command : command_list) {
		//a_command->Process(employees);
	}

	//delete employees;
	delete inputmanager;
	delete parsermanager;


	return 0;
}

