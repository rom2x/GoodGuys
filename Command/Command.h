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

	virtual void Process(Employees* database) = 0;
	virtual void CommandValidation() = 0;

	vector<string>& get_command(void)
	{
		return this->command_;
	}

private:
	vector<string> command_;
};

class Add : public Command
{
public:
	Add(vector<string> command) : Command(command)
	{
		this->CommandValidation();
	}

	virtual void Process(Employees* database) override
	{
		cout << "do Add" << endl;

		//Employee employee;
		//database->add(employee);
	}

	virtual void CommandValidation() override
	{
		if (this->ADD_COMMAND_SIZE != this->get_command().size())
			throw invalid_argument("## ERROR :: Add()");
	}
private:
	static const int ADD_COMMAND_SIZE = 10;
};

class Del : public Command
{
public:
	Del(vector<string> command) : Command(command)
	{
		this->CommandValidation();
	}

	virtual void Process(Employees* database) override
	{
		cout << "do Del" << endl;

		throw invalid_argument("TODO: need to impl");

		//Employee employee;
		//database->del(employee);
	}

	virtual void CommandValidation() override
	{
		if (this->DEL_COMMAND_SIZE != this->get_command().size())
			throw invalid_argument("## ERROR :: Del()");
	}
private:
	static const int DEL_COMMAND_SIZE = 6;
};

class Search : public Command
{
public:
	Search(vector<string> command) : Command(command)
	{
		this->CommandValidation();
	}

	virtual void Process(Employees* database) override
	{
		cout << "do Search" << endl;

		throw invalid_argument("TODO: need to impl");

		// TODO: this->getSearch()->search(employee);
	}

	virtual void CommandValidation() override
	{
		if (this->SEARCH_COMMAND_SIZE != this->get_command().size())
			throw invalid_argument("## ERROR :: Search()");
	}

private:
	static const int SEARCH_COMMAND_SIZE = 6;
};

class Modify : public Command
{
public:
	Modify(vector<string> command) : Command(command)
	{
		this->CommandValidation();
	}

	virtual void Process(Employees* database) override
	{
		cout << "do Modify" << endl;

		throw invalid_argument("TODO: need to impl");

		//Employee src_employee;
		//Employee dst_employee;
		//database->modify(src_employee, dst_employee);
	}

	virtual void CommandValidation() override
	{
		if (this->MODIFY_COMMAND_SIZE != this->get_command().size())
			throw invalid_argument("## error :: modify()");
	}

private:
	static const int MODIFY_COMMAND_SIZE = 8;
};
