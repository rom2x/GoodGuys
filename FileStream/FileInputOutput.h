#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


class FileInput {
public:
	//String a[,구분갯수] = {ADD, -p , NULL, NULL,NULL, } -> 이런식으로 만들기
	FileInput(const string& inputFileName) : inputFileName_(inputFileName) {
		inputFileStream_.open(inputFileName_);
	}

	~FileInput() {
		inputFileStream_.close();
	}

	vector <string> getParsedString();
	bool isEOF();
	void setEmployNum(/*Employee* */);
	void setName(/*Employee* */);
	void setCL(/*Employee* */);
	void setPhoneNumber(/*Employee* */);
	void setBirth(/*Employee* */);
	void setCirti(/*Employee* */);

private:
	ifstream inputFileStream_;
	vector<string> parsedCmd_;
	string inputFileName_;
};


class FileOutput {
public:
	FileOutput(const string& outputFileName) : outputFileName_(outputFileName), outputFileStream_(outputFileName) {
	}

	void printResult(/*Result Class* */);

private:
	ofstream outputFileStream_;
	string outputFileName_;

};
