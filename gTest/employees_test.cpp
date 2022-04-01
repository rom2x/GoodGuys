#include "pch.h"
#include <algorithm>
#include "../Employees/Employees.cpp"

class clientTest : public ::testing::Test
{
public:
    clientTest() {
        db = createEmployees();
    }

    ~clientTest() {
        delete db;
    }

protected:
    virtual void SetUp() override
    {
        Employee test_employees[] = {
            { 15123099, "VXIHXOTH", "JHOP", CL::CL3, 3112, 2609, 19771211, CERTI::ADV},
            { 17112609, "FB", "NTAWR", CL::CL4, 5645,6122, 19861203, CERTI::PRO },
            { 18115040, "TTETHU", "HBO", CL::CL3, 4581, 2050, 20080718, CERTI::ADV },
            { 88114052, "NQ", "LVARW", CL::CL4, 4528, 3059, 19911021, CERTI::PRO },
            { 19129568, "SRERLALH", "HMEF", CL::CL2, 3091, 9521, 19640910, CERTI::PRO },
            { 17111236, "VSID", "TVO", CL::CL1, 3669, 1077, 20120718, CERTI::PRO },
            { 18117906, "TWU", "QSOLT", CL::CL4, 6672, 7186, 20030413, CERTI::PRO },
            { 8123556, "WN", "XV", CL::CL1, 7986, 5047, 20100614, CERTI::PRO },
            { 2117175, "SBILHUT", "LDEXRI", CL::CL4, 2814,1699, 19950704, CERTI::ADV },
        };

        for (auto t : test_employees) {
            db->add(t);
        }

        cout << "Client 생성" << endl;
    }

    virtual void TearDown() override
    {

    }

protected:
    Employees* db;
};

TEST(EmployeeTest, EmployeeOperator)
{
    Employee a = { 15123099, "VXIHXOTH", "JHOP", CL::CL3, 3112, 2609, 19771211, CERTI::ADV };
    Employee b = { 18115040, "TTETHU", "HBO", CL::CL3, 4581, 2050, 20080718, CERTI::ADV };

    EXPECT_TRUE(a < b);
    EXPECT_FALSE(a > b);

    Employee c = { 15123099, "VXIHXOTH", "JHOP", CL::CL3, 3112, 2609, 19771211, CERTI::ADV };
    Employee d = { 2117175, "SBILHUT", "LDEXRI", CL::CL4, 2814,1699, 19950704, CERTI::ADV }; // 2000년 이 후 사번에 대한 케이스 테스트

    EXPECT_TRUE(c < d);
    EXPECT_FALSE(c > d);
}

TEST_F(clientTest, EmployeesTestSize)
{
    const employeeList* t = db->getEmployees();

    EXPECT_EQ(t->size(), 9);
}

TEST_F(clientTest, EmployeesTestAdd)
{
    const employeeList* t = db->getEmployees();

    Employee empl = { 12234575, "EOJOEI", "EWFWEF", CL::CL2, 5332, 6544, 20152623, CERTI::PRO };
    db->add(empl);

    EXPECT_EQ(t->size(), 10);
}

TEST_F(clientTest, EmployeesTestDelete)
{
    const employeeList* t = db->getEmployees();

    Employee empl1 = { 17111236, "VSID", "TVO", CL::CL1, 3669, 1077, 20120718, CERTI::PRO };
    db->del(empl1);
    EXPECT_EQ(t->size(), 8);

    Employee empl2 = { 19129568, "SRERLALH", "HMEF", CL::CL2, 3091, 9521, 19640910, CERTI::PRO };
    db->del(empl2);
    EXPECT_EQ(t->size(), 7);

    Employee empl3 = { 32523452, "SRERLALH", "HMEF", CL::CL2, 3091, 9521, 19640910, CERTI::PRO };
    EXPECT_ANY_THROW(db->del(empl3));
}

TEST_F(clientTest, EmployeesTestModify) {
    Employee from = { 15123099, "VXIHXOTH", "JHOP", CL::CL3, 3112, 2609, 19771211, CERTI::ADV };
    Employee to = { 15123099, "VXIHXOTH", "ABC", CL::CL3, 3112, 2609, 19771211, CERTI::ADV };

    db->modify(from, to);

    const employeeList* t = db->getEmployees();

    Employee modified = *std::find(t->begin(), t->end(), from);
    EXPECT_NE(modified.lastName, "JHOP");
    EXPECT_EQ(modified.lastName, "ABC");

    Employee nodata = { 23452212, "VXIHXOTH", "ABC", CL::CL3, 3112, 2609, 19771211, CERTI::ADV };
    EXPECT_ANY_THROW(db->modify(nodata, to));
}
