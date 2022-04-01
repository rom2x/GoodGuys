#include "pch.h"


#include "../Employees/employees.cpp"
#include "../command/command.cpp"

class CommandTest : public ::testing::Test
{
public:
    CommandTest() {
        db = createEmployees();

        add = new Add(db);
        del = new Del(db);
        search = new Search(db);
        modify = new Modify(db);
    }

    ~CommandTest() {
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

TEST_F(CommandTest, command_test_1) {
    EXPECT_NO_THROW(add->Process(testCmdLine));
}
