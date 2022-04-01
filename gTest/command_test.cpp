#include "pch.h"

#include "../command/command.cpp"

class CommandTest : public ::testing::Test
{
public:
    CommandTest() {
        db = CreateEmployees();
    }

    ~CommandTest() {
        delete db;

    }

protected:
    virtual void SetUp() override
    {
        testCmdLine.push_back("15123099");
        testCmdLine.push_back("VXIHXOTH");
        testCmdLine.push_back("JHOP");
        testCmdLine.push_back("CL3");
        testCmdLine.push_back("3112");
        testCmdLine.push_back("2609");
        testCmdLine.push_back("ADV");
    }

    virtual void TearDown() override
    {

    }

protected:
    vector<string> testCmdLine;
    vector<Employee> testEmployee;

    Employees* db;
};

TEST_F(CommandTest, command_test_0_constructor)
{
    Command* add = new Add(testCmdLine);
    Command* del = new Del(testCmdLine);
    Command* search = new Search(testCmdLine);
    Command* modify= new Modify(testCmdLine);
}

TEST_F(CommandTest, command_test_0_command_process)
{
    //Command* add = new Add(testCmdLine);
    //EXPECT_NO_THROW(add->Process(db));
}
