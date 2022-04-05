#include "pch.h"
#include "../Search/Search.h"

class SearchTestDb
{
public:
	SearchTestDb() {
		db = CreateEmployees();

		db->Add(Employee("98123299", "A", "1", "CL1", "3112", "7053", "19771121", "ADV"));
		db->Add(Employee("16121099", "B", "2", "CL3", "7322", "5735", "19801112", "PRO"));
		db->Add(Employee("17123599", "B", "3", "CL4", "7623", "1237", "19821031", "ADV"));
		db->Add(Employee("18124099", "C", "LEE", "CL2", "5373", "3753", "19841112", "PRO"));
		db->Add(Employee("19122099", "D", "LEE", "CL3", "3112", "1765", "19901217", "ADV"));
		db->Add(Employee("20123099", "A", "6", "CL2", "2374", "7325", "19770505", "PRO"));
		db->Add(Employee("21123059", "F", "7", "CL4", "1237", "7524", "19711109", "PRO"));
		db->Add(Employee("21123199", "F", "8", "CL1", "3937", "7824", "19641112", "ADV"));
		db->Add(Employee("21125099", "F", "4", "CL3", "5372", "1745", "20221105", "PRO"));
	}

	~SearchTestDb() {
		delete db;
	}

	Employees* GetEmployeeDb(void) { return db; };

private : 
	Employees* db;;
};

TEST(Search_EmployNum, EmplyNum_20123099) {
	SearchTestDb search_test_db;
	Search search;
	SearchType search_type;
	string search_pattern;
	employeeList out;
	employeeList::iterator it;

	search.SetEmployeeList(search_test_db.GetEmployeeDb());

	search_pattern = "20123099";
	search_type = SearchType::EMPLOYEE_NUM;

	out = search.DoSearch(search_type, search_pattern);

	it = out.begin();
	ASSERT_EQ(out.size(), 1);
	EXPECT_EQ(it->employee_number, 2020123099);
}


TEST(Search_Name,Name_CLEE) {
	SearchTestDb search_test_db;
	Search search;
	SearchType search_type;
	string search_pattern;
	employeeList out;
	employeeList::iterator it;

	search.SetEmployeeList(search_test_db.GetEmployeeDb());

	search_pattern = "C LEE";
	search_type = SearchType::NAME;

	out = search.DoSearch(search_type, search_pattern);

	it = out.begin();
	ASSERT_EQ(out.size(), 1);
	EXPECT_EQ(it->employee_number, 2018124099);
}

TEST(Search_FirstName, FirstName_A) {
	SearchTestDb search_test_db;
	Search search;
	SearchType search_type;
	string search_pattern;
	employeeList out;
	employeeList::iterator it;

	search.SetEmployeeList( search_test_db.GetEmployeeDb() );

	search_pattern = "A";
	search_type = SearchType::FIRST_NAME;

	out = search.DoSearch(search_type, search_pattern);

	it = out.begin();
	ASSERT_EQ(out.size(), 2);
	EXPECT_EQ(it->employee_number, 1998123299);
	it++;
	EXPECT_EQ(it->employee_number, 2020123099);
}

TEST(Search_LastName, LastName_LEE) {
	SearchTestDb search_test_db;
	Search search;
	SearchType search_type;
	string search_pattern;
	employeeList out;
	employeeList::iterator it;

	search.SetEmployeeList(search_test_db.GetEmployeeDb());

	search_pattern = "LEE";
	search_type = SearchType::LAST_NAME;

	out = search.DoSearch(search_type, search_pattern);

	it = out.begin();
	ASSERT_EQ(out.size(), 2);
	EXPECT_EQ(it->employee_number, 2018124099);
	it++;
	EXPECT_EQ(it->employee_number, 2019122099);
}

TEST(Search_PhoneNum, PhoneNum_12377524) {
	SearchTestDb search_test_db;
	Search search;
	SearchType search_type;
	string search_pattern;
	employeeList out;
	employeeList::iterator it;

	search.SetEmployeeList(search_test_db.GetEmployeeDb());

	search_pattern = "010-1237-7524";
	search_type = SearchType::PHONE_NUM;

	out = search.DoSearch(search_type, search_pattern);

	it = out.begin();
	ASSERT_EQ(out.size(), 1);
	EXPECT_EQ(it->employee_number, 2021123059);
}

TEST(Search_PhoneNumMid, PhoneNumMid_1237) {
	SearchTestDb search_test_db;
	Search search;
	SearchType search_type;
	string search_pattern;
	employeeList out;
	employeeList::iterator it;

	search.SetEmployeeList(search_test_db.GetEmployeeDb());

	search_pattern = "1237";
	search_type = SearchType::PHONE_NUM_MID;

	out = search.DoSearch(search_type, search_pattern);

	it = out.begin();
	ASSERT_EQ(out.size(), 1);
	EXPECT_EQ(it->employee_number, 2021123059);
}

