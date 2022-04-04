#include <iostream>
#include <string>
#include <memory>

#include "file_input_manager.h"
#include "file_output_manager.h"
#include "input_parser_manager.h"
#include "../command/command.h"
#include "../Employees/Employees.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3 || !argv[1] || !argv[2]) {
		cout << "Invalid input parameter.\nex) goodguys.exe input.txt output.txt" << endl;
		return EXIT_FAILURE;
	}

	unique_ptr< FileInputManager> inputmanager = make_unique<FileInputManager>(argv[1]);
	unique_ptr< FileOutputManager> outputmanager = make_unique<FileOutputManager>(argv[2]);
	unique_ptr< InputParserManager> parsermanager = make_unique<InputParserManager>();

	if (!inputmanager->IsFileValid()) return EXIT_FAILURE;

	vector<Command*> command_list = parsermanager->GetCommandList(inputmanager->GetInputStringsFromFile());

	Employees* employees = CreateEmployees();
	for (auto a_command : command_list) {
		outputmanager->WriteResultToFile(a_command->Process(employees));
	}

	return EXIT_SUCCESS;
}

