#pragma once

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.

#ifndef  _SEARCH_H_
#define  _SEARCH_H_

#include <iostream>
#include <list>
#include <string>
#include "../Employees/employees.h"

enum class SearchType {
	FIRST_NAME,
	LAST_NAME,
	PHONE_NUM_MID,
	PHONE_NUM_LAST,
	BIRTHDAY_YEAR,
	BIRTHDAY_MONTH,
	BIRTHDAY_DAY
};

class SearchInput {
public:
	SearchType  search_type;
	std::string search_pattern;
	bool        is_search_and_p;     // be true when SCH & -p
};

class SearchCondition {
public:
	virtual bool Match(Employee in) = 0;
};

class FirstNameCondition : public SearchCondition {
public:
	FirstNameCondition(SearchInput in);
	virtual bool Match(Employee in) override;
private:
	std::string first_name;
};

class LastNameCondition : public SearchCondition {
public:
	LastNameCondition(SearchInput in);
	virtual bool Match(Employee in) override;
private:
	std::string last_name;
};

class PhoneNumMidCondition : public SearchCondition {
public:
	PhoneNumMidCondition(SearchInput in);
	virtual bool Match(Employee in) override;
private:
	unsigned phone_num_mid;
};

class PhoneNumLastCondition : public SearchCondition {
public:
	PhoneNumLastCondition(SearchInput in);
	virtual bool Match(Employee in) override;
private:
	unsigned phone_num_last;
};

class BirthYearCondition : public SearchCondition {
public:
	BirthYearCondition(SearchInput in);
	virtual bool Match(Employee in) override;
private:
	unsigned year;
};

class BirthMonthCondition : public SearchCondition {
public:
	BirthMonthCondition(SearchInput in);
	virtual bool Match(Employee in) override;
private:
	unsigned month;
};

class BirthDayCondition : public SearchCondition {
public:
	BirthDayCondition(SearchInput in);
	virtual bool Match(Employee in) override;
private:
	unsigned day;
};

class Search {
public:
	void SetEmployeeList(employeeList* list);
	employeeList DoSearch(SearchInput in);

private:
	employeeList* employee_db;
	SearchCondition* search_condition;
};


#endif
