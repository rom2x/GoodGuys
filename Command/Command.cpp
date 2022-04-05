#include "command.h"

static const char NAME_SAPCE_CHAR = ' ';

static string getFirstName(const string& in) {
	return in.substr(0, in.find_first_of(NAME_SAPCE_CHAR));
}

static string getLastName(const string& in) {
	return in.substr(in.find_first_of(NAME_SAPCE_CHAR) + 1);
}

static string getPhoneNumMid(const string& in) {
	return in.substr(4, 4);
}

static string getPhoneNumLast(const string& in) {
	return in.substr(9, 4);
}

static void Print(const string& outstr) {
#if (PRINT_CONSOLE == 1)
	cout << outstr << endl;
#endif
}


static string Output(string name, bool opt, employeeList& list) {
	string ret = "";
	if (list.size() == 0) {
		Print(name + ",NONE");
		ret = name + ",NONE\n";
		return ret;
	}

	if (opt) {
		int i = 0;

		list.sort();

		for (auto empl : list) {
			Print(name + ',' + empl.to_string());
			ret += name + ',' + empl.to_string() + "\n";
			if (i++ == 4) break;
		}
	}
	else {
		Print(name + ',' + to_string(list.size()));
		ret += name + ',' + to_string(list.size()) + "\n";
	}

	return ret;
}

string SearchableCommand::GetSearchPattern(void) {
	string search_pattern = param(CommandOffset::SEARCH__SRC_VALUE);
	search_pattern.erase(search_pattern.find_last_not_of(" \t\n\r\f\v") + 1);
	return search_pattern;
}

SearchType SearchableCommand::GetSearchType(void) {
	if (param(CommandOffset::SEARCH__SRC_KEY) == "employeeNum") return SearchType::EMPLOYEE_NUM;

	if (param(CommandOffset::SEARCH__SRC_KEY) == "name") {
		if (param(CommandOffset::SUB_OPTION) == "-f") return SearchType::FIRST_NAME;
		if (param(CommandOffset::SUB_OPTION) == "-l") return SearchType::LAST_NAME;
		return SearchType::NAME;
	}

	if (param(CommandOffset::SEARCH__SRC_KEY) == "cl") return SearchType::CL;

	if (param(CommandOffset::SEARCH__SRC_KEY) == "phoneNum") {
		if (param(CommandOffset::SUB_OPTION) == "-m") return SearchType::PHONE_NUM_MID;
		if (param(CommandOffset::SUB_OPTION) == "-l") return SearchType::PHONE_NUM_LAST;
		return SearchType::PHONE_NUM;
	}

	if (param(CommandOffset::SEARCH__SRC_KEY) == "birthday") {
		if (param(CommandOffset::SUB_OPTION) == "-y") return SearchType::BIRTHDAY_YEAR;
		if (param(CommandOffset::SUB_OPTION) == "-m") return SearchType::BIRTHDAY_MONTH;
		if (param(CommandOffset::SUB_OPTION) == "-d") return SearchType::BIRTHDAY_DAY;
		return SearchType::BIRTHDAY;
	}

	if (param(CommandOffset::SEARCH__SRC_KEY) == "certi") return SearchType::CERTI;

	throw invalid_argument("Invalid search type\n");
}

string AddCommand::Process(Employees* employees) {
	Employee employee = {
		param(CommandOffset::ADD__EMPLOYEE_NUM),
		param(CommandOffset::ADD__NAME),
		param(CommandOffset::ADD__CL),
		param(CommandOffset::ADD__PHONE_NUM),
		param(CommandOffset::ADD__BIRTHDAY),
		param(CommandOffset::ADD__CERTI)
	};
	employees->Add(employee);

	return "";
}

void AddCommand::CommandValidation() {
	if (ADD_COMMAND_SIZE != params().size()) {
		print_error_msg();
	}
}

string DelCommand::Process(Employees* employees) {
	employeeList delete_employee_list = SearchEmployees(employees);

	for (auto delete_employee : delete_employee_list) {
		employees->Del(delete_employee);
	}

	return Output(name(), param(CommandOffset::PRINT) == "-p", delete_employee_list);
}

void DelCommand::CommandValidation() {
	if (DEL_COMMAND_SIZE != params().size()) {
		print_error_msg();
	}
}

string SearchCommand::Process(Employees* employees) {
	employeeList search_employee_list = SearchEmployees(employees);

	return Output(name(), param(CommandOffset::PRINT) == "-p", search_employee_list);
}

void SearchCommand::CommandValidation() {
	if (SEARCH_COMMAND_SIZE != params().size()) {
		print_error_msg();
	}
}

using mod_func = function<void(Employee&)>;

static mod_func GetModFunction(string target, string modify_val);

string ModifyCommand::Process(Employees* employees) {
	employeeList modify_employee_list = SearchEmployees(employees);

	for (auto employee : modify_employee_list) {
		employees->Modify(employee, GetModFunction(param(CommandOffset::MODIFY__DST_KEY), param(CommandOffset::MODIFY__DST_VALUE)));
	}

	return Output(name(), param(CommandOffset::PRINT) == "-p", modify_employee_list);
}

void ModifyCommand::CommandValidation() {
	if (MODIFY_COMMAND_SIZE != params().size()) {
		print_error_msg();
	}
}

static mod_func GetModFunction(string target, string modify_val) {
	if (target == "name")
		return [modify_val](Employee& empl) { empl.first_name = getFirstName(modify_val); empl.last_name = getLastName(modify_val); };

	if (target == "cl")
		return [modify_val](Employee& empl) { empl.cl = StrToCL(modify_val); };

	if (target == "phoneNum")
		return [modify_val](Employee& empl) { empl.phone_num_mid = stoi(getPhoneNumMid(modify_val)); empl.phone_num_last = stoi(getPhoneNumLast(modify_val)); };

	if (target == "birthday")
		return [modify_val](Employee& empl) { empl.birth = stoi(modify_val); };

	if (target == "certi")
		return [modify_val](Employee& empl) { empl.certi = StrToCerti(modify_val); };

	throw invalid_argument("알 수 없는 column 수정 시도");
};