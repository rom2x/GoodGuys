#include "Employees.h"

#include <algorithm>
#include <exception>
#include <unordered_map>

using namespace std;

static const string cl_string[] = { "CL1", "CL2", "CL3", "CL4" };

CL StrToCL(const std::string& cl_str) {
	if (cl_str == cl_string[static_cast<unsigned>(CL::CL1)])
		return CL::CL1;
	else if (cl_str == cl_string[static_cast<unsigned>(CL::CL2)])
		return CL::CL2;
	else if (cl_str == cl_string[static_cast<unsigned>(CL::CL3)])
		return CL::CL3;
	else if (cl_str == cl_string[static_cast<unsigned>(CL::CL4)])
		return CL::CL4;

	throw invalid_argument("정해지지 않은 CL 형식");
}

static const string certi_string[] = { "ADV", "PRO", "EX" };

CERTI StrToCerti(const std::string& certi_str) {
	if (certi_str == certi_string[static_cast<unsigned>(CERTI::ADV)])
		return CERTI::ADV;
	else if (certi_str == certi_string[static_cast<unsigned>(CERTI::PRO)])
		return CERTI::PRO;
	else if (certi_str == certi_string[static_cast<unsigned>(CERTI::EX)])
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

static string getFirstName(const string& name) {
	return name.substr(0, name.find(' '));
}

static string getLastName(const string& name) {
	size_t delim_pos = name.find(' ');
	return name.substr(delim_pos + 1, name.size() - delim_pos);
}

static unsigned getPhoneNumMid(const string& phone_num) {
	size_t delim_pos = phone_num.find('-');
	return stoi(phone_num.substr(delim_pos + 1, 4));
}

static unsigned getPhoneNumLast(const string& phone_num) {
	size_t delim_pos = phone_num.find('-', 0);
	delim_pos = phone_num.find('-', delim_pos + 1);
	return stoi(phone_num.substr(delim_pos + 1, 4));
}

static vector<string> ParseInputStringOfEmployee(const string& input) {
	vector<string> ret(6);
	size_t pos = 0, npos = 0, i = 0;

	while (pos != string::npos && i < 6) {
		npos = input.find(',', pos);
		ret[i++] = input.substr(pos, npos - pos);
		pos = npos + 1;
	}

	return ret;
}

Employee::Employee(std::string input)
	: employee_number(StrToEmployeeNumber(input.substr(0, input.find(',')))) {
	vector<string> str_token = std::move(ParseInputStringOfEmployee(input));

	first_name = std::move(getFirstName(str_token[1]));
	last_name = std::move(getLastName(str_token[1]));
	cl = StrToCL(str_token[2]);
	phone_num_mid = getPhoneNumMid(str_token[3]);
	phone_num_last = getPhoneNumLast(str_token[3]);
	birth = stoi(str_token[4]);
	certi = StrToCerti(str_token[5]);
}

Employee::Employee(std::string employeeNumber_, std::string name_, std::string cl_, std::string phoneNum_, std::string birth_, std::string certi_)
	: Employee(employeeNumber_ + "," + name_ + "," + cl_ + "," + phoneNum_ + "," + birth_ + "," + certi_) {}

Employee::Employee(std::string employeeNumber_, std::string firstName_, std::string lastName_, std::string cl_, std::string phoneNumMid_, std::string phoneNumLast_, std::string birth_, std::string certi_)
	: Employee(employeeNumber_, firstName_ + " " + lastName_, cl_, "010-" + phoneNumMid_ + "-" + phoneNumLast_, birth_, certi_) {}

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
	return !operator<(b) && !operator==(b);
}

const string Employee::to_string() const {
	return
		std::to_string(employee_number).substr(2, 8) + ","
		+ first_name + " " + last_name + ","
		+ cl_string[(static_cast<unsigned>(cl))] + ","
		+ "010-" + std::to_string(phone_num_mid) + "-" + std::to_string(phone_num_last) + ","
		+ std::to_string(birth) + ","
		+ certi_string[static_cast<unsigned>(certi)];
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

	virtual const size_t getEmployeeNumbers() const {
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
