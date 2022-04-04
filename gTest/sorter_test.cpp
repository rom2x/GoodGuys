#include "pch.h"
#include "../GoodGuys/Sorter.cpp"
#include "../Employees/Employees.h"

class SortTest : public ::testing::Test
{
public:
    SortTest() {
        sorter = new Sorter<Employee>();
    }

    ~SortTest() {
        delete sorter;
    }

protected:
    virtual void SetUp() override
    {
        employees.push_back(new Employee{ "15123099", "VXIHXOTH", "JHOP", "CL3", "3112", "2609", "19771211", "ADV" });
        employees.push_back(new Employee{ "17112609", "FB", "NTAWR", "CL4", "5645", "6122", "19861203", "PRO" });
        employees.push_back(new Employee{ "18115040", "TTETHU", "HBO", "CL3", "4581", "2050", "20080718", "ADV" });
        employees.push_back(new Employee{ "88114052", "NQ", "LVARW", "CL4", "4528", "3059", "19911021", "PRO"});
        employees.push_back(new Employee{ "19129568", "SRERLALH", "HMEF", "CL2", "3091", "9521", "19640910", "PRO"});
        employees.push_back(new Employee{ "17111236", "VSID", "TVO", "CL1", "3669", "1077", "20120718", "PRO" });
        employees.push_back(new Employee{ "18117906", "TWU", "QSOLT", "CL4", "6672", "7186", "20030413", "PRO" });
        employees.push_back(new Employee{ "81235564", "WN", "XV", "CL1", "7986", "5047", "20100614", "PRO" });
        employees.push_back(new Employee{ "21171756", "SBILHUT", "LDEXRI", "CL4", "2814","1699", "19950704", "ADV" });

        
        sorter->Run(employees);

        cout << "Sort ¿Ï·á" << endl;
    }

    virtual void TearDown() override
    {

    }

protected:
    vector<Employee*> employees;
    Sorter<Employee>* sorter;

};

TEST_F(SortTest, SORT_TEST1) {
    EXPECT_EQ(1981235564, employees[0]->employee_number);
    EXPECT_EQ(1988114052, employees[1]->employee_number);
    EXPECT_EQ(2015123099, employees[2]->employee_number);
    EXPECT_EQ(2021171756, employees[8]->employee_number);
    EXPECT_TRUE(true);
}
