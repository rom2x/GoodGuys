
#include "Search.h"


void Search::SetEmployeeList(employeeList* list) {
	this->employee_db = list;
}

void Search::SearchByFirstName(SearchInput in, SearchOutput& out) {
	employeeList::iterator employee;
	for (employee = this->employee_db->begin(); employee != this->employee_db->end(); employee++)
	{
		if (employee->firstName == in.search_pattern)
			out.push_back(&(*employee));
		if (in.is_search_and_p && out.size() == 5)
			break;
	}
}

void Search::SearchByLastName(SearchInput in, SearchOutput& out) {
	employeeList::iterator employee;
	for (employee = this->employee_db->begin(); employee != this->employee_db->end(); employee++)
	{
		if (employee->lastName == in.search_pattern)
			out.push_back(&(*employee));
		if (in.is_search_and_p && out.size() == 5)
			break;
	}
}

void Search::SearchByPhoneNumMid(SearchInput in, SearchOutput& out) {
	employeeList::iterator employee;
	for (employee = this->employee_db->begin(); employee != this->employee_db->end(); employee++)
	{
		if (employee->phoneNumMid == stoi(in.search_pattern))
			out.push_back(&(*employee));
		if (in.is_search_and_p && out.size() == 5)
			break;
	}
}

void Search::SearchByPhoneNumLast(SearchInput in, SearchOutput& out) {
	employeeList::iterator employee;
	for (employee = this->employee_db->begin(); employee != this->employee_db->end(); employee++)
	{
		if (employee->phoneNumLast == stoi(in.search_pattern))
			out.push_back(&(*employee));
		if (in.is_search_and_p && out.size() == 5)
			break;
	}
}

void Search::SearchByBirthYear(SearchInput in, SearchOutput& out) {
	employeeList::iterator employee;
	for (employee = this->employee_db->begin(); employee != this->employee_db->end(); employee++)
	{
		unsigned year = employee->birth / 10000;
		if (year == stoi(in.search_pattern))
			out.push_back(&(*employee));
		if (in.is_search_and_p && out.size() == 5)
			break;
	}
}

void Search::SearchByBirthMonth(SearchInput in, SearchOutput& out) {
	employeeList::iterator employee;
	for (employee = this->employee_db->begin(); employee != this->employee_db->end(); employee++)
	{
		unsigned month = employee->birth % 10000 / 100;
		if (month == stoi(in.search_pattern))
			out.push_back(&(*employee));
		if(month > 12)
			throw std::out_of_range("month Range Error!");
		if (in.is_search_and_p && out.size() == 5)
			break;
	}
}

void Search::SearchByBirthDay(SearchInput in, SearchOutput& out) {
	employeeList::iterator employee;
	for (employee = this->employee_db->begin(); employee != this->employee_db->end(); employee++)
	{
		unsigned day = employee->birth % 100;
		if (day == stoi(in.search_pattern))
			out.push_back(&(*employee));
		if (day > 31)
			throw std::out_of_range("Day Range Error!");
		if (in.is_search_and_p && out.size() == 5)
			break;
	}
}


SearchOutput Search::DoSearch(SearchInput in) {
	SearchOutput searchOutput;

	switch (in.search_type)	{
	case SearchType::FIRST_NAME:		Search::SearchByFirstName(in, searchOutput);	break;
	case SearchType::LAST_NAME:         Search::SearchByLastName(in, searchOutput);		break;
	case SearchType::PHONE_NUM_MID:     Search::SearchByPhoneNumMid(in, searchOutput);	break;
	case SearchType::PHONE_NUM_LAST:    Search::SearchByPhoneNumLast(in, searchOutput);	break;
	case SearchType::BIRTHDAY_YEAR:     Search::SearchByBirthYear(in, searchOutput);	break;
	case SearchType::BIRTHDAY_MONTH:    Search::SearchByBirthMonth(in, searchOutput);	break;
	case SearchType::BIRTHDAY_DAY:      Search::SearchByBirthDay(in, searchOutput);		break;
	default: throw std::out_of_range("SearchType Range Error!");
	}

	return searchOutput;
}
