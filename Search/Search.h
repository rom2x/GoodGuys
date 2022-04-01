#pragma once

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.

#ifndef  _SEARCH_H_
#define  _SEARCH_H_

#include <iostream>
#include <list>
#include <Vector>
#include <string>
#include "../Employees/Employees.h"

using namespace std;
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

class SearchInput
{
public:
	SearchType searchType;
	string     searchPattern;
	bool       isOnly5;     // be true when SCH & -p
};

class SearchOutput
{
public:
	SearchList searchList;
	unsigned   num;
};

class Search
{
public:
	void setEmployeeList(employeeList* list);
	SearchOutput doSearch(SearchInput in);

private:
	employeeList* employeeDB;
	void searchByFirstName		(SearchInput in, SearchOutput& out);
	void searchByLastName		(SearchInput in, SearchOutput& out);
	void searchByPhoneNumMid	(SearchInput in, SearchOutput& out);
	void searchByPhoneNumLast   (SearchInput in, SearchOutput& out);
	void searchByBirthYear		(SearchInput in, SearchOutput& out);
	void searchByBirthMonth		(SearchInput in, SearchOutput& out);
	void searchByBirthDay		(SearchInput in, SearchOutput& out);
};

#endif
