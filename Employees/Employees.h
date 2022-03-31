#pragma once

#include <iostream>
#include <list>
#include <string>

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
	unsigned phoneNumMid; // xxxx
	unsigned phoneNumLast; // xxxx
	unsigned birth; // YYYYMMDD
	CL cl;
	CERTI certi;
};

using employeeList = std::list<Employee>;

// pure virtual class (interface)
class Employees
{
public:
	virtual void add(Employee&) = 0;
	virtual void del(Employee&) = 0;
	virtual void modify(Employee& from, Employee& to) = 0;
	virtual const employeeList& getEmployees() const = 0;
};

Employees* createEmployees();
