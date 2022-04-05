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
	enum class CommandOffset
	{
		OFFSET_0,
		COMMAND = OFFSET_0,    // ADD, DEL, SCH, MOD
		OFFSET_1,
		PRINT = OFFSET_1,      // -p
		OFFSET_2,
		SUB_OPTION = OFFSET_2, // (-f, -l), (-m, -l), (-y, -m, -d)
		OFFSET_3, // NOT USED
		OFFSET_4,
		ADD__EMPLOYEE_NUM = OFFSET_4,
		SEARCH__SRC_KEY = OFFSET_4,
		OFFSET_5,
		ADD__NAME = OFFSET_5,
		SEARCH__SRC_VALUE = OFFSET_5,
		OFFSET_6,
		ADD__CL = OFFSET_6,
		MODIFY__DST_KEY = OFFSET_6,
		OFFSET_7,
		ADD__PHONE_NUM = OFFSET_7,
		MODIFY__DST_VALUE = OFFSET_7,
		OFFSET_8,
		ADD__BIRTHDAY = OFFSET_8,
		OFFSET_9,
		ADD__CERTI = OFFSET_9,
	};

	Command(string name, vector<string> params) : name_(name), params_(params) {
	}

	virtual string Process(Employees* employees) = 0;
	virtual void CommandValidation() = 0;

	vector<string>& params(void) {
		return this->params_;
	}
	string& param(CommandOffset command_offset)
	{
		return this->params_[static_cast<int>(command_offset)];
	}

	string& name(void) {
		return this->name_;
	}

	void print_error_msg(void) {
		string errorMessage = "## ERROR ::" + param(CommandOffset::COMMAND) + ". size: ";
		cout << errorMessage;
		cout << this->params().size() << endl;
		throw invalid_argument(errorMessage);
	}

private:
	string name_;
	vector<string> params_;
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
	AddCommand(vector<string> command) : Command("ADD", command) {
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
	DelCommand(vector<string> command) : SearchableCommand("DEL", command) {
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
	SearchCommand(vector<string> command) : SearchableCommand("SCH", command) {
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
	ModifyCommand(vector<string> command) : SearchableCommand("MOD", command) {
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