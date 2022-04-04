
#include "Search.h"


FirstNameCondition::FirstNameCondition(SearchInput in) {
	this->first_name = in.search_pattern;
}

bool FirstNameCondition::Match(Employee in) {
	return in.first_name == this->first_name;
}

LastNameCondition::LastNameCondition(SearchInput in) {
	this->last_name = in.search_pattern;
}

bool LastNameCondition::Match(Employee in) {
	return in.last_name == this->last_name;
}

PhoneNumMidCondition::PhoneNumMidCondition(SearchInput in) {
	this->phone_num_mid = stoi(in.search_pattern);
}

bool PhoneNumMidCondition::Match(Employee in) {
	return in.phone_num_mid == this->phone_num_mid;
}

PhoneNumLastCondition::PhoneNumLastCondition(SearchInput in) {
	this->phone_num_last = stoi(in.search_pattern);
}

bool PhoneNumLastCondition::Match(Employee in) {
	return in.phone_num_last == this->phone_num_last;
}

BirthYearCondition::BirthYearCondition(SearchInput in) {
	this->year = stoi(in.search_pattern);
}

bool BirthYearCondition::Match(Employee in) {
	unsigned year = in.birth / 10000;
	return year == this->year;
}

BirthMonthCondition::BirthMonthCondition(SearchInput in) {
	this->month = stoi(in.search_pattern);
	if (this->month < 0 || this->month > 12) {
		throw std::out_of_range("Search month range error!");
	}
}

bool BirthMonthCondition::Match(Employee in) {
	unsigned month = in.birth % 10000 / 100;
	if (month < 0 || month > 12) {
		throw std::out_of_range("Month range error!");
	}
	return month == this->month;
}

BirthDayCondition::BirthDayCondition(SearchInput in) {
	this->day = stoi(in.search_pattern);
	if (this->day < 0 || this->day > 31) {
		throw std::out_of_range("Search day range error!");
	}
}

bool BirthDayCondition::Match(Employee in) {
	unsigned day = in.birth % 100;
	if (day < 0 || day > 31) {
		throw std::out_of_range("Day range error!");
	}
	return day == this->day;
}

void Search::SetEmployeeList(employeeList* list) {
	this->employee_db = list;
}

employeeList Search::DoSearch(SearchInput in) {
	employeeList searchOutput;

	switch (in.search_type)	{
	case SearchType::FIRST_NAME:	 this->search_condition = new FirstNameCondition(in);	  break;
	case SearchType::LAST_NAME:		 this->search_condition = new LastNameCondition(in);	  break;
	case SearchType::PHONE_NUM_MID:	 this->search_condition = new PhoneNumMidCondition(in);	  break;
	case SearchType::PHONE_NUM_LAST: this->search_condition = new PhoneNumLastCondition(in);  break;
	case SearchType::BIRTHDAY_YEAR:	 this->search_condition = new BirthYearCondition(in);	  break;
	case SearchType::BIRTHDAY_MONTH: this->search_condition = new BirthMonthCondition(in);	  break;
	case SearchType::BIRTHDAY_DAY:	 this->search_condition = new BirthDayCondition(in);	  break;
	default: throw std::out_of_range("SearchType range error!");
	}

	for (auto employee : *(this->employee_db)) {
		if (this->search_condition->Match(employee))
		{
			searchOutput.emplace_back(employee);
		}
		if (in.is_search_and_p && searchOutput.size() == 5)
			break;
	}

	delete this->search_condition;

	return searchOutput;
}
