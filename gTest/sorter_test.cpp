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
        employees.push_back(new Employee{ 15123099, "VXIHXOTH", "JHOP", CL::CL3, 3112, 2609, 19771211, CERTI::ADV });
        employees.push_back(new Employee{ 17112609, "FB", "NTAWR", CL::CL4, 5645, 6122, 19861203, CERTI::PRO });
        employees.push_back(new Employee{ 18115040, "TTETHU", "HBO", CL::CL3, 4581, 2050, 20080718, CERTI::ADV });
        employees.push_back(new Employee{ 88114052, "NQ", "LVARW", CL::CL4, 4528, 3059, 19911021, CERTI::PRO });
        employees.push_back(new Employee{ 19129568, "SRERLALH", "HMEF", CL::CL2, 3091, 9521, 19640910, CERTI::PRO });
        employees.push_back(new Employee{ 17111236, "VSID", "TVO", CL::CL1, 3669, 1077, 20120718, CERTI::PRO });
        employees.push_back(new Employee{ 18117906, "TWU", "QSOLT", CL::CL4, 6672, 7186, 20030413, CERTI::PRO });
        employees.push_back(new Employee{ 81235564, "WN", "XV", CL::CL1, 7986, 5047, 20100614, CERTI::PRO });
        employees.push_back(new Employee{ 21171756, "SBILHUT", "LDEXRI", CL::CL4, 2814,1699, 19950704, CERTI::ADV });

        
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
    EXPECT_EQ(81235564, employees[0]->employeeNumber);
    EXPECT_EQ(88114052, employees[1]->employeeNumber);
    EXPECT_EQ(15123099, employees[2]->employeeNumber);
    EXPECT_EQ(21171756, employees[8]->employeeNumber);
    EXPECT_TRUE(true);
}
