#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Command {
public:
	void process(/*Database& database*/);
	virtual void doCommand(vector<string> cmdLine) = 0;
};

// TODO: class 명 변경.
class Add :public Command
{

};
class Del :public Command
{

};
class Search :public Command
{

};
class Modify :public Command
{

};