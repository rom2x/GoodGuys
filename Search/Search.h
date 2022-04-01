#pragma once

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.

#ifndef  _SEARCH_H_
#define  _SEARCH_H_

#include <iostream>
#include <list>
#include <string>
#include "../Employees/Employees.h"

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

class Search {
public:
	void SetEmployeeList(employeeList* list);
	employeeList DoSearch(SearchInput in);

private:
	employeeList* employee_db;
	void SearchByFirstName		(SearchInput in, employeeList& out);
	void SearchByLastName		(SearchInput in, employeeList& out);
	void SearchByPhoneNumMid	(SearchInput in, employeeList& out);
	void SearchByPhoneNumLast   (SearchInput in, employeeList& out);
	void SearchByBirthYear		(SearchInput in, employeeList& out);
	void SearchByBirthMonth		(SearchInput in, employeeList& out);
	void SearchByBirthDay		(SearchInput in, employeeList& out);
};

#endif
