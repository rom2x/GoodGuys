#include "pch.h"
#include "../GoodGuys/file_input_manager.cpp"
#include "../GoodGuys/input_parser_manager.cpp"

class FileInputManagerTest : public ::testing::Test
{
protected:
    virtual void SetUp() override
    {
        inputmanager_ = new FileInputManager("Invalid.txt");
    }

    virtual void TearDown() override
    {

    }

    FileInputManager* inputmanager_;
};


TEST_F(FileInputManagerTest, InvalidFile) {
    EXPECT_FALSE(inputmanager_->IsFileValid());
}

class InputParserManagerTest : public ::testing::Test
{
protected:
    virtual void SetUp() override
    {
        parsemanager_ = new InputParserManager();
        inputstrings_.push_back("ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV");
        inputstrings_.push_back("SCH,-p,-d, ,birthday,04");
        inputstrings_.push_back("MOD,-p, , ,name,FB NTAWR,birthday,20050520");
        inputstrings_.push_back("DEL,-p,-l, ,name,MPOSXU");

        addoutputstring_.push_back("ADD");
        addoutputstring_.push_back(" ");
        addoutputstring_.push_back(" ");
        addoutputstring_.push_back(" ");
        addoutputstring_.push_back("15123099");
        addoutputstring_.push_back("VXIHXOTH JHOP");
        addoutputstring_.push_back("CL3");
        addoutputstring_.push_back("010-3112-2609");
        addoutputstring_.push_back("19771211");
        addoutputstring_.push_back("ADV");

        schoutputstring_.push_back("SCH");
        schoutputstring_.push_back("-p");
        schoutputstring_.push_back("-d");
        schoutputstring_.push_back(" ");
        schoutputstring_.push_back("birthday");
        schoutputstring_.push_back("04");

        modoutputstring_.push_back("MOD");
        modoutputstring_.push_back("-p");
        modoutputstring_.push_back(" ");
        modoutputstring_.push_back(" ");
        modoutputstring_.push_back("name");
        modoutputstring_.push_back("FB NTAWR");
        modoutputstring_.push_back("birthday");
        modoutputstring_.push_back("20050520");

        deloutputstring_.push_back("DEL");
        deloutputstring_.push_back("-p");
        deloutputstring_.push_back("-l");
        deloutputstring_.push_back(" ");
        deloutputstring_.push_back("name");
        deloutputstring_.push_back("MPOSXU");
    }

    virtual void TearDown() override
    {

    }

    InputParserManager* parsemanager_;
    vector <string> inputstrings_;
    vector <string> addoutputstring_;
    vector <string> schoutputstring_;
    vector <string> modoutputstring_;
    vector <string> deloutputstring_;
};


TEST_F(InputParserManagerTest, AddStringTest) {
    EXPECT_EQ(addoutputstring_, parsemanager_->GetEachLineParsedStrings(inputstrings_[0]));
}

TEST_F(InputParserManagerTest, SchStringTest) {
    EXPECT_EQ(schoutputstring_, parsemanager_->GetEachLineParsedStrings(inputstrings_[1]));
}

TEST_F(InputParserManagerTest, ModStringTest) {
    EXPECT_EQ(modoutputstring_, parsemanager_->GetEachLineParsedStrings(inputstrings_[2]));
}

TEST_F(InputParserManagerTest, DelStringTest) {
    EXPECT_EQ(deloutputstring_, parsemanager_->GetEachLineParsedStrings(inputstrings_[3]));
}