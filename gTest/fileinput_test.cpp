#include "pch.h"
#include "../GoodGuys/file_input_manager.cpp"

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

