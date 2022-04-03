#include "Employees.h"

#include <algorithm>
#include <exception>
#include <unordered_map>

using namespace std;

CL StrToCL(const std::string& cl_str) {
	if (cl_str == "CL1")
		return CL::CL1;
	else if (cl_str == "CL2")
		return CL::CL2;
	else if (cl_str == "CL3")
		return CL::CL3;
	else if (cl_str == "CL4")
		return CL::CL4;

	throw invalid_argument("정해지지 않은 CL 형식");
}

CERTI StrToCerti(const std::string& certi_str) {
	if (certi_str == "ADV")
		return CERTI::ADV;
	else if (certi_str == "PRO")
		return CERTI::PRO;
	else if (certi_str == "EX")
		return CERTI::EX;

	throw invalid_argument("정해지지 않은 CERTI 형식");
}

static unsigned StrToEmployeeNumber(const std::string& num) {
	string t = "";

	if ('6' <= num[0] && num[0] <= '9')
		t = "19";
	else
		t = "20";

	t.append(num);

	return stoi(t);
}

Employee::Employee(std::string employeeNumber_, std::string firstName_, std::string lastName_, std::string cl_, std::string phoneNumMid_, std::string phoneNumLast_, std::string birth_, std::string certi_)
	: employee_number(StrToEmployeeNumber(employeeNumber_)), first_name(std::move(firstName_)), last_name(std::move(lastName_)), phone_num_mid(stoi(phoneNumMid_)), phone_num_last(stoi(phoneNumLast_)), birth(stoi(birth_)) {
	cl = StrToCL(cl_);
	certi = StrToCerti(certi_);
	str = employeeNumber_ + "," + first_name + " " + last_name + "," + cl_ + ",010-" + phoneNumMid_ + "-" + phoneNumLast_ + "," + birth_ + "," + certi_;
}

const bool Employee::operator== (const Employee& b) const {
	if (employee_number == b.employee_number)
		return true;
	else
		return false;
}

const bool Employee::operator< (const Employee& b) const {
	if (employee_number < b.employee_number)
		return true;
	else
		return false;
}

const bool Employee::operator> (const Employee& b) const {
	return !operator<(b);
}

class EmployeesImpl : public Employees
{
public:
	virtual void Add(Employee& new_employee) override {
		employeeList::const_iterator pos = FindAscendingOrderPositionAtList(new_employee);
		map.insert(std::pair<unsigned, Employee*>(new_employee.employee_number, &(*list.emplace(pos, new_employee))));
	}

	virtual employeeList Del(Employee& del_employee) override {
		employeeList ret;

		try {
			Employee* t = FindEmployeePointerFromMap(del_employee);
			map.erase(t->employee_number);
			ret.push_back(*t);
			list.remove(*t);

			return ret;
		}
		catch (invalid_argument& e) {
			cout << e.what();
			throw e;
		}
	}

	virtual employeeList Modify(Employee& target, std::function<void(Employee&)> func) override {
		employeeList ret;

		try {
			Employee& t = *FindEmployeePointerFromMap(target);
			ret.push_back(t);
			func(t);

			return ret;
		}
		catch (invalid_argument& e) {
			cout << e.what();
			throw e;
		}
		catch (exception& e) {
			throw e;
		}
	}

	virtual employeeList Search(std::function<bool(Employee&)> func) override {
		employeeList ret;

		for (auto employee : list) {
			if (func(employee))
				ret.emplace_back(employee);
		}

		return ret;
	}

	virtual const unsigned getEmployeeNumbers() const {
		return list.size();
	}

private:
	employeeList list;
	unordered_map<unsigned, Employee*> map;

	Employee* FindEmployeePointerFromMap(Employee& target) {
		auto search = map.find(target.employee_number);
		if (search == map.end())
			throw invalid_argument("존재하지 않는 직원");
		return map.find(target.employee_number)->second;
	}

	employeeList::const_iterator FindAscendingOrderPositionAtList(Employee& empl) {
		return find_if(list.begin(), list.end(), [empl](Employee& listEmpl)->bool { return empl < listEmpl; });
	}
};

Employees* CreateEmployees() {
	return new EmployeesImpl();
}
