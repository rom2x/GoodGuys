#pragma once

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.

#ifndef  _SEARCH_H_
#define  _SEARCH_H_

#include <iostream>
#include <list>
#include <Vector>
#include <string>
#include "../Employees/Employees.h"

using SearchList = std::vector<Employee*>;

enum SearchType {
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

class SearchOutput {
public:
	SearchList search_list;
	unsigned   num;
};

class Search {
public:
	void SetEmployeeList(employeeList* list);
	SearchOutput DoSearch(SearchInput in);

private:
	employeeList* employee_db;
	void SearchByFirstName		(SearchInput in, SearchOutput& out);
	void SearchByLastName		(SearchInput in, SearchOutput& out);
	void SearchByPhoneNumMid	(SearchInput in, SearchOutput& out);
	void SearchByPhoneNumLast   (SearchInput in, SearchOutput& out);
	void SearchByBirthYear		(SearchInput in, SearchOutput& out);
	void SearchByBirthMonth		(SearchInput in, SearchOutput& out);
	void SearchByBirthDay		(SearchInput in, SearchOutput& out);
};

#endif
