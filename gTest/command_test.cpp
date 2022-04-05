#include "pch.h"
#include "../command/command.h"

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
        Employee test_employees[] = {
            { "18050301", "KYUMOK KIM", "CL2","010-9777-6055","19980906","PRO"},
        };

        for (auto t : test_employees) {
            db->Add(t);
        }

        add_cmd.push_back("ADD");
        add_cmd.push_back("");
        add_cmd.push_back("");
        add_cmd.push_back("");
        add_cmd.push_back("18050301");
        add_cmd.push_back("KYUMOK KIM");
        add_cmd.push_back("CL2");
        add_cmd.push_back("010-9777-6055");
        add_cmd.push_back("19980906");
        add_cmd.push_back("PRO");

        del_cmd.push_back("DEL");
        del_cmd.push_back("");
        del_cmd.push_back("");
        del_cmd.push_back("");
        del_cmd.push_back("name");
        del_cmd.push_back("KYUMOK KIM");

        search_cmd.push_back("SCH");
        search_cmd.push_back("");
        search_cmd.push_back("");
        search_cmd.push_back("");
        search_cmd.push_back("name");
        search_cmd.push_back("KYUMOK KIM\t");

        modify_cmd.push_back("MOD");
        modify_cmd.push_back("");
        modify_cmd.push_back("");
        modify_cmd.push_back("");
        modify_cmd.push_back("name");
        modify_cmd.push_back("KYUMOK KIM");
        modify_cmd.push_back("name");
        modify_cmd.push_back("KYUMOK LEE");
    }

    virtual void TearDown() override
    {

    }

protected:
    vector<string> add_cmd;
    vector<string> del_cmd;
    vector<string> search_cmd;
    vector<string> modify_cmd;

    Employees* db;
};

TEST_F(CommandTest, command_test_0_constructor)
{
    EXPECT_NO_THROW(new AddCommand(add_cmd));
    EXPECT_ANY_THROW(new DelCommand(add_cmd));
    EXPECT_ANY_THROW(new SearchCommand(add_cmd));
    EXPECT_ANY_THROW(new ModifyCommand(add_cmd));

    EXPECT_NO_THROW(new DelCommand(del_cmd));
    EXPECT_NO_THROW(new SearchCommand(search_cmd));
    EXPECT_NO_THROW(new ModifyCommand(modify_cmd));
}

TEST_F(CommandTest, command_test_1_command_0_add_process)
{
    Command* add = new AddCommand(add_cmd);
    EXPECT_NO_THROW(add->Process(db));
}

TEST_F(CommandTest, command_test_1_command_1_del_process)
{
    Command* del = new DelCommand(del_cmd);
    EXPECT_NO_THROW(del->Process(db));
}

TEST_F(CommandTest, command_test_1_command_2_search_process)
{
    Command* search = new SearchCommand(search_cmd);
    EXPECT_NO_THROW(search->Process(db));
}

TEST_F(CommandTest, command_test_1_command_3_modify_process)
{
    Command* modify = new ModifyCommand(modify_cmd);
    EXPECT_NO_THROW(modify->Process(db));
}
