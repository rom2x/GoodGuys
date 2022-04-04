#pragma once

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.

#ifndef  _SEARCH_H_
#define  _SEARCH_H_

#include <iostream>
#include <list>
#include <string>
#include "../Employees/employees.h"

enum class SearchType {
	EMPLOYEE_NUM,
	NAME,
	FIRST_NAME,
	LAST_NAME,
	PHONE_NUM,
	PHONE_NUM_MID,
	PHONE_NUM_LAST,
	BIRTHDAY,
	BIRTHDAY_YEAR,
	BIRTHDAY_MONTH,
	BIRTHDAY_DAY,
	CL,
	CERTI,
};

class SearchInput {
public:
	SearchType  search_type;
	std::string search_pattern;
};

class SearchCondition {
public:
	std::function<bool(Employee&)> Match;
};

class EmployNumCondition : public SearchCondition {
public:
	EmployNumCondition(SearchInput in);
private:
	unsigned  employee_number;
};

class NameCondition : public SearchCondition {
public:
	NameCondition(SearchInput in);
private:
	std::string name;
};

class FirstNameCondition : public SearchCondition {
public:
	FirstNameCondition(SearchInput in);
private:
	std::string first_name;
};

class LastNameCondition : public SearchCondition {
public:
	LastNameCondition(SearchInput in);
private:
	std::string last_name;
};

class PhoneNumCondition : public SearchCondition {
public:
	PhoneNumCondition(SearchInput in);
private:
	std::string phone_num;
};

class PhoneNumMidCondition : public SearchCondition {
public:
	PhoneNumMidCondition(SearchInput in);
private:
	unsigned phone_num_mid;
};

class PhoneNumLastCondition : public SearchCondition {
public:
	PhoneNumLastCondition(SearchInput in);
private:
	unsigned phone_num_last;
};

class BirthCondition : public SearchCondition {
public:
	BirthCondition(SearchInput in);
private:
	unsigned birth;
};

class BirthYearCondition : public SearchCondition {
public:
	BirthYearCondition(SearchInput in);
private:
	unsigned year;
};

class BirthMonthCondition : public SearchCondition {
public:
	BirthMonthCondition(SearchInput in);
private:
	unsigned month;
};

class BirthDayCondition : public SearchCondition {
public:
	BirthDayCondition(SearchInput in);
private:
	unsigned day;
};

class ClCondition : public SearchCondition {
public:
	ClCondition(SearchInput in);
private:
	CL cl;
};

class CertiCondition : public SearchCondition {
public:
	CertiCondition(SearchInput in);
private:
	CERTI certi;
};


class Search {
public:
	void SetEmployeeList(Employees* employees_ptr);
	employeeList DoSearch(SearchInput in);

private:
	Employees* employees_;
	SearchCondition* search_condition;
};


#endif
