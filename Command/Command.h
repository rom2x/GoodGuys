#pragma once

#include <iostream>
#include <vector>

#include "../Employees/Employees.h"

using namespace std;

constexpr auto NUM_OPTION_PARAM = (3);

struct Option
{
	// param[0] : -p
	// param[1] : -f / -l / -m / -l / -y / -m / -d
	// param[2] : not used
	string param[NUM_OPTION_PARAM];
};

class Command {
public:
	Command(Employees* db) :db_(db) {}

	virtual void Process(vector<string> cmdLine) = 0;

	Employees* get_database(void)
	{
		return this->db_;
	}

private:
	Employees* db_;
	//Parser* parser;
};

// TODO: class 명 변경.
class Add :public Command
{
public:
	Add(Employees* db) : Command(db) {}

	virtual void Process(vector<string> cmdLine) override
	{
		cout << "do Add" << endl;

		throw invalid_argument("TODO: need to impl");

		Employee employee;
		this->get_database()->add(employee);
	}
};

class Del :public Command
{
public:
	Del(Employees* db) : Command(db) {}

	virtual void Process(vector<string> cmdLine) override
	{
		cout << "do Del" << endl;

		throw invalid_argument("TODO: need to impl");

		Employee employee;
		this->get_database()->del(employee);
	}
};

class Search :public Command
{
public:
	Search(Employees* db) : Command(db) {}

	virtual void Process(vector<string> cmdLine) override
	{
		cout << "do Search" << endl;

		throw invalid_argument("TODO: need to impl");

		// TODO: this->getSearch()->search(employee);
	}
};

class Modify :public Command
{
public:
	Modify(Employees* db) : Command(db) {}

	virtual void Process(vector<string> cmdLine) override
	{
		cout << "do Modify" << endl;

		throw invalid_argument("TODO: need to impl");
		
		Employee src_employee;
		Employee dst_employee;
		this->get_database()->modify(src_employee, dst_employee);
	}
};
