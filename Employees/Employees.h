#pragma once

#include <iostream>
#include <list>
#include <string>
#include <functional>

enum class CL {
	CL1,
	CL2,
	CL3,
	CL4
};
CL strToCL(const std::string&);

enum class CERTI {
	ADV,
	PRO,
	EX,
};
CERTI strToCerti(const std::string&);

unsigned strToEmployeeNumber(const std::string&);

struct Employee
{
	const unsigned employeeNumber; // 69xxxxxx ~ 21xxxxxx
	std::string firstName;
	std::string lastName;
	CL cl;
	unsigned phoneNumMid; // xxxx
	unsigned phoneNumLast; // xxxx
	unsigned birth; // YYYYMMDD
	CERTI certi;

	Employee(std::string employeeNumber_, std::string firstName_, std::string lastName_, std::string cl_, std::string phoneNumMid_, std::string phoneNumLast_, std::string birth_, std::string certi_)
		: employeeNumber(strToEmployeeNumber(employeeNumber_)), firstName(std::move(firstName_)), lastName(std::move(lastName_)), phoneNumMid(stoi(phoneNumMid_)), phoneNumLast(stoi(phoneNumLast_)), birth(stoi(birth_))
	{
		cl = strToCL(cl_);
		certi = strToCerti(certi_);
	}

	const bool operator== (const Employee& b) const
	{
		if (employeeNumber == b.employeeNumber)
			return true;
		else
			return false;
	}

	const bool operator< (const Employee& b) const
	{
		if (employeeNumber < b.employeeNumber)
			return true;
		else
			return false;
	}

	const bool operator> (const Employee& b) const
	{
		return !operator<(b);
	}
};

using employeeList = std::list<Employee>;

// pure virtual class (interface)
class Employees
{
public:
	virtual void add(Employee&) = 0;
	virtual void del(Employee&) = 0;
	virtual void modify(Employee&, std::function<void (Employee&)>) = 0;
	virtual employeeList search(std::function<bool(Employee&)>) = 0;
	virtual const employeeList* const getEmployees() const = 0;
};

Employees* createEmployees();
