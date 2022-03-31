#include "Employees.h"

#include <algorithm>
#include <exception>
#include <unordered_map>

using namespace std;

class EmployeesImpl : public Employees
{
public:
	virtual void add(Employee& new_employee) override
	{

	}

	virtual void del(Employee& del_employee) override
	{

	}

	virtual void modify(Employee& from, Employee& to) override
	{

	}

	virtual const employeeList* const getEmployees() const override
	{
		return &list;
	}

private:
	employeeList list;
	unordered_map<unsigned, Employee*> map;

	Employee* find(Employee& target)
	{
		auto search = map.find(target.employeeNumber);
		if (search == map.end())
			throw invalid_argument("존재하지 않는 직원");
		return map.find(target.employeeNumber)->second;
	}
};

Employees* createEmployees()
{
	return new EmployeesImpl();
}