TEST(Search_PhoneNumLast, PhoneNumLast_7824) {
	SearchTestDb search_test_db;
	Search search;
	SearchType search_type;
	string search_pattern;
	employeeList out;
	employeeList::iterator it;

	search.SetEmployeeList(search_test_db.GetEmployeeDb());

	search_pattern = "7824";
	search_type = SearchType::PHONE_NUM_LAST;

	out = search.DoSearch(search_type, search_pattern);

	it = out.begin();
	ASSERT_EQ(out.size(), 1);
	EXPECT_EQ(it->employee_number, 2021123199);
}

TEST(Search_Birthday, Birthday_19641112) {
	SearchTestDb search_test_db;
	Search search;
	SearchType search_type;
	string search_pattern;
	employeeList out;
	employeeList::iterator it;

	search.SetEmployeeList(search_test_db.GetEmployeeDb());

	search_pattern = "19641112";
	search_type = SearchType::BIRTHDAY;

	out = search.DoSearch(search_type, search_pattern);

	it = out.begin();
	ASSERT_EQ(out.size(), 1);
	EXPECT_EQ(it->employee_number, 2021123199);
}

TEST(Search_BirthdayYear, BirthdayYear_1977) {
	SearchTestDb search_test_db;
	Search search;
	SearchType search_type;
	string search_pattern;
	employeeList out;
	employeeList::iterator it;

	search.SetEmployeeList(search_test_db.GetEmployeeDb());

	search_pattern = "1977";
	search_type = SearchType::BIRTHDAY_YEAR;

	out = search.DoSearch(search_type, search_pattern);

	it = out.begin();
	ASSERT_EQ(out.size(), 2);
	EXPECT_EQ(it->employee_number, 1998123299);
	it++;
	EXPECT_EQ(it->employee_number, 2020123099);
}

TEST(Search_BirthdayMonth, BirthdayMonth_11) {
	SearchTestDb search_test_db;
	Search search;
	SearchType search_type;
	string search_pattern;
	employeeList out;
	employeeList::iterator it;

	search.SetEmployeeList(search_test_db.GetEmployeeDb());

	search_pattern = "11";
	search_type = SearchType::BIRTHDAY_MONTH;

	out = search.DoSearch(search_type, search_pattern);

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

TEST(Search_BirthdayDay, BirthdayDay_12) {
	SearchTestDb search_test_db;
	Search search;
	SearchType search_type;
	string search_pattern;
	employeeList out;
	employeeList::iterator it;

	search.SetEmployeeList(search_test_db.GetEmployeeDb());

	search_pattern = "12";
	search_type = SearchType::BIRTHDAY_DAY;

	out = search.DoSearch(search_type, search_pattern);

	it = out.begin();
	ASSERT_EQ(out.size(), 3);
	EXPECT_EQ(it->employee_number, 2016121099);
	it++;
	EXPECT_EQ(it->employee_number, 2018124099);
	it++;
	EXPECT_EQ(it->employee_number, 2021123199);
}

TEST(Search_Cl, Cl_2) {
	SearchTestDb search_test_db;
	Search search;
	SearchType search_type;
	string search_pattern;
	employeeList out;
	employeeList::iterator it;

	search.SetEmployeeList(search_test_db.GetEmployeeDb());

	search_pattern = "CL2";
	search_type = SearchType::CL;

	out = search.DoSearch(search_type, search_pattern);

	it = out.begin();
	ASSERT_EQ(out.size(), 2);
	EXPECT_EQ(it->employee_number, 2018124099);
	it++;
	EXPECT_EQ(it->employee_number, 2020123099);
}

TEST(Search_Certi, Certi_ADV) {
	SearchTestDb search_test_db;
	Search search;
	SearchType search_type;
	string search_pattern;
	employeeList out;
	employeeList::iterator it;

	search.SetEmployeeList(search_test_db.GetEmployeeDb());

	search_pattern = "ADV";
	search_type = SearchType::CERTI;

	out = search.DoSearch(search_type, search_pattern);

	it = out.begin();
	ASSERT_EQ(out.size(), 4);
	EXPECT_EQ(it->employee_number, 1998123299);
	it++;
	EXPECT_EQ(it->employee_number, 2017123599);
	it++;
	EXPECT_EQ(it->employee_number, 2019122099);
	it++;
	EXPECT_EQ(it->employee_number, 2021123199);
}
