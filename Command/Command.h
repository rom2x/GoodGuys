#pragma once
#define PRINT_CONSOLE  (0)

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

	virtual string Process(Employees* employees) = 0;
	virtual void CommandValidation() = 0;

	vector<string>& get_command(void) {
		return this->command_;
	}

	string& get_name(void) {
		return this->name_;
	}

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

class SearchableCommand : public Command
{
public:
	using Command :: Command;
	employeeList SearchEmployees(Employees* employees) {
		shared_ptr<Search> search(new Search());
		search->SetEmployeeList(employees);
		return std::move(search->DoSearch(GetSearchType(), GetSearchPattern()));
	}

private:
	string GetSearchPattern(void);
	SearchType GetSearchType(void);
};

class AddCommand : public Command
{
public:
	AddCommand(vector<string> command) : Command("ADD", command)
	{
		this->CommandValidation();
	}

	virtual string Process(Employees* employees) override;
	virtual void CommandValidation() override;

private:
	static const int ADD_COMMAND_SIZE = 10;
};

class DelCommand : public SearchableCommand
{
public:
	DelCommand(vector<string> command) : SearchableCommand("DEL", command)
	{
		this->CommandValidation();
	}

	virtual string Process(Employees* employees) override;
	virtual void CommandValidation() override;

private:
	static const int DEL_COMMAND_SIZE = 6;
};

class SearchCommand : public SearchableCommand
{
public:
	SearchCommand(vector<string> command) : SearchableCommand("SCH", command)
	{
		this->CommandValidation();
	}

	virtual string Process(Employees* employees) override;
	virtual void CommandValidation() override;

private:
	static const int SEARCH_COMMAND_SIZE = 6;
};

class ModifyCommand : public SearchableCommand
{
public:
	ModifyCommand(vector<string> command) : SearchableCommand("MOD", command)
	{
		this->CommandValidation();
	}

	virtual string Process(Employees* employees) override;
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