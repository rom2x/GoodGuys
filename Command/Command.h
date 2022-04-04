#pragma once

#include <iostream>
#include <vector>

#include "../Employees/employees.h"

using namespace std;

class Command
{
public:
	Command(vector<string> command) : command_(command) {
	}

	virtual string Process(Employees* database) = 0;
	virtual void CommandValidation() = 0;

	vector<string>& get_command(void)
	{
		return this->command_;
	}

protected:
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

class Add : public Command
{
public:
	Add(vector<string> command) : Command(command)
	{
		this->CommandValidation();
	}

	virtual string Process(Employees* database) override
	{
		cout << "do Add" << endl;

		//Employee employee;
		//database->add(employee);
		return "";
	}

	virtual void CommandValidation() override
	{
		if (this->ADD_COMMAND_SIZE != this->get_command().size())
			throw invalid_argument("## ERROR :: Add()");
	}
private:
	static const int ADD_COMMAND_SIZE = 10;
};

class Del : public PrintableCommand
{
public:
	Del(vector<string> command) : PrintableCommand(command)
	{
		this->CommandValidation();
	}

	virtual string Process(Employees* database) override
	{
		cout << "do Del" << endl;

		throw invalid_argument("TODO: need to impl");

		//Employee employee;
		//result_employees = database->del(employee);
		return PrintResult(result_employees);
	}

	virtual void CommandValidation() override
	{
		if (this->DEL_COMMAND_SIZE != this->get_command().size())
			throw invalid_argument("## ERROR :: Del()");
	}
private:
	static const int DEL_COMMAND_SIZE = 6;
};

class Search : public PrintableCommand
{
public:
	Search(vector<string> command) : PrintableCommand(command)
	{
		this->CommandValidation();
	}

	virtual string Process(Employees* database) override
	{
		cout << "do Search" << endl;

		throw invalid_argument("TODO: need to impl");

		// TODO: this->getSearch()->search(employee);
		return PrintResult(result_employees);
	}

	virtual void CommandValidation() override
	{
		if (this->SEARCH_COMMAND_SIZE != this->get_command().size())
			throw invalid_argument("## ERROR :: Search()");
	}

private:
	static const int SEARCH_COMMAND_SIZE = 6;
};

class Modify : public PrintableCommand
{
public:
	Modify(vector<string> command) : PrintableCommand(command)
	{
		this->CommandValidation();
	}

	virtual string Process(Employees* database) override
	{
		cout << "do Modify" << endl;

		throw invalid_argument("TODO: need to impl");

		//Employee src_employee;
		//Employee dst_employee;
		//result_employees = database->modify(src_employee, dst_employee);
		return PrintResult(result_employees);
	}

	virtual void CommandValidation() override
	{
		if (this->MODIFY_COMMAND_SIZE != this->get_command().size())
			throw invalid_argument("## error :: modify()");
	}

private:
	static const int MODIFY_COMMAND_SIZE = 8;
};

static Command* GetAddCommand(vector<string> input_cmd_param) {
	return new Add(input_cmd_param);
}

static Command* GetDelCommand(vector<string> input_cmd_param) {
	return new Del(input_cmd_param);
}

static Command* GetModCommand(vector<string> input_cmd_param) {
	return new Modify(input_cmd_param);
}

static Command* GetSchCommand(vector<string> input_cmd_param) {
	return new Search(input_cmd_param);
}