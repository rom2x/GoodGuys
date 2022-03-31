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

enum class CERTI {
	ADV,
	PRO,
	EX,
};

struct Employee
{
	unsigned employeeNumber; // 69xxxxxx ~ 21xxxxxx
	std::string firstName;
	std::string lastName;
	CL cl;
	unsigned phoneNumMid; // xxxx
	unsigned phoneNumLast; // xxxx
	unsigned birth; // YYYYMMDD
	CERTI certi;

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
	virtual const employeeList* const getEmployees() const = 0;
};

Employees* createEmployees();
