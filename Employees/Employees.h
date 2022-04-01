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
CL StrToCL(const std::string&);

enum class CERTI {
	ADV,
	PRO,
	EX,
};
CERTI StrToCerti(const std::string&);

unsigned StrToEmployeeNumber(const std::string&);

struct Employee
{
	const unsigned employee_number; // 69xxxxxx ~ 21xxxxxx
	std::string first_name;
	std::string last_name;
	CL cl;
	unsigned phone_num_mid; // xxxx
	unsigned phone_num_last; // xxxx
	unsigned birth; // YYYYMMDD
	CERTI certi;

	Employee(std::string employeeNumber_, std::string firstName_, std::string lastName_, std::string cl_, std::string phoneNumMid_, std::string phoneNumLast_, std::string birth_, std::string certi_)
		: employee_number(StrToEmployeeNumber(employeeNumber_)), first_name(std::move(firstName_)), last_name(std::move(lastName_)), phone_num_mid(stoi(phoneNumMid_)), phone_num_last(stoi(phoneNumLast_)), birth(stoi(birth_))
	{
		cl = StrToCL(cl_);
		certi = StrToCerti(certi_);
	}

	const bool operator== (const Employee& b) const
	{
		if (employee_number == b.employee_number)
			return true;
		else
			return false;
	}

	const bool operator< (const Employee& b) const
	{
		if (employee_number < b.employee_number)
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
	virtual void Add(Employee&) = 0;
	virtual employeeList Del(Employee&) = 0;
	virtual employeeList Modify(Employee&, std::function<void (Employee&)>) = 0;
	virtual employeeList Search(std::function<bool(Employee&)>) = 0;
	virtual const employeeList* const getEmployees() const = 0;
};

Employees* CreateEmployees();
