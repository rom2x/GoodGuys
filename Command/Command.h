#pragma once

#include <iostream>
#include <vector>

#include "../Employees/Employees.h"

using namespace std;
#define NUM_OPTION_PARAM	(3)
struct Option
{
	// -p
	// -f / -l / -m / -l / -y / -m / -d
	// not used
	string param[NUM_OPTION_PARAM]; 
};

class Command {
public:
	Command(Employees* db) :db(db) {}

	// NOTE: parser 에서 애초에 Employee 및 Option 잘라서 주면 좋을듯 하다.
	void process(vector<string> cmdLine)
	{
		static const int CMD_LINE_SIZE = 9;
		if (CMD_LINE_SIZE != cmdLine.size())
		{
			cout << "## ERROR :: process. size:" << cmdLine.size() << endl;
			throw invalid_argument("");
		}

		Option option = parseToOption(cmdLine);
		Employee employee = parseToEmployee(cmdLine);

		this->doCommand(option, employee);
	}

	virtual void doCommand(Option option, Employee& employee) = 0;
	Employees* getDatabase(void)
	{
		return this->db;
	}
private:
	// TODO: need to impl
	Option parseToOption(vector<string> cmdLine)
	{
		throw invalid_argument("");

		int cmdLineIndex = 0;
		Option option;
		for (int i = 0; i < NUM_OPTION_PARAM; i++)
		{
			option.param[i] = cmdLine[cmdLineIndex++];
		}
		return option;
	}

	// TODO: need to impl
	Employee parseToEmployee(vector<string> cmdLine)
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

	Employees* db;
};

// TODO: class 명 변경.
class Add :public Command
{
public:
	Add(Employees* db) : Command(db){}

	virtual void doCommand(Option option, Employee& employee) override {
		cout << "do Add" << endl;

		// TODO: process Option

		this->getDatabase()->add(employee);
	}
};
class Del :public Command
{
public:
	Del(Employees* db) : Command(db) {}

	virtual void doCommand(Option option, Employee& employee) override {
		// TODO: process Option
		cout << "do Del" << endl;
		this->getDatabase()->del(employee);
	}
};
class Search :public Command
{
public:
	Search(Employees* db) : Command(db) {}

	virtual void doCommand(Option option, Employee& employee) override {
		cout << "do Search" << endl;

		// TODO: process Option
		// TODO: this->getSearch()->search(employee);
	}
};
class Modify :public Command
{
public:
	Modify(Employees* db) : Command(db) {}

	virtual void doCommand(Option option, Employee& employee) override {
		// TODO: doCommand 로 커버 안됨.. 설계 확인 필요.
		cout << "do Modify" << endl;

		// TODO: process Option
		this->getDatabase()->modify(employee, employee);
	}
};