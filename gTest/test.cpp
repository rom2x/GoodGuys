#include "pch.h"
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
        Employee testEmployee[] = {
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

        for (auto t : testEmployee) {
            db->add(t);
        }

        cout << "Client »ı¼º" << endl;
    }

    virtual void TearDown() override
    {

    }

protected:
    Employees* db;
};

TEST_F(clientTest, EmployeesTest1) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}