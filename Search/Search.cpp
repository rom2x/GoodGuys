
#include "Search.h"


void Search::setEmployeeList(employeeList* list)
{
	this->employeeDB = list;
}

void Search::searchByFirstName(SearchInput in, SearchOutput& out)
{
	employeeList::iterator iter;
	out.num = 0;
	for (iter = this->employeeDB->begin(); iter != this->employeeDB->end(); iter++)
	{
		if (iter->firstName == in.searchPattern)
		{
			out.searchList.push_back(&*iter);
			out.num++;
		}
		if (in.isOnly5 && out.num == 5)
			break;
	}
}

void Search::searchByLastName(SearchInput in, SearchOutput& out)
{
	employeeList::iterator iter;
	out.num = 0;
	for (iter = this->employeeDB->begin(); iter != this->employeeDB->end(); iter++)
	{
		if (iter->lastName == in.searchPattern)
		{
			out.searchList.push_back(&*iter);
			out.num++;
		}
		if (in.isOnly5 && out.num == 5)
			break;
	}
}

void Search::searchByPhoneNumMid(SearchInput in, SearchOutput& out)
{
	employeeList::iterator iter;
	out.num = 0;
	for (iter = this->employeeDB->begin(); iter != this->employeeDB->end(); iter++)
	{
		if (iter->phoneNumMid == stoi(in.searchPattern))
		{
			out.searchList.push_back(&*iter);
			out.num++;
		}
		if (in.isOnly5 && out.num == 5)
			break;
	}
}

void Search::searchByPhoneNumLast(SearchInput in, SearchOutput& out)
{
	employeeList::iterator iter;
	out.num = 0;
	for (iter = this->employeeDB->begin(); iter != this->employeeDB->end(); iter++)
	{
		if (iter->phoneNumLast == stoi(in.searchPattern))
		{
			out.searchList.push_back(&*iter);
			out.num++;
		}
		if (in.isOnly5 && out.num == 5)
			break;
	}
}

void Search::searchByBirthYear(SearchInput in, SearchOutput& out)
{
	employeeList::iterator iter;
	out.num = 0;
	for (iter = this->employeeDB->begin(); iter != this->employeeDB->end(); iter++)
	{
		unsigned year = iter->birth / 10000;
		if (year == stoi(in.searchPattern))
		{
			out.searchList.push_back(&*iter);
			out.num++;
		}
		if (in.isOnly5 && out.num == 5)
			break;
	}
}

void Search::searchByBirthMonth(SearchInput in, SearchOutput& out)
{
	employeeList::iterator iter;
	out.num = 0;
	for (iter = this->employeeDB->begin(); iter != this->employeeDB->end(); iter++)
	{
		unsigned month = iter->birth % 10000 / 100;
		if (month == stoi(in.searchPattern))
		{
			out.searchList.push_back(&*iter);
			out.num++;
		}
		if(month > 12)
			throw out_of_range("month Range Error!");
		if (in.isOnly5 && out.num == 5)
			break;
	}
}

void Search::searchByBirthDay(SearchInput in, SearchOutput& out)
{
	employeeList::iterator iter;
	out.num = 0;
	for (iter = this->employeeDB->begin(); iter != this->employeeDB->end(); iter++)
	{
		unsigned day = iter->birth / 100;
		if (day == stoi(in.searchPattern))
		{
			out.searchList.push_back(&*iter);
			out.num++;
		}
		if (day > 31)
			throw out_of_range("Day Range Error!");
		if (in.isOnly5 && out.num == 5)
			break;
	}
}


SearchOutput Search::doSearch(SearchInput in)
{
	SearchOutput searchOutput;

	switch (in.searchType)
	{
	case FIRST_NAME:		Search::searchByFirstName(in, searchOutput);	break;
	case LAST_NAME:         Search::searchByLastName(in, searchOutput);		break;
	case PHONE_NUM_MID:     Search::searchByPhoneNumMid(in, searchOutput);	break;
	case PHONE_NUM_LAST:    Search::searchByPhoneNumLast(in, searchOutput);	break;
	case BIRTHDAY_YEAR:     Search::searchByBirthYear(in, searchOutput);	break;
	case BIRTHDAY_MONTH:    Search::searchByBirthMonth(in, searchOutput);	break;
	case BIRTHDAY_DAY:      Search::searchByBirthDay(in, searchOutput);		break;
	default: throw out_of_range("SearchType Range Error!");
	}

	return searchOutput;
}
