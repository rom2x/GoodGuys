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
public:
	virtual void doCommand(vector<string> cmdLine) override {

	}
};
class Del :public Command
{
public:
	virtual void doCommand(vector<string> cmdLine) override {

	}
};
class Search :public Command
{
public:
	virtual void doCommand(vector<string> cmdLine) override {

	}
};
class Modify :public Command
{
public:
	virtual void doCommand(vector<string> cmdLine) override {

	}
};