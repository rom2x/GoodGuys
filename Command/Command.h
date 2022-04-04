#pragma once

#include <iostream>
#include <vector>

#include "../Employees/employees.h"
#include "../Search/Search.h"

using namespace std;

class Command
{
public:
	Command(string name, vector<string> command) : name_(name), command_(command) {
	}

	virtual string Process(Employees* database) = 0;
	virtual void CommandValidation() = 0;

	vector<string>& get_command(void) {
		return this->command_;
	}

	string& get_name(void) {
		return this->name_;
	}

	virtual SearchInput get_search_input(void);

	void print_error_msg(void) {
		string errorMessage = "## ERROR ::" + get_command()[0] + ". size: ";
		cout << errorMessage;
		cout << this->get_command().size() << endl;
		throw invalid_argument(errorMessage);
	}

protected:
	string name_;
	vector<string> command_;
};

class PrintableCommand : public Command
{
public:
	using Command :: Command;
	string PrintResult(vector<Employee*> employees) {
		string str = "";
		if (command_[1] == " ") {
			str = command_[0] + "," + std::to_string(employees.size()) + "\n";
		}
		else if (command_[1] == "-p") {
			int employeeCount = 0;
			for (Employee* employee : employees) {
				str += (command_[0] + "," + employee->to_string() + "\n");
				if (++employeeCount >= 5) break;
			}
		}
		return str;
	}
	vector<Employee*> result_employees;
};

class AddCommand : public Command
{
public:
	AddCommand(vector<string> command) : Command("ADD", command)
	{
		this->CommandValidation();
	}

	virtual string Process(Employees* database) override;
	virtual void CommandValidation() override;

private:
	static const int ADD_COMMAND_SIZE = 10;
};

class DelCommand : public Command
{
public:
	DelCommand(vector<string> command) : Command("DEL", command)
	{
		this->CommandValidation();
	}

	virtual string Process(Employees* database) override;
	virtual void CommandValidation() override;

private:
	static const int DEL_COMMAND_SIZE = 6;
};

class SearchCommand : public Command
{
public:
	SearchCommand(vector<string> command) : Command("SCH", command)
	{
		this->CommandValidation();
	}

	virtual string Process(Employees* database) override;
	virtual void CommandValidation() override;

private:
	static const int SEARCH_COMMAND_SIZE = 6;
};

class ModifyCommand : public Command
{
public:
	ModifyCommand(vector<string> command) : Command("MOD", command)
	{
		this->CommandValidation();
	}

	virtual string Process(Employees* database) override;
	virtual void CommandValidation() override;

private:
	static const int MODIFY_COMMAND_SIZE = 8;
};

static Command* GetAddCommand(vector<string> input_cmd_param) {
	return new AddCommand(input_cmd_param);
}

static Command* GetDelCommand(vector<string> input_cmd_param) {
	return new DelCommand(input_cmd_param);
}

static Command* GetModCommand(vector<string> input_cmd_param) {
	return new ModifyCommand(input_cmd_param);
}

static Command* GetSchCommand(vector<string> input_cmd_param) {
	return new SearchCommand(input_cmd_param);
}