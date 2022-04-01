#include "pch.h"
#include "../Search/Search.h"

class SearchTestDb
{
public:
	SearchTestDb() {
		this->employee_db.push_back( Employee( "98123299", "A", "1", "CL1", "3112", "7053", "19771121", "ADV" ) );
		this->employee_db.push_back( Employee( "16121099", "B", "2", "CL3", "7322", "5735", "19801112", "PRO" ) );
		this->employee_db.push_back( Employee( "17123599", "B", "3", "CL4", "7623", "1237", "19821031", "ADV" ) );
		this->employee_db.push_back( Employee( "18124099", "C", "LEE", "CL2", "5373", "3753", "19841112", "PRO" ) );
		this->employee_db.push_back( Employee( "19122099", "D", "LEE", "CL3", "3112", "1765", "19901217", "ADV" ) );
		this->employee_db.push_back( Employee( "20123099", "A", "6", "CL2", "2374", "7325", "19770505", "PRO" ) );
		this->employee_db.push_back( Employee( "21123059", "F", "7", "CL4", "1237", "7524", "19711109", "PRO" ) );
		this->employee_db.push_back( Employee( "21123199", "F", "8", "CL1", "3937", "7824", "19641112", "ADV" ) );
		this->employee_db.push_back( Employee( "21125099", "F", "4", "CL3", "5372", "1745", "20221105", "PRO" ) );
	}

	~SearchTestDb() {
		this->employee_db.clear();
	}

	employeeList* GetEmployeeDb(void) { return &employee_db; };

private : 
	employeeList employee_db;
};


TEST(Search_FirstName, FirstName_A) {
	SearchTestDb search_test_db;
	Search search;
	SearchInput in;
	employeeList out;
	employeeList::iterator it;

	search.SetEmployeeList( search_test_db.GetEmployeeDb() );

	in.search_pattern = "A";
	in.is_search_and_p = false;
	in.search_type = SearchType::FIRST_NAME;

	out = search.DoSearch(in);

	it = out.begin();
	ASSERT_EQ(out.size(), 2);
	EXPECT_EQ(it->employee_number, 1998123299);
	it++;
	EXPECT_EQ(it->employee_number, 2020123099);
}


TEST(Search_LastName, LastName_LEE) {
	SearchTestDb search_test_db;
	Search search;
	SearchInput in;
	employeeList out;
	employeeList::iterator it;

	search.SetEmployeeList(search_test_db.GetEmployeeDb());

	in.search_pattern = "LEE";
	in.is_search_and_p = false;
	in.search_type = SearchType::LAST_NAME;

	out = search.DoSearch(in);

	it = out.begin();
	ASSERT_EQ(out.size(), 2);
	EXPECT_EQ(it->employee_number, 2018124099);
	it++;
	EXPECT_EQ(it->employee_number, 2019122099);
}


TEST(Search_PhoneNumMid, PhoneNumMid_1237) {
	SearchTestDb search_test_db;
	Search search;
	SearchInput in;
	employeeList out;
	employeeList::iterator it;

	search.SetEmployeeList(search_test_db.GetEmployeeDb());

	in.search_pattern = "1237";
	in.is_search_and_p = false;
	in.search_type = SearchType::PHONE_NUM_MID;

	out = search.DoSearch(in);

	it = out.begin();
	ASSERT_EQ(out.size(), 1);
	EXPECT_EQ(it->employee_number, 2021123059);
}

TEST(Search_PhoneNumLast, PhoneNumLast_7824) {
	SearchTestDb search_test_db;
	Search search;
	SearchInput in;
	employeeList out;
	employeeList::iterator it;

	search.SetEmployeeList(search_test_db.GetEmployeeDb());

	in.search_pattern = "7824";
	in.is_search_and_p = false;
	in.search_type = SearchType::PHONE_NUM_LAST;

	out = search.DoSearch(in);

	it = out.begin();
	ASSERT_EQ(out.size(), 1);
	EXPECT_EQ(it->employee_number, 2021123199);
}

TEST(Search_BirthdayYear, BirthdayYear_1977) {
	SearchTestDb search_test_db;
	Search search;
	SearchInput in;
	employeeList out;
	employeeList::iterator it;

	search.SetEmployeeList(search_test_db.GetEmployeeDb());

	in.search_pattern = "1977";
	in.is_search_and_p = false;
	in.search_type = SearchType::BIRTHDAY_YEAR;

	out = search.DoSearch(in);

	it = out.begin();
	ASSERT_EQ(out.size(), 2);
	EXPECT_EQ(it->employee_number, 1998123299);
	it++;
	EXPECT_EQ(it->employee_number, 2020123099);
}


TEST(Search_BirthdayMonth, BirthdayMonth_11) {
	SearchTestDb search_test_db;
	Search search;
	SearchInput in;
	employeeList out;
	employeeList::iterator it;

	search.SetEmployeeList(search_test_db.GetEmployeeDb());

	in.search_pattern = "11";
	in.is_search_and_p = false;
	in.search_type = SearchType::BIRTHDAY_MONTH;

	out = search.DoSearch(in);

	it = out.begin();
	ASSERT_EQ(out.size(), 6);
	EXPECT_EQ(it->employee_number, 1998123299);
	it++;
	EXPECT_EQ(it->employee_number, 2016121099);
	it++;
	EXPECT_EQ(it->employee_number, 2018124099);
	it++;
	EXPECT_EQ(it->employee_number, 2021123059);
	it++;
	EXPECT_EQ(it->employee_number, 2021123199);
	it++;
	EXPECT_EQ(it->employee_number, 2021125099);
}

TEST(Search_BirthdayMonth_Only5, BirthdayMonth_11_Only5) {
	SearchTestDb search_test_db;
	Search search;
	SearchInput in;
	employeeList out;
	employeeList::iterator it;

	search.SetEmployeeList(search_test_db.GetEmployeeDb());

	in.search_pattern = "11";
	in.is_search_and_p = true;
	in.search_type = SearchType::BIRTHDAY_MONTH;

	out = search.DoSearch(in);

	it = out.begin();
	ASSERT_EQ(out.size(), 5);
	EXPECT_EQ(it->employee_number, 1998123299);
	it++;
	EXPECT_EQ(it->employee_number, 2016121099);
	it++;
	EXPECT_EQ(it->employee_number, 2018124099);
	it++;
	EXPECT_EQ(it->employee_number, 2021123059);
	it++;
	EXPECT_EQ(it->employee_number, 2021123199);
}


TEST(Search_BirthdayDay_Only5, BirthdayDay_12_Only5) {
	SearchTestDb search_test_db;
	Search search;
	SearchInput in;
	employeeList out;
	employeeList::iterator it;

	search.SetEmployeeList(search_test_db.GetEmployeeDb());

	in.search_pattern = "12";
	in.is_search_and_p = false;
	in.search_type = SearchType::BIRTHDAY_DAY;

	out = search.DoSearch(in);

	it = out.begin();
	ASSERT_EQ(out.size(), 3);
	EXPECT_EQ(it->employee_number, 2016121099);
	it++;
	EXPECT_EQ(it->employee_number, 2018124099);
	it++;
	EXPECT_EQ(it->employee_number, 2021123199);
}
