#include "pch.h"


#include "../Command/Command.cpp"
#include "../Employees/Employees.cpp"

class clientTest : public ::testing::Test
{
public:
    clientTest() {
        db = createEmployees();

        add = new Add(db);
        del = new Del(db);
        search = new Search(db);
        modify = new Modify(db);
    }

    ~clientTest() {
        delete db;

        delete add;
        delete del;
        delete search;
        delete modify;
    }

protected:
    virtual void SetUp() override
    {
        testCmdLine.push_back("");
        testCmdLine.push_back("");
        testCmdLine.push_back("");
        testCmdLine.push_back("15123099");
        testCmdLine.push_back("VXIHXOTH JHOP");
        testCmdLine.push_back("CL3");
        testCmdLine.push_back("010 - 3112 - 2609");
        testCmdLine.push_back("19771211");
        testCmdLine.push_back("ADV");

        testEmployee.push_back({ 17112609, "FB", "NTAWR", CL::CL4, 5645,6122, 19861203, CERTI::PRO });
        testEmployee.push_back({ 18115040, "TTETHU", "HBO", CL::CL3, 4581, 2050, 20080718, CERTI::ADV });
        testEmployee.push_back({ 88114052, "NQ", "LVARW", CL::CL4, 4528, 3059, 19911021, CERTI::PRO });
        testEmployee.push_back({ 19129568, "SRERLALH", "HMEF", CL::CL2, 3091, 9521, 19640910, CERTI::PRO });
        testEmployee.push_back({ 17111236, "VSID", "TVO", CL::CL1, 3669, 1077, 20120718, CERTI::PRO });
        testEmployee.push_back({ 18117906, "TWU", "QSOLT", CL::CL4, 6672, 7186, 20030413, CERTI::PRO });
        testEmployee.push_back({ 8123556, "WN", "XV", CL::CL1, 7986, 5047, 20100614, CERTI::PRO });
        testEmployee.push_back({ 2117175, "SBILHUT", "LDEXRI", CL::CL4, 2814,1699, 19950704, CERTI::ADV });

        for (auto t : testEmployee) {
            db->add(t);
        }

        cout << "Client »ý¼º" << endl;
    }

    virtual void TearDown() override
    {

    }

protected:
    vector<string> testCmdLine;
    vector<Employee> testEmployee;

    Employees* db;

    Command* add;
    Command* del;
    Command* search;
    Command* modify;
};

TEST_F(clientTest, EmployeesTest1) {
    EXPECT_NO_THROW(add->Process(testCmdLine));
}