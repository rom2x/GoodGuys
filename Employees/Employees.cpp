#include "Employees.h"

#include <algorithm>
#include <exception>

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
};

Employees* createEmployees()
{
	return new EmployeesImpl();
}
