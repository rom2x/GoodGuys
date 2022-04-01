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
	Command(Employees* db) :db(db) {}

	// NOTE: parser 에서 애초에 Employee 및 Option 잘라서 주면 좋을듯 합니다.
	virtual void Process(vector<string> cmdLine) = 0;

	Employees* get_database(void)
	{
		return this->db;
	}

	// TODO: need to impl
	Option ParseToOption(vector<string> cmdLine)
	{
		int cmdLineIndex = 0;
		Option option;
		for (int i = 0; i < NUM_OPTION_PARAM; i++)
		{
			option.param[i] = cmdLine[cmdLineIndex++];
		}
		return option;
	}

	// TODO: need to impl
	Employee ParseToEmployee(vector<string> cmdLine)
	{
		throw invalid_argument("");

		int cmdLineIndex = 3;
		Employee employee;
		//employee.employeeNumber = stoi(cmdLine[cmdLineIndex++]); // NOTE: 앞에 0이 붙는데 상관 없나?
		employee.employeeNumber = 22222222; // NOTE: 앞에 0이 붙는데 상관 없나?
		//employee.firstName = cmdLine[cmdLineIndex]; // TODO: split;
		employee.firstName = "abab"; // TODO: split;
		employee.lastName = "cdcd"; // TODO: split;
		cmdLineIndex++;
		//employee.cl = static_cast<CL>(stoi(cmdLine[cmdLineIndex++]));
		employee.cl = CL::CL4;
		employee.phoneNumMid = 3626; // TODO: split;
		employee.phoneNumLast = 7777; // TODO: split;
		//employee.birth = stoi(cmdLine[cmdLineIndex++]);
		employee.birth = 19990111;
		//employee.certi = static_cast<CERTI>(stoi(cmdLine[cmdLineIndex++]));
		employee.certi = CERTI::EX;
		return employee;
	}

private:
	Employees* db;
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
