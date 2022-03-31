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
		list.emplace_back(new_employee);
		map.insert(std::pair<unsigned, Employee*>(new_employee.employeeNumber, &list.back()));
	}

	virtual void del(Employee& del_employee) override
	{
		try {
			list.remove(*find(del_employee));
			map.erase(del_employee.employeeNumber);
		}
		catch (invalid_argument& e) {
			cout << e.what();
			throw e;
		}
	}

	virtual void modify(Employee& target, std::function<void(Employee&)> func) override
	{
		try {
			Employee& t = *find(target);
			func(t);
		}
		catch (invalid_argument& e) {
			cout << e.what();
			throw e;
		}
		catch (exception& e) {
			throw e;
		}
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
