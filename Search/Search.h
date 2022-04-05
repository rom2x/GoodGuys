#pragma once

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.

#ifndef  _SEARCH_H_
#define  _SEARCH_H_

#include <iostream>
#include <list>
#include <string>
#include "../Employees/employees.h"

using namespace std;

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

class SearchCondition {
public:
	std::function<bool(Employee&)> Match;
};

class EmployNumCondition : public SearchCondition {
public:
	EmployNumCondition(string search_pattern);
private:
	unsigned  employee_number;
};

class NameCondition : public SearchCondition {
public:
	NameCondition(string search_pattern);
private:
	std::string name;
};

class FirstNameCondition : public SearchCondition {
public:
	FirstNameCondition(string search_pattern);
private:
	std::string first_name;
};

class LastNameCondition : public SearchCondition {
public:
	LastNameCondition(string search_pattern);
private:
	std::string last_name;
};

class PhoneNumCondition : public SearchCondition {
public:
	PhoneNumCondition(string search_pattern);
private:
	std::string phone_num;
};

class PhoneNumMidCondition : public SearchCondition {
public:
	PhoneNumMidCondition(string search_pattern);
private:
	unsigned phone_num_mid;
};

class PhoneNumLastCondition : public SearchCondition {
public:
	PhoneNumLastCondition(string search_pattern);
private:
	unsigned phone_num_last;
};

class BirthCondition : public SearchCondition {
public:
	BirthCondition(string search_pattern);
private:
	unsigned birth;
};

class BirthYearCondition : public SearchCondition {
public:
	BirthYearCondition(string search_pattern);
private:
	unsigned year;
};

class BirthMonthCondition : public SearchCondition {
public:
	BirthMonthCondition(string search_pattern);
private:
	unsigned month;
};

class BirthDayCondition : public SearchCondition {
public:
	BirthDayCondition(string search_pattern);
private:
	unsigned day;
};

class ClCondition : public SearchCondition {
public:
	ClCondition(string search_pattern);
private:
	CL cl;
};

class CertiCondition : public SearchCondition {
public:
	CertiCondition(string search_pattern);
private:
	CERTI certi;
};


class Search {
public:
	void SetEmployeeList(Employees* employees_ptr);
	employeeList DoSearch(SearchType  search_type, string search_pattern);

private:
	Employees* employees_;
	SearchCondition* search_condition;
};


#endif
